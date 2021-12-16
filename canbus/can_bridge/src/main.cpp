#include <ros/ros.h>
#include <ros/callback_queue.h>
#include "can_bridge_handle.hpp"
#include <boost/thread.hpp>

typedef ns_can_bridge::CanBridgeHandle CanBridgeHandle;

ros::CallbackQueue g_queue;
ns_likecan::LikeCan likecan;

void customQueue(const can_msgs::Frames::ConstPtr &msg){
  ROS_INFO_STREAM("convert topic to can msg");
  
  std::vector<can_msgs::Frame> send_frames = msg->frames;
  likecan.sendProc(send_frames);
}

void canSendThread(){
   ROS_INFO_STREAM("can send thread id = " << boost::this_thread::get_id());
   ros::NodeHandle n;
   while (n.ok()){
     g_queue.callAvailable(ros::WallDuration(0.02));
   }
 }

int main(int argc, char **argv) {
  ros::init(argc, argv, "can_bridge");

  ros::NodeHandle nodeHandle("~");
  CanBridgeHandle myCanBridgeHandle(nodeHandle);
  ros::Rate loop_rate(1);

  // intialize can device
  likecan.setCanParameters(myCanBridgeHandle.can_para_);
  likecan.openCanDevice();
  likecan.readCanDeviceInfo();
  likecan.openCanChannel(0);

  // create subscriber and  can send thread
  ros::SubscribeOptions ops = 
      ros::SubscribeOptions::create<can_msgs::Frames>(myCanBridgeHandle.can_send_topic_name_,1000, customQueue,
                                                                                                                ros::VoidPtr(), &g_queue);
  ros::Subscriber sub = nodeHandle.subscribe(ops);
  boost::thread can_send_thread(canSendThread);

  // create publisher
  ros::Publisher canMsgsPublisher = 
      nodeHandle.advertise<can_msgs::Frames> (myCanBridgeHandle.can_recv_topic_name_,1);
  
  can_msgs::Frames receive_frames;

  while (ros::ok()) {

    // main thread for can receive
    while (1){
      likecan.recvProc();
      if(likecan.rcv_frames.size() > 0){
        ROS_INFO_STREAM("Recv queue size: " << likecan.rcv_frames.size());
        receive_frames.frames = likecan.rcv_frames;
        canMsgsPublisher.publish(receive_frames);
        receive_frames.frames.clear();
      }
    }
    
    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

