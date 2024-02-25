#include "ros/ros.h"
#include "plumbing_server_client1/Addints.h"

/*
    服务端实现：解析客户端提交的数据，并运算再产生响应
        1.包含头文件
        2.初始化ros节点
        3.创建节点句柄
        4.创建服务对象
        5.处理请求并产生响应，（处理回调函数）
        6.spin（）
*/
bool doNums(plumbing_server_client1::Addints::Request &request,
            plumbing_server_client1::Addints::Response &response){
    // 1.处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("解析出来的数据: num1=%d,num2=%d",num1,num2);
    // 2.组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求得的结果： sum=%d",sum);

    return true;
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"heishui");//节点名称需要唯一
    ros::NodeHandle nh;
    ros::ServiceServer server= nh.advertiseService("addints",doNums);
    ROS_INFO("服务器端启动…………");
    ros::spin();
    return 0;
}
