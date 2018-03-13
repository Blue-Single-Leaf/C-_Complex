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
		//���㸴�����ʽ
		Comp c;
		Complex c1;
		string str;
		str = c.getStr("\n\n��������Ҫ����ĸ������ʽ���� '=' �żӻس�����:");
		while(!c.checkStr(str))
		{
			str = c.getStr();
		}
		c1 = c.computeStr(str);
		cout<<"\n\n\t\t\t->�������� ";
		c1.display();
		cout<<"\n\n"<<endl;
		circle(disFunInfo());
	}
	else if(m == 2)
	{
		//���и����Ƚ�
		Comp c;
		string str;
		str = c.getStr("\n\n��������Ҫ�Ƚϵ�������������ʽ���м���>=,<=,==,!=����������������ʽ:");
		if(c.compare(str))
		{
			cout<<"\n\n\t\t\t->�ñȽϳ���";
		}
		else
		{
			cout<<"\n\n\t\t\t->�ñȽϲ�����";
		}
		cout<<"\n\n"<<endl;
		circle(disFunInfo());
	}
	else if(m == 3)
	{
		//���и�������
		Comp c;
		c.test();
		cout<<"\n\n"<<endl;
		dealF();
		circle(disFunInfo());
	}
	else if(m == 4)
	{
		//��ѯ���Լ�¼
		int w;
		cout<<"��ѯ��ʽ:    1.��ѯ��һ����ҵ��¼\t2.��ѯ���м�¼\n\n";
		cout<<"��������Ҫ��ѯ�ķ�ʽ��";
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
		//�����˳�
	}
	else if(m == 6)
	{
		cout<<"It is made by FranceYang!"<<endl;
		circle(disFunInfo());
	}
	else
	{
		cout<<"������������޷�����!"<<endl;
		circle(disFunInfo());
	}
}
Process::Process()
{
	cout<<"\n\n***************��ӭʹ�ø��������ģ�����!*********************\n\n"<<endl;
	userName = Comp::getStr("�������û�����");
	fstream outf;
	outf.open(FILENAME,ios::out|ios::app);
	outf<<"#"<<userName<<"#\t";
	outf.close();
}
void Process::disLogInfo()
{
	system("cls");
	cout<<"\n\n************************����������ģ�����*********************************\n";
	cout<<"\n�˳�����c++��ҵҪ���Ͻ��������䣬��Ҫ�����¼��㣺"<<endl;
	cout<<"\n\t->1.�û����԰�������д���ʽ����ȥ���и��ӵĸ������㣬���Դ���������ţ��� +��-��*��/�����,��������ı��ʽ��\n\t  �����������ڵ������."<<endl;
	cout<<"\n\t->2.�û����Ա�����ǰ���еĲ������ݲ�����ѡ���Եز鿴��һ�λ����м�¼."<<endl;
	cout<<"\n\t->3.�û����Կ��Խ��в��ѵ�����ѡ��С�����Ŀ���У������б��ʽ�������."<<endl;
	cout<<"\n\n**********************************************************************\n\n\n";
	cout<<"\t��ӭ����ϵͳ�����ĵ�¼�Ĵ���Ϊ��"<<logNum<<endl;
	cout<<"\n\n->";
	fstream out;
	out.open("userData.txt",ios::out|ios::app);
	out<<"�� "<<logNum<<" �ν���ϵͳ\n";
	out.close();
}
int Process::disFunInfo()
{
	int m;
	system("pause");
	system("cls");
	cout<<"\n\n************************����������ģ�����*********************************\n";
	cout<<"\n��ѡ�����²�����Ŀ֮һ��"<<endl;
	cout<<"\n\t->1.���и�������\t->2.���и����Ƚ�"<<endl;
	cout<<"\n\t->3.���Ѷȸ����������\t->4.�鿴���Լ�¼"<<endl;
	cout<<"\n\t->5.�����˳�\n\n"<<endl;
	cout<<"����������ѡ��";
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
		cout<<"����δ���в��ԣ�������ؼ�¼."<<endl;
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
		cerr<<"�ļ���ʧ��!"<<endl;
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
{				//���ﲢ��λ����m�����ף��ɹ��򷵻� true; ���� ���� false����ζ�Ÿ��ļ��������� m ��;
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
