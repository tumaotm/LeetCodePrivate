#include <iostream>

using namespace std;

class Complex{
public:
	Complex(double r=0.0,double m=0.0):real(r),imaginary(m){}
	Complex operator+ (const Complex &);
	Complex operator- (const Complex &);
public:
	double real;
	double imaginary;
};

Complex Complex::operator+(const Complex & operand2){
	return Complex(real+operand2.real,imaginary+operand2.imaginary);
}

Complex Complex::operator-(const Complex & operand2){
	return Complex(real-operand2.real, imaginary-operand2.imaginary);
}

/*int main()
{
	Complex x,y(4.3,5.7),z(3.3,1.1);
	x = y + z;
	cout<<x.real<<"+"<<x.imaginary<<"i"<<endl;
	x = y - z;
	cout<<x.real<<"+"<<x.imaginary<<"i"<<endl;
	return 0;
}*/