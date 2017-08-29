//Ϊ��̬��������virtual��������
#include <iostream>
/*���һ�� TimeKeeper base class ��һЩderved classes��Ϊ��ͬ�ļ�ʱ����*/

class TimeKeeper {
public:
	TimeKeeper();
	~TimeKeeper();
};
class AtomicClock :public TimeKeeper {};
class WaterClock :public TimeKeeper {};
class WristWatch :public TimeKeeper {};
/*���ͻ�ֻ���ڳ�����ʹ��ʱ�䣬�������ʱ����μ����ϸ�ڣ����ǾͿ������factory(����)����������ָ��ָ��һ����ʱ����
Factory�����᷵��һ��base classָ�룬ָ��������֮derived class����
*/
TimeKeeper* getTimeKeeper();		//����һ��ָ�� ָ��һ��
									//timeKeeper������Ķ�̬�������
//Ϊ����factory�����Ĺ�� ��getTimeKeeper()���صĶ������λ��heap ���
//Ϊ�˱���й©�ڴ��������Դ����factory�������ص�ÿһ�������ʵ���delete������Ҫ:
TimeKeeper* ptk = getTimeKeeper();
delete ptk;

//��base class һ��virtual�����������˺�ɾ��derived class�����
//��������Ҫ�������������� ��������derived class����
class TimeKeeper {
public :
	TimeKeeper();
	virtual ~TimeKeeper();
};
TimeKeeper* ptk = getTimeKeeper();
delete ptk;//�κ�classֻҪ����virtual������ȷ��Ӧ��Ҳ��һ��virtual��������

//���class����virtual���� ͨ����ʾ��������ͼ������һ��base class����class����ͼ������base class������
//��������Ϊvirtual �����Ǹ�������

//һ����
class Point {
public:
	Point(int xCoord, int yCoord);
	~Point();
private:
	int x, y;
};
/*���intռ��32bits ��ôPint���������һ��64-bit�������С�
����һ��Point����ɱ�����һ��64-bit�� ����������������C��FORTRAN׫д��
������Ȼ����Point������������virtual �����б仯��
��ʵ�ֳ�virtual���� �������Я��ĳЩ��Ϣ����Ҫ�����������ھ�����һ��virtual����
�ñ����á������Ϣͨ������һ����νvptr��virtual table pointer��ָ��ָ��
vptrָ��һ���ɺ���ָ�빹�ɵ����飬��Ϊbtbl(virtual table);ÿһ������virtual ������class����
һ����Ӧ��vtbl�����������ĳһvirtual���� ʵ�ʱ����õĺ���ȡ���ڸö����vptr��ָ���Ǹ�vtbl--������������Ѱ���ʵ��ĺ���ָ��
virtual������ʵ��ϸ�ڲ���Ҫ����Ҫ�������Point class�ں�virtual�������������������ӣ���32bit�������ϵ�ṹ�н�ռ��64bit��96bit
����64bit�������ϵ�п���ռ��64~128bit �����ΪPoint���һ��vptr������������С0.5���ҡ�
*/
/*�޶˵ؽ�����classes��������������Ϊvirtual������
��δ��������Ϊvirtualһ�����Ǵ���ġ�
�ĵã�ֻ�е�class�ں�����һ��virtual���� ��Ϊ������virtual����������
*/

/*��Ҫ��ͼ�̳�һ����׼���������κ�����������non-virtual ������������class*/


/*��base classesһ��virtual�������� �ù���ֻ������polymorphic ����̬
���ʵ� base classes���� 
*/
/*���ס��
polymorphic ����̬���ʵ�baseclasses Ӧ������һ��virtual ����������
���class�����κ�virtual���� ����Ӧ��ӵ��һ��virtual����������

Classes�����Ŀ�����������Ϊbase classesʹ�ã�����Ϊ�˾߱���̬�ԣ��Ͳ�������virtual��������
*/





