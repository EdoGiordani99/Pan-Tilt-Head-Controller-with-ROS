#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv){

    // Initializing the Node
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;

    // Initializing the Publisher
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("topic_name", 1000);

    // Setting the frequency rate of the publishing funciton
    // (publishing messages every 1 second)
    ros::Rate loop_rate(1);

    while(ros::ok()) {

        std_msgs::String msg; 
        msg.data = "Hello World!";

        topic_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;

}

