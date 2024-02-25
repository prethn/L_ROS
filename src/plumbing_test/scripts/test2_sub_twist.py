#!/usr/bin/env python
import rospy
from turtlesim.msg import Pose

"""
    需求：订阅乌龟位姿信息，并输出到控制台
        1.导包
        2.初始化ros节点
        4.创建订阅者对象
        5.处理订阅到的信息（用回调函数）
        6.spin();

"""
def doPose(pose):
    rospy.loginfo("乌龟的位姿：速度:(%.2f,%.2f),朝向（%.2f),线速度：%.2f,角速度：%.2f",
                  pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)
    pass

if __name__=="__main__":
    rospy.init_node("sub_turt_p")
    sub=rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=100)
    rospy.spin()
    pass