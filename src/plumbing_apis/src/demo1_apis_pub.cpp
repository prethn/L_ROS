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
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化ROS节点
/*
    ros::init
    作用：初始化ros节点
    
    参数：int &argc,              ----  封装实参个数（n+1）参数个数+自身文件名
         char **argv,             ---- 封装参数的数组
         const std::string &name, ---- 为节点命名 （唯一性）
         uint32_t options = 0U， ----   节点启动选项
        返回值：void
    使用：
        1.argc 与 argv 的使用
            如说按照ros中的特定格式传入实参，那么ros可以加以使用，比如设置全局参数，给节点重命名……(参数服务器),设置命名空间
        2.option 的使用
          节点名称需要保证唯一性，会导致一个问题：同一个节点不能重复启动。
          结果：ros中当有重名的节点启动时，之前的节点会被关闭。
          需求：特定场景下，需要一个节点多次启动且能正常运行，怎么办？
          解决：设置启动项 ros::init_options::AnonymousName  
                当创建ros节点时，会在用户自定义的节点名称后加上随机数（时间戳），从而避免重名问题。
*/
    ros::init(argc,argv,"erGouZi",ros::init_options::AnonymousName);
    //实现机制是使用了ros::init_options::AnonymousName，在创建节点时候，命名的时候，是使用erGouZi前缀后面再加上一个随机数(时间戳)
    // ros::init()
    // 3.创建节点句柄
    ros::NodeHandle nh;//(设置命名空间)//直接调用他的无参构造，再在他的基础之上创建他的衍生对象
    // 4.创建发布者对象
    /*
    nh.advertise
    作用：创建发布者对象
    模板：被发布的消息的类型
    参数（语法）：const std::string &topic, 
                uint32_t queue_size,     
                bool latch（可选）        如果设置为true ,会保存发布方的最后一条消息，并且新的订阅对象连接到发布方时
                                        ，发布方会将这条消息发送给订阅方
    使用：
        latch 设置为 true 作用？
        以静态地图发布为例，方案一：可以使用该固定频率发送地图，但是效率低；方案二：可以将地图发布对象
        的latch设置为true,并且发布方只发送一次数据，每当订阅者连接时，将地图数据发送给订阅者（只发送一次），这样提高了数据发送效率
    */
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);
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
        //如果计数器>=50,那么就关闭节点
        if (count>=50)
        {
            ros::shutdown();
        }
        count++;
        std::stringstream ss;
        ss<<"hello---> "<<count;
        // msg.data = "hello,你好";
        msg.data = ss.str();
        // if (count<=10)
        // {
        //     pub.publish(msg);
        //     // 添加日志
        //     ROS_INFO("发布的数据:%s",ss.str().c_str());
        // }   
        pub.publish(msg);
        //     // 添加日志
        ROS_INFO("发布的数据:%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//官方建议添加，处理回调函数  //执行完回调函数后回来执行后面函数
        ROS_INFO("我还在~");
    } 
    return 0;
}
