#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool isOperand(char c);
bool isOperator(char c);
int Priority(char opr);
void Convert2Postfix(char* infix, char* postfix);
int CalculatePostfix(char* postfix);

void main()
{
	char infix[51] = "1+2*3";
	char postfix[51];
	Convert2Postfix(infix,postfix);
	cout<<"Infix: "<<infix<<endl;
	cout<<"Postfix: "<<postfix<<endl;
	cout<<"Calculate: "<<CalculatePostfix(postfix)<<endl;
	system("pause");
}

bool isOperand(char c)
{
	return (c>='0' && c<='9');
}
bool isOperator(char c)
{
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='%');
}
int Priority(char opr)
{
	if(opr=='+' || opr=='-') return 1;
	if(opr=='*' || opr=='/' || opr=='%') return 2;
	return 0;
}
void Convert2Postfix(char* infix, char* postfix)
{
	stack<char> st;
	int len = strlen(infix);
	int i, k;
	for(i=0, k=0; i<len; i++)
	{
		if(isOperand(infix[i]))
		{
			postfix[k++] = infix[i];
		}
		else if(isOperator(infix[i]))
		{			
			if(!st.empty() && isOperator(st.top()) && Priority(infix[i])<=Priority(st.top()))
			{
				postfix[k++] = st.top();
				st.pop();
			}
			st.push(infix[i]);
		}
		else if(infix[i]=='(')
		{
			st.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(st.top()!='(')
			{
				postfix[k++]=st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			return;
		}
	}
	while(!st.empty())
	{
		postfix[k++]=st.top();
		st.pop();
	}
	postfix[k]='\0';
}

int CalculatePostfix(char* postfix)
{
	int i;
	int num1, num2;
	int len = strlen(postfix);	
	stack<int> st;
	for(i=0; i<len; i++)
	{
		if(isOperand(postfix[i]))
		{
			st.push(postfix[i]-'0');
		}
		else if(isOperator(postfix[i]))
		{
			num1=st.top();
			st.pop();
			num2=st.top();
			st.pop();
			switch(postfix[i])
			{
			case '+':
				st.push(num2+num1);
				break;
			case '-':
				st.push(num2-num1);
				break;
			case '*':
				st.push(num2*num1);
				break;
			case '/':
				st.push(num2/num1);
				break;
			case '%':
				st.push(num2%num1);
				break;
			}
		}
		else
		{
			return 0;
		}
	}
	return st.top();
}