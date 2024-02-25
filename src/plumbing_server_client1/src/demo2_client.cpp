#include "ros/ros.h"
#include "plumbing_server_client1/Addints.h"
#include <iostream>
using namespace::std;

/*
    客户端实现：提交两个整数，并处理响应结果。
        1.包含头文件
        2.初始化ros
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应
        // 6.spin()


        问题：
            如果先启动客户端，那么会请求异常
        需求：
            如果先启动客户端，不要直接抛出异常，而是挂起，等服务器启动后再正常请求。
            ros节点较多，难以保证先后顺序
        解决：
            在ros中内置了相关函数，这些函数可以让客户端先启动后挂起，等待服务器启动
            client.waitForExistence();
            ros::service::waitForService("服务话题");

        实现参数的动态提交
        1.格式 ：rosrun xxx xxxxx 12 23
        2.节点执行时，需要获取命令中参数，并组织进req参数中
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 优先实现，获取命令中参数
    if(argc != 3)
    {
        ROS_INFO("提交参数个数不对！");
        return false;
    }
            
    ros::init(argc,argv,"xiaoHei");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client1::Addints>("addints");
    plumbing_server_client1::Addints req;
    //提交请求
    // cout<<"请您输入数据："<<endl;//method1
    // cin >> req.request.num1;
    // cin >> req.request.num2;
    req.request.num1=atoi(argv[1]);//method2
    req.request.num2=atoi(argv[2]);//atoi将字符串类型转换成整型
    //处理响应
    // 调用判断服务器状态的函数
    // 函数1
    // client.waitForExistence();
    // 函数2
    ros::service::waitForService("addints");
    bool flag = client.call(req);
    if (flag)
    {
        ROS_INFO("**响应成功**");
        ROS_INFO("结果为：%d",req.response.sum);
    }
    else{
        ROS_INFO("**响应失败**");

    }
    return 0;
}
