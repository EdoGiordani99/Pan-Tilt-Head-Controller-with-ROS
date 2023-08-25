#include <iostream>
#include <stdio.h>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <conio.h>

using namespace std;

class Controller
{
public:
    Controller() : x(90), y(90), step(0), speed(0)
    {
        ros::Subscriber subscriber = nh.subscribe("servo_cmd", 1000, &Controller::callbackFN, this);
        set_speed(5);
        cout << "Controller Initialized" << endl;

        ros::spin();
    }

    void set_speed(const int spd)
    {
        speed = spd;
        step = 5 * speed;
    }

    void send(const std_msgs::String::ConstPtr& msg)
    {
        ROS_INFO("Received Message: %s", msg->data.c_str());
        cout << "X: " + std::to_string(x) << endl;
        cout << "Y: " + std::to_string(y) << endl;
        cout << "\n" << endl;
    }

    void callbackFN(const std_msgs::String::ConstPtr& msg)
    {
        if (msg->data == "Down") {
            y -= step;
        } else if (msg->data == "Up") {
            y += step;
        } else if (msg->data == "Left") {
            x -= step;
        } else if (msg->data == "Right") {
            x += step;
        }

        send(msg);
    }

private:
    ros::NodeHandle nh;
    ros::Subscriber subscriber;
    int x;
    int y;
    float step;
    float speed;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "controller");
    ros::NodeHandle nh;

    Controller controller;

    return 0;
}
