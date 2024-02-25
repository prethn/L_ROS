#include "ros/ros.h"
/*
    参数删除：
        ros::nodeHandle       (nh.xx)
            deleteParam("键")
            带bool类型返回值
        ros::param         (::xx)
            del(“键”)

*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"daHeiZi");
    ros::NodeHandle nh;
    // ros::nodeHandle 
    // bool flag = nh.deleteParam("radius");
    // if (flag)
    // {
    //     ROS_INFO("删除成功！");
    // }
    // else
    // {
    //     ROS_INFO("删除失败！");
    // }
    // ros::param
    bool flag1 = ros::param::del("radius");
    if (flag1)
    {
        ROS_INFO("1删除成功！");
    }
    else
    {
        ROS_INFO("1删除失败！");
    }
    
    
    
    //  ros::param
    return 0;
}
