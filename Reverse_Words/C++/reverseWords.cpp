#include <iostream>
#include "string"
using namespace std;

void reverseStr(string &s, int start, int end){
	int i = start;
	int j = end;
	while(i<j)
	{
		swap(s[i],s[j]);
		i++;
		j--;
	}
}

void reverseStr(string &s){
	reverseStr(s,0,s.size()-1);
}

void reverseWords(string &s){
	reverseStr(s);
	int start = 0;
	int end = 0;
	int i = 0;
	while (s.size()>0&&s[0]==' ')
	{
		s.erase(0,1); //Erases part of the string, reducing its length
	}
	s +=' ';
	
	for (i=0;i< s.size();++i) //For a for loop, either works. ++i seems more common, perhaps because that is what is used in K&R.
	{
		if (s[i]!=' ')
		{
			end++;
		}
		while(s[i]==' '&& i<s.size()-1 && s[i+1]==' ')
		{	
			s.erase(i,1);
		}
		if (s[i] == ' ')
		{
		
			if (end>start)
			{
				reverseStr(s,start,end-1);
				start = end +1;
				end = start;
			}
		}
		
	}

	s.erase(s.size()-1,1);

	cout<<s<<endl;
}

void main ()
{
	string s = "Hello world  hi! ";
		reverseWords(s);
	cout<<s<<endl;	
}