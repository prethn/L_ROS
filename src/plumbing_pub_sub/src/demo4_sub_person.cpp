#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
   订阅方：订阅数据
        1.包含头文件
        #include "plumbing_pub_sub/Person.h"
        2.初始化ros节点
        3.创建节点句柄
        4.创建订阅者对象
        5.编写订阅者逻辑，接收数据
        6.调用spin()函数
*/
void doPerson(const plumbing_pub_sub::Person::ConstPtr& person)
{
    ROS_INFO("订阅者的信息：%s,%d,%.3f",person->name.c_str(),person->age,person->height);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");
    ros::init(argc,argv,"XianRen");
    ros::NodeHandle nh;
    ros::Subscriber sub =nh.subscribe("liaotian",10,doPerson);
    ros::spin();
    return 0;
}
