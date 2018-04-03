#include "ros/ros.h"
#include "lab_ciber_homework1/Student.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    char *names[5] = {"Rudy","Paolo","Antonello","Daniele","Giovanni"};
    char *degree_courses[4] = {"Informatica","Biotecnologia","Scienze politiche","Economia"};
    srand(time(NULL));

    ros::init(argc, argv, "generator");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<lab_ciber_homework1::Student>("students",1000);

    ros::Rate loop_rate(1);

    while(ros::ok()) {
        lab_ciber_homework1::Student msg;
        msg.name = names[rand()%5];
        msg.age = rand() % 40 + 18;
        msg.degree_course = degree_courses[rand()%4];

        ROS_INFO("%s - %d - %s\n",msg.name.c_str(),msg.age,msg.degree_course.c_str());

        pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}