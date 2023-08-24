# ROS with C++
In this tutorial I'm going to explain how I build my very first ROS project in C++. 

## Creating a Workspace
Create a folder with the name of your workspace (WS). Inside that folder, create also a _src_ folder. To do that, open a new termina window and use the command: 
```
mkdir -p ws_name/src
```
Once this is done, go inside your WS folder and use the command
```
catkin_make
```
Of course, no code is build since we didn't create nothing yet, but 2 new folders should be created (_build_ and _devel_) inside the WS dir. __WARNING__: if you get an error like this:
```
Unable to find either executable 'empy' or Python module 'em'...  try
installing the package 'python3-empy'
```
Use this command instead (this is needed only the first time.
```
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
```

## Creating a Package
The smallest buildstone in a ROS project are packages! It contains configuration files, dataset, scripts and ROS NODES! To create a package use the command:
```
catkin_create_pkg package_name roscpp
```

## Publisher, Subscriber, Nodes & Topics
To be Published Soon!


## Creating a ROS Publisher
Let's create a publisher. Let's open the WS dir in a IDE. Go into the src/pgk_folder and create a new folder _src_. Inside this folder we are going to put all the scripts!

### Coding the Publisher
Let's create a _publisher.cpp_ file in src/pgk_folder/src. The code for the publisher is: 
```
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){

    // Initializing the Node
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;

    // Initializing the Publisher
    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("my_topic", 1000);

    // Setting the frequency rate of the publishing funciton
    // Publishing messages every 1 second
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
```

### Change the CMake file
Now, go in the _CMakeLists.txt_ file and let's do these changes:

1. Replace command starting in line 10 with the following lines
```
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)
include_directories(${catkin_INCLUDE_DIRS})
```
2. Uncomment line 68, 69, 70, 71: those lines should start with "generate_messages(DEPENDENCIES std_msgs)
3. Uncomment and change required names in line 133, 143, 146, 147, 148: you can choose the name of your node. Since we are creating a publisher, let's call it *publisher_node*

### Build & Run 
Open a new terminal window, access your WS folder. To build, run: 
```
catkin_make
```
If no mistake has been done, everything should work fine. Now run:
```
source devel/setup.bash
```
Open now a new terminal tab and run: 
```
roscore
```
Going back on the other terminal tab we can now run our publisher. To do that, we use this command syntax: 
```
rosrun pkg_name node_name
```
Which in our case node_name is *publisher_node*. 
By running the command, nothing compares. That's correct! We are not printing the messages. We are only sending them through the topics!

### Managing & Visualizing topics
Open a new terminal tab. Type this command to see all the topics of the project.
```
rostopic list
```
To see all the messages sent through a topic, use the command
```
rostopic echo topic_name
```
In our case, according to the written code, our topic is called "*my_topic*". Using that, we should see the Hello World messages!









