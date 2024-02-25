#!/usr/bin/ env python

import rospy

"""
    演示参数删除
        delete_param()

"""

if __name__=="__main__":
    rospy.init_node("xiaoLaoDi")
    try:#二次删除提示异常。
        rospy.delete_param("radius_q")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在！")
    pass