//别让异常逃离析构函数
#include <iostream>
#include <vector>
//C++并不禁止析构函数吐出异常，但它不鼓励你这样做。

class Widget {
public:
	~Widget() {}//假设该函数可能吐出一个异常
};
void doSomething() {
	std::vector<Widget> v;
	//V在这里被自动销毁
}
/*如果在v被销毁时，它有责任销毁其内含所有Widgets。假设v含有10个Widgets，
在析构第一个元素期间有2个异常被抛出。程序就会结束执行或导致不明确行为
使用标准库其他任何容器list，set或tri的任何容器甚至array都会出现相同情况
C++不喜欢析构吐出异常
*/

//一个class负责数据库连接:
class  DBConnection
{	
public:
	static DBConnection create();//这个函数返回DBConnection对象 
	void close();				//关闭练级：失败则抛出异常
};

//为确保客户不忘记在DBConnection对象上调用close(),
//一个合理的宪法是创建一个用来管理DBConnection资源的对象，并在其
//析构函数中调用close().
class  DBConn
{
public:
	 DBConn();
	 ~DBConn() { db.close(); }
	 //只要调用好 一切都米好
	 //但如果该调用导致异常，DBConn析构函数会传播该异常
	 //也就是允许它离开这个析构函数 会造成问题。
private:
	DBConnection db;
};

//改进:
//1.如果close()抛出异常就结束程序。通常通过调用abort完成
DBConn::~DBConn{
	try
	{
		db.close();
	}
	catch (const std::exception&)
	{
		//制作运转记录，记下对close的调用失败;
		std::abort();
	//若程序遭遇一个 于析构期间发生的错误后无法继续执行
	//强迫结束程序是个合理选项 毕竟它可以组织异常从析构函数传播出去
	//也就是说abort可以抢先制 “不明确行为”于死地。
	}
};

//2.吞下因调用close而发生的异常
DBConn::~DBConn{
	try
	{
	db.close();
	}
	catch (const std::exception&)
	{
		//制作运转记录，记下对close的调用失败；
		//badidea 压制了某些动作失败的重要信息 然后有时候也比结束程序要好
	}
};

//另一个较好的策略是重新设计DBConn接口，使客户有机会对可能出现的问题作出反应。
class DBConn1 {
public:
	void close() {
		db.close();
		closed = true;
	}
	~DBConn1(){
		if (!closed) {
			try
			{		//关闭连接 如果客户不那么做的话
				db.close();
			}
			catch (const std::exception&)
			{
				//制作运转记录，记下对close的调用失败
				//结束程序或者吞并异常
			}
		} 
	}
private:
	DBConnection db;
	bool closed;
};
/*把调用close的责任从DBConn析构函数手上转移到DBConn客户手上
但DBConn析构函数仍内含一个 双保险调用。
客户自己调用close并不会对他们带来负担 而是给他们一个处理错误的机会，否则他们没机会相应，否则他们没有机会相应。
*/

/*请记住：
1.析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们不做传播或结束程序
2.如果客户需要对某个操作函数运行期间抛出的异常作出反应，那么class应该提供一个普通函数 
而非在析构函数中执行该操作。

*/