#include "ros/ros.h"

/*
        参数查询
            实现：可以分别调用两套API实现
            ros::NodeHandle nh
            * nh.setParam("键"，“值”)
            *ros::param::set("键"，“值”)
                // set()
        ros::NodeHandle
        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)

        // 需要用一个bool接受数据和声明第二个参数

            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached(键,存储结果的变量)--提高变量获取效率
        // 从缓存里面获取数据。会判断本地缓存里面是否有该参数，没有再通过RPC远程调用
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，    参数1是被搜索的键，参数2存储搜索结果的变量

*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"xiaoHeiZi");
    ros::NodeHandle nh;
    // param
    double radius = nh.param("radius",0.5);
    ROS_INFO("获取到的半径为：%.2f",radius);
    // getparam
    double radius2;
    // bool flag = nh.getParam("radiusxx",radius2);
    // getParam和getParamCached类似，只是性能上有提升
    // getParamCached
    bool flag = nh.getParamCached("radiusw",radius2);
    if (flag)
        {
            ROS_INFO("数据获取成功!radius2=%.2f",radius2);
        }
    else{
        ROS_INFO("参数获取失败！");
    }
    // getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name :names) //元素name 被遍历的是names
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    
    // hasParam
    bool flag1 = nh.hasParam("radius");
    if (flag1)
    {
        ROS_INFO("存在该键！");
    }
    else
    {
        ROS_INFO("不存在该键！");
    } 
    // searchParam
    std::string key;
    nh.searchParam("radiusxx",key); //将搜索到的键存放在key里面，也就是key<=radius
    ROS_INFO("搜索到的键值是：%s",key.c_str());
    // ros::param
    double radiuis_ros=ros::param::param("radius",100.1);
    ROS_INFO("查询到的数值：%f",radiuis_ros);
    // ros::param::getpParamNames
    std::vector<std::string> names1;
    ros::param::getParamNames(names1);
    for (auto  &&name: names1)
    {
        ROS_INFO("遍历元素为：%s",name.c_str());
    }
    return 0;
}
