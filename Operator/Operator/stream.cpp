#include <iostream>



using namespace std;

class CStudent
{
public:
	int nAge;
};

ostream & operator<<(ostream & o, const CStudent & s)
{
	o<<s.nAge;
	return o;
}

/*int main()
{
	CStudent s;
	s.nAge = 5;
	cout<<s<<s.nAge<<"Hello"<<endl;
}*/