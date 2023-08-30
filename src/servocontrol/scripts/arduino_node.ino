
#include <ros.h>
#include <Servo.h>
#include <geometry_msgs/Pose.h>


Servo Xs;
Servo Ys;
int X_PIN = 13;
int Y_PIN = 12;

ros::NodeHandle nh;
bool set_;
geometry_msgs::Pose pose;

ros::Subscriber<geometry_msgs::Pose> sub("poses",updateServos);


void updateServos(const geometry_msgs::Pose& pose){
  
  Serial.print("Received NEW message: ");
  
  float new_x = pose.position.x;
  float new_y = pose.position.y;
  
  Xs.write(new_x);
  Ys.write(new_y);
  
  Serial.print("Servo X Angle: ");
  Serial.println(new_x);
  Serial.print("Servo Y Angle: ");
  Serial.println(new_y);
}


void setup()
{ 
  
  Xs.attach(X_PIN); 
  Ys.attach(Y_PIN); 
  
  Xs.write(90);
  Ys.write(90);
  
  nh.initNode();
  nh.subscribe(sub);
  
  while (!nh.connected()) {
    nh.spinOnce();
  }
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
