//�����쳣������������
#include <iostream>
#include <vector>
//C++������ֹ���������³��쳣����������������������

class Widget {
public:
	~Widget() {}//����ú��������³�һ���쳣
};
void doSomething() {
	std::vector<Widget> v;
	//V�����ﱻ�Զ�����
}
/*�����v������ʱ�����������������ں�����Widgets������v����10��Widgets��
��������һ��Ԫ���ڼ���2���쳣���׳�������ͻ����ִ�л��²���ȷ��Ϊ
ʹ�ñ�׼�������κ�����list��set��tri���κ���������array���������ͬ���
C++��ϲ�������³��쳣
*/

//һ��class�������ݿ�����:
class  DBConnection
{	
public:
	static DBConnection create();//�����������DBConnection���� 
	void close();				//�ر�������ʧ�����׳��쳣
};

//Ϊȷ���ͻ���������DBConnection�����ϵ���close(),
//һ���������ܷ��Ǵ���һ����������DBConnection��Դ�Ķ��󣬲�����
//���������е���close().
class  DBConn
{
public:
	 DBConn();
	 ~DBConn() { db.close(); }
	 //ֻҪ���ú� һ�ж��׺�
	 //������õ��õ����쳣��DBConn���������ᴫ�����쳣
	 //Ҳ�����������뿪����������� ��������⡣
private:
	DBConnection db;
};

//�Ľ�:
//1.���close()�׳��쳣�ͽ�������ͨ��ͨ������abort���
DBConn::~DBConn{
	try
	{
		db.close();
	}
	catch (const std::exception&)
	{
		//������ת��¼�����¶�close�ĵ���ʧ��;
		std::abort();
	//����������һ�� �������ڼ䷢���Ĵ�����޷�����ִ��
	//ǿ�Ƚ��������Ǹ�����ѡ�� �Ͼ���������֯�쳣����������������ȥ
	//Ҳ����˵abort���������� ������ȷ��Ϊ�������ء�
	}
};

//2.���������close���������쳣
DBConn::~DBConn{
	try
	{
	db.close();
	}
	catch (const std::exception&)
	{
		//������ת��¼�����¶�close�ĵ���ʧ�ܣ�
		//badidea ѹ����ĳЩ����ʧ�ܵ���Ҫ��Ϣ Ȼ����ʱ��Ҳ�Ƚ�������Ҫ��
	}
};

//��һ���ϺõĲ������������DBConn�ӿڣ�ʹ�ͻ��л���Կ��ܳ��ֵ�����������Ӧ��
class DBConn1 {
public:
	void close() {
		db.close();
		closed = true;
	}
	~DBConn1(){
		if (!closed) {
			try
			{		//�ر����� ����ͻ�����ô���Ļ�
				db.close();
			}
			catch (const std::exception&)
			{
				//������ת��¼�����¶�close�ĵ���ʧ��
				//������������̲��쳣
			}
		} 
	}
private:
	DBConnection db;
	bool closed;
};
/*�ѵ���close�����δ�DBConn������������ת�Ƶ�DBConn�ͻ�����
��DBConn�����������ں�һ�� ˫���յ��á�
�ͻ��Լ�����close����������Ǵ������� ���Ǹ�����һ����������Ļ��ᣬ��������û������Ӧ����������û�л�����Ӧ��
*/

/*���ס��
1.�����������Բ�Ҫ�³��쳣�����һ���������������õĺ��������׳��쳣����������Ӧ�ò�׽�κ��쳣��Ȼ���������ǲ����������������
2.����ͻ���Ҫ��ĳ���������������ڼ��׳����쳣������Ӧ����ôclassӦ���ṩһ����ͨ���� 
����������������ִ�иò�����

*/