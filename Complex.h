#include<string>
//复数定义及运算符重载类
class Complex
{
public:
	Complex(double,double);
	Complex(int,double);
	Complex(double,int);
	Complex(int,int);
	Complex();
	friend Complex operator+(int,Complex);
	friend Complex operator+(double,Complex);
	friend Complex operator+(Complex,int);
	friend Complex operator+(Complex,double);
	friend Complex operator+(Complex,Complex);
	friend Complex operator-(Complex,Complex);
	friend Complex operator*(Complex,Complex);
	friend Complex operator/(Complex,Complex);
	friend Complex operator+(std::string,Complex);
	friend Complex operator+(Complex,std::string);
	friend Complex operator-(std::string,Complex);
	friend Complex operator-(Complex,std::string);
	friend Complex operator*(std::string,Complex);
	friend Complex operator*(Complex,std::string);
	friend Complex operator/(std::string,Complex);
	friend Complex operator/(Complex,std::string);
	friend bool operator >=(Complex,Complex);
	friend bool operator <=(Complex,Complex);
	friend bool operator !=(Complex,Complex);
	friend bool operator ==(Complex,Complex);
	void display();
	std::string toStr();
	double real;
	double imag;
};
