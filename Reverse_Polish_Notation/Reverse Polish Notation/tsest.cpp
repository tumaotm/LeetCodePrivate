/*
	public class Solution {
		public int evalRPN(String[] tokens) {
			int returnValue = 0;
	
			String operators = "+-* /";
			Stack<String> stack = new Stack<String>();
	
			for(int t=0; t<tokens.length; t++){
				if(!operators.contains(tokens[t])){
					stack.push(tokens[t]);
				}
				else{
					int a = Integer.valueOf(stack.pop());
					int b = Integer.valueOf(stack.pop());
					int opear = operators.indexOf(tokens[t]);
					switch(opear){
					case 0:
						stack.push(String.valueOf(a+b));
						break;
					case 1:
						stack.push(String.valueOf(b-a));
						break;
					case 2:
						stack.push(String.valueOf(b*a));
					case 3:
						if (a!=0)    
						{stack.push(String.valueOf(b/a));}
						else
						{
							a+=1;
							stack.push(String.valueOf(b/a));
						}
					}
				}
				returnValue = Integer.valueOf(stack.pop());
	
				return returnValue;
			}
		}*/
	