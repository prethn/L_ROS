#!/usr/bin/env python

import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
"""
        需求：是向服务端发送请求，生成一只新乌龟
        话题：/spawn
        消息: turtlesim/Spawn
    
        1.导包
        2.初始化ros节点
        4.创建客户端对象
        5.组织数据并发送
        6.处理响应

"""

if __name__=="__main__":
    rospy.init_node("server_spawn")
    client=rospy.ServiceProxy("/spawn",Spawn)

    req= SpawnRequest()
    req.x=4.4
    req.y=3.3
    req.theta=1.9
    req.name="xiaoHeiZi"

    rospy.wait_for_service("/spawn")
    # client.wait_for_service()
    try:
        res=client.call(req)
        rospy.loginfo("生成乌龟名字叫：%s",res.name)
    except Exception as e:
        rospy.loginfo("请求异常！")
    pass