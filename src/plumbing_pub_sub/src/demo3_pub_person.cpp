#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
/*
    发布方：发布人的数据
        1.包含头文件
        #include "plumbing_pub_sub/Person.h"
        2.初始化ros节点
        3.创建节点句柄
        4.创建发布者对象
        5.编写发布者逻辑，发布数据
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
        //  2.初始化ros节点
    ros::init(argc,argv,"DaXia");   
        // 3.创建节点句柄
    ROS_INFO("发布方实现");
    ros::NodeHandle nh;
        // 4.创建发布者对象
    ros::Publisher pub =nh.advertise<plumbing_pub_sub::Person>("liaotian",10);
        // 5.编写发布者逻辑，发布数据
    // 创建发布数据
    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age  =10;
    person.height =100.0;
    // 设置发布频率
    ros::Rate rate(1);
    // 循环发布数据
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        // 修改被发布的数据
        person.age +=1;
        pub.publish(person);
        ROS_INFO("发布的消息：%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
