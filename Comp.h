#include"Complex.h"
//�����ļ��㡢�Ƚϡ����ʽ�ļ�⴦����
class Comp:public Complex
{
public:
	static std::string getStr();
	static std::string getStr(std::string s);
	static Complex computeStr(std::string &s);		//��������ŵĸ������ʽ
	void test();
	bool checkStr(std::string &s);
	static bool compare(std::string &s);
	friend Complex bra_twoC(std::string s,unsigned int m);
private:
	Complex userAns;
	Complex rightAns;
	std::string title;
};
