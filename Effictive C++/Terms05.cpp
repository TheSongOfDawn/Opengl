//了解C++默默编写并调用哪些函数
/*
什么时候空类不再是个empty class呢？
当C++处理它之后，如果你自己没声明，编译器就会为它声明(编译器版本的)
一个copy构造函数,一个copy assignment操作符合一个析构函数
此外如果你没有声明任何构造函数 编译器也会为你声明一个default构造函数 所有这些函数都是public且inline
*/
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
//注意编译器产出的析构函数是个non-virtual 除非这个class的base class 自身声明有virtual析构函数
//这种情况下这个函数的虚属性；virtualness；主要来自base class