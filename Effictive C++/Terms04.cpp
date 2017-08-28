//条款04：确定对象被使用前已先被初始化
#include <iostream>
#include <list>
class point {
	int x, y;
};
point p;//p的成员变量有时候被初始化为0，有时候不会。

//最佳处理办法是:永远在使用对象之前先将它初始化。对于无任何成员的内置类型
//你必须手工完成此事
void myInit1(){
int x = 0;
const char* text = "A C-style string";

double d;
std::cin >> d;
}

//对于内置类型以外的任何东西，初始化责任落在构造函数身上
//确保每一个构造函数豆浆对象的每一个成员初始化
//下面是一个用来表现通讯簿的class
class PhoneNumber {
public:
	PhoneNumber() {};
};
class ABEntry {
public:
	ABEntry(const std::string& name, const std::string&address, const std::list<PhoneNumber>& phones);
	ABEntry();
private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};
/*C++规定，对象的成员变量的初始化动作发生在进入构造函数本体之前
	初始化的发生时间更早 发生于这些成员的default构造函数被自动调用之时

*/
ABEntry::ABEntry(const std::string & name, const std::string & address, const std::list<PhoneNumber>& phones)
{
	//基于赋值的版本首先调用default构造函数为theName，...设初值，然后立刻再对它们赋予新值。
	//default构造函数的一切作为因此浪费了
	theName = name;			//这些都是赋值
	theAddress = address;	//不是初始化
	thePhones = phones;
	numTimesConsulted = 0;
}
//构造函数一个较好的写法是 使用所谓的member initialization list(成员初值列替换赋值动作)
ABEntry::ABEntry(const std::string & name, const std::string & address, const std::list<PhoneNumber>& phones)
	:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0)
{
	//这一个构造函数和上一个最终结果相同 但效率较高 
	//初值列中针对各个成员变量而设的实参，被拿去作为各成员变量之构造函数的实参
	//本例中theName以name为初值进行copy构造，theaddress以address为初值进行copy构造，thePhones以phones为初值进行copy构造
}
ABEntry::ABEntry() 
	:theName(),					//调用theName的default构造函数
	theAddress(),				//为theAddress()做类似动作
	thePhones(),				//~~~
	numTimesConsulted(0)		//将numTimesConsulted显示初始化为0
{}
class FileSystem {
public:
	std::size_t numDisks() const;
};
//extern FileSystem tfs;//客户如果在thefileSystem对象构造完成前就使用它，会发生灾难
class Directory {
public:
	Directory();//参数);
};
Directory::Directory() {
	std::size_t disks = tfs.numDisks();//使用tfs
}
//客户决定创建一个Directory对象 用来放置临时文件
Directory tempDir();

//C++对 定义与不同的变异单元内的non-local static对象的 初始化相对次序并无明确定义
//唯一要做的是：将每个non-local static 对象搬到自己的专属函数内（该对象在此函数内被声明为static）
//这些函数返回一个reference指向它所含的对象 然后用户调用这些函数 而不直接指涉这些函数
//换句话说 non-local static 对象被local static对象替换了.

FileSystem& tfs() {//这个函数用来替换tfs对象 它在
	//FileSystem class 中可能是个static
	static FileSystem fs;//定义并初始化一个local static对象
	return fs;//返回一个reference指向上诉对象
}
Directory::Directory() {
	std::size_t disks = tfs().numDisks();
}
Directory& tempDir() {//这个函数用来替换tempDir对象
					  //它在Directoryclass中可能是个static
	static Directory td;//定义并初始化local static对象
	return td;//返回一个reference指向上述对象
}
/*为避免在对象初始化之前过早地使用它们，你需要做三件事。
1.手工初始化内置型non-member对象。
2.使用成员初值列对付对象的所有成分
3.在初始化次序不确定性 氛围下加强你的设计
*/

/*请记住：
*为内置型对象进行手工初始化，因此C++不保证初始化它们
*构造函数最好使用成隐患初值列，而不要在构造函数体内使用赋值操作。
初值列列出的成员变量，其排列次序应该和它们在class中的声明次序相同
*为免除 “跨编译单元之初始化次序”问题 请以local static对象替换non-local static对象
*/



