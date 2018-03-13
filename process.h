#include"Comp.h"
#include<vector>
//流程控制类
//包括显示信息、循环、文件处理、测试信息查看

class Process
{
public:
	static std::string userName;
	void disLogInfo();
	int disFunInfo();
	void testRecord(int m);	//查看测试记录，1为全部查看，2为查看上一次
	void dealF();			//查看文件，获取登录次数
	void quit();			//退出存盘
	void control();			//流程总控
	void circle(int);		//循环
	Process();
	static int logNum;
	static std::vector<int> vecTest;

};