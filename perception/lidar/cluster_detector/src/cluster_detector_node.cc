#include "ros_detector.hxx"

int main(int argc, char **argv){
    ros::init(argc, argv, "ros_detector");
    ros::NodeHandle nh("~");
    cloud_toolbox::ROSDetector core(nh);
    return 0;
}

// int main(){


//     std::string bin_file = "/home/wyl/workspace/W/cluster_detector/data/000000.bin"; 

//     cloud_toolbox::ClusterDetector cd;
//     pcl::PointCloud<pcl::PointXYZI>::Ptr points(new pcl::PointCloud<pcl::PointXYZI>);
//     pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZI>);
//     pcl::PointCloud<pcl::PointXYZI>::Ptr ground_cloud(new pcl::PointCloud<pcl::PointXYZI>);
//     pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud(new pcl::PointCloud<pcl::PointXYZI>);
//     std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> clustered_clouds;



//     cd.load_cloud_bin(bin_file, points);
//     cd.cloud_preprocess(points, filtered_cloud);
//     cd.ground_filter(filtered_cloud, ground_cloud, scene_cloud);
//     cd.cloud_cluster(scene_cloud, clustered_clouds);


//     std::cout<< "Num ground points: " << ground_cloud->points.size()<<std::endl;
//     std::cout<< "Num scene points: " << scene_cloud->points.size()<<std::endl;
//     std::cout<< "Num clusters:" << clustered_clouds.size() << std::endl;
//     return 0;

    
// }