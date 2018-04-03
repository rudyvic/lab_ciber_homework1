#include "ros/ros.h"
#include "lab_ciber_homework1/Student.h"
#include "std_msgs/Char.h"

char selected_field = 'a';

void studentsCallback(const lab_ciber_homework1::Student::ConstPtr& msg) {
    if(selected_field == 'a') {
        ROS_INFO("Name: %s\nAge: %d\nDegree course: %s\n\n",msg->name.c_str(),msg->age,msg->degree_course.c_str());
    } else if(selected_field == 'n') {
        ROS_INFO("Name: %s\n\n",msg->name.c_str());
    } else if(selected_field == 'e') {
        ROS_INFO("Age: %d\n\n",msg->age);
    } else if(selected_field == 'c') {
        ROS_INFO("Degree course: %s\n\n",msg->degree_course.c_str());
    }
}

void selectionCallback(const std_msgs::Char::ConstPtr& msg) {
    selected_field = msg->data;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "viewer");
    ros::NodeHandle n;

    ros::Subscriber students_sub = n.subscribe("students",1000,studentsCallback);
    ros::Subscriber selection_sub = n.subscribe("selection",1000,selectionCallback);

    ros::spin();
    
    return 0;
}