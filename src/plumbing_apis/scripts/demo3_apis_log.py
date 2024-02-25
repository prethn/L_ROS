#!/usr/bin/env python
import rospy

if __name__=="__main__":
    # 演示日志函数
    rospy.init_node("hello_log1")


    rospy.logdebug("debug……") #不在控制台输出
    rospy.loginfo("info……")
    rospy.logwarn("warn……")
    rospy.logerr("err……")
    rospy.logfatal("fatal……")
    pass