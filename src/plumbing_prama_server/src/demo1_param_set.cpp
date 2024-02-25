#include "ros/ros.h"

/*
        需要实现参数的增删改查
        需求：首先设置机器人的共享参数、类型、半径（0.15m）
            再修改半径(0.2m)
        实现：
            ros::NodeHandle nh
               * nh.setParam("键"，“值”)
            *ros::param::set("键"，“值”)
                // set()
        修改，只需要继续调用原来函数赋值就可以实现
*/

int main(int argc, char *argv[])
{
    // 初始化ros节点
    ros::init(argc,argv,"ShanBen");
    // 创建ros节点句柄
    ros::NodeHandle nh;
    // 参数增
    // method1: nh,
    nh.setParam("type","xiaohuangche");//键————值
    nh.setParam("radius",0.15);
    // method2: ros::param
    ros::param::set("type_param","xiaobaiche");
    ros::param::set("radius_param",0.15);
    // 删

    // 改
    nh.setParam("radius",0.2);//键一样的话，参数就被覆盖，从而完成参数修改
    ros::param::set("radius_param",0.2);
    // 查

    return 0;
}
