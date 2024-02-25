#!/usr/bin/env python

import rospy
from std_msgs.msg import String
""""
        订阅流程
            1.导包
            2.初始化ros节点
            3.创建订阅者对象
            4.回调函数处理数据
            5.spin()
"""
def doMsg(msg):
    rospy.loginfo("我的订阅数据：%s",msg.data)

def lestener():
    #   2.初始化ros节点
    rospy.init_node("HuaHua")
    # 3.创建订阅者对象
    sub =rospy.Subscriber("fang",String,doMsg,queue_size=10)
    #         4.回调函数处理数据
    #         5.spin()
    rospy.spin()


if __name__ =="__main__":
    lestener()

