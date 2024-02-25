#!/usr/bin/env python
import rospy
from std_msgs.msg import String #发布的消息类型
"""
    使用python实现消息发布

        1.导报
        2.初始化ros节点
        3.创建发布者对象
        4.编写发布逻辑并发布数据
"""
def oncb():
     rospy.loginfo("正在关闭中……")


if __name__== "__main__":
        # 2.初始化ros节点
        """
        rospy.init_node
        作用： 初始化ros节点
        
        参数
            name---设置节点名称的
            argv=None, -----封装节点调用时传递的参数
            anonymous=False, -----可以为节点名称生成随机后缀。可以解决重名问题
            log_level=None, 
            disable_rostime=False, 
            disable_rosout=False, 
            disable_signals=False, 
            xmlrpc_port=0, 
            tcpros_port=0
        使用：
            1.argv
            可以安装ros中指定的语法格式传参 ,ros可以解析并加以使用

            2.anonymous


        """
        rospy.init_node("sandai",anonymous=True) #传入节点名称
        # 3.创建发布者对象
        """
            latch
            内容： latch
            作用： 如果设置为true ,会保存发布方的最后一条消息，并且新的订阅对象连接到发布方时
                ，发布方会将这条消息发送给订阅方
            使用： latch=true
        """
        pub =rospy.Publisher("che",String,queue_size=10,latch=True)
        # 4.编写发布逻辑并发布数据
        #创建数据
        msg=String()
        #指定发布频率
        rate =rospy.Rate(1)
        #设置计数器
        count = 0
        #休眠
        rospy.sleep(2)
        #使用循环发布数据
        while not rospy.is_shutdown():
            count +=1
        #发布数据
            if count<=4:           
                msg.data ="hello!"+ str(count)
                rospy.loginfo("发布的数据：%s",msg.data)
                pub.publish(msg)
            else:
                # 关闭节点
                rospy.on_shutdown(oncb)
                rospy.signal_shutdown("关闭节点")                 
            rate.sleep()
        pass

