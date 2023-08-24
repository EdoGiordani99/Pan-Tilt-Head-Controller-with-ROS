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
The smallest milestone in a ROS project are packages!


