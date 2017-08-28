//尽量以const,enum,inline替换#define
#define ASPECT_RATIO 1.653
//可能记号名称ASPECT_RATIO在编译器开始处理远吗之前就被预处理器移走了
#include <iostream>
//以一个常量替换上述宏
const double AspectRatio = 1.653;

//将指针声明为const exp
//在头文件内定义一个常量的 不变的 char*-based字符串 必须写const两次:
const char* const authorName = "Scott Meyers";
//改成string 更好
const std::string authorName("Scott Meyers");

//第二个值得注意的是class专属常量。为了将常量的作用域限制于
//class内，你必须让它成为class的一个成员 而为确保此常量至多只有一份实体 你必须让它成为一个static成员
class GamePlayer {
private:
	static const int NumTurns = 5;
	int scores[NumTurns];
};

//enum hack 模板元编程的基础技术

//对于单纯常量 最好以const对象或enums替换#defines
//对于形似函数的宏，最好改用inline函数替换#defines