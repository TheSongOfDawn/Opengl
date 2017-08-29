//�˽�C++ĬĬ��д��������Щ����
/*
ʲôʱ����಻���Ǹ�empty class�أ�
��C++������֮��������Լ�û�������������ͻ�Ϊ������(�������汾��)
һ��copy���캯��,һ��copy assignment��������һ����������
���������û�������κι��캯�� ������Ҳ��Ϊ������һ��default���캯�� ������Щ��������public��inline
*/
#include <iostream>
class Empty{};
//������д��
/*
class Empty {
public:
	Empty(){}//default���캯��
	Empty(const Empty& rhs){}//copy���캯��
	~Empty(){}//����������non-virtual
	Empty& operator=(const Empty& rhs) {}//copy assignment ������
};
*/
Empty e1;				//default���캯��
						//��������
Empty e2(e1);			//copy���캯��
e2 = e1;				//copy assignment������

//default���캯��������������Ҫ�Ǹ�������һ���ط��������� ����Ļ�� �Ĵ��룬���ǵ���base classes��non-static��Ա�����Ĺ��캯��������������
//ע����������������������Ǹ�non-virtual �������class��base class ����������virtual��������
//�����������������������ԣ�virtualness����Ҫ����base class



//����һ��NamedObjet template���������㽫һ�������ƺ�����ΪT�Ķ����������
template<typename T>
class NamedObject {
public:
	NamedObject(const char* name, const T& value);
	NamedObject ( const std::string& name, const T& value);

private:
	std::string nameValue;
	T objectValue;
};
/*��������������һ���������,���������ǲ���Ϊ������default���캯��������ζ�������
���һ��class���乹�����Ҫ��ʵ�Σ�������뵣�ı���������޹��ǵ�Ϊ�����һ����ʵ�ι��캯�������ǵ���İ汾
NamedObject ��û������copy���캯����Ҳû������copy assignment�����������Ա�������Ϊ��������Щ����
*/
//����
NamedObject<int> no1("Smallest Prime Number", 2);
NamedObject<int> no2(no1);						//����copy���캯��

//����NamedObject�������� ����nameValue�Ǹ�reference to string,objectValue �Ǹ�const T:
template<class T>
class NamedObject {
public:
	//һ�¹��캯��������һ��const���ƣ���ΪnameValue����Ǹ�reference-to-non-const string.
	//��ǰ�Ǹ�char*���캯���Ѿ���ȥ�ˣ���Ϊ�����и�string�ɹ�ָ��
	NamedObject(std::string& name, const T& value);
										//��ǰ ���貢δ����operator=
private:
	std::string& nameValue;//reference
	const T objectValue;//const
};
std::string newDog("Persephone");
std::string oldDog("Satch");
NamedObject<int> p(newDog, 2);

NamedObject<int> s(oldDog, 36);

p = s;					//

/*���ס��
���������԰���Ϊclass����default���캯����copy���캯����copy assignment���������Լ���������

*/