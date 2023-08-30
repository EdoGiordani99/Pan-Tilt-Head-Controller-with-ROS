#include "ros/ros.h"
#include "std_msgs/String.h"

#include "servocontrol/state.h"
#include <thread>
#include <cstdlib>

using namespace std;


ros::Publisher cmd_pub;
ros::Subscriber state_sub;
ros::Publisher t_pub;

void cmd_send()
{
    //ros::Rate rate(1);  // 1 Hz
    int i = 0;
    int j = 0;

    servocontrol::state state;

    while (ros::ok()) {

        if (i == 0){
            state.last_cmd = "Left!" + to_string(j);
            state.step = 20;
            state.speed = 0.2;
            state.x = 22;
            state.y = 22;
            i = 1;
        }
        else{
            state.last_cmd = "Right!" + to_string(j);
            state.step = 60;
            state.speed = 0.6;
            state.x = 66;
            state.y = 66;
            i = 0;
        }

        cmd_pub.publish(state);
        ros::spinOnce();
        sleep(1);
        j++;
    }
}


void stateCallback(const servocontrol::state &state)
{
    cout << "Received servo command:  " << state.last_cmd << endl;   
}


int main(int argc, char** argv) {

    ros::init(argc, argv, "Commander");
    ros::NodeHandle nh;
    ros::NodeHandle nh3;

    cout << "Initialized PUB" << endl; 
    cmd_pub = nh.advertise<servocontrol::state>("servo_cmd", 1000);

    ros::Duration(3).sleep();

    cout << "Initialized SUB" << endl; 
    state_sub = nh3.subscribe("servo_state", 1000, stateCallback);

    std::thread thread_obj(cmd_send);

    ros::spin();

    return 0;
}


