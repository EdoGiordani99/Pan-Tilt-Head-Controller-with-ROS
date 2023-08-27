#include "ros/ros.h"
#include "std_msgs/String.h"

#include "servocontrol/state.h"


int main(int argc, char **argv){

    // Initializing the Node
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;

    // Initializing the Publisher
    ros::Publisher topic_pub = nh.advertise<servocontrol::state>("topic_name", 1000);

    // Setting the frequency rate of the publishing funciton
    // (publishing messages every 1 second)
    ros::Rate loop_rate(1);

    int i = 0;

    while(ros::ok()) {

        
        servocontrol::state state;
        
        if (i == 0){
            state.last_cmd = "Left!";
            state.step = 20;
            state.speed = 0.2;
            state.x = 22;
            state.y = 22;
            i = 1;
        }
        else{
            state.last_cmd = "Right!";
            state.step = 60;
            state.speed = 0.6;
            state.x = 66;
            state.y = 66;
            i = 0;
        }

        topic_pub.publish(state);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;

}

