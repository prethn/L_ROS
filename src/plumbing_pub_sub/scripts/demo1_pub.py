#!/usr/bin/env python
import rospy
from std_msgs.msg import String #发布的消息类型


# 导入模块 tools.py
# 设置临时环境变量
# 路径写死，影响代码的可移植性
# 优化，动态获取路径
# sys.path.insert(0,"/home/szu/User/Project_A/Test_F/rosdemo1/src/plumbing_pub_sub/scripts")

import os
import sys
path = os.path.abspath(".")
sys.path.insert(0,path + "/src/plumbing_pub_sub/scripts")
import tools


"""
    使用python实现消息发布

        1.导报
        2.初始化ros节点
        3.创建发布者对象
        4.编写发布逻辑并发布数据
"""

if __name__== "__main__":
        # 2.初始化ros节点
        rospy.init_node("sandai") #传入节点名称
        # 异常 ModuleNotFoundError: No module named 'tools'“”“””
        """
            原因： rosrun 执行时候，参考路径是工作空间的路径，在工作空间下无法查找依赖的模块
            解决：可以生命 python 的环境变量，当依赖某个模块时，先去指定的环境变量中查找依赖
        """
        # path = os.path.abspath(".")
        # rospy.loginfo("执行时参考路径是：%s",path)
        
        
        rospy.loginfo("num = %d",tools.num)
        # 3.创建发布者对象
        pub =rospy.Publisher("che",String,queue_size=10)
        # 4.编写发布逻辑并发布数据
        #创建数据
        msg=String()
        #指定发布频率
        rate =rospy.Rate(1)
        #设置计数器
        count = 0
        #休眠
        rospy.sleep(3)
        #使用循环发布数据
        while not rospy.is_shutdown():
            count +=1
            msg.data ="hello!"+ str(count)
        #发布数据
            rospy.loginfo("发布的数据：%s",msg.data)
            pub.publish(msg)
            rate.sleep()
            pass

