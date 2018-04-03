#include "ros/ros.h"
#include "lab_ciber_homework1/Student.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "generator");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<lab_ciber_homework1::Student>("students",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()) {
        lab_ciber_homework1::Student msg;
        msg.name = "Rudy";
        msg.age = 32;
        msg.degree_course = "Informatica";

        ROS_INFO("%s - %d - %s\n",msg.name.c_str(),msg.age,msg.degree_course.c_str());

        pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}