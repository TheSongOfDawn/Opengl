//了解C++默默编写并调用哪些函数
/*
什么时候空类不再是个empty class呢？
当C++处理它之后，如果你自己没声明，编译器就会为它声明(编译器版本的)
一个copy构造函数,一个copy assignment操作符合一个析构函数
此外如果你没有声明任何构造函数 编译器也会为你声明一个default构造函数 所有这些函数都是public且inline
*/
#include <iostream>
class Empty{};
//就像你写下
/*
class Empty {
public:
	Empty(){}//default构造函数
	Empty(const Empty& rhs){}//copy构造函数
	~Empty(){}//析构函数，non-virtual
	Empty& operator=(const Empty& rhs) {}//copy assignment 操作符
};
*/
Empty e1;				//default构造函数
						//析构函数
Empty e2(e1);			//copy构造函数
e2 = e1;				//copy assignment操作符

//default构造函数和析构函数主要是给编译器一个地方用来放置 藏身幕后 的代码，像是调用base classes和non-static成员变量的构造函数和析构函数。
//注意编译器产出的析构函数是个non-virtual 除非这个class的base class 自身声明有virtual析构函数
//这种情况下这个函数的虚属性；virtualness；主要来自base class



//考虑一个NamedObjet template，它允许你将一个个名称和类型为T的对象产生关联
template<typename T>
class NamedObject {
public:
	NamedObject(const char* name, const T& value);
	NamedObject ( const std::string& name, const T& value);

private:
	std::string nameValue;
	T objectValue;
};
/*由于其中声明了一个构造参数,编译器于是不再为它创建default构造函数。这意味着如果你
设计一个class，其构造参数要求实参，你就无须担心编译器会毫无挂虑地为你添加一个无实参构造函数而覆盖掉你的版本
NamedObject 既没有声明copy构造函数，也没有声明copy assignment操作符，所以编译器会为它创建那些函数
*/
//用例
NamedObject<int> no1("Smallest Prime Number", 2);
NamedObject<int> no2(no1);						//调用copy构造函数

//假如NamedObject定义如下 其中nameValue是个reference to string,objectValue 是个const T:
template<class T>
class NamedObject {
public:
	//一下构造函数不接受一个const名称，因为nameValue如今是个reference-to-non-const string.
	//先前那个char*构造函数已经过去了，因为必须有个string可供指涉
	NamedObject(std::string& name, const T& value);
										//如前 假设并未声明operator=
private:
	std::string& nameValue;//reference
	const T objectValue;//const
};
std::string newDog("Persephone");
std::string oldDog("Satch");
NamedObject<int> p(newDog, 2);

NamedObject<int> s(oldDog, 36);

p = s;					//

/*请记住：
编译器可以暗自为class创建default构造函数，copy构造函数，copy assignment操作符，以及析构函数

*/