#include"TestInfo.h"
#include<iostream>
#include<fstream>
using namespace std;
TestInfo::TestInfo(int n,std::string t,std::string u,std::string r,int s)
{
	num =n;
	title = t;
	userAns = u;
	rightAns = r;
	score = s;
}
void TestInfo::toFile()
{
	fstream out("userData.txt",ios::out|ios::app);
	out<<" "<<num<<"\t\t";
	title = title + "=";
	int num;
	num = 40 - title.length();
	string t(num,' ');
	title = title + t;
	out<<title;
	num = 20 - userAns.length();
	string u(num,' ');
	userAns = userAns + u;
	out<<userAns;
	num = 20 - rightAns.length();
	string r(num,' ');
	rightAns = rightAns + r;
	out<<rightAns;
	out<<score<<"\n";
	out.close();	
}