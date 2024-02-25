#! /usr/bin/env python
import rospy
# from plumbing_server_client1.srv import Addints,AddIntsRequest,AddIntsResponse
from plumbing_server_client1.srv import Addints,AddintsRequest,AddintsResponse
import sys
"""
    客户端：
        1.导包
        2.初始化ros节点
        3.创建客户端对象；
        4.组织请求数据，并发送
        5.处理响应

        优化实现：
            可以再执行节点时，动态传入参数

        问题：
        客户端先于服务端启动会抛出异常
        需求：
        客户端先于服务端启动，不要抛出异常而是挂起，等待服务启动后再次发送请求
        实现：
        ros中已经内置相关函数 ，这些函数可以判断服务器状态，如果服务
        没有启动，就让客户端挂起。


        在创建对象完毕之后发送请求之前

        client.wait_for_service()
        rospy.wait_for_service("话题名称")
"""
        

if __name__=="__main__":
    # 判断参数长度
    if len(sys.argv) !=3:  #索引为0的位置文件名，索引为1的位置第一个参数……
        rospy.logerr("传入参数个数不对！")
        sys.exit(1)

        # 2.初始化ros节点
    rospy.init_node("daShen")
        # 3.创建客户端对象；
    client =rospy.ServiceProxy("addints",Addints)
    rospy.loginfo("客户端创建完毕！")
        # 4.组织请求数据，并发送
    # 解析传入的参数
    num1 = int (sys.argv[1])#int将字符串转成整数
    num2 = int (sys.argv[2])
    # 等待服务启动  (对象、ros)
    # client.wait_for_service()
    rospy.wait_for_service("addints")
    res=client.call(num1,num2)
        # 5.处理响应
    rospy.loginfo("响应数据：%d",res.sum)
    
    pass