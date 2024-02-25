#!/usr/bin/env python

import rospy

if __name__=="__main__":
    rospy.init_node("change_color")
    rospy.set_param("/turtlesim/background_r",100)
    rospy.set_param("/turtlesim/background_g",50)
    rospy.set_param("/turtlesim/background_b",50)
    pass