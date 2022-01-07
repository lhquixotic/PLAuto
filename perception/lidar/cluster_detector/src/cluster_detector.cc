#include "cluster_detector.hxx"



cloud_toolbox::ClusterDetector::ClusterDetector(){};
cloud_toolbox::ClusterDetector::~ClusterDetector(){};



void cloud_toolbox::ClusterDetector::load_cloud_bin(std::string bin_file, pcl::PointCloud<pcl::PointXYZI>::Ptr cloud){
    std::fstream input(bin_file.c_str(), std::ios::in | std::ios::binary);
    if (!input.good()){
        std::cerr << "Could Not Read File: " << bin_file << std::endl;
        exit(EXIT_FAILURE);
    }

    input.seekg(0, std::ios::beg);

    cloud->clear();


    int i;
    for (i = 0; input.good() && !input.eof(); i ++){
        pcl::PointXYZI point;
        input.read((char *) &point.x, 3*sizeof(float));
        input.read((char *) &point.intensity, sizeof(float));
        cloud->push_back(point);
    }
    input.close();
    std::cout << "Read .bin point cloud with " << i << "points." << std::endl;

}

void cloud_toolbox::ClusterDetector::cloud_preprocess(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud, 
                                                      pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_cloud){
    // remove NaN points
    std::vector<int> indices;
    pcl::removeNaNFromPointCloud(*cloud, *cloud, indices);


    //remove out-range points
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_inrange( new pcl::PointCloud<pcl::PointXYZI>);
    
    for (size_t i = 0; i < cloud->points.size(); i++){
        if (cloud->points[i].x > cloud_range_[0] && cloud->points[i].x < cloud_range_[3]
         && cloud->points[i].y > cloud_range_[1] && cloud->points[i].y < cloud_range_[4]
         && cloud->points[i].z > cloud_range_[2] && cloud->points[i].z < cloud_range_[5]){
             cloud_inrange->points.push_back(cloud->points[i]);
         } 
    }



    // voxel-based downsampling
    pcl::VoxelGrid<pcl::PointXYZI> voxel_filter;
    voxel_filter.setInputCloud(cloud_inrange);
    voxel_filter.setLeafSize(voxel_filter_leaf_size_[0], voxel_filter_leaf_size_[1], voxel_filter_leaf_size_[2]);
    voxel_filter.filter(*filtered_cloud);
    std::cout<< "Cloud after filtering has " << filtered_cloud->points.size() << " points." <<std::endl;

    

}



void cloud_toolbox::ClusterDetector::ground_filter_2(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud, 
                                                     pcl::PointCloud<pcl::PointXYZI>::Ptr &ground_cloud, 
                                                     pcl::PointCloud<pcl::PointXYZI>::Ptr &scene_cloud){

}

void cloud_toolbox::ClusterDetector::ground_filter(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud, 
                                                   pcl::PointCloud<pcl::PointXYZI>::Ptr ground_cloud, 
                                                   pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud){
    
    // cloud_toolbox::PointXYZIL point;
    // for (size_t i = 0; i < cloud->points.size(); i ++){
    //     point.x = cloud->points[i].x;
    //     point.y = cloud->points[i].y;
    //     point.z = cloud->points[i].z;
    //     point.intensity = cloud->points[i].intensity;
    //     point.label = 0u;

    // }

    if (cloud->points.size() < 100){
        std::cout << "points before ground_filter is less than 100, totoal "
                  <<cloud->points.size()<< " points."<< std::endl;
    }

    //find k lowest points   O(N*k)
    double z_min[num_ground_seeds_];
    int z_min_id = 0;
    
    for (size_t i = 0; i < cloud->points.size(); i ++){
        if (cloud->points[i].z > -1.5*lidar_height_){
            if (z_min_id < num_ground_seeds_){
                z_min[z_min_id] = cloud->points[i].z;
                z_min_id ++;
            }
            else{
                for (int j = 0; j < num_ground_seeds_; j ++){
                    if (cloud->points[i].z < z_min[j]){
                        z_min[j] = cloud->points[i].z;
                        break;
                    }
                }
            }
        }
    }
    if (z_min_id < num_ground_seeds_){
        std::cout << "Valid lowest points less than " << num_ground_seeds_ 
                  << ", total number is " << z_min_id << "."<<std::endl;
    }


    // extract initial seeds
    double sum = 0;
    for (int i = 0; i < num_ground_seeds_; i++){
        sum += z_min[i];
    }
    double avg_z_min = sum / num_ground_seeds_;

    ground_cloud->points.clear();
    for (size_t i = 0; i < cloud->points.size(); i ++){
        if (cloud->points[i].z < avg_z_min + th_ground_seeds_){
            ground_cloud->points.push_back(cloud->points[i]);
        }
    }
    
    Eigen::Matrix3f cloud_cov;
    Eigen::Vector4f cloud_mean;
    Eigen::MatrixXf normal_;
    Eigen::Vector3f mean_;
    
    float th_distance_;
    float distance;

    for (int i = 0; i< iter_ground_plane_; i ++){

        pcl::computeMeanAndCovarianceMatrix(*ground_cloud, cloud_cov, cloud_mean);
        Eigen::JacobiSVD<Eigen::MatrixXf> svd(cloud_cov, Eigen::DecompositionOptions::ComputeFullU);
        normal_ = (svd.matrixU().col(2));
        mean_ = cloud_mean.head<3>();
        distance = -(normal_.transpose() * mean_)(0,0);
        th_distance_ = th_ground_plane_ - distance;

        ground_cloud->clear();
        scene_cloud->clear();

        Eigen::MatrixXf points(cloud->points.size(), 3);
        for (size_t j = 0; j < cloud->points.size(); j ++){
            points.row(j) << cloud->points[j].x, cloud->points[j].y, cloud->points[j].z;
        }

        Eigen::VectorXf points_ground_dis = points*normal_;
        for (size_t k = 0; k < points_ground_dis.rows(); k ++){
            if (points_ground_dis[k] < th_distance_){
                ground_cloud->points.push_back(cloud->points[k]);
            }
            else{
                scene_cloud->points.push_back(cloud->points[k]);
            }
        }
    }
}
void cloud_toolbox::ClusterDetector::cloud_cluster(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, 
                       std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds){
    pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_scene_cloud (new pcl::PointCloud<pcl::PointXYZI>); // remove points those are too high
    for (size_t i = 0; i < scene_cloud->points.size(); i ++){
        if (scene_cloud->points[i].z < clip_height_ + lidar_height_){
            filtered_scene_cloud->points.push_back(scene_cloud->points[i]);
        }
    }
    std::vector<pcl::PointIndices> cluster_indices;

    pcl::EuclideanClusterExtraction<pcl::PointXYZI>  euc_cluster;
    euc_cluster.setInputCloud(filtered_scene_cloud);
    euc_cluster.setClusterTolerance(cluster_ths_[0]);
    euc_cluster.setMinClusterSize(cluster_min_size_);
    euc_cluster.setMaxClusterSize(cluster_max_size_);
    euc_cluster.extract(cluster_indices);

    if (cluster_indices.empty()){
        return;
    }

    for(std::vector<pcl::PointIndices>::const_iterator cloud_it = cluster_indices.begin(); cloud_it != cluster_indices.end(); ++cloud_it){
        clustered_clouds.emplace_back(new pcl::PointCloud<pcl::PointXYZI>);
        // pcl::PointXYZI point;

        for(std::vector<int>::const_iterator point_it = cloud_it->indices.begin(); point_it != cloud_it->indices.end(); ++point_it){
            clustered_clouds.back()->points.push_back(filtered_scene_cloud->points[*point_it]);
        }
    }
}

void cloud_toolbox::ClusterDetector::cloud_cluster_2(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, 
                                                   std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds){
    std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> clouds_array(5);
    for (int i = 0; i < clouds_array.size(); i ++){
        pcl::PointCloud<pcl::PointXYZI>::Ptr tmp_cloud(new pcl::PointCloud<pcl::PointXYZI>);
        clouds_array[i] = tmp_cloud;
    }
    double distance;
    
    for (size_t i = 0; i < scene_cloud->points.size(); i ++){

        if (scene_cloud->points[i].z > clip_height_ + lidar_height_){
            continue;
        }

        distance = sqrt(scene_cloud->points[i].x *scene_cloud->points[i].x + scene_cloud->points[i].y *scene_cloud->points[i].y);

        if (distance <scene_split_[0]){
            clouds_array[0]->points.push_back(scene_cloud->points[i]);
        }
        else if (distance < scene_split_[1]){
            clouds_array[1]->points.push_back(scene_cloud->points[i]);
        }
        else if (distance < scene_split_[2]){
            clouds_array[2]->points.push_back(scene_cloud->points[i]);
        }
        else if (distance < scene_split_[3]){
            clouds_array[3]->points.push_back(scene_cloud->points[i]);
        }
        else{
            clouds_array[4]->points.push_back(scene_cloud->points[i]);
        }
    }

    for (int i = 0; i <clouds_array.size(); i ++){
        splited_cloud_cluster(clouds_array[i], cluster_ths_[i], cluster_leaf_sizes_[i], clustered_clouds);
    }
}

void cloud_toolbox::ClusterDetector::splited_cloud_cluster(pcl::PointCloud<pcl::PointXYZI>::Ptr splited_cloud, 
                                                           double cluster_th, double leaf_size, 
                                                           std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> & clustered_clouds){

    //voxel grid downsampling
    pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_splited_cloud( new pcl::PointCloud<pcl::PointXYZI> );

    pcl::VoxelGrid<pcl::PointXYZI> voxel_filter;

    voxel_filter.setInputCloud(splited_cloud);
    voxel_filter.setLeafSize(leaf_size, leaf_size, leaf_size);
    voxel_filter.filter(*filtered_splited_cloud);


    std::vector<pcl::PointIndices> cluster_indices;

    pcl::EuclideanClusterExtraction<pcl::PointXYZI>  euc_cluster;
    euc_cluster.setInputCloud(filtered_splited_cloud);
    euc_cluster.setClusterTolerance(cluster_th);
    euc_cluster.setMinClusterSize(cluster_min_size_);
    euc_cluster.setMaxClusterSize(cluster_max_size_);
    euc_cluster.extract(cluster_indices);

    if (cluster_indices.empty()){
        return;
    }

    for(std::vector<pcl::PointIndices>::const_iterator cloud_it = cluster_indices.begin(); cloud_it != cluster_indices.end(); ++cloud_it){
        clustered_clouds.emplace_back(new pcl::PointCloud<pcl::PointXYZI>);
        // pcl::PointXYZI point;

        for(std::vector<int>::const_iterator point_it = cloud_it->indices.begin(); point_it != cloud_it->indices.end(); ++point_it){
            // point.x = filtered_splited_cloud->points[*point_it].x;
            // point.y = filtered_splited_cloud->points[*point_it].y;
            // point.z = filtered_splited_cloud->points[*point_it].z;
            // point.intensity = filtered_splited_cloud->points[*point_it].intensity;
            clustered_clouds.back()->points.push_back(filtered_splited_cloud->points[*point_it]);
        }
    }
}


void cloud_toolbox::ClusterDetector::cal_box_info(std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds, std::vector<box_info>& bboxes){
    for (size_t i = 0; i < clustered_clouds.size(); i ++){
        pcl::PointCloud<pcl::PointXYZI>::Ptr cur_cloud = clustered_clouds[i];
        box_info bbox;

        float z_max = -1000;
        float z_min = 1000;
        for (size_t j = 0; j < cur_cloud->points.size(); j ++){
            if (cur_cloud->points[j].z > z_max){
                z_max = cur_cloud->points[j].z;
            }
            if (cur_cloud->points[j].z < z_min){
                z_min = cur_cloud->points[j].z;
            }
        }

        bbox.h = z_max-z_min;
        bbox.z = (z_max+z_min)/2;


        float v_box = 1000000;
        bbox.r_z = 0; 
        for(int theta = 0; theta < 180; theta ++){
            float x_max = -1000;
            float y_max = -1000;
            float x_min = 1000;
            float y_min = 1000;

            float theta_r = theta*M_PI/180;
            for (size_t j = 0; j < cur_cloud->points.size(); j ++){
                float tmp_x = cur_cloud->points[j].x * cos(theta_r) - cur_cloud->points[j].y * sin(theta_r);
                float tmp_y = cur_cloud->points[j].x * sin(theta_r) + cur_cloud->points[j].y * cos(theta_r);

                if (tmp_x > x_max){
                    x_max = tmp_x;
                }
                if (tmp_y > y_max){
                    y_max = tmp_y;
                }
                if (tmp_x < x_min){
                    x_min = tmp_x;
                }
                if (tmp_y < y_min){
                    y_min = tmp_y;
                }
            }

            float tmp_v_box = (x_max-x_min) * (y_max - y_min);
            if (tmp_v_box < v_box){
                v_box = tmp_v_box;
                bbox.r_z = theta_r;
                bbox.l = x_max - x_min;
                bbox.w = y_max - y_min;
                
                float x_cen_r = (x_max + x_min)/2;
                float y_cen_r = (y_max + y_min)/2;
                bbox.x =  x_cen_r * cos(theta_r) + y_cen_r * sin(theta_r);
                bbox.y = -x_cen_r * sin(theta_r) + y_cen_r * cos(theta_r);
            }
        }

        bboxes.push_back(bbox);
    }
}
