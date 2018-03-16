#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100

void DaonguocChuoi(char* s1, char* s2)
{
	//sao chép nội dung của s1 qua s2
	strcpy(s2,s1);
	int n = strlen(s2);
	//đảo ngược s2
	for(int i = 0; i<n/2; i++)
	{
		char c = s2[i];
		s2[i] = s2[n-i-1];
		s2[n-i-1] = c;
	}
}

void DaonguocTuTrongChuoi(char* s, int bd, int kt)
{
	int n = kt-bd;
	for(int i=0; i<n/2; i++)
	{
		char c = s[bd+i];
		s[bd+i] = s[bd+n-i-1];
		s[bd+n-i-1] = c;
	}
}

void DaonguocTu(char* s1, char* s2)
{
	//sao chép nội dung của s1 qua s2
	strcpy(s2,s1);
	int n = strlen(s2);
	int i;
	int bd, kt;
	for(i=0; i<=n; i++)
	{
		bd=i;
		//xác định vị trí kết thúc của 1 từ trong chuỗi
		while(s2[i]!=' ' && s2[i]!='\0')
			i++;
		kt=i;
		DaonguocTuTrongChuoi(s2,bd,kt);
	}
}

void XoaCuoi(char* s)
{
	int n = strlen(s);
	while(s[n-1]==' ')
	{
		s[n-1] = '\0';
		n = strlen(s);
	}
}
void XoaDau(char* s)
{	
	while(s[0]==' ')
	{
		strcpy(s,s+1);
	}
}
void XoaGiua(char* s)
{
	int n = strlen(s);
	for(int i=0; i<n-1; i++)
	{
		if(s[i]==' ' && s[i+1]==' ')
		{
			while(s[i+1]==' ')
			{
				strcpy(s+i,s+i+1);
			} 
		}
		n = strlen(s);
	}
}
void XoaKhoangtrangDu(char* s)
{
	XoaCuoi(s);
	XoaDau(s);
	XoaGiua(s);
}

bool KtraChuoiDoixung(char* s)
{
	char s2[MAX+1];
	DaonguocChuoi(s,s2);
	if(_stricmp(s,s2)==0) return true;
	else return false;
}

void TachTen(char* fullname, char* name)
{
	//tìm vị trí của khoảng trắng cuối cùng
	int i;
	for(i = strlen(fullname)-1; i>=0; i--)
	{
		if(fullname[i]==' ') break;
	}
	//tách tên
	strcpy(name,fullname+i+1);
}

void main()
{
	char s1[MAX+1];
	char s2[MAX+1];
	//nhập chuỗi
	printf("Nhap chuoi: ");
	gets(s1);
	cout<<"Xuat chuoi: "<<s1<<endl;
	/*DaonguocChuoi(s1,s2);
	cout<<"Xuatchuoi: "<<s2<<endl;*/
	/*DaonguocTu(s1,s2);
	cout<<"Xuatchuoi: "<<s2<<endl;*/
	/*XoaKhoangtrangDu(s1);
	cout<<"Xuat chuoi: "<<s1<<"|"<<endl;*/
	TachTen(s1,s2);
	cout<<"Xuat chuoi: "<<s2<<endl;
}