#include"testInfo.h"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<ctime>
#include<fstream>
#include"Process.h"
using namespace std;
string Comp::getStr()
{
	string str;
	getline(cin,str);
	return str;
}
string Comp::getStr(string s)
{
	string str;
	cout<<s;
	getline(cin,str);
	return str;
}
bool Comp::compare(string &s)
{
	int i,l;
	string s1,s2,sign;
	for(i = 0,l =  s.length();i < l;i++)
	{
		if(s[i] == '>' && s[i+1] == '=')
		{
			s1 = s.substr(0,i);
			s2 = s.substr(i+2);
			return (computeStr(s1) >= computeStr(s2));
		}
		else if(s[i] == '<' && s[i+1] == '=')
		{
			s1 = s.substr(0,i);
			s2 = s.substr(i+2);
			return (computeStr(s1) <= computeStr(s2));
		}
		else if(s[i] == '=' && s[i+1] == '=')
		{
			s1 = s.substr(0,i);
			s2 = s.substr(i+2);
			return (computeStr(s1) == computeStr(s2));
		}
		else if(s[i] == '!' && s[i+1] == '=')
		{
			s1 = s.substr(0,i);
			s2 = s.substr(i+2);
			return (computeStr(s1) != computeStr(s2));
		}
	}
	cout<<"你输入的字符串中无比较符号 ==、!=、>=、<= 这四种之一！"<<endl;
	return false;
}
void Comp::test()
{
	int num;
	int i,j;
	int e[3] = {0};
	fstream out;
	out.open("userData.txt",ios::out|ios::app);
	out<<"****"<<Process::userName<<"****"<<"\t第 "<<(Process::vecTest.size()+1)<<" 次作业\n\n";
	out<<"题号\t\t";
	string t(28,' ');
	out<<"复数表达式题目"<<t;
	string u(11,' ');
	out<<"学生答案"<<u;
	string r(10,' ');
	out<<"正确答案"<<r;
	out<<"得分\n\n";
	out.close();
	srand((unsigned)time(0));
	for(j = 0;j < 4;j++)
	{
		string str = " ";
		stringstream stream;
		cout<<"第 "<<j+1<<" 题：";
		for(i = 0;i < 4;i++)
		{
			num = rand() % 10;
			if(num == 0) num = 10;
			stream<<num;
			str = stream.str();
			if(i == 0) 
			{
				stream<<'+';
				str = stream.str();
			}
			if(i == 1)
			{
				stream<<"i+(";
				str = stream.str();
			}
			if(i == 2)
			{
				stream<<"-";
				str = stream.str();
			}
			if(i == 3)
			{
				stream<<"i)";
				str = stream.str();
			}
		}
		for(i = 0;i < str.length();i++)
		{
			if(str[i] == '1' && str[i+1] == 'i')
				str.replace(i,1,"");
		}
		cout<<str<<'=';
		title = str;
		rightAns = computeStr(str);
		userAns = computeStr(getStr());
		if(rightAns.real == userAns.real && rightAns.imag == userAns.imag)
		{
			cout<<"\n\n\tGood Job!答案正确!"<<endl;
			e[0]++;
			TestInfo t(j+1,title,userAns.toStr(),rightAns.toStr(),10);
			t.toFile();
		}
		else
		{
			cout<<"\n\n\t正确答案为：";
			rightAns.display();
			TestInfo t(j+1,title,userAns.toStr(),rightAns.toStr(),0);
			t.toFile();
		}
		cout<<"\n";
	}
	for(j = 0;j < 3;j++)
	{
		string str = " ";
		stringstream stream;
		cout<<"第 "<<j+5<<" 题：";
		for(i = 0;i < 4;i++)
		{
			num = rand() % 10;
			if(num == 0) num = 10;
			stream<<num;
			str = stream.str();
			if(i == 0) 
			{
				stream<<'+';
				str = stream.str();
			}
			if(i == 1)
			{
				stream<<"i)*";
				str = stream.str();
			}
			if(i == 2)
			{
				stream<<"-";
				str = stream.str();
			}
			if(i == 3)
			{
				stream<<"/("<<2*num<<"i)";
				str = stream.str();
			}
		}
		for(i = 0;i < str.length();i++)
		{
			if(str[i] == '1' && str[i+1] == 'i')
				str.replace(i,1,"");
		}
		str = "(" + str;
		cout<<str<<'=';
		title = str;
		rightAns = computeStr(str);
		userAns = computeStr(getStr());
		if(rightAns.real == userAns.real && rightAns.imag == userAns.imag)
		{
			cout<<"\n\n\tGood Job!答案正确!"<<endl;
			e[1]++;
			TestInfo t(j+5,title,userAns.toStr(),rightAns.toStr(),10);
			t.toFile();
		}
		else
		{
			cout<<"\n\n\t正确答案为：";
			rightAns.display();
			TestInfo t(j+5,title,userAns.toStr(),rightAns.toStr(),0);
			t.toFile();
		}
		cout<<"\n";
	}
	for(j = 0;j < 3;j++)
	{
		string str = " ";
		stringstream stream;
		cout<<"第 "<<j+8<<" 题：";
		for(i = 0;i < 8;i++)
		{
			num = rand() % 10;
			if(num == 0) num = 10;
			stream<<num;
			str = stream.str();
			if(i == 0) 
			{
				stream<<'+';
				str = stream.str();
			}
			if(i == 1)
			{
				stream<<"i+";
				str = stream.str();
			}
			if(i == 2)
			{
				stream<<"i*";
				str = stream.str();
			}
			if(i == 3)
			{
				stream<<")(";
				str = stream.str();
			}
			if(i == 4)
			{
				stream<<"i*";
				str = stream.str();
			}
			if(i == 5)
			{
				stream<<"/"<<4*num<<"+";
				str = stream.str();
			}
			if(i == 6)
			{
				stream<<")-";
				str = stream.str();
			}
			if(i == 7)
			{
				stream<<"i)";
				str = stream.str();
			}
		}
		for(i = 0;i < str.length();i++)
		{
			if(str[i] == '1' && str[i+1] == 'i')
				str.replace(i,1,"");
		}
		str = "((" + str;
		cout<<str<<'=';
		title = str;
		rightAns = computeStr(str);
		userAns = computeStr(getStr());
		if(rightAns.real == userAns.real && rightAns.imag == userAns.imag)
		{
			cout<<"\n\n\tGood Job!答案正确!"<<endl;
			e[2]++;
			TestInfo t(j+8,title,userAns.toStr(),rightAns.toStr(),10);
			t.toFile();
		}
		else
		{
			cout<<"\n\n\t正确答案为：";
			rightAns.display();
			TestInfo t(j+8,title,userAns.toStr(),rightAns.toStr(),0);
			t.toFile();
		}
		cout<<"\n";
	}
	//fstream out;
	out.open("userData.txt",ios::out|ios::app);
	out<<"\n\n";
	out.close();
	cout<<"\n\n\t十道题目已经做完，基本情况如下："<<endl;
	if((e[0]+e[1]+e[2]) == 10)
		cout<<"\n\t->恭喜全部正确！"<<endl;
	else
	{
		cout<<"\n共做对 "<<e[0]+e[1]+e[2]<<" 道题目."<<endl;
	}
	cout<<"基础难度题目1-4：";
	if(e[0] == 4)
		cout<<"\t 恭喜 全对！！！"<<endl;
	else
		cout<<"\t 做对 "<<e[0]<<" 道."<<endl;
	cout<<"拔高难度题目5-7：";
	if(e[1] == 3)
		cout<<"\t 恭喜 全对！！！"<<endl;
	else
		cout<<"\t 做对 "<<e[1]<<" 道."<<endl;
	cout<<"复杂难度题目8-10：";
	if(e[2] == 3)
		cout<<"\t 恭喜 全对！！！"<<endl;
	else
		cout<<"\t 做对 "<<e[2]<<" 道."<<endl;

}
bool Comp::checkStr(string &s)
{
	int i,l;
	//去掉空格
	for(i = 0,l = s.length();i < l;i++)
	{	
		if(s[i] == ' ')
			s.replace(i,1,"");
	}
	//去掉'='
	/*if(s.find('=') == string::npos)
	{
		cout<<"您输入的表示式 "<<s<<" 未包含 = 号!请重新输入:";
		return false;
	}*/
	if(s.find('=') != string::npos)
	{
		s.replace(s.find('='),1,"");
	}
	//检测括号是否符合标准
	int left = 0,right = 0;
	for(i = 0,l = s.length();i < l;i++)
	{
		if(s[i] == ')')
			right++;
		if(s[i] == '(')
			left++;
	
	}
	if(left != right)
	{
		cout<<"您输入的表达式 "<<s<<" 左右括号数目不一致.\t其中左括号:"<<left<<"个，右括号"<<right<<"个.\n请重新输入表达式:";
		return false;
	}
	//检测字符是否符合标准
	for(i = 0,l = s.length();i < l;i++)
	{	
		if(s[i] != ' ' && s[i] != 'i' && s[i] != '.' )
		{
			if(s[i] != '(' && s[i] != ')' )
			{
				if(!(s[i] <= '9' && s[i] >= '0'))
				{
					if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
					{
						cout<<"您输入的字符串 "<<s<<" 中的第 "<<i+1<<"个字符 "<<s[i]<<" 无法识别，请重新输入：";
						return false;
					}
				}
			}
		}
			
	}
	if(s == "quit") return true;
	return true;
}
Complex Comp::computeStr(std::string &a)
{
	unsigned int min(vector<unsigned int> vec);
	unsigned int max(vector<unsigned int> vec);
	unsigned int getSmall(vector<unsigned int> vec,unsigned int aim);
	unsigned int getBig(vector<unsigned int> vec,unsigned int aim);
	Complex compute(string &a);
	bool isBE(string);
	bool is_out_bra(unsigned int num,string s);
	Complex twoC(string s,char ch);
	Complex bra_twoC(string s,unsigned int m);
	Complex c(0,0);
	vector<unsigned int> addSign;
	vector<unsigned int> minusSign;
	vector<unsigned int> timesSign;
	vector<unsigned int> divSign;
	vector<unsigned int> allSign;
	size_t aim;
	size_t begin;
	size_t end;
	size_t mid;
	mid = 0;
	int i;
	for(i = 0;i < a.length();i++)
	{
		if(!(a[i] <= '9' && a[i] >= '0') && a[i+1] == 'i')
		{
			a.replace(i+1,1,"1i");
		}
		if(a[i] == '+' && a[i+1] == '+')
		{
			a.replace(i,1,"");
			break;
		}
		else if(a[i] == '+' && a[i+1] == '-')
		{
			a.replace(i,1,"");
			break;
		}
		else if(a[i] == '-' && a[i+1] == '+')
		{
			a.replace(i+1,1,"");
			break;
		}
		else if(a[i] == '-' && a[i+1] == '-')
		{
			a.replace(i,2,"+");
			break;
		}
	}
	while(isBE(a))				//如果有首尾括号成对，则去掉
	{
		a.replace(0,1,"");
		a.replace(a.length()-1,1,"");
	}
	if(a.find("(") == string::npos)
	{
		c = compute(a);
	}
	else
	{
		for(i = 0;i < a.length();i++)
		{
			if(a[i] == ')' && a[i+1] == '(')
				a.replace(i,1,")*");
			if(a[i] <= '9' && a[i] >= '0' && a[i+1] == '(')
				a.replace(i+1,1,"*(");
		}
		for(i = 0;i < a.length();i++)
		{
			if(a[i] == '+' && is_out_bra(i,a))
			{
				addSign.push_back(i);
				allSign.push_back(i);
				mid = i + 1;
			}
			if(a[i] == '-' && is_out_bra(i,a))
			{
				minusSign.push_back(i);
				allSign.push_back(i);
				mid = i + 1;
			}
			if(a[i] == '*' && is_out_bra(i,a))
			{
				timesSign.push_back(i);
				allSign.push_back(i);
				mid = i + 1;
			}
			if(a[i] == '/' && is_out_bra(i,a))
			{
				divSign.push_back(i);
				allSign.push_back(i);
				mid = i + 1;
			}
		}
		if(timesSign.size() == 0 && divSign.size() == 0)
		{
			//只有加减法运算;
			if(allSign.size() == 1 && allSign[0] == 0)	//仅有一个+,-号位于首字符
			{
				if(a.at(allSign[0]) == '+'){
					a.replace(0,1,"");
					c = c + computeStr(a);
				}
				else
				{
					a.replace(0,1,"");
					c = c - computeStr(a);
				}
				return c;
			}
			else if(allSign.size() == 1 && allSign[0] != 0 )//仅含一个+ 或 - 且不为首
			{
				c = c + bra_twoC(a,allSign[0]);
			}
			else if(allSign.size() >= 2 && min(allSign) == 0)//含两个加减号且一个位于首字符处
			{
				vector<unsigned int> cp_allSign(allSign);
				for(i = 0;i < cp_allSign.size();i++)
				{
					if(min(allSign) == cp_allSign[i])
					{
						cp_allSign.erase(cp_allSign.begin() + i);
						break;
					}
				}
				string left,right;
				left = a.substr(0,min(cp_allSign));
				right = a.substr(min(cp_allSign));
				c = c + computeStr(left) + computeStr(right);
			}
			else if(allSign.size() >= 2 && min(allSign) != 0)
			{
				string left,right;
				left = a.substr(0,min(allSign));
				right = a.substr(min(allSign));
				c = c + computeStr(left) + computeStr(right);
			}
		}
		else if(timesSign.size() != 0 && divSign.size() == 0)
		{
			//只存在乘法运算
			vector<unsigned int> temp(allSign);
			aim = min(timesSign);
			if(min(timesSign) == min(allSign) && min(timesSign) == max(allSign))	//只有一个运算且为乘法运算	
			{
				c = c + bra_twoC(a,min(timesSign));
			}
			else if(min(timesSign) == min(allSign))								//乘号位于第一个运算符
			{
				if(a[0] != '*')
					begin = 0;
				else
					cout<<"输入格式有误，*不能放表达式首位!"<<endl;
				end = getBig(temp,aim);
				string sub_str;
				sub_str = a.substr(begin,end - begin);
				c = c + bra_twoC(sub_str,min(timesSign));
				if(c.real == 0 && c.imag == 0)
				{
					stringstream stream;
					stream<<'0';
					stream>>sub_str;
				}
				else if(c.real == 0)
				{
					stringstream stream;
					stream<<'('<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				else if(c.imag == 0)
				{
					stringstream stream;
					stream<<'('<<c.real<<')';
					stream>>sub_str;
				}
				else 
				{
					stringstream stream;
					string e;
					if(c.imag < 0)
						e = "";
					else
						e = '+';
					stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				a.replace(begin,end,sub_str);
				c = computeStr(a);

			}
			else if(min(timesSign) == max(allSign))		//乘号位于末位运算符处
			{
				if(a[a.length()-1] != '*')
					end = a.length()-1;
				else
					cout<<"输入格式有误，*不能放表达式末位!"<<endl;
			
				begin = getSmall(temp,aim);
				string sub_str;
				sub_str = a.substr(begin+1,end - begin+1);
				c = c + bra_twoC(sub_str,min(timesSign)-begin-1);
				if(c.real == 0 && c.imag == 0)
				{
					stringstream stream;
					stream<<'0';
					stream>>sub_str;
				}
				else if(c.real == 0)
				{
					stringstream stream;
					stream<<'('<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				else if(c.imag == 0)
				{
					stringstream stream;
					stream<<'('<<c.real<<')';
					stream>>sub_str;
				}
				else 
				{
					stringstream stream;
					string e;
					if(c.imag < 0)
						e = "";
					else
						e = '+';
					stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				a.replace(begin+1,end,sub_str);
				c = computeStr(a);
			}
			else 
			{
				begin = getSmall(temp,aim);
				end = getBig(temp,aim);
				string sub_str;
				sub_str = a.substr(begin+1,end - begin-1);
				c = c + bra_twoC(sub_str,min(timesSign)-begin-1);
				if(c.real == 0 && c.imag == 0)
				{
					stringstream stream;
					stream<<'0';
					stream>>sub_str;
				}
				else if(c.real == 0)
				{
					stringstream stream;
					stream<<'('<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				else if(c.imag == 0)
				{
					stringstream stream;
					stream<<'('<<c.real<<')';
					stream>>sub_str;
				}
				else 
				{
					stringstream stream;
					string e;
					if(c.imag < 0)
						e = "";
					else
						e = '+';
					stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				a.replace(begin + 1,end - begin - 1,sub_str);
				c = computeStr(a);
			}

		}
		else if(timesSign.size() == 0 && divSign.size() != 0)
		{
		//只存在除法运算
			vector<unsigned int> temp(allSign);
			aim = min(divSign);
			if(min(divSign) == min(allSign) && min(divSign) == max(allSign))	//只有一个运算且为除法运算	
			{
				c = c + bra_twoC(a,min(divSign));
			}
			else if(min(divSign) == min(allSign))
			{
				if(a[0] != '/')
					begin = 0;
				else
					cout<<"输入格式有误，/不能放表达式首位!"<<endl;
				end = getBig(temp,aim);
				string sub_str;
				sub_str = a.substr(begin,end - begin);
				c = c + bra_twoC(sub_str,min(divSign));
				if(c.real == 0 && c.imag == 0)
				{
					stringstream stream;
					stream<<'0';
					stream>>sub_str;
				}
				else if(c.real == 0)
				{
					stringstream stream;
					stream<<'('<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				else if(c.imag == 0)
				{
					stringstream stream;
					stream<<'('<<c.real<<')';
					stream>>sub_str;
				}
				else 
				{
					stringstream stream;
					string e;
					if(c.imag < 0)
						e = "";
					else
						e = '+';
					stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
					stream>>sub_str;
				}
				a.replace(begin,end,sub_str);
				c = computeStr(a);

		}
		else if(min(divSign) == max(allSign))
		{
			if(a[a.length()-1] != '/')
				end = a.length()-1;
			else
				cout<<"输入格式有误，/不能放表达式末位!"<<endl;
			begin = getSmall(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin+1);
			c = c + bra_twoC(sub_str,min(divSign)-begin-1);
			if(c.real == 0 && c.imag == 0)
			{
				stringstream stream;
				stream<<'0';
				stream>>sub_str;
			}
			else if(c.real == 0)
			{
				stringstream stream;
				stream<<'('<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<'('<<c.real<<')';
				stream>>sub_str;
			}
			else 
			{
				stringstream stream;
				string e;
				if(c.imag < 0)
				e = "";
				else
					e = '+';
				stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			a.replace(begin+1,end,sub_str);
			c = computeStr(a);
		}
		else 
		{
			begin = getSmall(temp,aim);
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin-1);
			c = c + bra_twoC(sub_str,min(divSign)-begin-1);
			if(c.real == 0 && c.imag == 0)
			{
				stringstream stream;
				stream<<'0';
				stream>>sub_str;
			}
			else if(c.real == 0)
			{
				stringstream stream;
				stream<<'('<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<'('<<c.real<<')';
				stream>>sub_str;
			}
			else 
			{
				stringstream stream;
				string e;
				if(c.imag < 0)
					e = "";
				else
					e = '+';
				stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin - 1,sub_str);
			c = computeStr(a);
		}
	}
	else if(timesSign.size() != 0 && divSign.size() != 0)
	{
		//存在乘法与除法运算
		vector<unsigned int> temp(allSign);
		aim = min(divSign) > min(timesSign)?min(timesSign):min(divSign);
		if(aim == min(temp))
		{
			begin = 0;
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin,end - begin);
			c = c + bra_twoC(sub_str,(aim));
			if(c.real == 0 && c.imag == 0)
			{
				stringstream stream;
				stream<<'0';
				stream>>sub_str;
			}
			else if(c.real == 0)
			{
				stringstream stream;
				stream<<'('<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<'('<<c.real<<')';
				stream>>sub_str;
			}
			else 
			{
				stringstream stream;
				string e;
				if(c.imag < 0)
					e = "";
				else
					e = '+';
				stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			a.replace(begin,end,sub_str);
			c = computeStr(a);
		}
		else
		{
			begin = getSmall(temp,aim);
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin-1);
			c = c + bra_twoC(sub_str,aim-begin-1);
			if(c.real == 0 && c.imag == 0)
			{
				stringstream stream;
				stream<<'0';
				stream>>sub_str;
			}
			else if(c.real == 0)
			{
				stringstream stream;
				stream<<'('<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<'('<<c.real<<')';
				stream>>sub_str;
			}
			else 
			{
				stringstream stream;
				string e;
				if(c.imag < 0)
					e = "";
				else
					e = '+';
				stream<<'('<<c.real<<e<<c.imag<<'i'<<')';
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin - 1,sub_str);
			c =computeStr(a);
		}
	}
	}
	return c;
}
bool isBE(string s)				//检测是否含有首尾括号
{
	int i,j = 0,l;
	char  token[2] = {'+','-'};
	l = s.length();
	if(s[0] == '(' && s[l-1] == ')')
	{
		for(i = 1;i < l-1;i++)
		{
			if(s[i] == '(')
			{
				token[j] = '+';
				j++;
				if(j == 2)
					j = 0;
			}
				
			else if(s[i] == ')')
			{
				token[j] = '-';
				j++;
				if(j == 2)
					j = 0;
			}
		}
	}
	else
		return false;
	if(token[0] == '+' && token[1] == '-')
		return true;
	else 
		return false;
}
Complex compute(string &a)
{
	unsigned int min(vector<unsigned int> vec);
	unsigned int max(vector<unsigned int> vec);
	unsigned int getSmall(vector<unsigned int> vec,unsigned int aim);
	unsigned int getBig(vector<unsigned int> vec,unsigned int aim);
	Complex twoC(string s,char ch);
	Complex c(0,0);
	vector<unsigned int> addSign;
	vector<unsigned int> minusSign;
	vector<unsigned int> timesSign;
	vector<unsigned int> divSign;
	vector<unsigned int> allSign;
	size_t aim;
	size_t begin;
	size_t end;
	size_t mid;
	mid = 0;
	int i;
	for(i = 0;i < a.length();i++)
	{
		if(a[i] == '+' && a[i+1] == '+')
		{
			a.replace(i,1,"");
			break;
		}
		else if(a[i] == '+' && a[i+1] == '-')
		{
			a.replace(i,1,"");
			break;
		}
		else if(a[i] == '-' && a[i+1] == '+')
		{
			a.replace(i+1,1,"");
			break;
		}
		else if(a[i] == '-' && a[i+1] == '-')
		{
			a.replace(i,2,"+");
			break;
		}
	}
	i = 0;
	while((aim = a.find("+",mid)) != string::npos)
	{
		addSign.push_back(aim);
		allSign.push_back(aim);
		mid = aim + 1;
		i++;
	}
	i = 0;
	mid = 0;
	while((aim = a.find("-",mid)) != string::npos)
	{
		minusSign.push_back(aim);
		allSign.push_back(aim);
		mid = aim + 1;
		i++;
	}
	i = 0;
	mid = 0;
	while((aim = a.find("*",mid)) != string::npos)
	{
		timesSign.push_back(aim);
		allSign.push_back(aim);
		mid = aim + 1;
		i++;
	}
	i = 0;
	mid = 0;
	while((aim = a.find("/",mid)) != string::npos)
	{
		divSign.push_back(aim);
		allSign.push_back(aim);
		mid = aim + 1;
		i++;
	}
	if(allSign.size() == 0)
	{
		//纯实数或虚数
			return (c + a);
	}
	else if(timesSign.size() == 0 && divSign.size() == 0)
	{
		//只有加减法运算;
		if(allSign.size() == 1 && allSign[0] == 0)	//+,-号位于首字符
		{
			return (c + a);
		}
		else if(allSign.size() == 1 && allSign[0] != 0 )//仅含一个+ 或 - 且不为首
		{
			c = c + twoC(a,a.at(allSign[0]));
		}
		else if(allSign.size() >= 2 && min(allSign) == 0)//含两个加减号且一个位于首字符处
		{
			vector<unsigned int> cp_allSign(allSign);
			for(i = 0;i < cp_allSign.size();i++)
			{
				if(min(allSign) == cp_allSign[i])
				{
					cp_allSign.erase(cp_allSign.begin() + i);
					break;
				}
			}
			string left,right;
			left = a.substr(0,min(cp_allSign));
			right = a.substr(min(cp_allSign));
			c = c + left + compute(right);
		}
		else if(allSign.size() >= 2 && min(allSign) != 0)
		{
			vector<unsigned int> cp_allSign(allSign);
			for(i = 0;i < cp_allSign.size();i++)
			{
				if(min(allSign) == cp_allSign[i])
				{
					cp_allSign.erase(cp_allSign.begin() + i);
					break;
				}
			}
			string left,right;
			left = a.substr(0,min(allSign));
			right = a.substr(min(allSign));
			c = c + left + compute(right);
		}

	}
	else if(timesSign.size() != 0 && divSign.size() == 0)
	{
		//只存在乘法运算
		vector<unsigned int> temp(allSign);
		aim = min(timesSign);
		if(min(timesSign) == min(allSign) && min(timesSign) == max(allSign))	//只有一个运算且为乘法运算	
		{
			c = c + twoC(a,'*');
		}
		else if(min(timesSign) == min(allSign))
		{
			if(a[0] != '*')
				begin = 0;
			else
				cout<<"输入格式有误，*不能放表达式首位!"<<endl;
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin,end - begin);
			c = c + twoC(sub_str,'*');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin,end,sub_str);
			c = compute(a);

		}
		else if(min(timesSign) == max(allSign))
		{
			if(a[a.length()-1] != '*')
				end = a.length()-1;
			else
				cout<<"输入格式有误，*不能放表达式末位!"<<endl;
			begin = getSmall(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin+1);
			c = c + twoC(sub_str,'*');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin + 1,sub_str);
			c = compute(a);
		}
		else 
		{
			begin = getSmall(temp,aim);
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin-1);
			c = c + twoC(sub_str,'*');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin - 1,sub_str);
			c = compute(a);
		}

	}
	else if(timesSign.size() == 0 && divSign.size() != 0)
	{
		//只存在除法运算
		vector<unsigned int> temp(allSign);
		aim = min(divSign);
		if(min(divSign) == min(allSign) && min(divSign) == max(allSign))	//只有一个运算且为除法运算	
		{
			c = c + twoC(a,'/');
		}
		else if(min(divSign) == min(allSign))
		{
			if(a[0] != '/')
				begin = 0;
			else
				cout<<"输入格式有误，/不能放表达式首位!"<<endl;
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin,end - begin);
			c = c + twoC(sub_str,'/');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin,end,sub_str);
			c = compute(a);

		}
		else if(min(divSign) == max(allSign))
		{
			if(a[a.length()-1] != '/')
				end = a.length()-1;
			else
				cout<<"输入格式有误，/不能放表达式末位!"<<endl;
			begin = getSmall(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin+1);
			c = c + twoC(sub_str,'/');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin + 1,sub_str);
			c = compute(a);
		}
		else 
		{
			begin = getSmall(temp,aim);
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin-1);
			c = c + twoC(sub_str,'/');
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin - 1,sub_str);
			c = compute(a);
		}
	}
	else if(timesSign.size() != 0 && divSign.size() != 0)
	{
		//存在乘法与除法运算
		vector<unsigned int> temp(allSign);
		aim = min(divSign) > min(timesSign)?min(timesSign):min(divSign);
		if(aim == min(temp))
		{
			begin = 0;
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin,end - begin);
			c = c + twoC(sub_str,a.at(aim));
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin,end,sub_str);
			c = compute(a);
		}
		else
		{
			begin = getSmall(temp,aim);
			end = getBig(temp,aim);
			string sub_str;
			sub_str = a.substr(begin+1,end - begin-1);
			c = c + twoC(sub_str,a.at(aim));
			if(c.real == 0)
			{
				stringstream stream;
				stream<<c.imag<<'i';
				stream>>sub_str;
			}
			else if(c.imag == 0)
			{
				stringstream stream;
				stream<<c.real;
				stream>>sub_str;
			}
			a.replace(begin + 1,end - begin - 1,sub_str);
			c = compute(a);
		}
	}
	return c;
}
//获得容器中最小的数
unsigned int min(vector<unsigned int> vec)
{
	int i,l;
	int min;
	min = vec[0];
	l = vec.size();
	for(i = 1;i < l;i++)
		if(vec[i] < min)
			min = vec[i];
	return (unsigned)min;
}
//获得容器中最大的数
unsigned int max(vector<unsigned int> vec)
{
	int i,l;
	int max;
	max = vec[0];
	l = vec.size();
	for(i = 1;i < l;i++)
		if(vec[i] > max)
			max = vec[i];
	return (unsigned)max;
}
//从容器vec 中获得小于aim 离 aim 最近的数
unsigned int getSmall(vector<unsigned int> vec,unsigned int aim)
{
	int i,j;
	int t = -1000;
	unsigned int small;
	for(i = 0;i < vec.size();i++)
	{
		j = vec[i] - (int)aim;
		if(j < 0)
			if(j > t)
			{
				t = j;
				small = i;
			}
	}
	return vec[small];
}
//从容器vec 中获得大于aim 离 aim 最近的数
unsigned int getBig(vector<unsigned int> vec,unsigned int aim)
{
	int i,j;
	int t = 1000;
	unsigned int small;
	for(i = 0;i < vec.size();i++)
	{
		j = vec[i] - (int)aim;
		if(j > 0)
			if(j < t)
			{
				t = j;
				small = i;
			}
	}
	return vec[small];
}
//处理运算符为 ch 的字符串，无括号
Complex twoC(string s,char ch)
{
	size_t pos;
	string s1,s2;
	Complex c(0,0);
	pos = s.find(ch,1);
	s1 = s.substr(0,pos);
	c = c + s1;
	s2 = s.substr(pos + 1);
	if(ch == '+')
		c = c + s2;
	else if(ch == '-')
		c = c - s2;
	else if(ch == '*')
		c =  c * s2;
	else
		c = c/s2;
	return c;
}
//判断是否在拓号外，num为指定位置 
bool is_out_bra(unsigned int num,string s)
{
	int i,l;
	l = s.length();
	int token = 0;
	for(i = 0;i <= num;i++)
	{
		if(s[i] == '(')
			token++;
		else if(s[i] == ')')
			token--;
	}
	if(token == 0)
		return true;
	else 
		return false;
}
//处理m处对应运算符的字符串
Complex bra_twoC(string s,unsigned int m)
{
	string s1,s2;
	char ch = s[m];
	Complex c(0,0);
	s1 = s.substr(0,m);
	
	if(s1.at(0) == '(')
	{
		s1.replace(0,1,"");
		s1.replace(s1.length()-1,1,"");
	}
	s2 = s.substr(m + 1);
	if(s2[0] == '(')
	{
		s2.replace(0,1,"");
		s2.replace(s2.length()-1,1,"");
	}
	if(ch == '+')
		c = Comp::computeStr(s1) + Comp::computeStr(s2);
	else if(ch == '-')
		c = Comp::computeStr(s1) - Comp::computeStr(s2);
	else if(ch == '*')
		c =  Comp::computeStr(s1) * Comp::computeStr(s2);
	else
		c = Comp::computeStr(s1) / Comp::computeStr(s2);
	return c;
}

