//绝不在构造函数和析构过程中调用virtual函数
#include <iostream>
using namespace std;
//以下class，用来塑模股市交易如买进，卖出的订单等等。
//这样的交易一定要经过审计，所以每当创建一个交易对象，在审计日志中
//也需要创建一笔适当记录
class  Transaction
{
public:
	 Transaction();
	~ Transaction();
	virtual void logTransaction() const = 0;//作出一份因类型不同而不同
											//的日志记录(log entry)
};

Transaction::Transaction()//base class构造函数之实现
{
	logTransaction();//最后动作是志记这笔交易
}
class BuyTransaction:public Transaction//derived class
{
public:
	virtual void logTransaction()const;//志记(log)此型交易
	
private:
};
class SellTransaction :public Transaction {//derived class
public:
	virtual void logTransaction()const;		//志记此类型交易
};
//Attention
BuyTransaction b;
//在执行base class的构造函数的最后一行调用virtual函数 logTransaction,
//该函数的版本不是BuyTransaction的版本，即baseclass构造期间virtual函数绝不会下降到
//derived classes阶层。

//更根本的原因：在derived class对象的base class构造期间，对象的类型
//是base class而不是derived class。对象在derived class构造函数开始后执行 前不会成为一个derivedclass对象

/*相同道理也适用于析构函数。一旦derived class析构函数开始执行，对象内的derived class成员变量便呈现
未定义值，所以C++视它们仿佛不存在。进入base class析构函数后对象就成为一个
base class 对象，而C++的任何部分包括virtual函数，dynamic_casts等等也就那么看它。
*/

/*如果Transaction有多个构造函数 每个都需要执行某些相同工作，就把共同的初始化代码
放进一个初始化函数init内，但该中方法也可能会调用virtual函数而且隐藏的更深
*/

/*一种做法是在class Transaction内将logTransaction函数改为non-virtual，然后
要求derived class构造函数传递必要信息给Transaction构造函数，而后那个构造函数
便可安全地调用non-virtual logTransaction*/
class  Transaction0
{
public:
	explicit Transaction0(const std::string& logInfo);
	 void logTransaction(const std::string& logInfo) const;//一个non-virtual函数
											//
};

Transaction0::Transaction0(const std::string& logInfo)//base class构造函数之实现
{
	logTransaction(logInfo);//non-virtual函数调用
}
class BuyTransaction :public Transaction0//derived class
{
public:
	BuyTransaction(parameters):
	  Transaction0(createLogString(parameters));//志记(log)此型交易

private:
	static string createLogString(parameters);
};
//由于你无法使用virtual函数从base classes向下调用 在构造期间
//可以藉由令derived classes将必要的构造信息向上传递至base class构造函数 替换之而加以弥补。

/* 请记住：
在构造和析构期间不要调用virtual函数 因为这类调用从不下降至derived class(比起当前执行构造函数和析构函数的那层)

*/


