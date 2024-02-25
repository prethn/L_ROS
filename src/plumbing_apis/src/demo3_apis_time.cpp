#include "ros/ros.h"
/*

    需求1：演示时间相关操作（获取当前时刻+设置指定时刻）
        实现：
        1.准备（头文件、节点初始化、NodeHandle）
        2.获取当前时刻
        3.设置指定时刻
    需求2：程序执行中停顿一段时间
    实现：
        1.创建持续时间对象
        2.休眠
    需求3：已知程序开始执行时间和运行时间求运行结束时刻
    实现：
        1.获取开始执行时刻
        2.模拟运行时间
        3.计算结束时刻
    注意：
        1.时刻与持续时间可以相加减
        2.持续时间之间可以相加减
        3.时刻之间可以相减，不可以相加
    需求4：每隔1秒钟在控制台输出一段文本
    实现：
        法1：ros::Rate()
        法2：定时器
    注意：
        创建：nh.createTimer()
        参数1：时间间隔
        参数2：回调函数
        参数3.是否只执行一步
        参数4.是否自动启动（当设置为false，需要手动调用tim.start()）
        定时器启动后：ros::spin();
*/
//回调函数
void cb(const ros::TimerEvent& event){
    ROS_INFO("--12002");
    ROS_INFO("函数被调用的时刻：%.2f",event.current_real.toSec());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 1.准备（头文件、节点初始化、NodeHandle）已经在ros.h中包含了
    // 2.获取当前时刻
    ros::init(argc,argv,"time_q");
    ros::NodeHandle nh; //注意：必须，这是时间初始化操作(V)
    // 当前时刻：now 被执行的那一刻
    // ros::Time::init();(V)
    // ros::start();//(v)
    ros::Time right_now=ros::Time::now();
    ROS_INFO("当前时刻：%.2f",right_now.toSec());
    ROS_INFO("当前时刻：%d",right_now.sec);
    // 3.设置指定时刻
    ros::Time t1(20,222211111);
    ros::Time t2(100.21);
    ROS_INFO("t1= %.2f",t1.toSec());
    ROS_INFO("t2= %.2f",t2.toSec());
    ROS_INFO("-----------------------------------------");
    // 持续时间
    ROS_INFO("----------------持续时间-----------------");
        // 1.创建持续时间对象
    ros::Duration du(1);
    ros::Time rt=ros::Time::now();
    ROS_INFO("开始休眠:%.2f",rt.toSec());
    du.sleep();
    ros::Time rt1=ros::Time::now();
    ROS_INFO("结束休眠:%.2f",rt1.toSec());

    ROS_INFO("-----------------------------------------");
    // 计算时间
    ROS_INFO("----------------计算时间-----------------");
    // 时刻与时间
    ros::Time t3=ros::Time::now();
    ROS_INFO("开始时间：%.2f",t3.toSec());
    ros::Duration du1(3.8);
    ros::Time stop= t3 - du1;//可加可减
    ROS_INFO("结束时间：%.2f",stop.toSec());
    // 时刻与时刻
    // ros::Time sum=t3+stop;//不可以相加
    ros::Duration du2=t3-stop;
    // 持续时间与持续时间
    ROS_INFO("持续时间：%d",du2.sec);
    ros::Duration sum =du-du1;//-2.8
    ROS_INFO("持续时间：%.2f",sum.toSec());
    ros::Duration delta=rt-rt1;
    ROS_INFO("delta=%.2f",delta.toSec());
    ROS_INFO("----------------定时器-----------------");
    /*ros::Timer createTimer

    ros::Duration period, //时间间隔 ---1s
    const ros::TimerCallback &callback, //回调函数---封装业务
    bool oneshot = false,    //定时器是否是一次性的
    bool autostart = true      //自动启动
    */
    ros::Timer tim=nh.createTimer(ros::Duration(1),cb,false,false);
    // ros::Timer tim=nh.createTimer(ros::Duration(1),cb,true);
    // ros::Timer tim=nh.createTimer(ros::Duration(1),cb);
    tim.start();//将定时器tim启动，手动启动
    // ros::spinOnce();//需要回旋
    ros::spin();
            // 2.休眠
    return 0;
}
