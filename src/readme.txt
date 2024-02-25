笔记：
1、  在 .bashrc 中最后 source 的工作空间优先级高， 也就是会产生覆盖
2、  ROS 会解析 .bashrc 文件，并生成 ROS_PACKAGE_PATH ROS包路径，
    该变量中按照 .bashrc 中配置设置工作空间优先级，
    在设置时需要遵循一定的原则:ROS_PACKAGE_PATH 中的值，
    和 .bashrc 的配置顺序相反--->后配置的优先级更高，
    如果更改自定义空间A与自定义空间B的source顺序，那么调用时，将进入工作空间A。
3、 功能包重名时，会按照 ROS_PACKAGE_PATH 查找，配置在前的会优先执行。
4、 （功能包重名）工作空间覆盖有安全隐患！！！！！