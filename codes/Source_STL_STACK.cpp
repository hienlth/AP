#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stack>
#define MAX 100
using namespace std;

bool Ktra(char* s)
{
	stack<char> st;
	int n = strlen(s);
	for(int i=0; i<n; i++)
	{
		if(s[i]=='{' || s[i]=='(' || s[i]=='[')
			st.push(s[i]);
		else if(s[i]=='}')
		{
			if(st.top()!='{') return false;
			st.pop();
		}
		else if(s[i]==')')
		{
			if(st.top()!='(') return false;
			st.pop();
		}
		else if(s[i]==']')
		{
			if(st.top()!='[') return false;
			st.pop();
		}
		else;
	}
	return true;
}

int Fibo(int n)
{
	stack<int> st;
	int i;
	int f1, f2;
	st.push(1);
	st.push(1);
	i=2;
	while(i<=n)
	{
		//lấy f(n-1) và f(n-2)
		f1 = st.top();
		st.pop();
		f2 = st.top();
		st.pop();
		//đưa vào stack các giá trị f(n-1) và f(n)
		st.push(f1);
		st.push(f1+f2);
		i++;
	}
	return st.top();
}

void main()
{	
	/*char s[MAX+1];
	cout<<"Nhap chuoi: ";
	gets(s);
	if(Ktra(s)) cout<<"Hop le"<<endl;
	else cout<<"Khong hop le"<<endl;*/
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"So Fibonaci thu "<<n<<" la: "<<Fibo(n)<<endl;
}