#!/usr/bin/env python
import rospy
from plumbing_pub_sub.msg import Person

"""
        订阅流程:订阅人消息
            1.导包
            2.初始化ros节点
            3.创建订阅者对象
            4.回调函数处理数据
            5.spin()
"""

def doPerson (p):
    rospy.loginfo("小伙子的数据：%s,%d,%.2f",p.name,p.age,p.height)
    
if __name__=="__main__":

    rospy.init_node("DaYe")

    sub = rospy.Subscriber("jiaoSheTou",Person,doPerson,queue_size=10)

    rospy.spin()
    pass