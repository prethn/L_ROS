#ifndef __HELLO_H
#define __HELLO_H
    /*
在ros中头文件的使用核心内容是CMakeLists.txt文件配置，不同的封装方式配置上也有差异
 ############################################
   # 使用头文件和源文件的方式封装代码有两种方式： #
   # 1、设置头文件，可执行文件作为源文件        #
   # 2、分别设置头文件、源文件与可执行文件       #
 ############################################

    声明 namespace
            |--class
                |--run   
                
    设置头文件，可执行文件作为源文件  
    */
namespace hello_ns{
class myhello{
    public:
        void run();
};
} // namespace name


#endif