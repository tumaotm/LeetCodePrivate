/*
  #include "iostream"
  #include <string>
  #include <vector>
  #include <stdlib.h>
  #include <sstream>
  #include <stack>
 // 
 // 
 // using namespace std;
 // using namespace string;
 // 
 // 
 // int evalRPN(vector <string> &tokens)
 // {
 // 	int results=0;
 // 
 // 	stack<int> s;
 // 	string operators = "+-* /";
 // 	int a = 0;
 // 	int b = 0;
 // 
 // 	for (int i=0; i<tokens.size();i++)
 // 	{	
 // 		char x=tokens[i];
 // 		if ((x == "+")||(x=="-")||(x=="*")||(x=="/"))
 // 		{
 // 			int a = s.top();
 // 			s.pop();
 // 			int b = s.top();
 // 			s.pop();
 // 			switch(x){
 // 				case '+': s.push(a+b); break;
 // 				case '-'; s.push(b-a); break;
 // 				case '*': s.push(b*a); break;
 // 				case '/': s.push(b/a); break;
 // 			}
 // 		else
 // 		{
 // 			s.push(int(x));
 // 
 // 		}
 // 		}
 // 		
 // 	}
 // 	if(s.size()){
 // 		int results = int (s.top());
 // 		while (s.size())
 // 		{
 // 			s.pop();
 // 		}
 // 	}
 // 	return results;
 // 
 // }
 
 
 
 class Solution {
 public:
 	int evalRPN(vector<string> &tokens) {
  		stack<int> nums;
  		int len = tokens.size();
  		for (int i = 0; i < len; i ++) {             
 			string x = tokens[i];             
 			if ((x == "+") || (x == "-") || (x == "*") || (x == "/")) {                 
 				// pop two numbers off the stack                 
  				int a = nums.top();                 
  				nums.pop();                 
  				int b = nums.top();                 
  				nums.pop();                 
  				// evaluate and push the result back                 
  				switch (x[0]) {                     
  								case '+': nums.push(a + b); break;                     
  								case '-': nums.push(b - a); break;                     
 								case '*': nums.push(b * a); break;                     
  								case '/': nums.push(b / a); break;                 
  				}             
  			} else { // push a number into the stack                 
  				int n;                 
  				istringstream(x) >> n;
  				nums.push(n);
  			}
  		}
  		if (nums.size()) {
 			 			int xx = nums.top();
  			while (nums.size()) {
  				nums.pop();
  			}
  			return xx;
  		}
  		return 0;
  	}
  };*/
 