#include <iostream>
#include <stdio.h>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <conio.h>

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
    Interface(ros::Publisher publisher)
    {
        cout << "Interface Started" << endl;
        pub = publisher;
    }

    void send(const string &s) // Specify the data type of the parameter
    {
        system("clear");
        cout << endl << s << endl;

        std_msgs::String msg; // Create a String message
        msg.data = s; // Set the data of the message

        pub.publish(msg); // Publish the message
    }

    
    void start()
    {
        system("clear");

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
    ros::Publisher pub;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "ui");
    ros::NodeHandle nh;

    ros::Publisher publisher = nh.advertise<std_msgs::String>("servo_cmd", 1000);

    Interface interface(publisher);

    interface.start();

    return 0;
}
