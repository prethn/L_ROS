#include "plumbing_head_src/hello.h"
#include "ros/ros.h"
/*
    这里虽然包含了 #include "plumbing_head_src/hello.h" 头文件，
    但是没有办法连接到 hello.cpp 的
    需要配置 链接
*/ 
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hellohead_src");

    hello_ns::myhello myhello;
    myhello.run();

    return 0;
}
