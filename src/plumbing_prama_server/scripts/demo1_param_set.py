#! /usr/bin/env python
import rospy
"""
    演示参数的增改
        需求：在参数服务器中设置机器人属性、型号、半径
        实现：
            rospy.set_param()
"""

if __name__=="__main__":
    rospy.init_node("xiaoHeiZi")
    #新增参数
    rospy.set_param("radius_q",10)
    rospy.set_param("type_q","xiaoHuangChe")
    pass
