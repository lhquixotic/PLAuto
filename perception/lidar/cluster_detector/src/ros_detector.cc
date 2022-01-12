#include "ros_detector.hxx"

#define PI 3.1415926
cloud_toolbox::ROSDetector::ROSDetector(ros::NodeHandle &nh){
    std::string input_cloud_topic;
    std::string filter_cloud_topic;
    std::string ground_cloud_topic;
    std::string scene_cloud_topic;
    std::string occ_grid_topic;
    std::string obj_array_topic;
    std::string vis_cluster_cloud_topic;
    std::string marker_array_topic;
    std::string boundary_marker_topic;


    nh.getParam("input_cloud_topic", input_cloud_topic);
    nh.getParam("filtered_cloud_topic", filter_cloud_topic);
    nh.getParam("ground_cloud_topic", ground_cloud_topic);
    nh.getParam("scene_cloud_topic", scene_cloud_topic);
    nh.getParam("occ_grid_topic", occ_grid_topic);
    nh.getParam("obj_array_topic", obj_array_topic);
    nh.getParam("vis_cluster_cloud_topic", vis_cluster_cloud_topic);
    nh.getParam("marker_array_topic", marker_array_topic);
    nh.getParam("boundary_marker_topic", boundary_marker_topic);

    // get parameters
    // preprocessing
        // cloud_range
    nh.getParam("cloud_range_x_min", cloud_range_[0]);
    nh.getParam("cloud_range_y_min", cloud_range_[1]);
    nh.getParam("cloud_range_z_min", cloud_range_[2]);
    nh.getParam("cloud_range_x_max", cloud_range_[3]);
    nh.getParam("cloud_range_y_max", cloud_range_[4]);
    nh.getParam("cloud_range_z_max", cloud_range_[5]);

    nh.getParam("ego_size_x_min", ego_size_[0]);
    nh.getParam("ego_size_y_min", ego_size_[1]);
    nh.getParam("ego_size_z_min", ego_size_[2]);
    nh.getParam("ego_size_x_max", ego_size_[3]);
    nh.getParam("ego_size_y_max", ego_size_[4]);
    nh.getParam("ego_size_z_max", ego_size_[5]);

        // voxel filter leaf size
    nh.getParam("voxel_filter_leaf_size_x", voxel_filter_leaf_size_[0]);
    nh.getParam("voxel_filter_leaf_size_y", voxel_filter_leaf_size_[1]);
    nh.getParam("voxel_filter_leaf_size_z", voxel_filter_leaf_size_[2]);

    // ground filter
    nh.getParam("num_ground_seeds", num_ground_seeds_);
    nh.getParam("lidar_height", lidar_height_);
    nh.getParam("th_ground_seeds", th_ground_seeds_);
    nh.getParam("iter_ground_plane", iter_ground_plane_);
    nh.getParam("th_ground_plane", th_ground_plane_);


    //boundary make
    nh.getParam("max_distance", boundary_max_distance);
    // cloud cluster
    nh.getParam("clip_height", clip_height_);

        // scene_split
    nh.getParam("scene_slit_0", scene_split_[0]);
    nh.getParam("scene_slit_1", scene_split_[1]);
    nh.getParam("scene_slit_2", scene_split_[2]);
    nh.getParam("scene_slit_3", scene_split_[3]);
    
        // cluster_leaf_sizes
    nh.getParam("cluster_leaf_sizes_0", cluster_leaf_sizes_[0]);
    nh.getParam("cluster_leaf_sizes_1", cluster_leaf_sizes_[1]);
    nh.getParam("cluster_leaf_sizes_2", cluster_leaf_sizes_[2]);
    nh.getParam("cluster_leaf_sizes_3", cluster_leaf_sizes_[3]);
    nh.getParam("cluster_leaf_sizes_4", cluster_leaf_sizes_[4]);


        // cluster_ths
    nh.getParam("cluster_ths_0", cluster_ths_[0]);
    nh.getParam("cluster_ths_1", cluster_ths_[1]);
    nh.getParam("cluster_ths_2", cluster_ths_[2]);
    nh.getParam("cluster_ths_3", cluster_ths_[3]);
    nh.getParam("cluster_ths_4", cluster_ths_[4]);

    nh.getParam("cluster_min_size", cluster_min_size_);
    nh.getParam("cluster_max_size", cluster_max_size_);


    // std::cout<<"cluster_max_size: "<<cluster_max_size_<<std::endl;




    input_cloud = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    filter_cloud = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    ground_cloud = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    scene_cloud = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    vis_cluster_cloud = pcl::PointCloud<pcl::PointXYZRGB>::Ptr(new pcl::PointCloud<pcl::PointXYZRGB>);

    filter_cloud_publisher = nh.advertise<sensor_msgs::PointCloud2>(filter_cloud_topic, 10);
    ground_cloud_publisher = nh.advertise<sensor_msgs::PointCloud2>(ground_cloud_topic, 10);
    scene_cloud_publisher = nh.advertise<sensor_msgs::PointCloud2>(scene_cloud_topic, 10);
    occ_grid_publisher = nh.advertise<nav_msgs::OccupancyGrid>(occ_grid_topic, 10);
    obj_array_publisher = nh.advertise<autoware_msgs::DetectedObjectArray>(obj_array_topic, 10);
    vis_cluster_cloud_publisher = nh.advertise<sensor_msgs::PointCloud2>(vis_cluster_cloud_topic, 10);
    marker_array_publisher = nh.advertise<visualization_msgs::MarkerArray>(marker_array_topic, 10);
    boundary_marker_publisher = nh.advertise<visualization_msgs::Marker>(boundary_marker_topic, 10);


    cloud_subscriber = nh.subscribe(input_cloud_topic, 10, &cloud_toolbox::ROSDetector::execute, this);
    ros::spin();



};

cloud_toolbox::ROSDetector::~ROSDetector(){};

void cloud_toolbox::ROSDetector::paint_cluster_cloud(std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> cluster_cloud, pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_cluster_cloud){
    
    pcl::PointXYZRGB tmp_point;
    int total_points = 0;
    for (size_t i = 0; i < cluster_cloud.size(); i ++){
        int rgb = ((int)rand()%255) << 16 | ((int)rand()%255) << 8 | ((int)rand()%255);
        for (size_t j = 0; j < cluster_cloud[i]->points.size(); j ++){
            tmp_point.x = cluster_cloud[i]->points[j].x;
            tmp_point.y = cluster_cloud[i]->points[j].y;
            tmp_point.z = cluster_cloud[i]->points[j].z;
            tmp_point.rgb = rgb;
            vis_cluster_cloud->points.push_back(tmp_point);
            total_points++;
        }
    }
    // std::cout<<"total points: "<<total_points<<std::endl;
}

void cloud_toolbox::ROSDetector::cal_marker_array(std::vector<box_info>& bboxes, visualization_msgs::MarkerArray& marker_array){
    int marker_id = 0;
    for (int i = 0; i < bboxes.size(); i ++){
        visualization_msgs::Marker marker_bbox;
        marker_bbox.header = common_header;
        marker_bbox.ns = "bbox";
        marker_bbox.id = marker_id;
        marker_bbox.type = visualization_msgs::Marker::CUBE;
        marker_bbox.action = visualization_msgs::Marker::ADD;

        marker_bbox.pose.position.x = bboxes[i].x;
        marker_bbox.pose.position.y = bboxes[i].y;
        marker_bbox.pose.position.z = bboxes[i].z;

        Eigen::Vector3d ori(0.0, 0.0, -bboxes[i].r_z);
        Eigen::Matrix3d R;
        R = Eigen::AngleAxisd(ori[0], Eigen::Vector3d::UnitX()) *
            Eigen::AngleAxisd(ori[1], Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(ori[2], Eigen::Vector3d::UnitZ()) ;
        Eigen::Quaterniond q(R);
        marker_bbox.pose.orientation.x = q.x();
        marker_bbox.pose.orientation.y = q.y();
        marker_bbox.pose.orientation.z = q.z();
        marker_bbox.pose.orientation.w = q.w();

        marker_bbox.scale.x = bboxes[i].l;
        marker_bbox.scale.y = bboxes[i].w;
        marker_bbox.scale.z = bboxes[i].h;

        marker_bbox.color.r = 1.0f;
        marker_bbox.color.g = 1.0f;
        marker_bbox.color.b = 0.0f;
        marker_bbox.color.a = 0.5f;

        marker_bbox.lifetime = ros::Duration(0.5);
        marker_bbox.frame_locked = true;
        marker_id ++;

        marker_array.markers.push_back(marker_bbox);

    }
}
void cloud_toolbox::ROSDetector::cal_obj_array(std::vector<box_info>& bboxes, autoware_msgs::DetectedObjectArray& obj_array){
    obj_array.header = common_header;
    for (int i = 0; i < bboxes.size(); i ++){
        autoware_msgs::DetectedObject obj;
        obj.header = common_header;
        obj.id = 0;
        obj.label = "car";
        obj.score = 1.0;
        obj.valid = true;

        obj.pose.position.x = bboxes[i].x;
        obj.pose.position.y = bboxes[i].y;
        obj.pose.position.z = bboxes[i].z;

        Eigen::Vector3d ori(0.0, 0.0, -bboxes[i].r_z);
        Eigen::Matrix3d R;
        R = Eigen::AngleAxisd(ori[0], Eigen::Vector3d::UnitX()) *
            Eigen::AngleAxisd(ori[1], Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(ori[2], Eigen::Vector3d::UnitZ()) ;
        Eigen::Quaterniond q(R);

        obj.pose.orientation.x = q.x();
        obj.pose.orientation.y = q.y();
        obj.pose.orientation.z = q.z();
        obj.pose.orientation.w = q.w();

        obj.dimensions.x = bboxes[i].l;
        obj.dimensions.y = bboxes[i].w;
        obj.dimensions.z = bboxes[i].h;

        obj_array.objects.push_back(obj);



    }
}


void cloud_toolbox::ROSDetector::cal_polar_boundary(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, visualization_msgs::Marker& boundary_marker){
    std::vector<float> polar_boundary;
    std::vector<int> to_del_id;
    polar_boundary.clear();
    to_del_id.clear();
    for (size_t i = 0; i < 360; i ++){
        polar_boundary.push_back(boundary_max_distance);
    }
    for (size_t i = 0; i < scene_cloud->points.size(); i ++){
        if (scene_cloud->points[i].z > clip_height_ + lidar_height_){
            continue;
        }
        double distance = sqrt(scene_cloud->points[i].x * scene_cloud->points[i].x + scene_cloud->points[i].y * scene_cloud->points[i].y);
        double theta = atan2(scene_cloud->points[i].y, scene_cloud->points[i].x);

        if (distance >=boundary_max_distance){
            continue;
        }
        
        int theta_round = ceil(theta / PI * 180) + 180 - 1; //jxy: (-180, 180] to [0, 359]
        
        if (theta_round < 0 || theta_round >= 360){ //jxy: theoretically impossible, but there are always some points with x and y of value "nan"
            continue;
        }
        if (polar_boundary[theta_round] > distance){
            polar_boundary[theta_round] = distance;
        }
    }


    del_points(polar_boundary, to_del_id);



    vis_boundary(polar_boundary, to_del_id, boundary_marker);
}


void cloud_toolbox::ROSDetector::del_points(std::vector<float>& original_polar_boundary, std::vector<int>& to_del_id){
    double th_outlier = 1.0;
    for (size_t i = 1; i < 360-1; i ++){
        if (original_polar_boundary[i] - original_polar_boundary[i-1] > th_outlier && original_polar_boundary[i] - original_polar_boundary[i+1] > th_outlier){
            to_del_id.push_back(i);
        }
    }

    if (original_polar_boundary[0] - original_polar_boundary[360-1] > th_outlier && original_polar_boundary[0] - original_polar_boundary[1] > th_outlier){
        to_del_id.push_back(0);
    }
    if (original_polar_boundary[360-1] - original_polar_boundary[0] > th_outlier && original_polar_boundary[360-1] - original_polar_boundary[360-2] > th_outlier){
        to_del_id.push_back(360-1);
    }


    double th_line = 10 * PI / 180;

    double curr_length, tri_a, tri_b, tri_c, tri_p, tri_mid, tmp_x, tmp_y, c_alpha;
    for (size_t i = 1; i < 360-1; i ++){

        curr_length = original_polar_boundary[i];
        tri_a = original_polar_boundary[i-1];
        tri_c = original_polar_boundary[i+1];
        tri_b = sqrt( tri_a * tri_a + tri_c * tri_c - 2* tri_a* tri_c* cos(2*PI/180));
        tri_p = (tri_a + tri_b +tri_c)/2;
        tri_mid = 2/(tri_a +tri_c) *sqrt(tri_a*tri_c*tri_p*(tri_p - tri_b));

        tmp_x = sqrt(tri_a*tri_a+tri_mid*tri_mid-2*tri_a*tri_mid*cos(PI/180));
        tmp_y = sqrt(tri_a*tri_a+curr_length*curr_length-2*tri_a*curr_length*cos(PI/180));
        c_alpha = (tmp_x*tmp_x+tmp_y*tmp_y-(curr_length-tri_mid)*(curr_length-tri_mid))/(2*tmp_x*tmp_y);
        if (c_alpha > cos(th_line) && curr_length > tri_mid){
            to_del_id.push_back(i);
        }
    }


    //for the first and last point
    curr_length = original_polar_boundary[0];
    tri_a = original_polar_boundary[360-1];
    tri_c = original_polar_boundary[1];
    tri_b = sqrt( tri_a * tri_a + tri_c * tri_c - 2* tri_a* tri_c* cos(2*PI/180));
    tri_p = (tri_a + tri_b +tri_c)/2;
    tri_mid = 2/(tri_a +tri_c) *sqrt(tri_a*tri_c*tri_p*(tri_p - tri_b));

    tmp_x = sqrt(tri_a*tri_a+tri_mid*tri_mid-2*tri_a*tri_mid*cos(PI/180));
    tmp_y = sqrt(tri_a*tri_a+curr_length*curr_length-2*tri_a*curr_length*cos(PI/180));
    c_alpha = (tmp_x*tmp_x+tmp_y*tmp_y-(curr_length-tri_mid)*(curr_length-tri_mid))/(2*tmp_x*tmp_y);
    if (c_alpha > cos(th_line) && curr_length > tri_mid){
        to_del_id.push_back(0);
    }


    curr_length = original_polar_boundary[360-1];
    tri_a = original_polar_boundary[360-2];
    tri_c = original_polar_boundary[0];
    tri_b = sqrt( tri_a * tri_a + tri_c * tri_c - 2* tri_a* tri_c* cos(2*PI/180));
    tri_p = (tri_a + tri_b +tri_c)/2;
    tri_mid = 2/(tri_a +tri_c) *sqrt(tri_a*tri_c*tri_p*(tri_p - tri_b));

    tmp_x = sqrt(tri_a*tri_a+tri_mid*tri_mid-2*tri_a*tri_mid*cos(PI/180));
    tmp_y = sqrt(tri_a*tri_a+curr_length*curr_length-2*tri_a*curr_length*cos(PI/180));
    c_alpha = (tmp_x*tmp_x+tmp_y*tmp_y-(curr_length-tri_mid)*(curr_length-tri_mid))/(2*tmp_x*tmp_y);
    if (c_alpha > cos(th_line) && curr_length > tri_mid){
        to_del_id.push_back(360-1);
    }


}



void cloud_toolbox::ROSDetector::vis_boundary(std::vector<float>& polar_boundary, std::vector<int>& to_del_id, visualization_msgs::Marker& boundary_marker){
    visualization_msgs::Marker tempmarker;
    tempmarker.header.frame_id = "/base_link";
    tempmarker.header.stamp = ros::Time::now();
    tempmarker.ns = "basic_shapes";
    tempmarker.id = 0;

    tempmarker.type = visualization_msgs::Marker::LINE_STRIP;
    tempmarker.action = visualization_msgs::Marker::ADD;
    tempmarker.scale.x = 0.5;
    tempmarker.color.r = 1.0;
    tempmarker.color.g = 1.0;
    tempmarker.color.b = 0.0;
    tempmarker.color.a = 0.5;
    tempmarker.lifetime = ros::Duration(0.5);
    tempmarker.points.resize(0);
    for (int i = 175; i < 185; i++){
        if (std::count(to_del_id.begin(), to_del_id.end(), i)){
            // std::cout<< "del" << i << std::endl;
            geometry_msgs::Point p;
            double theta = (i - 180) * PI / 180;
            p.x = polar_boundary[i] * cos(theta);
            p.y = polar_boundary[i] * sin(theta);
            p.z = 0.1; //mark that this point should be removed
            tempmarker.points.push_back(p);
            continue;
        }
        geometry_msgs::Point p;
        double theta = (i - 180) * PI / 180;
        p.x = polar_boundary[i] * cos(theta);
        p.y = polar_boundary[i] * sin(theta);
        p.z = 0;
        tempmarker.points.push_back(p);
    }
    // tempmarker.points.push_back(tempmarker.points[0]); //close the figure
    boundary_marker = tempmarker;

    std::cout << "num points deleted: " << to_del_id.size()<<std::endl;
    std::cout << "num marker points:  " << boundary_marker.points.size() << std::endl;
}



void cloud_toolbox::ROSDetector::cal_occ_grid(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, nav_msgs::OccupancyGrid& occ_grid){
    int grid_cell_width = 500;
    int grid_cell_height = 1000;
    double g_resolution = 0.1;
    unsigned char *cost_map_point_count;
    cost_map_point_count = (unsigned char *)malloc(grid_cell_width * grid_cell_height * sizeof(unsigned char));
    memset(cost_map_point_count, 0, grid_cell_width * grid_cell_height);

    cv::Mat cost_map;
    cost_map = cv::Mat(grid_cell_height, grid_cell_width, CV_8UC1, cv::Scalar(0));

    double map_center_x = (grid_cell_width / 2.0) * g_resolution;
    double map_center_y = (grid_cell_height / 2.0) * g_resolution;

    for (size_t i = 0; i < scene_cloud->points.size(); i ++){
        if (scene_cloud->points[i].z > clip_height_ + lidar_height_){
            continue;
        }

        int grid_x = (scene_cloud->points[i].x + map_center_x) / g_resolution;
        int grid_y = (scene_cloud->points[i].y + map_center_y) / g_resolution;

        if (grid_x < 0 || grid_x >= grid_cell_width || grid_y < 0 || grid_y >= grid_cell_height){
            continue;
        }
        int index = grid_cell_width * grid_y + grid_x;
        cost_map.data[index] = 100;
    }

    static int count = 0;

    occ_grid.info.resolution = g_resolution;
    occ_grid.info.width = grid_cell_width;
    occ_grid.info.height = grid_cell_height;

    occ_grid.info.origin.position.x = (-1) * (grid_cell_width / 2.0) * g_resolution;
    occ_grid.info.origin.position.y = (-1) * (grid_cell_height / 2.0) * g_resolution;
    occ_grid.info.origin.position.z = 0.0;
    occ_grid.info.origin.orientation.x = 0.0;
    occ_grid.info.origin.orientation.y = 0.0;
    occ_grid.info.origin.orientation.z = 0.0;
    occ_grid.info.origin.orientation.w = 1.0;

    occ_grid.header.frame_id = "base_link";
    occ_grid.header.stamp = common_header.stamp;
    occ_grid.header.seq = count++;
    occ_grid.data = std::vector<int8_t>((int8_t *)cost_map.data, (int8_t *)cost_map.data + grid_cell_height * grid_cell_width);
}


void cloud_toolbox::ROSDetector::occgrid2boundary(nav_msgs::OccupancyGrid& occ_grid, visualization_msgs::Marker& boundary_marker){
    
    std::vector<float> polar_boundary;
    std::vector<int> to_del_id;
    polar_boundary.clear();
    to_del_id.clear();
    for (size_t i = 0; i < 360; i ++){
        polar_boundary.push_back(boundary_max_distance);
    }


    int grid_cell_width = occ_grid.info.width;
    int grid_cell_height = occ_grid.info.height;
    double g_resolution = occ_grid.info.resolution;

    double map_center_x = (grid_cell_width / 2.0) * g_resolution;
    double map_center_y = (grid_cell_height / 2.0) * g_resolution;

    int index = 0;

    for (std::vector<int8_t>::const_iterator iter = occ_grid.data.cbegin(); iter != occ_grid.data.cend(); iter ++){
        if ((*iter) == 'd') {
            int grid_y = index/occ_grid.info.width;
            int grid_x = index%occ_grid.info.width;
            
            double point_x = grid_x * g_resolution - map_center_x;
            double point_y = grid_y * g_resolution - map_center_y;

            double distance = sqrt(point_x * point_x + point_y * point_y);
            double theta = atan2(point_y, point_x);

            if (distance >= boundary_max_distance){
                continue;
            }
            int theta_round = ceil(theta/PI * 180) + 180 -1;
            if (theta_round < 0 || theta >=360){
                continue;
            }
            if (polar_boundary[theta_round] > distance){
                polar_boundary[theta_round] = distance;
            }



        }
        index ++;
    }


    del_points(polar_boundary, to_del_id);



    vis_boundary(polar_boundary, to_del_id, boundary_marker);


}


void cloud_toolbox::ROSDetector::publish_ros(){

    sensor_msgs::PointCloud2 filter_cloud_msg;
    pcl::toROSMsg(*filter_cloud, filter_cloud_msg);
    filter_cloud_msg.header = common_header;
    filter_cloud_publisher.publish(filter_cloud_msg);


    sensor_msgs::PointCloud2 ground_cloud_msg;
    pcl::toROSMsg(*ground_cloud, ground_cloud_msg);
    ground_cloud_msg.header = common_header;
    ground_cloud_publisher.publish(ground_cloud_msg);

    // occ_grid_publisher.publish(occ_grid);

    // obj_array_publisher.publish(obj_array);

    sensor_msgs::PointCloud2 scene_cloud_msg;
    pcl::toROSMsg(*scene_cloud, scene_cloud_msg);
    scene_cloud_msg.header = common_header;
    scene_cloud_publisher.publish(scene_cloud_msg);


    // sensor_msgs::PointCloud2 vis_cluster_cloud_msg;
    // pcl::toROSMsg(*vis_cluster_cloud, vis_cluster_cloud_msg);
    // vis_cluster_cloud_msg.header = common_header;
    // vis_cluster_cloud_publisher.publish(vis_cluster_cloud_msg);

    // marker_array_publisher.publish(marker_array);
    boundary_marker_publisher.publish(boundary_marker);



}
void cloud_toolbox::ROSDetector::execute(const sensor_msgs::PointCloud2ConstPtr &input_cloud_ptr){
    common_header = input_cloud_ptr->header;

    input_cloud->clear();
    filter_cloud->clear();
    ground_cloud->clear();
    scene_cloud->clear();
    cluster_cloud.clear();
    bboxes.clear();
    obj_array.objects.clear();
    marker_array.markers.clear();
    occ_grid.data.clear();
    vis_cluster_cloud->clear();
    boundary_marker.points.clear();

    
    pcl::fromROSMsg(*input_cloud_ptr, *input_cloud);

    cloud_preprocess(input_cloud, filter_cloud);
    ground_filter(filter_cloud, ground_cloud, scene_cloud);
    cal_polar_boundary(scene_cloud, boundary_marker);
    // cal_occ_grid(scene_cloud, occ_grid);
    // occgrid2boundary(occ_grid, boundary_marker);
    // cloud_cluster(scene_cloud, cluster_cloud);
    // cal_occ_grid(scene_cloud, occ_grid);
    // cal_box_info(cluster_cloud, bboxes);
    // cal_obj_array(bboxes, obj_array);

    // cal_marker_array(bboxes, marker_array);
    // paint_cluster_cloud(cluster_cloud, vis_cluster_cloud);
    

    publish_ros();




    // std::cout<< "Num ground points: " << ground_cloud->points.size()<<std::endl;
    // std::cout<< "Num scene points: " << scene_cloud->points.size()<<std::endl;
    // std::cout<< "Num clusters:" << cluster_cloud.size() << std::endl;
    // std::cout<<"Num vis_cluster_cloud points: "<<vis_cluster_cloud->points.size()<<std::endl;

    // std::cout<< "Num objs: "<<obj_array.objects.size()<<std::endl;

    

}