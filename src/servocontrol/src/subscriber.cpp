#include "ros/ros.h"
#include "std_msgs/String.h"


void callbackFN(const std_msgs::String::ConstPtr& msg){

    ROS_INFO("Received Message: %s", msg->data.c_str());
}


int main(int argc, char **argv){

    // Initializing the Node
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle nh;

    // Initializing Subscriber
    // the nh.subscribe function takes the following args:
    ros::Subscriber sub = nh.subscribe("servo_cmd", 1000, callbackFN);

    ros::spin();

    return 0;

}