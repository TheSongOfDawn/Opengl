//������const,enum,inline�滻#define
#define ASPECT_RATIO 1.653
//���ܼǺ�����ASPECT_RATIO�ڱ�������ʼ����Զ��֮ǰ�ͱ�Ԥ������������
#include <iostream>
//��һ�������滻������
const double AspectRatio = 1.653;

//��ָ������Ϊconst exp
//��ͷ�ļ��ڶ���һ�������� ����� char*-based�ַ��� ����дconst����:
const char* const authorName = "Scott Meyers";
//�ĳ�string ����
const std::string authorName("Scott Meyers");

//�ڶ���ֵ��ע�����classר��������Ϊ�˽�������������������
//class�ڣ������������Ϊclass��һ����Ա ��Ϊȷ���˳�������ֻ��һ��ʵ�� �����������Ϊһ��static��Ա
class GamePlayer {
private:
	static const int NumTurns = 5;
	int scores[NumTurns];
};

//enum hack ģ��Ԫ��̵Ļ�������

//���ڵ������� �����const�����enums�滻#defines
//�������ƺ����ĺ꣬��ø���inline�����滻#defines