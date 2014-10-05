#include <iostream>

using namespace std;

class String
{
public:
	String():str(NULL){}
	const char *c_str(){return str;} // return value is const. Cannot revise the address of str.
	char * operator= (const char *s);
	~String();
protected:
private:
	char* str;
};

char* String::operator=(const char* s){
	if (str)
	{
		delete []str;
	}
	if(s)
	{
		str = new char[strlen(s)+1];
		strcpy(str,s);
	}
	else
		str = NULL;
	return str;
}

String::~String(){
	if(str)
		delete []str;
}

/*int main()
{
	String s;
	s = "Good Luck";
	cout<< s.c_str()<<endl;
	s = "Dalian !";
	cout<< s.c_str()<<endl;

	return 0;
}*/