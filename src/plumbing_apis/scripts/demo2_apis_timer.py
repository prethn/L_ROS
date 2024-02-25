#!/usr/bin/env python

import rospy
"""
        需求1: 演示时间相关操作（获取当前时刻+设置指定时刻）

        需求2: 程序执行中停顿一段时间

        需求3: 已知程序开始执行时间和运行时间求运行结束时刻

        需求4: 每隔1秒钟在控制台输出一段文本

"""
def cb(Event):
    rospy.loginfo("--+---+---111")
    rospy.loginfo("调用回调函数的时刻：%.2f",Event.current_real.to_sec())

if __name__=="__main__":
    rospy.init_node("hello_time")
    right_time=rospy.Time.now()##将当前时刻（被调用时候），获取并封装成对象
    rospy.loginfo("right_time=%.3f",right_time.to_sec())
    rospy.loginfo("right_time=%d",right_time.secs)
    # 设置时间
    time1=rospy.Time(100.5)#将时间（从1970年1月1日 00：00：00 过去100.5s）封装成time1对象
    time2=rospy.Time(200,22)
    rospy.loginfo("time2=%.3f",time2.to_sec())
    rospy.loginfo("time2=%d",time2.secs)

    # 从某个时间值获取时间对象
    time3=rospy.Time.from_sec(210.2)
    rospy.loginfo("time3=%.2f",time3.to_sec())
    # 需求2: 程序执行中停顿5s
    rospy.loginfo("休眠前")
    du1= rospy.Duration(0)
    # du1.sleep()此语句异常
    rospy.sleep(du1)
    rospy.loginfo("休眠后---------")
    # 需求3: 已知程序开始执行时间和运行时间求运行结束时刻
    # 1.先获取时刻 t1
    t1=rospy.Time.now()
    rospy.loginfo("t1=%.2f",t1.to_sec())
    # 2.设置持续时间 du2
    du2=rospy.Duration(1)
    # 3.结果时刻 t2=t1+du2
    t2=t1+du2
    rospy.loginfo("t2=%.2f",t2.to_sec())
    t3=t1-time3
    rospy.loginfo("t3=%.2f",t3.to_sec())
    # 需求4: 创建定时器，实现rospy.rate的功能， （每隔1秒钟在控制台输出一段文本） 
    # period: Any,
    # callback: Any,
    # oneshot: bool = False,
    # reset: bool = False
    tim1=rospy.Timer(rospy.Duration(2),cb,oneshot=False) #创建一个定时器
    rospy.spin()
    pass