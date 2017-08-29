//��operator=�д��� "���Ҹ�ֵ"
#include <iostream>
using namespace std;
class Widget0{};
Widget0 w;
w = w;//���Ҹ�ֵ�����ڶ��󱻸�ֵ���Լ�ʱ

//�����Ե����
a[i] = a[j];//Ǳ�ڵ����Ҹ�ֵ i,j��ͬ�����
*px = *py;//px,pyָ��ͬһ������

//��������һ��ָ��ָ��һ�鶯̬�����λͼ(bitmap):
class Bitmap {};
class Widget {
public:
	Widget& operator=(const Widget& rhs);
private:
	Bitmap* pb;//ָ�� ָ��һ����heap������õ��Ķ���
};
Widget& Widget::operator=(const Widget& rhs) {//һ�ݲ���ȫ��operator=ʵ�ְ汾
	delete pb;//ֹͣʹ�õ�ǰ��bitmap
	pb = new Bitmap(*rhs.pb);//ʹ��rhs's bitmap�ĸ���
	return *this;
}
/*���Ҹ�ֵ����ʱ��operator=�����ڵ�*this��ֵ��Ŀ�Ķ˺�rhs�п���
 ��ͬһ�����󡣴�ʱ��delete�Ͳ�֪�����ٵ�ǰ�����bitmap����Ҳ����rhs��bitmap.�ں���ĩβ��widget
 �ᷢ���Լ�����һ��ָ��ָ��һ���ѱ�ɾ���Ķ���
*/
//��ͳ����������ǰ����һ��֤ͬ���� ���ﵽ����Ŀ��
//���߱��쳣��ȫ�ԡ����new Bitmap�����쳣��widget���ջ����һ��ָ��
//ָ��һ�鱻ɾ����Bitmap��
Widget& Widget::operator=(const Widget& rhs) {//һ�ݲ���ȫ��operator=ʵ�ְ汾
	if (this == &rhs) return *this;		//֤ͬ����
										//��������Ҹ�ֵ���Ͳ����κ�����
	delete pb;//ֹͣʹ�õ�ǰ��bitmap
	pb = new Bitmap(*rhs.pb);//ʹ��rhs's bitmap�ĸ���
	return *this;
}
//��һ�ַ������ܹ��������Ҹ�ֵ��Ϊ���Ƕ�ԭ����bitmap����һ�ݸ�����ɾ��ԭ
//bitmap,Ȼ��ָ����������Ǹ����� �����Ч ���е�ͨ
Widget& Widget::operator=(const Widget& rhs) {//һ�ݲ���ȫ��operator=ʵ�ְ汾
	Bitmap* pOrig = pb;//��סԭ�ȵ�pb
	pb = new Bitmap(*rhs.pb);//ʹ��*pb��һ������
	delete pOrig;
	return *this;
}

//operator= �������ֹ��������(ȷ�����벻���쳣��ȫ�������Ҹ�ֵ��ȫ)
//��һ����������ǣ�ʹ����ν��copy and swap���� �����ҹ���
//template <class T> void swap(T& a, T& b)
//{
//	T c(a); a = b; b = c;
//}
class Widget1 {

	void swap(Widget1&rhs) {//����*this��rhs��ֵ
		Widget1 c(rhs);
		*this = rhs;
		rhs = c;
	}
	Widget1& operator=(Widget1 rhs);
	Widget1& operator=(const Widget1& rhs) {
		Widget1 temp(rhs);//Ϊrhs��������һ�ݸ���
		swap(temp);		//��*this���ݺ��������������ݽ���
		return *this;
	}
};
/*����������һ��������������һ����ʵ:
1.ĳclass��copy assignment���������ܱ�����Ϊ "��by value��ʽ����ʵ��"
2.��by value��ʽ���ݶ���������������/����
*/
Widget1& Widget1::operator=( Widget1 rhs) {//rhs�Ǳ��������һ�ݸ���
	swap(rhs);		//ע��������pass by value ���ݽ���
	return *this;//�������Ч
}
/*���ס��
ȷ�����������Ҹ�ֵʱ operator=��������Ϊ�����м��������Ƚ� "��Դ����"
��Ŀ�����"�ĵ�ַ�������ܵ������˳���Լ�copy-and-swap

ȷ���κκ����������һ�����ϵĶ��󣬶����ж��������ͬһ������ʱ��������Ϊ��Ȼ��ȷ��

*/	












