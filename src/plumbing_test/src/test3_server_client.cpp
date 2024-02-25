#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
    需求：是向服务端发送请求，生成一只新乌龟
        话题：/spawn
        消息：turtlesim/Spawn
    
        1.包含头文件
        2.初始化ros节点
        3.创建节点句柄
        4.创建客户端对象
        5.组织数据并发送
        6.处理响应


*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
        // 2.初始化ros节点
    ros::init(argc,argv,"server_call");
        // 3.创建节点句柄
    ros::NodeHandle nh;
        // 4.创建客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
        // 5.组织数据并发送
        // 组织请求数据
    turtlesim::Spawn spawn;
    spawn.request.x=1.0;
    spawn.request.y=2.0;
    spawn.request.theta=1.54;
    spawn.request.name="turtle2";
    // 发送请求
    // 判断服务状态
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag=client.call(spawn);//flag用来接收响应状态（T/F）,响应结果也会被设置进spawn对象
        // 6.处理响应
    if (flag)
    {
        ROS_INFO("响应成功!新乌龟叫：%s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("响应失败！");
    }
    return 0;
}
