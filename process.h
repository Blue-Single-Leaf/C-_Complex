#include"Comp.h"
#include<vector>
//���̿�����
//������ʾ��Ϣ��ѭ�����ļ�����������Ϣ�鿴

class Process
{
public:
	static std::string userName;
	void disLogInfo();
	int disFunInfo();
	void testRecord(int m);	//�鿴���Լ�¼��1Ϊȫ���鿴��2Ϊ�鿴��һ��
	void dealF();			//�鿴�ļ�����ȡ��¼����
	void quit();			//�˳�����
	void control();			//�����ܿ�
	void circle(int);		//ѭ��
	Process();
	static int logNum;
	static std::vector<int> vecTest;

};