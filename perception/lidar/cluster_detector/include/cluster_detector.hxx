// #pragma once
#ifndef CLUSTER_DETECTOR_HXX
#define CLUSTER_DETECTOR_HXX

#include <pcl/io/io.h>
#include <pcl/point_types.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/centroid.h>
#include <pcl/segmentation/extract_clusters.h>

#include <Eigen/Dense>

#include <math.h>
#include <fstream>
#include <string>

namespace cloud_toolbox{

struct PointXYZIL
{
    PCL_ADD_POINT4D;
    float intensity;
    uint16_t label;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
}EIGEN_ALIGN16;

}

POINT_CLOUD_REGISTER_POINT_STRUCT(cloud_toolbox::PointXYZIL,
                                  (float, x, x)(float, y, y)(float, z, z)(float, intensity, intensity)(uint16_t, label, label))

namespace cloud_toolbox{

struct box_info {
    float x;  //center
    float y;
    float z;
    float h; //size
    float w;
    float l;
    float r_z; //rotation
};

class ClusterDetector{
public:
    ClusterDetector();
    ~ClusterDetector();

    void load_cloud_bin(std::string bin_file, pcl::PointCloud<pcl::PointXYZI>::Ptr cloud);  // input
    void cloud_preprocess(pcl::PointCloud<pcl::PointXYZI>::Ptr points, pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_points);
    void ground_filter(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud, 
                       pcl::PointCloud<pcl::PointXYZI>::Ptr ground_cloud, 
                       pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud);
    void cloud_cluster(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, 
                       std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds);
    void ground_filter_2(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud,      
                         pcl::PointCloud<pcl::PointXYZI>::Ptr &ground_cloud, 
                         pcl::PointCloud<pcl::PointXYZI>::Ptr &scene_cloud);   // TODO: split the whole scene into nine parts and calculate ground points for each part
    void cloud_cluster_2(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, 
                       std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> & clustered_clouds); // split the whole scene into five parts according to the distance
    void splited_cloud_cluster(pcl::PointCloud<pcl::PointXYZI>::Ptr splited_cloud, 
                               double cluster_th, double leaf_size, 
                               std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds);
    
    void cal_box_info(std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr>& clustered_clouds, std::vector<box_info>& bboxes);
    // void bbox_maker();

    //cloud_preprocess
    float cloud_range_[6] = {-100.0, -80.0, -5.0, 100.0, 80.0, 5.0}; //x_min, y_min, z_min, x_max, y_max, z_max

    float voxel_filter_leaf_size_[3] = {0.05, 0.05, 0.05}; 
    
    //ground filter
    int num_ground_seeds_ = 15;
    double lidar_height_ = 1.9;
    double th_ground_seeds_ = 1.0;
    int iter_ground_plane_ = 3;
    float th_ground_plane_ = 0.10;
    //cloud cluster
    double clip_height_ = 3.0;
    double scene_split_[4] = {20.0, 35.0, 50.0, 70.0};
    double cluster_ths_[5] = {0.6, 1.2, 1.5, 2.0, 2.5};
    double cluster_leaf_sizes_[5] = {0.15, 0.12, 0.10, 0.08, 0.06};

    int cluster_min_size_ = 10;
    int cluster_max_size_ = 5000;




};
}

#endif