#!/usr/bin/env python

import rospy

"""
        get_param(键,默认值)
            当键存在时，返回对应的值，如果不存在返回默认值
        get_param_cached


        get_param_names//列出所有参数键的集合//获取所有参数（键），建立集合


        has_param//判断是否包含某个键
        search_param//查找某个键名,并返回1完整键名,否则返回none
"""

if __name__=="__main__":

    rospy.init_node("xiaoBaiZi")
    radius=rospy.get_param("radius_q",13)
    typexx=rospy.get_param_cached("type_q","xiaoHeiZi")
    rospy.loginfo("radius= %d,typexx=%s",radius,typexx)
    flag =rospy.has_param("radius_q")
    if (flag):{
        rospy.loginfo("存在该元素！")
    }
    else:{
        rospy.loginfo("NO")

    }
    names=rospy.get_param_names()
    for name in names:
        rospy.loginfo("信息：%s",name)

    key=rospy.search_param("radiqus_q")
    rospy.loginfo("key=%s",key)
    pass