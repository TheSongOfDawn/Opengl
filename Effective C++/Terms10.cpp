//��operator= ����һ��reference to *this

#include <iostream>
using namespace std;
//���ڸ�ֵ ������ֵ��ʽ
int x, y, z;
x = y = z = 15;//������Ϊx=(y=(z=15));����15�ȱ���ֵ��z
				//Ȼ���������º��z�ٱ���ֵ��y��Ȼ������(���º��y)
				//�ٱ���ֵ��x
//Ϊ��ʵ�������� ��ֵ���������뷵��һ��referenceָ������������ʵ��
class Widget {
public:
	Widget& operator=(const Widget& rhs) {//���������Ǹ�reference
											//ָ��ǰ����
		return*this;//����������
	//���Э�鲻�����������ϵı�׼��ֵ��ʽ��Ҳ���������и�ֵ�������
	}
	Widget& operator=(int rhs) {
		return *this;
	}
};
/*���ס
�ֵ(assignment)����������һ��reference to *this
*/