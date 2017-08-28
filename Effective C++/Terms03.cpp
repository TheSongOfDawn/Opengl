//尽可能使用const
//const用来修饰global或namespace作用域中的常量,
//或修饰文件，函数，或区块作用域中被声明为static的对象
//面对指针，也可以指出指针自身 指针所指事物，或两者都(或都不)是const

#include <iostream>
#include <vector>

using namespace std;
char greeting[] = "hello";
char* p = greeting;//non-const pointer,non-const data
const char*p = greeting;//non-const pointer,const data
char* const p = greeting;//const pointer,non-const data
const char* const p= greeting;//const ptr,const data

//const出现在*左边 表示被指物是常量；出现在*右边，表示指针自身是常量;
//如果出现在*号两边，表示被指物和指针两者都是常量
class widget;
void f1(const widget* pw);//f1获得一个指针，指向一个常量的(不变的)widget对象
void f2(widget const* pw);//f2也一样

std::vector<int> vec;
/*以下代码必须放入函数体中才可以
不然 
*iter =10;			//改变iter所指物
										会报错

*/
void f1(){
const std::vector<int>::iterator iter =
vec.begin();//iter的作用像个T* const
*iter =10;			//改变iter所指物
++iter;				//错误！iter是const
std::vector<int>::const_iterator cIter = vec.begin();
*cIter = 10;				//错误， *cIter是const
++cIter;					//没问题，改变cIter
}


//令函数返回一个常量值 
class Rational{};

const Rational operator*(const Rational& lhs, const Rational& rhs);
//可用来预防 if(a*b=c)//美滋滋

//至于const参数 它们不过就像local const对象一样，应该在必要使用它们的时候使用它们。
//除非你有需要改动参数或local对象 否则声明为const。可以省下 想要键入==却成= 的错误.

/*改善C++程序效率的一个根本办法是以pass by reference-to-const方式传递对象
	前提是我们有const成员函数可用来处理取得const对象
*/

/*const 成员函数
	为了确认该成员函数可作用于const对象身上。
	reason1:它们使class接口比较容易被理解
	reason2:它们使操作const对象称为可能
*/

class TextBlock {
public:
	TextBlock(char* cstring) {
		text = cstring;
	}
	const char& operator[](std::size_t position)const
	{
		return text[position];
	}
	char& operator[](std::size_t position)
	{
		return text[position];
	}
private:
	std::string text;
};
void f2(){
//TextBlock的operator[]s 可被这么使用:
TextBlock tb("HELLO");
std::cout<< tb[0];
const TextBlock ctb("world");
std::cout << ctb[0]; // 调用const TextBlock::operator[]

//真实程序中const对象大多用于passed by pointer-to-const或passed by reference-to-const的传递结果

//只要重载operator[]并对不同的版本给予不同的返回类型，就可以令const和non-const TextBlocks获得不同的处理
std::cout << tb[0];			//没问题  读一个non-const TextBlock
tb[0] = 'x';				//没问题 写一个non-const TextBlock
std::cout << ctb[0];		//没问题 读一个const TextBlock
ctb[0] = 'x';		//错误 写一个const TextBlock
}
void print(const TextBlock&ctb) {//ctb是const
	std::cout << ctb[0];//调用const TextBlock::operator[]
}
class textBlock {
public:
	const char& operator[](std::size_t position)const //一如既往
	{
		return text[position];
	}
	char& operator[](std::size_t position) {
		return const_cast<char&>(static_cast<const textBlock&>(*this)[position]);
	//将op[]返回值的const转除
		//为*this 加上const
			//调用cosnt op[]
	/*
	
	non-const operator[]调用其const兄弟,但non-const operator[]内部若只是单纯调用operator[]
	会递归调用自己.为了避免递归调用，我们必须明确指出调用的是const operator[],但C++缺少直接的语法可以那么做，因此我们必须明确指出调用的const operatorp[]

	因此这里将*this从其原始类型 TextBlock&转型为const TextBlock&.为它加上const
	第一次用来为*this添加const(这使接下来调用operator[]时得以调用const版本),第二次
	则是从const operator[]的返回值中移除const
	添加const--将no-const对象转为const对象
	移除const的那个动作只可以藉由const_cast完成，没有其他选择
	*/
	}
private:
	string text;
};
/*
请记住：
*将某些东西声明为const可帮助编译器侦测出错误用法。const可被施加于任何作用域内的对象 函数参数 函数返回类型 成员函数本体
*编译器强制实施bitwise constness,但你编写程序时应该使用 概念上的常量性

*当const和non-const成员函数有着实质等价的实现时，令non-const版本调用const版本可避免代码重复

*/