#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
/*
    需求：订阅乌龟位姿信息，并输出到控制台
        1.包含头文件
        2.初始化ros节点
        3.创建节点句柄
        4.创建订阅者对象
        5.处理订阅到的信息（用回调函数）
        6.spin（）。
*/
void doPose(const turtlesim::Pose::ConstPtr &pose){
    ROS_INFO("乌龟的位姿信息：坐标:(%.2f,%.2f),朝向（%.2f),线速度：%.2f,角速度：%.2f",
            pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);

}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>("/turtle1/pose",100,doPose);
    ros::spin();
    return 0;
}
