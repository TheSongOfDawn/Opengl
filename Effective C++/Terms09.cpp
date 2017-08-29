//�����ڹ��캯�������������е���virtual����
#include <iostream>
using namespace std;
//����class��������ģ���н���������������Ķ����ȵȡ�
//�����Ľ���һ��Ҫ������ƣ�����ÿ������һ�����׶����������־��
//Ҳ��Ҫ����һ���ʵ���¼
class  Transaction
{
public:
	 Transaction();
	~ Transaction();
	virtual void logTransaction() const = 0;//����һ�������Ͳ�ͬ����ͬ
											//����־��¼(log entry)
};

Transaction::Transaction()//base class���캯��֮ʵ��
{
	logTransaction();//�������־����ʽ���
}
class BuyTransaction:public Transaction//derived class
{
public:
	virtual void logTransaction()const;//־��(log)���ͽ���
	
private:
};
class SellTransaction :public Transaction {//derived class
public:
	virtual void logTransaction()const;		//־�Ǵ����ͽ���
};
//Attention
BuyTransaction b;
//��ִ��base class�Ĺ��캯�������һ�е���virtual���� logTransaction,
//�ú����İ汾����BuyTransaction�İ汾����baseclass�����ڼ�virtual�����������½���
//derived classes�ײ㡣

//��������ԭ����derived class�����base class�����ڼ䣬���������
//��base class������derived class��������derived class���캯����ʼ��ִ�� ǰ�����Ϊһ��derivedclass����

/*��ͬ����Ҳ����������������һ��derived class����������ʼִ�У������ڵ�derived class��Ա���������
δ����ֵ������C++�����Ƿ·𲻴��ڡ�����base class�������������ͳ�Ϊһ��
base class ���󣬶�C++���κβ��ְ���virtual������dynamic_casts�ȵ�Ҳ����ô������
*/

/*���Transaction�ж�����캯�� ÿ������Ҫִ��ĳЩ��ͬ�������Ͱѹ�ͬ�ĳ�ʼ������
�Ž�һ����ʼ������init�ڣ������з���Ҳ���ܻ����virtual�����������صĸ���
*/

/*һ����������class Transaction�ڽ�logTransaction������Ϊnon-virtual��Ȼ��
Ҫ��derived class���캯�����ݱ�Ҫ��Ϣ��Transaction���캯���������Ǹ����캯��
��ɰ�ȫ�ص���non-virtual logTransaction*/
class  Transaction0
{
public:
	explicit Transaction0(const std::string& logInfo);
	 void logTransaction(const std::string& logInfo) const;//һ��non-virtual����
											//
};

Transaction0::Transaction0(const std::string& logInfo)//base class���캯��֮ʵ��
{
	logTransaction(logInfo);//non-virtual��������
}
class BuyTransaction :public Transaction0//derived class
{
public:
	BuyTransaction(parameters):
	  Transaction0(createLogString(parameters));//־��(log)���ͽ���

private:
	static string createLogString(parameters);
};
//�������޷�ʹ��virtual������base classes���µ��� �ڹ����ڼ�
//���Խ�����derived classes����Ҫ�Ĺ�����Ϣ���ϴ�����base class���캯�� �滻֮�������ֲ���

/* ���ס��
�ڹ���������ڼ䲻Ҫ����virtual���� ��Ϊ������ôӲ��½���derived class(����ǰִ�й��캯���������������ǲ�)

*/


