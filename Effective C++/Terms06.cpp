//������ʹ�ñ������Զ����ɵĺ������͸���ȷ�ܾ�
#include <iostream>
//��ֹ��������������
//���б����������ĺ�������public��Ϊ��ֹ��Щ��������������
//��������������ǡ����Խ�copy���캯����copy assignment����������Ϊprivate��
//������ȷ����һ����Ա���� ��ֹ�˱��������Դ�����ר���汾 ������Щ����Ϊprivate��ʹ����Գɹ���ֹ���ǵ�������

//����Ա��������Ϊprivate���ҹ��ⲻʵ������
class HomeForSale {
private:
	HomeForSale(const HomeForSale&);		//ֻ������
	HomeForSale& operator=(const HomeForSale&);
};
//������������ ���û���ͼ����HomeForSale���� ������ ��������������㲻����member������friend����֮����ô�����ֵ�������������Թ��

//�������ڴ��������������ǿ��ܵ� ֻҪ��copy���캯����copy asignment����������Ϊprivate�Ϳ��԰쵽 ��������HomeForSale����
//������һ��ר��Ϊ����ֹcoppying��������Ƶ�base class�ڡ�

class Uncopyable {
protected:
	Uncopyable(){}	//����derived������й��������
	~Uncopyable(){}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator= (const Uncopyable&);
};
//Ϊ��ֹHomeForSale���󱻿��� ����Ψһ��Ҫ���ľ��Ǽ̳� Uncopyable:
class HomeForSale :private Uncopyable {
	//class��������
	//copy���캯����copy assign.������
};
/*���ס
	Ϊ���ر������Զ��ṩ�ļ��ܣ��ɽ���Ӧ�ĳ�Ա��������Ϊprivate���Ҳ���ʵ�֡�
	ʹ����Uncopyable������base classҲ��һ��������
*/


