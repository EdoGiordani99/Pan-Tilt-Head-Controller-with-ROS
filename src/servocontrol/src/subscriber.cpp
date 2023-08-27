#include "ros/ros.h"
#include "std_msgs/String.h"

#include "servocontrol/state.h"
#include <thread>
#include <cstdlib>

using namespace std;


ros::Publisher state_pub;
ros::Subscriber cmd_sub;

void cmdCallback(const servocontrol::state &state) {
    cout << "Received servo command:  " << state.last_cmd << endl;    
    state_pub.publish(state);

    ros::spinOnce();
}

void activateConnection()
{

    while(ros::ok() && cmd_sub.getNumPublishers() == 0)
    {
    servocontrol::state state;

    state.last_cmd = "[Controller]: Activating Connection";
    state.step = 0;
    state.speed = 0.0;
    state.x = 0;
    state.y = 0;
    state_pub.publish(state);

    ros::spinOnce();
    ros::Duration(0.5).sleep();
    cout << "Waiting for connection with COMMANDER" << endl;
    }
}


int main(int argc, char** argv) {

    setenv("ROS_MASTER_URI", "http://192.168.222.128:11311", 1);

    ros::init(argc, argv, "Controller");
    ros::NodeHandle nh;

    state_pub = nh.advertise<servocontrol::state>("servo_state", 1000);
    cmd_sub = nh.subscribe("servo_cmd", 1000, cmdCallback);

    activateConnection();

    ros::spin();

    return 0;
}
