#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

"""
    发布方：发布速度消息
        话题:/turtle1/cmd_vel
        消息: geometry_msgs/tWist

    1.导包
    2.初始化ros节点
    3.创建发布者对象
    4.组织数据并发布
    
"""

if __name__=="__main__":
    # 2.初始化ros节点
    rospy.init_node("my_ctr")
    # 3.创建发布者对象
    pub=rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    # 4.组织数据并发布
    #设置发布频率
    rate=rospy.Rate(10)
    msg = Twist()
    msg.angular.x=0.0
    msg.angular.y=0.0
    msg.angular.z=0.5

    msg.linear.x=2.0
    msg.linear.y=0.0
    msg.linear.z=0.0
    rospy.sleep(3)
    while not rospy.is_shutdown():
        pub.publish(msg)
        # rate.sleep()
    pass