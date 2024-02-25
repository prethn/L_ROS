#! /usr/bin/env python
import rospy
# import sys
# sys.path.append('./')

# # 之后是出现import错误的代码
# # import ModuleXXX

# from plumbing_server_client1.srv import AddInts,AddIntsRequest,AddIntsResponse
from plumbing_server_client1.srv import AddintsResponse,Addints,AddintsRequest

"""
        服务器：
        1.导包
        2.初始化ros节点
        3.创建服务端对象；
        4.处理逻辑（回调函数）
        5.spin()
"""
def doNum(req):
    # 1.解析1提交的两个数据
    num1 = req.num1
    num2 = req.num2

    sum = num1+num2
    # 将结果封装进响应
    res = AddintsResponse()
    res.sum=sum
    rospy.loginfo("接受的数据:num1= %d ,num2 = %d,处理结果：%d",num1,num2,sum)
    return res
    pass


if __name__=="__main__":
    
    rospy.init_node("laoK")
    service =rospy.Service("addints",Addints,doNum)#话题，消息类型，回调函数
    rospy.loginfo("服务器启动！")
    rospy.spin()
    pass