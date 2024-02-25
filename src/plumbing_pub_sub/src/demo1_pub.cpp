#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"

/*          
            发布方实现：
                1.包含头文件；
                ros中文文本类型 --->std_msgs/String.h
                2.初始化ROS节点
                3.创建节点句柄
                4.创建发布者对象
                5.编写发布逻辑并发布数据
*/

/*
    通过代码实现命名空间重置
    std::map<std::string,std::string>map;
    map["__ns"] = "DaWang";
    ros::init(map,"erGouZi");
    将以上代码替换
    ros::init(argc,argv,"erGouZi");
    即可实现
*/
std::map<std::string,std::string>map;
int main(int argc, char *argv[])
{
    map["__ns"] = "DaWang";
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点
    // ros::init(argc,argv,"erGouZi");
    ros::init(map,"erGouZi");
    // ros::init()
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    // 5.编写发布逻辑并发布数据
    // 要求以10Hz的频率发布数据，并且文本后加编号
    // 创建被发布的消息
    std_msgs::String msg;
    // 发布频率
    ros::Rate rate(1);
    // 编写循环，循环中发布数据
    int count =0;
    ros::Duration(3).sleep();
    while (ros::ok())
    {
        count++;
        std::stringstream ss;
        ss<<"hello---> "<<count;
        // msg.data = "hello,你好";
        msg.data = ss.str();
        pub.publish(msg);
        // 添加日志
        ROS_INFO("发布的数据:%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//官方建议添加，处理回调函数
    } 
    return 0;
}
