#include "cluster_detector.hxx"
#include <ros/ros.h>
#include <std_msgs/Header.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl_ros/point_cloud.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include "autoware_msgs/DetectedObjectArray.h"
#include "common_msgs/PolarBoundary.h"

#include <nav_msgs/OccupancyGrid.h>
#include "opencv2/core.hpp"


namespace cloud_toolbox{

class ROSDetector: public ClusterDetector{
public:
    ROSDetector(ros::NodeHandle &nh);
    ~ROSDetector();

    void visualizer(pcl::PointCloud<pcl::PointXYZI>::Ptr filter_cloud,
                    pcl::PointCloud<pcl::PointXYZI>::Ptr ground_cloud, 
                    pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, 
                    std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> cluster_cloud);
    void execute(const sensor_msgs::PointCloud2ConstPtr &input_cloud_ptr);
    void paint_cluster_cloud(std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> cluster_cloud, pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_cluster_cloud);
    void cal_marker_array(std::vector<box_info>& bboxes, visualization_msgs::MarkerArray& marker_array);
    void cal_obj_array(std::vector<box_info>& bboxes, autoware_msgs::DetectedObjectArray& obj_array);
    void cal_occ_grid(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, nav_msgs::OccupancyGrid& occ_grid);
    void del_points(common_msgs::PolarBoundary& PB, std::vector<int>& to_del_id);
    void cal_polar_boundary(pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud, visualization_msgs::Marker& boundary_marker);
    void vis_boundary(common_msgs::PolarBoundary& PB, std::vector<int>& to_del_id, visualization_msgs::Marker& boundary_marker);
    void occgrid2boundary(nav_msgs::OccupancyGrid& occ_grid, visualization_msgs::Marker& boundary_marker);
    void publish_ros();



    ros::Subscriber cloud_subscriber;
    ros::Publisher filter_cloud_publisher;
    ros::Publisher ground_cloud_publisher;
    ros::Publisher scene_cloud_publisher;
    ros::Publisher occ_grid_publisher;
    ros::Publisher obj_array_publisher;
    ros::Publisher polar_boundary_publisher; // zbw: add polar_boundary_publisher

    ros::Publisher vis_cluster_cloud_publisher;
    ros::Publisher marker_array_publisher;
    ros::Publisher boundary_marker_publisher;

    std_msgs::Header common_header;


    pcl::PointCloud<pcl::PointXYZI>::Ptr input_cloud;
    pcl::PointCloud<pcl::PointXYZI>::Ptr filter_cloud;
    pcl::PointCloud<pcl::PointXYZI>::Ptr ground_cloud;
    pcl::PointCloud<pcl::PointXYZI>::Ptr scene_cloud;
    std::vector<pcl::PointCloud<pcl::PointXYZI>::Ptr> cluster_cloud;
    std::vector<box_info> bboxes;
    common_msgs::PolarBoundary polar_boundary; // zbw: define polar_boundary
    autoware_msgs::DetectedObjectArray obj_array;
    nav_msgs::OccupancyGrid occ_grid;

    // for visualization and debug
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr vis_cluster_cloud;
    visualization_msgs::MarkerArray marker_array;
    visualization_msgs::Marker boundary_marker;


    double boundary_max_distance;   // for polar boundary
    

};

}