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
Since nothing created yet, the cmake command will give a final error. Besides that, it should create 2 new folders (_build_ and _devel_) inside the WS dir. 



### Solved: Unable to find empy executable.
If catkin_make command gives you errors like this:

```
Unable to find either executable 'empy' or Python module 'em'...  try
installing the package 'python3-empy'
```
Just address the correct python3 path!
```
catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
```
