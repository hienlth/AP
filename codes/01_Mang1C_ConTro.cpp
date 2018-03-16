#include <iostream>
#include<iomanip>
using namespace std;


//Khai báo & định nghĩa hàm tạo mảng
void NhapMang(double *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Gia tri thu " << i << " : ";
		cin >> A[i];
	}
}
void KhoiTaoNN(double *A, int n)
{
	for (int i = 0; i < n; i++)
		A[i] = rand() % 151;//0 --> 150
}
void XuatMang(double *A, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(7) << A[i];
	cout << endl;
}

double tinhTrungBinh(double *a, int n)
{
	double kq = 0;
	for (int i = 0; i < n; i++)
		if(a[i] > 0)
			kq += a[i];
	return kq / n;
}

void InterchangeSortDesc(double *a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] > a[i])
				swap(a[i], a[j]);
}

int main()
{
	/*
	int a = 9;
	int *p = &a;
	cout << "&a = " << &a << ", p = " << p << endl;
	cout << "a = " << a << ", *p = " << *p << endl;
	*/
	int n;//so phan tu
	cout << "Nhap so phan tu: ";
	cin >> n;
	//khai bao mang
	double *B = new double[n];
	KhoiTaoNN(B, n);
	XuatMang(B, n);
	InterchangeSortDesc(B, n);
	XuatMang(B, n);
	delete []B;//xoa mang
	system("pause");
	return 0;
}