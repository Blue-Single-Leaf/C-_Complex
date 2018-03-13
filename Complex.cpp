#include<iostream>
#include<sstream>
#include "string"
#include"Complex.h"
using namespace std;
Complex::Complex(int r,double i)
{
	real =(double) r;
	imag = i;
}
Complex::Complex(int r,int i)
{
	real =(double) r;
	imag =(double) i;
}
Complex::Complex(double r,double i)
{
	real = r;
	imag = i;
}
Complex::Complex(double r,int i)
{
	real = r;
	imag =(double) i;
}
Complex::Complex()
{
	real = 0;
	imag = 0;
}
string Complex::toStr()
{
	string str;
	if(real == 0 && imag != 0)
	{
		if(imag == 1)
		{
			str = " i";
		}
		else if(imag == -1)
		{
			str = " -i";
		}
		else
		{
			stringstream stream;
			stream<<" "<<imag<<"i";
			str = stream.str();
		}
	}
	else if(imag == 0)
	{
		stringstream stream;
		stream<<" "<<real;
		str = stream.str();
	}
	else if(imag > 0)
	{
		if(imag ==1)
		{
			stringstream stream;
			stream<<" "<<real<<"+"<<"i";
			str = stream.str();
		}
		else
		{
			stringstream stream;
			stream<<" "<<real<<"+"<<imag<<"i";
			str = stream.str();
		}
	}
	else
	{
		if(imag == 1)
		{
			stringstream stream;
			stream<<" "<<real<<"i";
			str = stream.str();
		}
		else if(imag == -1)
		{
			stringstream stream;
			stream<<" "<<real<<"-i";
			str = stream.str();
		}
		else
		{
			stringstream stream;
			stream<<" "<<real<<imag<<"i";
			str = stream.str();
		}
	}
	return str;
}
void Complex::display()
{
	if(real == 0 && imag != 0)
	{
		if(imag == 1)
		{
			cout<<"i";
		}
		else if(imag == -1)
		{
			cout<<"-i";
		}
		else
		{
			cout<<imag<<"i";
		}
	}
	else if(imag == 0)
		cout<<real;
	else if(imag > 0)
	{
		if(imag ==1)
		{
			cout<<" "<<real<<"+"<<"i";
		}
		else
		{
			cout<<" "<<real<<"+"<<imag<<"i";
		}
	}
	else
	{
		if(imag == 1)
		{
			cout<<" "<<real<<"i";
		}
		else if(imag == -1)
		{
			cout<<" "<<real<<"-i";
		}
		else
		{
			cout<<" "<<real<<imag<<"i";
		}
	}
}
bool operator>=(Complex c1,Complex c2)
{
	return ((c1.real*c1.real + c1.imag*c1.imag) >= (c2.real*c2.real + c2.imag*c2.imag));
}
bool operator<=(Complex c1,Complex c2)
{
	return ((c1.real*c1.real + c1.imag*c1.imag) <= (c2.real*c2.real + c2.imag*c2.imag));
}
bool operator==(Complex c1,Complex c2)
{
	return ((c1.real*c1.real + c1.imag*c1.imag) == (c2.real*c2.real + c2.imag*c2.imag));
}
bool operator!=(Complex c1,Complex c2)
{
	return ((c1.real*c1.real + c1.imag*c1.imag) != (c2.real*c2.real + c2.imag*c2.imag));
}
Complex operator+(int c1,Complex c2)
{
	Complex c;
	c.real = (double)c1 + c2.real;
	c.imag = c2.imag;
	return c;
}
Complex operator+(double c1,Complex c2)
{
	Complex c;
	c.real = (double)c1 + c2.real;
	c.imag = c2.imag;
	return c;
}
Complex operator+(Complex c2,int c1)
{
	Complex c;
	c.real = (double)c1 + c2.real;
	c.imag = c2.imag;
	return c;
}
Complex operator+(Complex c2,double c1)
{
	Complex c;
	c.real = (double)c1 + c2.real;
	c.imag = c2.imag;
	return c;
}
Complex operator+(Complex c1,Complex c2)
{
	Complex c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	return c;
}
Complex operator-(Complex c1,Complex c2)
{
	Complex c;
	c.real = c1.real - c2.real;
	c.imag = c1.imag - c2.imag;
	return c;
}
Complex operator*(Complex c3,Complex c2)
{
	Complex c;
	c.real = c3.real * c2.real - c3.imag * c2.imag;
	c.imag = c3.real * c2.imag + c3.imag * c2.real;
	return c;
}
Complex operator/(Complex c2,Complex c3)
{
	Complex c;
	int m = c3.real * c3.real + c3.imag * c3.imag;
	c.real = (c2.real * c3.real + c2.imag * c3.imag)/m;
	c.imag = (c2.imag * c3.real - c2.real * c3.imag)/m;
	return c;
}
Complex operator+(string c1,Complex c2)
{
	Complex c;
	stringstream stream;
	double num;
	if(c1.find("i") != string::npos)
	{
		c1 = c1.replace(c1.find("i"),1,"");
		stream << c1;
		stream >> num;
		c.real = c2.real;
		c.imag = c2.imag + num;
	}
	else 
	{
		stream << c1;
		stream >> num;
		c.real = c2.real + num;
		c.imag = c2.imag;
	}
	return c;
}
Complex operator+(Complex c2,string c1)
{
	Complex c;
	stringstream stream;
	double num;
	if(c1.find("i") != string::npos)
	{
		c1 = c1.replace(c1.find("i"),1,"");
		stream << c1;
		stream >> num;
		c.real = c2.real;
		c.imag = c2.imag + num;
	}
	else 
	{
		stream << c1;
		stream >> num;
		c.real = c2.real + num;
		c.imag = c2.imag;
	}

	return c;
}
Complex operator-(Complex c2,string c1)
{
	Complex c;
	stringstream stream;
	double num;
	if(c1.find("i") != string::npos)
	{
		c1 = c1.replace(c1.find("i"),1,"");
		stream << c1;
		stream >> num;
		c.real = c2.real;
		c.imag = c2.imag - num;
	}
	else 
	{
		stream << c1;
		stream >> num;
		c.real = c2.real - num;
		c.imag = c2.imag;
	}

	return c;
}
Complex operator*(Complex c2,string c1)
{
	Complex c;
	stringstream stream;
	double num;
	if(c1.find("i") != string::npos)
	{
		c1 = c1.replace(c1.find("i"),1,"");
		stream << c1;
		stream >> num;
		Complex c3(0,num);
		c.real = c3.real * c2.real - c3.imag * c2.imag;
		c.imag = c3.real * c2.imag + c3.imag * c2.real;
	}
	else 
	{
		stream << c1;
		stream >> num;
		Complex c3(num,0);
		c.real = c3.real * c2.real - c3.imag * c2.imag;
		c.imag = c3.real * c2.imag + c3.imag * c2.real;
	}

	return c;
}
Complex operator/(Complex c2,string c1)
{
	Complex c;
	stringstream stream;
	double num;
	if(c1.find("i") != string::npos)
	{
		c1 = c1.replace(c1.find("i"),1,"");
		stream << c1;
		stream >> num;
		Complex c3(0,num);
		if(c3.imag == 0)
		{
			cout<<"零不能做除数!"<<endl;
			c.real = -10000;
			c.imag = -10000;
		}
		else
		{
			int m = c3.real * c3.real + c3.imag * c3.imag;
			c.real = (c2.real * c3.real + c2.imag * c3.imag)/m;
			c.imag = (c2.imag * c3.real - c2.real * c3.imag)/m;
		}
	}
	else 
	{
		stream << c1;
		stream >> num;
		Complex c3(num,0);
		if(c3.real == 0)
		{
			cout<<"零不能做除数!"<<endl;
			c.real = -10000;
			c.imag = -10000;
		}
		else
		{
			int m = c3.real * c3.real + c3.imag * c3.imag;
			c.real = (c2.real * c3.real - c2.imag * c3.imag)/m;
			c.imag = (c2.imag * c3.real + c2.real * c3.imag)/m;
		}
	}

	return c;
}









