//������ʹ��const
//const��������global��namespace�������еĳ���,
//�������ļ����������������������б�����Ϊstatic�Ķ���
//���ָ�룬Ҳ����ָ��ָ������ ָ����ָ��������߶�(�򶼲�)��const

#include <iostream>
#include <vector>

using namespace std;
char greeting[] = "hello";
char* p = greeting;//non-const pointer,non-const data
const char*p = greeting;//non-const pointer,const data
char* const p = greeting;//const pointer,non-const data
const char* const p= greeting;//const ptr,const data

//const������*��� ��ʾ��ָ���ǳ�����������*�ұߣ���ʾָ�������ǳ���;
//���������*�����ߣ���ʾ��ָ���ָ�����߶��ǳ���
class widget;
void f1(const widget* pw);//f1���һ��ָ�룬ָ��һ��������(�����)widget����
void f2(widget const* pw);//f2Ҳһ��

std::vector<int> vec;
/*���´��������뺯�����вſ���
��Ȼ 
*iter =10;			//�ı�iter��ָ��
										�ᱨ��

*/
void f1(){
const std::vector<int>::iterator iter =
vec.begin();//iter���������T* const
*iter =10;			//�ı�iter��ָ��
++iter;				//����iter��const
std::vector<int>::const_iterator cIter = vec.begin();
*cIter = 10;				//���� *cIter��const
++cIter;					//û���⣬�ı�cIter
}


//�������һ������ֵ 
class Rational{};

const Rational operator*(const Rational& lhs, const Rational& rhs);
//������Ԥ�� if(a*b=c)//������

//����const���� ���ǲ�������local const����һ����Ӧ���ڱ�Ҫʹ�����ǵ�ʱ��ʹ�����ǡ�
//����������Ҫ�Ķ�������local���� ��������Ϊconst������ʡ�� ��Ҫ����==ȴ��= �Ĵ���.

/*����C++����Ч�ʵ�һ�������취����pass by reference-to-const��ʽ���ݶ���
	ǰ����������const��Ա��������������ȡ��const����
*/

/*const ��Ա����
	Ϊ��ȷ�ϸó�Ա������������const�������ϡ�
	reason1:����ʹclass�ӿڱȽ����ױ����
	reason2:����ʹ����const�����Ϊ����
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
//TextBlock��operator[]s �ɱ���ôʹ��:
TextBlock tb("HELLO");
std::cout<< tb[0];
const TextBlock ctb("world");
std::cout << ctb[0]; // ����const TextBlock::operator[]

//��ʵ������const����������passed by pointer-to-const��passed by reference-to-const�Ĵ��ݽ��

//ֻҪ����operator[]���Բ�ͬ�İ汾���費ͬ�ķ������ͣ��Ϳ�����const��non-const TextBlocks��ò�ͬ�Ĵ���
std::cout << tb[0];			//û����  ��һ��non-const TextBlock
tb[0] = 'x';				//û���� дһ��non-const TextBlock
std::cout << ctb[0];		//û���� ��һ��const TextBlock
ctb[0] = 'x';		//���� дһ��const TextBlock
}
void print(const TextBlock&ctb) {//ctb��const
	std::cout << ctb[0];//����const TextBlock::operator[]
}
class textBlock {
public:
	const char& operator[](std::size_t position)const //һ�����
	{
		return text[position];
	}
	char& operator[](std::size_t position) {
		return const_cast<char&>(static_cast<const textBlock&>(*this)[position]);
	//��op[]����ֵ��constת��
		//Ϊ*this ����const
			//����cosnt op[]
	/*
	
	non-const operator[]������const�ֵ�,��non-const operator[]�ڲ���ֻ�ǵ�������operator[]
	��ݹ�����Լ�.Ϊ�˱���ݹ���ã����Ǳ�����ȷָ�����õ���const operator[],��C++ȱ��ֱ�ӵ��﷨������ô����������Ǳ�����ȷָ�����õ�const operatorp[]

	������ｫ*this����ԭʼ���� TextBlock&ת��Ϊconst TextBlock&.Ϊ������const
	��һ������Ϊ*this���const(��ʹ����������operator[]ʱ���Ե���const�汾),�ڶ���
	���Ǵ�const operator[]�ķ���ֵ���Ƴ�const
	���const--��no-const����תΪconst����
	�Ƴ�const���Ǹ�����ֻ���Խ���const_cast��ɣ�û������ѡ��
	*/
	}
private:
	string text;
};
/*
���ס��
*��ĳЩ��������Ϊconst�ɰ������������������÷���const�ɱ�ʩ�����κ��������ڵĶ��� �������� ������������ ��Ա��������
*������ǿ��ʵʩbitwise constness,�����д����ʱӦ��ʹ�� �����ϵĳ�����

*��const��non-const��Ա��������ʵ�ʵȼ۵�ʵ��ʱ����non-const�汾����const�汾�ɱ�������ظ�

*/