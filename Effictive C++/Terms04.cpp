//����04��ȷ������ʹ��ǰ���ȱ���ʼ��
#include <iostream>
#include <list>
class point {
	int x, y;
};
point p;//p�ĳ�Ա������ʱ�򱻳�ʼ��Ϊ0����ʱ�򲻻ᡣ

//��Ѵ���취��:��Զ��ʹ�ö���֮ǰ�Ƚ�����ʼ�����������κγ�Ա����������
//������ֹ���ɴ���
void myInit1(){
int x = 0;
const char* text = "A C-style string";

double d;
std::cin >> d;
}

//������������������κζ�������ʼ���������ڹ��캯������
//ȷ��ÿһ�����캯�����������ÿһ����Ա��ʼ��
//������һ����������ͨѶ����class
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
/*C++�涨������ĳ�Ա�����ĳ�ʼ�����������ڽ��빹�캯������֮ǰ
	��ʼ���ķ���ʱ����� ��������Щ��Ա��default���캯�����Զ�����֮ʱ

*/
ABEntry::ABEntry(const std::string & name, const std::string & address, const std::list<PhoneNumber>& phones)
{
	//���ڸ�ֵ�İ汾���ȵ���default���캯��ΪtheName��...���ֵ��Ȼ�������ٶ����Ǹ�����ֵ��
	//default���캯����һ����Ϊ����˷���
	theName = name;			//��Щ���Ǹ�ֵ
	theAddress = address;	//���ǳ�ʼ��
	thePhones = phones;
	numTimesConsulted = 0;
}
//���캯��һ���Ϻõ�д���� ʹ����ν��member initialization list(��Ա��ֵ���滻��ֵ����)
ABEntry::ABEntry(const std::string & name, const std::string & address, const std::list<PhoneNumber>& phones)
	:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0)
{
	//��һ�����캯������һ�����ս����ͬ ��Ч�ʽϸ� 
	//��ֵ������Ը�����Ա���������ʵ�Σ�����ȥ��Ϊ����Ա����֮���캯����ʵ��
	//������theName��nameΪ��ֵ����copy���죬theaddress��addressΪ��ֵ����copy���죬thePhones��phonesΪ��ֵ����copy����
}
ABEntry::ABEntry() 
	:theName(),					//����theName��default���캯��
	theAddress(),				//ΪtheAddress()�����ƶ���
	thePhones(),				//~~~
	numTimesConsulted(0)		//��numTimesConsulted��ʾ��ʼ��Ϊ0
{}
class FileSystem {
public:
	std::size_t numDisks() const;
};
//extern FileSystem tfs;//�ͻ������thefileSystem���������ǰ��ʹ�������ᷢ������
class Directory {
public:
	Directory();//����);
};
Directory::Directory() {
	std::size_t disks = tfs.numDisks();//ʹ��tfs
}
//�ͻ���������һ��Directory���� ����������ʱ�ļ�
Directory tempDir();

//C++�� �����벻ͬ�ı��쵥Ԫ�ڵ�non-local static����� ��ʼ����Դ�������ȷ����
//ΨһҪ�����ǣ���ÿ��non-local static ����ᵽ�Լ���ר�������ڣ��ö����ڴ˺����ڱ�����Ϊstatic��
//��Щ��������һ��referenceָ���������Ķ��� Ȼ���û�������Щ���� ����ֱ��ָ����Щ����
//���仰˵ non-local static ����local static�����滻��.

FileSystem& tfs() {//������������滻tfs���� ����
	//FileSystem class �п����Ǹ�static
	static FileSystem fs;//���岢��ʼ��һ��local static����
	return fs;//����һ��referenceָ�����߶���
}
Directory::Directory() {
	std::size_t disks = tfs().numDisks();
}
Directory& tempDir() {//������������滻tempDir����
					  //����Directoryclass�п����Ǹ�static
	static Directory td;//���岢��ʼ��local static����
	return td;//����һ��referenceָ����������
}
/*Ϊ�����ڶ����ʼ��֮ǰ�����ʹ�����ǣ�����Ҫ�������¡�
1.�ֹ���ʼ��������non-member����
2.ʹ�ó�Ա��ֵ�жԸ���������гɷ�
3.�ڳ�ʼ������ȷ���� ��Χ�¼�ǿ������
*/

/*���ס��
*Ϊ�����Ͷ�������ֹ���ʼ�������C++����֤��ʼ������
*���캯�����ʹ�ó�������ֵ�У�����Ҫ�ڹ��캯������ʹ�ø�ֵ������
��ֵ���г��ĳ�Ա�����������д���Ӧ�ú�������class�е�����������ͬ
*Ϊ��� ������뵥Ԫ֮��ʼ���������� ����local static�����滻non-local static����
*/



