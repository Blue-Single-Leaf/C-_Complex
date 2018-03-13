#include<string>
//测试信息类
//记录测试信息并将之写入到文件userData.txt文件中
class TestInfo	
{
public:
	void toFile();	//将测试信息写入文件
	TestInfo(int num,std::string title,std::string userAns,std::string rightAns,int score);
	std::string title;
	std::string userAns;
	std::string rightAns;
	int score;
	int num;		//第几道题
};