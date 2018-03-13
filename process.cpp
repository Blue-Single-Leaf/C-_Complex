#include"Process.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define FILENAME "userData.txt"
string Process::userName = "";
vector<int> Process::vecTest;
int Process::logNum = -1;
void Process::control()
{
	dealF();
	disLogInfo();
	circle(disFunInfo());
}
void Process::circle(int m)
{
	if(m == 1)
	{
		//计算复数表达式
		Comp c;
		Complex c1;
		string str;
		str = c.getStr("\n\n请输入您要计算的复数表达式，以 '=' 号加回车结束:");
		while(!c.checkStr(str))
		{
			str = c.getStr();
		}
		c1 = c.computeStr(str);
		cout<<"\n\n\t\t\t->计算结果： ";
		c1.display();
		cout<<"\n\n"<<endl;
		circle(disFunInfo());
	}
	else if(m == 2)
	{
		//进行复数比较
		Comp c;
		string str;
		str = c.getStr("\n\n请输入您要比较的两个复数或表达式，中间用>=,<=,==,!=区分两个复数或表达式:");
		if(c.compare(str))
		{
			cout<<"\n\n\t\t\t->该比较成立";
		}
		else
		{
			cout<<"\n\n\t\t\t->该比较不成立";
		}
		cout<<"\n\n"<<endl;
		circle(disFunInfo());
	}
	else if(m == 3)
	{
		//进行复数测试
		Comp c;
		c.test();
		cout<<"\n\n"<<endl;
		dealF();
		circle(disFunInfo());
	}
	else if(m == 4)
	{
		//查询测试记录
		int w;
		cout<<"查询方式:    1.查询上一次作业记录\t2.查询所有记录\n\n";
		cout<<"请输入您要查询的方式：";
		cin>>w;
		cin.clear();
		cin.ignore();
		cout<<"\n\n";
		if(w == 1 || w == 2)
		{
			testRecord(w);
		}
		else
		{

		}
		cout<<"\n\n->";
		circle(disFunInfo());
	}
	else if(m == 5)
	{
		//保存退出
	}
	else if(m == 6)
	{
		cout<<"It is made by FranceYang!"<<endl;
		circle(disFunInfo());
	}
	else
	{
		cout<<"您输入的命令无法操作!"<<endl;
		circle(disFunInfo());
	}
}
Process::Process()
{
	cout<<"\n\n***************欢迎使用复数计算机模拟程序!*********************\n\n"<<endl;
	userName = Comp::getStr("请输入用户名：");
	fstream outf;
	outf.open(FILENAME,ios::out|ios::app);
	outf<<"#"<<userName<<"#\t";
	outf.close();
}
void Process::disLogInfo()
{
	system("cls");
	cout<<"\n\n************************复数计算器模拟程序*********************************\n";
	cout<<"\n此程序在c++作业要求上进行了扩充，主要有以下几点："<<endl;
	cout<<"\n\t->1.用户可以按正常书写表达式输入去进行复杂的复数运算，可以处理带多括号，多 +、-、*、/运算符,多操作数的表达式。\n\t  而不仅局限于单运算符."<<endl;
	cout<<"\n\t->2.用户可以保存以前所有的测试数据并可以选择性地查看上一次或所有记录."<<endl;
	cout<<"\n\t->3.用户测试可以进行层次训练，难、中、易题目均有，且题中表达式随机生成."<<endl;
	cout<<"\n\n**********************************************************************\n\n\n";
	cout<<"\t欢迎进入系统，您的登录的次数为："<<logNum<<endl;
	cout<<"\n\n->";
	fstream out;
	out.open("userData.txt",ios::out|ios::app);
	out<<"第 "<<logNum<<" 次进入系统\n";
	out.close();
}
int Process::disFunInfo()
{
	int m;
	system("pause");
	system("cls");
	cout<<"\n\n************************复数计算器模拟程序*********************************\n";
	cout<<"\n请选择以下操作项目之一："<<endl;
	cout<<"\n\t->1.进行复数运算\t->2.进行复数比较"<<endl;
	cout<<"\n\t->3.分难度复数运算测试\t->4.查看测试记录"<<endl;
	cout<<"\n\t->5.保存退出\n\n"<<endl;
	cout<<"请输入您的选择：";
	cin>>m;
	cin.clear();
	cin.ignore();
	return m;
}
void Process::testRecord(int m)
{
	bool fgotoline(fstream &fp,int m);
	int i;
	fstream inf(FILENAME);
	string str;
	if(vecTest.size() == 0)
	{
		cout<<"您尚未进行测试，暂无相关记录."<<endl;
		return;
	}
	if(m == 1)
	{
		fgotoline(inf,vecTest[vecTest.size()-1]);
		for(i = 0;i < 14;i++)    //(getline(inf,str))
		{
			getline(inf,str);
			cout<<str<<endl;
		}
	}
	else
	{
		int l,j = 0;
		char c;
		l = vecTest.size();
		for(i = 0;i < l;i++)
		{
			fgotoline(inf,vecTest[i]);
			for(j = 0;j < 14;j++)    //(getline(inf,str))
			{
				getline(inf,str);
				cout<<str<<endl;
			}
			if(!(i == (l -1)))
			{
				system("pause");
				cout<<"\n\n";
			}
		}
	}
	inf.close();
}
void Process::dealF()
{
	bool fgotoline(fstream &fp,int m);
	fstream inf;
	string str;
	int num = 0;
	vecTest.clear();
	inf.open(FILENAME,ios::in);
	if(!inf)
	{
		cerr<<"文件打开失败!"<<endl;
	}
	else
	{
		int i = 0;
		while(getline(inf,str))
		{
			i++;
			if(str.find("#"+userName+"#") != string::npos)
			{
				num++;
			}
			if(str.find("****"+userName+"****") != string::npos)
			{
				vecTest.push_back(i);
			}
		}
		logNum = num;
		inf.close();	
	}
}
bool fgotoline(fstream &fp,int m)
{				//到达并定位到第m行行首，成功则返回 true; 否则 返回 false，意味着该文件行数不足 m 行;
	int i;
	string str;
	fp.seekg(0,ios::beg);
	for(i = 1;i < m;i++)
	{
		if(!getline(fp,str))
		{
			return false;
		}
	}
	return true;						
}
