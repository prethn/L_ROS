#!/usr/bin/env python

import rospy
from plumbing_pub_sub.msg import Person
"""
        发布方实现
            1.导包
            2.初始化ros节点
            3.创建发布者实现
            4.发布消息
"""
if __name__=="__main__":

    rospy.init_node("DaMa")
    # 2.始化ros节点
    pub = rospy.Publisher("jiaoSheTou",Person,queue_size=10)
    # 3.创建发布者实现
    # 创建Person数据
    msg = Person()
    msg.name="奥特曼"
    msg.age =10
    msg.height=172.1
    # 创建rate对象
    rate = rospy.Rate(1)
    rospy.sleep(2)
    # 4.发布消息
    while not rospy.is_shutdown():
        msg.age +=1
        rospy.loginfo("发布数据：%s,%d,%.2f",msg.name,msg.age,msg.height)
        pub.publish(msg)
        rate.sleep()
    pass