#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns{
    void myhello::run(){
        ROS_INFO("run 函数执行……");
    }
} // namespace hello_ns

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_cpp");
    // 函数调用
    hello_ns::myhello myhello;
    myhello.run();  //对象.方法
    
    return 0;
}
