//�˽�C++ĬĬ��д��������Щ����
/*
ʲôʱ����಻���Ǹ�empty class�أ�
��C++������֮��������Լ�û�������������ͻ�Ϊ������(�������汾��)
һ��copy���캯��,һ��copy assignment��������һ����������
���������û�������κι��캯�� ������Ҳ��Ϊ������һ��default���캯�� ������Щ��������public��inline
*/
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
//ע����������������������Ǹ�non-virtual �������class��base class ����������virtual��������
//�����������������������ԣ�virtualness����Ҫ����base class