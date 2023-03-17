#ifndef DATA_REPLAYER_HANDLE_HPP
#define DATA_REPLAYER_HANDLE_HPP


#include "data_replayer.hpp"

namespace ns_data_replayer {

class DataReplayerHandle {

 public:
  // Constructor
  DataReplayerHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  // void sendVisualization();

 private:
  ros::NodeHandle nodeHandle_;
  ros::Publisher virtualVehicleStatePublisher_;
  ros::Subscriber replayTriggerSubscriber_;

  void replayTriggerCallback(const common_msgs::Trigger &msg);

  std::string virtual_vehicle_state_topic_name_; 
  std::string replay_trigger_topic_name_;

  int node_rate_;

  DataReplayer data_replayer_;
  Para para_;

  bool replay_trigger_;

};
}

#endif //DATA_REPLAYER_HANDLE_HPP
