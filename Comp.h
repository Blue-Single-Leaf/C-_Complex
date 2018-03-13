#include"Complex.h"
//复数的计算、比较、表达式的检测处理类
class Comp:public Complex
{
public:
	static std::string getStr();
	static std::string getStr(std::string s);
	static Complex computeStr(std::string &s);		//计算带括号的复数表达式
	void test();
	bool checkStr(std::string &s);
	static bool compare(std::string &s);
	friend Complex bra_twoC(std::string s,unsigned int m);
private:
	Complex userAns;
	Complex rightAns;
	std::string title;
};
