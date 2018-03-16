/*
Bài tập về mảng 2 chiều sử dụng con trỏ cấp 2 (**)
1. Nhập mảng
2. Khởi tạo mảng ngẫu nhiên
3. Xuất mảng
4. Sắp xếp mảng 2 chiều (tăng/giảm)
5. Kiểm tra xem có phải ma trận đối xứng không?
*/
#include <iostream>
#include <iomanip>
using namespace std;
//Khai báo thư viện hàm
void NhapMang(int **&a, int m, int n);
void KhoiTao(int **&a, int m, int n);
void XuatMang(int **a, int m, int n);
void SapXepGiam(int **&a, int m, int n);
void SapXepTang(int **&a, int m, int n);

int main()
{
	int M, N;
	cout << "So dong: "; cin >> M;
	cout << "So cot: "; cin >> N;
	int **A = NULL;
	KhoiTao(A, M, N);
	XuatMang(A, M, N);
	//Sử dụng con trỏ hàm để sắp
	void(*pSort)(int**&, int, int);
	pSort = &SapXepGiam;
	pSort(A, M, N);
	cout << "Mang sau khi sap giam: " << endl;
	pSort = &SapXepTang;
	pSort(A, M, N);
	cout << "Mang sau khi sap tang: " << endl;
	XuatMang(A, M, N);
	system("pause");
	return 0;
}

//Định nghĩa hàm
void SapXepGiam(int **&a, int m, int n)
{
	//Chuyển mảng 2 chiều thành mảng 1 chiều
	int SoPT = m * n;
	//A[m][n] ---> B[m*n]
	//Phần tử A[i][j] ứng B[k] nào? k = i * n + j
	//Phần tử B[k] ứng với A[i][j], 
	//i = k / n, j = k %n
	//Sap xep dung InterchangeSort
	for (int i = 0; i < SoPT - 1; i++)
		for (int j = i + 1; j < SoPT; j++)
			if (a[j/n][j%n] > a[i/n][i%n])
				swap(a[i / n][i%n], a[j / n][j%n]);
}
void SapXepTang(int **&a, int m, int n)
{
	//Chuyển mảng 2 chiều thành mảng 1 chiều
	int SoPT = m * n;
	for (int i = 0; i < SoPT - 1; i++)
		for (int j = i + 1; j < SoPT; j++)
			if (a[j / n][j%n] < a[i / n][i%n])
				swap(a[i / n][i%n], a[j / n][j%n]);
}

void NhapMang(int **&a, int m, int n)
{
	a = new int*[m];//khởi tạo
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "Phan tu thu [" << i 
				<< "," << j << "] : ";
			cin >> a[i][j];
		}
	}
}
void KhoiTao(int **&a, int m, int n)
{
	srand(time_t(NULL));
	a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{			
			a[i][j] = rand() % 500 + 1;
		}
	}
}
void XuatMang(int **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(7) << a[i][j];
		cout << endl;
	}
}
