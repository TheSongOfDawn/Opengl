//为多态基类声明virtual析构函数
#include <iostream>
/*设计一个 TimeKeeper base class 和一些derved classes作为不同的计时方法*/

class TimeKeeper {
public:
	TimeKeeper();
	~TimeKeeper();
};
class AtomicClock :public TimeKeeper {};
class WaterClock :public TimeKeeper {};
class WristWatch :public TimeKeeper {};
/*许多客户只想在程序中使用时间，不想操心时间如何计算等细节，我们就可以设计factory(工厂)函数，返回指针指向一个计时对象
Factory函数会返回一个base class指针，指向新生成之derived class对象
*/
TimeKeeper* getTimeKeeper();		//返回一个指针 指向一个
									//timeKeeper派生类的动态分配对象
//为遵守factory函数的规矩 被getTimeKeeper()返回的对象必须位于heap 因此
//为了避免泄漏内存和其他资源，将factory函数返回的每一个对象适当地delete掉很重要:
TimeKeeper* ptk = getTimeKeeper();
delete ptk;

//给base class 一个virtual析构函数。此后删除derived class对象就
//会如你想要的销毁整个对象 包括所有derived class对象：
class TimeKeeper {
public :
	TimeKeeper();
	virtual ~TimeKeeper();
};
TimeKeeper* ptk = getTimeKeeper();
delete ptk;//任何class只要带有virtual函数都确定应该也有一个virtual析构函数

//如果class不含virtual函数 通常表示它并不意图被用作一个base class。当class不企图被当做base class，令其
//析构函数为virtual 往往是个馊主意

//一个点
class Point {
public:
	Point(int xCoord, int yCoord);
	~Point();
private:
	int x, y;
};
/*如果int占用32bits 那么Pint对象可塞入一个64-bit缓存器中。
这样一个Point对象可被当做一个64-bit量 传给以其他语言如C或FORTRAN撰写的
函数。然而当Point的析构函数是virtual 形势有变化。
欲实现出virtual函数 对象必须携带某些信息，主要用来在运行期决定哪一个virtual函数
该被调用。这份信息通畅是由一个所谓vptr（virtual table pointer）指针指出
vptr指向一个由函数指针构成的数组，称为btbl(virtual table);每一个带有virtual 函数的class都有
一个相应的vtbl。当对象调用某一virtual函数 实际被调用的函数取决于该对象的vptr所指的那个vtbl--编译器在其中寻找适当的函数指针
virtual函数的实现细节不重要。重要的是如果Point class内含virtual函数，其对象体积会增加：在32bit计算机体系结构中将占用64bit到96bit
；在64bit计算机体系中可能占用64~128bit 。因此为Point添加一个vptr会增加其对象大小0.5左右。
*/
/*无端地将所有classes的析构函数声明为virtual，就像
从未声明它们为virtual一样都是错误的。
心得：只有当class内含至少一个virtual函数 才为它声明virtual析构函数。
*/

/*不要企图继承一个标准容器或者任何其他“带有non-virtual 析构函数”的class*/


/*给base classes一个virtual析构函数 该规则只适用于polymorphic 带多态
性质的 base classes身上 
*/
/*请记住：
polymorphic 带多态性质的baseclasses 应该声明一个virtual 析构函数。
如果class带有任何virtual函数 它就应该拥有一个virtual析构函数。

Classes的设计目的如果不是作为base classes使用，或不是为了具备多态性，就不该声明virtual析构函数
*/





