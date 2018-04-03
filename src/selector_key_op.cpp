#include "ros/ros.h"
#include "lab_ciber_homework1/Student.h"
#include "std_msgs/Char.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "selector_key_op");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::Char>("selection",1000);

    while(ros::ok()) {
        char car = getchar();
        fflush(stdin);
        if(car == 'a' || car == 'n' || car == 'e' || car == 'c') {
            std_msgs::Char msg;
            msg.data = car;

            pub.publish(msg);

            ros::spinOnce();
        }
    }

    return 0;
}
