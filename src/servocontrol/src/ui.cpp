#include <iostream>
#include <stdio.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <conio.h>
#include <thread>

#include "servocontrol/state.h"

using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_QUIT 113


class Interface
{
public:
    // Constructor
    Interface()
    {   
        system("clear");

        // Interface Subscriber
        subscriber = nh.subscribe("servo_state", 1000, &Interface::state_callback, this);


        // Interface Publisher
        publisher = nh.advertise<std_msgs::String>("servo_cmd", 1000);

        std::thread thread_obj(&Interface::start, this);

        ros::spin();
        cout << "Interface Started" << endl;
    }

    void state_callback(const servocontrol::state &state){

        cout << "CIAOOO" << endl;

        //system("clear");

        //ROS_INFO("New Received Message");
        //cout << "Last Command: " << state.last_cmd << endl;
        //cout << "Speed:        " << std::to_string(state.speed) << endl;
        //cout << "Step:         " << std::to_string(state.step)<< endl;
        //cout << "Pan:          " << std::to_string(state.x) << endl;
        //cout << "Tilt          " << std::to_string(state.y) << endl;

    }

    void send(const string &s) // Specify the data type of the parameter
    {
        //system("clear");
        //cout << s << endl;

        std_msgs::String msg; // Create a String message
        msg.data = s; // Set the data of the message

        publisher.publish(msg); // Publish the message
    }

    
    void start()
    {
        int c;

        while (1)
        {
            c = getch();
            
            switch (c)
            {
            case KEY_UP:
                send("Up");
                break;

            case KEY_DOWN:
                send("Down");
                break;

            case KEY_LEFT:
                send("Left");
                break;

            case KEY_RIGHT:
                send("Right");
                break;

            case 27:
            case 91:
                continue;

            case KEY_QUIT:
                send("Quitting");
                break;

            default:
                send("Not an Arrow");
                break;
            }

            if (c == KEY_QUIT)
            {
                send("Quitting");
                break;
            }
        }
    }


private:
    ros::NodeHandle nh;
    ros::Subscriber subscriber;
    ros::Publisher publisher;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "ui");
    ros::NodeHandle nh;

    Interface interface; 
    interface.start();

    return 0;
}
