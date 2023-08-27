#include <iostream>
#include <stdio.h>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <conio.h>

#include "servocontrol/state.h"

using namespace std;

#define MAX_PAN 180
#define MAX_TILT 180
#define MIN_PAN 0
#define MIN_TILT 0

class Controller
{
public:
    Controller() : x(90), y(90), speed(0), step(0), last_cmd("None")
    {   
        // Controller's Subscriber
        subscriber = nh.subscribe("servo_cmd", 1000, &Controller::callbackFN, this);
        
        // Controller's Publisher
        publisher = nh.advertise<servocontrol::state>("servo_state", 1000);

        set_speed(0.5);

        cout << "Controller Initialized" << endl;
        ros::spin();
    }


    void set_speed(const float spd)
    {
        speed = spd;
        step = static_cast<int>(5 * speed);

        cout << "Step:  " << step << endl;
    }


    void send_servo_state(){

        servocontrol::state state;
        ros::Rate rate(1);

        state.last_cmd = last_cmd;
        state.step = step;
        state.speed = speed;
        state.x = x;
        state.y = y;

        cout << "Publishing"<<endl;
        cout << "Last Command: " << state.last_cmd << endl;
        cout << "Speed:        " << std::to_string(state.speed) << endl;
        cout << "Step:         " << std::to_string(state.step)<< endl;
        cout << "Pan:          " << std::to_string(state.x) << endl;
        cout << "Tilt          " << std::to_string(state.y) << endl;
        cout<<"---------------------------"<<endl;

        publisher.publish(state);
        ros::spinOnce();
        rate.sleep();
        cout << "End PUB"<<endl;

    }


    void callbackFN(const std_msgs::String::ConstPtr& msg)
    {
        cout << "Command Callback"<<endl;

        if (msg->data == "Down") {
            y -= step;
        } else if (msg->data == "Up") {
            y += step;
        } else if (msg->data == "Left") {
            x -= step;
        } else if (msg->data == "Right") {
            x += step;
        }

        last_cmd = msg->data;

        // Out of Range Values
        if (x < MIN_PAN || x > MAX_PAN) {
            x = std::max(MIN_PAN, std::min(MAX_PAN, x)); // x in [0, 180] range.
        }

        if (y < MIN_TILT || y > MAX_TILT) {
            y = std::max(MIN_TILT, std::min(MAX_TILT, y)); // y in [0, 180] range.
        }

        send_servo_state();
    }


private:
    ros::NodeHandle nh;
    ros::Subscriber subscriber;
    ros::Publisher publisher;
    int x;
    int y;
    string last_cmd;
    int step;
    float speed;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "controller");
    ros::NodeHandle nh;

    Controller controller;

    return 0;
}
