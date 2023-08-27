#include "ros/ros.h"
#include "std_msgs/String.h"

#include "servocontrol/state.h"

using namespace std;


void callbackFN(const servocontrol::state &state){
    system("clear");

    ROS_INFO("New Received Message");
    cout << "Last Command: " << state.last_cmd << endl;
    cout << "Speed:        " << std::to_string(state.speed) << endl;
    cout << "Step:         " << std::to_string(state.step)<< endl;
    cout << "Pan:          " << std::to_string(state.x) << endl;
    cout << "Tilt          " << std::to_string(state.y) << endl;


}

int main(int argc, char **argv){

    // Initializing the Node
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle nh;

    // Initializing Subscriber
    // the nh.subscribe function takes the following args:
    ros::Subscriber sub = nh.subscribe("topic_name", 1000, callbackFN);

    ros::spin();

    return 0;

}