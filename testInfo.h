#include<string>
//������Ϣ��
//��¼������Ϣ����֮д�뵽�ļ�userData.txt�ļ���
class TestInfo	
{
public:
	void toFile();	//��������Ϣд���ļ�
	TestInfo(int num,std::string title,std::string userAns,std::string rightAns,int score);
	std::string title;
	std::string userAns;
	std::string rightAns;
	int score;
	int num;		//�ڼ�����
};