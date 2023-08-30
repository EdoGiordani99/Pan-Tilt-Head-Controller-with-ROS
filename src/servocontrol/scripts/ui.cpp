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
#define KEY_VEL 118


class Interface
{
public:
    // Constructor
    Interface()
    {   
        cout << "--------------\nStarting the Interface\n--------------" << endl; 
        cmd_pub = nh.advertise<std_msgs::String>("servo_cmd", 1000);

        // Waiting for Controller Initialization
        ros::Duration(3).sleep();

        state_sub = nh.subscribe("servo_state", 1000, &Interface::state_callback, this);

        std::thread thread_obj(&Interface::key_listener, this);

        screen_init();

        ros::spin();
    }


    void state_callback(const servocontrol::state &state){

        system("clear");
        cout << "--------------\nPress any arrow key or 'q' to quit.\n--------------" << endl;
        cout << "Last Command: " << state.last_cmd << endl;

        if (setting_vel){
            cout << "SETTING SPEED:        " << std::to_string(state.speed) << endl;
        } else {
            cout << "Speed:        " << std::to_string(state.speed) << endl;
        }

        cout << "Step:         " << std::to_string(state.step)<< endl;
        cout << "Pan:          " << std::to_string(state.x) << endl;
        cout << "Tilt          " << std::to_string(state.y) << endl;

    }


    void screen_init()
    {
        system("clear");
        cout << "--------------\nPress any arrow key or 'q' to quit.\n--------------" << endl;
        cout << "Last Command: " << endl; 
        cout << "Speed:        " << endl;
        cout << "Step:         " << endl; 
        cout << "Pan:          " << endl;
        cout << "Tilt          " << endl;
    }


    void send(const string &s)
    {
        // Printing the message
        // system("clear");
        // cout << s << endl;

        // Sending the message
        std_msgs::String msg;
        msg.data = s;
        cmd_pub.publish(msg);
    }


    void key_listener()
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
                cout << "Are you sure you want to quit? [Y/n]: " << endl;
                while (1){

                    char userInput;
                    std::cin >> userInput;

                    if (userInput == 'Y' || userInput == 'y'){
                        send("Quitting");
                        sleep(0.3);
                        exit(0);
                    } else if (userInput == 'N' || userInput == 'n'){
                        break;
                    }else{
                        cout << "Invalid Answer. Please select one [Y/n]: " << endl;
                    }
                }


            case KEY_VEL:

                setting_vel = true;
                send("VelDown");
                send("VelUp");
                int cc;

                while(1)
                {   
                    cc = getch();

                    if (cc == KEY_UP){
                        send("VelUp");
                    }else if (cc == KEY_DOWN){
                        send("VelDown");
                    }else if (cc == KEY_VEL){
                        setting_vel = false;
                        send("VelDown");
                        send("VelUp");
                        break;
                    }else{
                        continue;
                    }
                }
                break;

            default:
                send("Not an Arrow " + to_string(c));
                break;
            }
        }
    }


private:
    ros::NodeHandle nh;
    ros::Subscriber state_sub;
    ros::Publisher cmd_pub;
    bool setting_vel = false; 
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "ui");

    Interface interface; 

    return 0;
}
