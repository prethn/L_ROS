#include "ros/ros.h"
/*
    需求：修改参数服务器参数，改变turtlesim背景
        1、初始化ros节点
        2.不一定需要创建节点句柄
        3.修改参数
*/

int main(int argc, char*argv[])
{
    //   1、初始化ros节点
    ros::init(argc,argv,"change_color");
    //     2.不一定需要创建节点句柄(如果使用ros::param,就不用创建节点句柄)
    // ros::NodeHandle nh("turtlesim");
    // nh.setParam("background_r",255);
    // nh.setParam("background_g",0);
    // nh.setParam("background_b",255);

    ros::NodeHandle nh;
    nh.setParam("/turtlesim/background_r",0);
    nh.setParam("/turtlesim/background_g",50);
    nh.setParam("/turtlesim/background_b",100);

    // ros::ServiceServer
    //     3.修改参数
    // method 1
    // ros::param::set("/turtlesim/background_r",255);  //   /turtlesim/background_r /命名空间/参数名
    // ros::param::set("/turtlesim/background_g",255);
    // ros::param::set("/turtlesim/background_b",255); 
    return 0;
}
