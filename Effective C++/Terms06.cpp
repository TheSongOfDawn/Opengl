//若不想使用编译器自动生成的函数，就该明确拒绝
#include <iostream>
//阻止编译器产出函数
//所有编译器产出的函数都是public。为阻止这些函数被创建出来
//你得自行声明他们。可以将copy构造函数或copy assignment操作符声明为private。
//藉由明确声明一个成员函数 阻止了编译器暗自创建其专属版本 而令这些函数为private，使你得以成功阻止人们调用它。

//将成员函数声明为private而且故意不实现它们
class HomeForSale {
private:
	HomeForSale(const HomeForSale&);		//只有声明
	HomeForSale& operator=(const HomeForSale&);
};
//有了上述定义 当用户企图拷贝HomeForSale对象 编译器 会阻挠他。如果你不慎在member函数或friend函数之内那么做，轮到连接器发出抱怨。

//将连接期错误移至编译期是可能的 只要将copy构造函数和copy asignment操作符声明为private就可以办到 但不是在HomeForSale自身，
//而是在一个专门为了阻止coppying动作而设计的base class内。

class Uncopyable {
protected:
	Uncopyable(){}	//允许derived对象进行构造和析构
	~Uncopyable(){}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator= (const Uncopyable&);
};
//为阻止HomeForSale对象被拷贝 我们唯一需要做的就是继承 Uncopyable:
class HomeForSale :private Uncopyable {
	//class不再声明
	//copy构造函数或copy assign.操作符
};
/*请记住
	为驳回编译器自动提供的技能，可将相应的成员函数声明为private并且不予实现。
	使用像Uncopyable这样的base class也是一种做法。
*/


