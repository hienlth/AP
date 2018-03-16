//viet chuong trinh quan ly tap tin nhi phan de luu DSHS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX 50
#define eps 0.00001

struct HS{
	char mhs[11];
	char hoten[51];
	int ns;
	char qq[101];
	double toan, ly, hoa;
};

int GhiDSHS(HS* arr, int n, char* fname);
int DocDSHS(HS* arr, int *n, char* fname);

int DocDSHS2(HS* arr, int *n, char* fname);

//Doc thong tin cua HS thu vt trong tap tin
int DocDSHS_VT(HS *arr, int vt, char* fname);

void NhapHS(HS* arr);
void NhapDSHS(HS* arr, int *n);
void XuatHS(HS arr);
void XuatDSHS(HS* arr, int n);

//tinh dien trung binh
double DTB(HS a);
//tim hs co que quan duoc chi dinh
int ViTriHS_QQ(char* fname, char* qq);

//xuat ds hoc sinh co DTB cao nhat
void XuatHS_DTBCaoNhat(HS *arr, int n);

//tao tap tin danh sach HS ROT va DAU
int GhiDSHS_ROT_DAU(HS *arr, int n, char* fname1, char* fname2);

//tìm HS có quê quán được chỉ định và thay thế quê quán mới
void SuaQuequan(char* fname, char* qq, char* qq_moi);

char menu()
{
	system("cls");
	printf("DANH SACH LUA CHON:\n");
	printf("1. Nhap DSHS (tu keyboard)\n");
	printf("2. Nhap DSHS (tu file)\n");
	printf("3. Xuat DSHS\n");
	printf("4. Xuat DSHS co DTB cao nhat\n");
	printf("5. Doc thong tin HS tai vi tri chi dinh\n");
	printf("6. Xuat thong tin HS theo que quan\n");
	//...
	printf("0. Thoat chuong trinh\n");
	
	return _getch();
}

void main()
{
	HS arr[MAX];
	int n;
	char fname[MAX+1];
	HS tam;
	//xuat danh sach lua chon
	while(1)
	{
		switch(menu())
		{
		case '1':
			system("cls");
			NhapDSHS(arr,&n);
			break;
		case '2':
			system("cls");
			printf("Nhap ten tap tin: ");
			gets_s(fname);
			if(DocDSHS2(arr,&n,fname)==-1)
			{
				printf("Hay dung chuc nang Nhap DSHS (tu keyboard)!\n");
			}
			else
			{
				printf("Doc tap tin thanh cong!\n");
			}
			break;
		case '3':
			system("cls");
			XuatDSHS(arr,n);
			break;
		case '4':
			system("cls");
			XuatHS_DTBCaoNhat(arr,n);
			break;
		case '5':
			system("cls");
			printf("Nhap ten tap tin: ");
			gets_s(fname);
			printf("Nhap vi tri HS muon lay thong tin: ");
			int vt;
			scanf_s("%d",&vt);
			fflush(stdin);
			
			DocDSHS_VT(&tam,vt,fname);
			printf("Thong tin HS thu %d la:\n",vt);
			XuatHS(tam);
			break;
		case '6':
			system("cls");
			char qq[MAX+1];
			printf("Nhap ten tap tin: ");
			gets_s(fname);
			printf("Nhap que quan: ");
			gets_s(qq);			
			DocDSHS_VT(&tam,ViTriHS_QQ(fname,qq),fname);
			XuatHS(tam);
			break;
		default:
			printf("Ket thuc chuong trinh!\n");
		}
		system("pause");
	}
	
}

int GhiDSHS(HS* arr, int n, char* fname)
{
	//B1: mo tap tin
	FILE* fp;
	fopen_s(&fp,fname,"wb");
	//B2: thao tac
	int kq=fwrite(arr,sizeof(HS),n,fp);

	//B3: dong tap tin
	fclose(fp);

	return kq;
}

int DocDSHS(HS* arr, int *n, char* fname)
{
	//B1: mo tap tin
	FILE* fp;
	fopen_s(&fp,fname,"rb");
	//kiem tra tap tin
	if(fp==NULL)
	{
		printf("Tap tin khong ton tai!\n");
		return -1;
	}

	//B2: thao tac
	//doc lan luot thong tin cua tung HS trong ds
	*n=0;
	while(!feof(fp))
	{
		//doc thong tin cua 1 HS de luu xuong bo nho
		HS tam;
		//doc thong tin cua 1 HS va luu vao bien tam
		if(fread(&tam,sizeof(HS),1,fp)==1)
		{
			//gan gia tri cua bien tam vao phan tu mang
			arr[*n]=tam;
			//tang so luong phan tu mang
			(*n)++;
		}
	}

	//B3: dong tap tin
	fclose(fp);
	//tra ve so luong HS doc duoc
	return *n;
}

int DocDSHS2(HS* arr, int *n, char* fname)
{
	//B1: mo tap tin
	FILE* fp;
	fopen_s(&fp,fname,"rb");
	//kiem tra tap tin
	if(fp==NULL)
	{
		printf("Tap tin khong ton tai!\n");
		return -1;
	}

	//B2: thao tac
	//doc lan luot thong tin cua tung HS trong ds
	*n=0;
	while(!feof(fp))
	{
		//doc thong tin cua 1 HS de luu xuong bo nho
		HS tam;

		//neu doc den hoc sinh thu 2, thi quay ve dau tap tin
		if(*n==2)
		{
			//dua con tro tap tin ve vi tri dau tien trong tap tin
			rewind(fp);
		}
		//doc thong tin cua 1 HS va luu vao bien tam
		if(fread(&tam,sizeof(HS),1,fp)==1)
		{
			printf("Vi tri con tro tap tin la %ld\n",ftell(fp));
			//gan gia tri cua bien tam vao phan tu mang
			arr[*n]=tam;
			//tang so luong phan tu mang
			(*n)++;
		}
	}

	//B3: dong tap tin
	fclose(fp);
	//tra ve so luong HS doc duoc
	return *n;
}

//Doc thong tin cua HS thu vt trong tap tin
int DocDSHS_VT(HS *arr, int vt, char* fname)
{
	//B1: mo tap tin
	FILE* fp;
	fopen_s(&fp,fname, "rb");
	if(fp==NULL)
	{
		printf("Tap tin khong ton tai!\n");
		return -1;
	}
	//B2: thao tac
	//di chuyen con tro tap tin den vi tri luu thong tin cua HS thu vt trong tap tin
	fseek(fp,vt*sizeof(HS),SEEK_SET);
	//doc thong tin ngay tai vi tri con tro tap tin
	if(fread(arr,sizeof(HS),1,fp)==1)
	{
		//B3: dong tap tin
		fclose(fp);
		return 1;
	}
	else
	{
		//B3: dong tap tin
		fclose(fp);
		return -1;
	}		
}

void NhapHS(HS* arr)
{
	printf("Nhap thong tin HS:\n");
	printf("Ma HS: ");
	gets_s(arr->mhs);
	printf("Ho ten: ");
	gets_s(arr->hoten);
	printf("Nam sinh: ");
	scanf_s("%d",&arr->ns);
	fflush(stdin);
	printf("Que quan: ");
	gets_s(arr->qq);
	printf("Diem Toan - Ly - Hoa: ");
	scanf_s("%lf%lf%lf",&arr->toan,&arr->ly,&arr->hoa);
	fflush(stdin);
}

void NhapDSHS(HS* arr, int *n)
{
	printf("Nhap so luong HS: ");
	scanf_s("%d",n);
	fflush(stdin);
	printf("Nhap danh sach HS\n");
	for(int i=0; i<*n; i++)
	{
		NhapHS(&arr[i]);
	}

	printf("Luu tap tin??? (Y|N)\n");
	char chon=_getch();

	if(chon=='Y' || chon=='y')
	{
		char fname[MAX+1];
		fflush(stdin);
		printf("Nhap ten tap tin: ");
		gets_s(fname);
		int kq=GhiDSHS(arr,*n, fname);
		if(kq>0)
		{
			printf("Ghi tap tin thanh cong!\n");
		}
		else
		{
			printf("Ghi tap tin that bai!\n");
		}
	}
}

void XuatHS(HS arr)
{
	printf("Thong tin HS:\n");
	printf("Ma hs: %s\n",arr.mhs);
	printf("Ho ten: %s\n",arr.hoten);
	printf("Nam sinh: %d\n",arr.ns);
	printf("Que quan: %s\n",arr.qq);
	printf("Diem Toan: %5.2lf - Ly: %5.2lf - Hoa: %5.2lf\n",arr.toan,arr.ly,arr.hoa);
}

void XuatDSHS(HS* arr, int n)
{
	printf("Xuat DSHS\n");
	for(int i=0; i<n; i++)
	{
		printf("\n---------%d---------\n",i);
		XuatHS(arr[i]);
	}
	
}

//tinh dien trung binh
double DTB(HS a)
{
	return (a.toan+a.ly+a.hoa)/3;
}

//xuat ds hoc sinh co DTB cao nhat
void XuatHS_DTBCaoNhat(HS *arr, int n)
{
	printf("Cac HS co DTB cao nhat la: \n");
	//tim DTB cao nhat
	double dtb_max=DTB(arr[0]);

	for(int i=0; i<n; i++)
	{
		if(dtb_max<DTB(arr[i]))
		{
			dtb_max=DTB(arr[i]);
		}
	}

	//liet ke cac hs co DTB == dtb_max
	for(int i=0; i<n; i++)
	{
		//neu do chenh lech giua 2 so thuc la rat nho, thi ta xem nhu 2 so bang nhau
		if(fabs(DTB(arr[i])-dtb_max)<=eps)
		{
			XuatHS(arr[i]);
		}
	}
}

//tao tap tin danh sach HS ROT va DAU
int GhiDSHS_ROT_DAU(HS *arr, int n, char* fname1, char* fname2)
{
	//B1: mo tap tin
	FILE* fp1;
	fopen_s(&fp1,fname1, "wb");
	FILE* fp2;
	fopen_s(&fp2,fname2, "wb");

	if(fp1 == NULL)
	{
		return -1;
	}
	if(fp2 == NULL)
	{
		return -2;
	}

	//B2: thao tac
	//duyet DSHS de loc ra nhung HS rot hoac dau
	for(int i=0; i<n; i++)
	{
		if(DTB(arr[i])>=5)
		{
			//ghi ra tap tin bao gom cac HS dau
			fwrite(&arr[i],sizeof(HS),1,fp1);
		}
		else
		{
			//ghi ra tap tin bao gom cac HS rot
			fwrite(&arr[i],sizeof(HS),1,fp2);
		}
	}

	//B3: dong tap tin
	fclose(fp1);
	fclose(fp2);

	return 1;
}

//tim hs co que quan duoc chi dinh
int ViTriHS_QQ(char* fname, char* qq)
{
	//B1: mo tap tin de doc
	FILE* fp;
	fopen_s(&fp,fname,"rb");
	if(fp == NULL)
	{
		return -1;
	}
	//B2; thao tac
	//luu lai vi tri cua HS sap doc
	long cur;
	//doc lan luot tung HS tren tap tin
	while(!feof(fp))
	{
		cur=ftell(fp);	//luu lai vi tri con tron tap tin
		HS tam;	//bien HS tam de lay thong tin
		if(fread(&tam,sizeof(HS),1,fp)==1)
		{
			//kiem tra que quan co phu hop hay ko?
			//dung ham so sanh chuoi
			if(strcmp(qq,tam.qq)==0)
			{
				fclose(fp);
				return cur/sizeof(HS);
			}
		}
	}
	fclose(fp);
	return -1;
}
//tìm HS có quê quán được chỉ định và thay thế quê quán mới
void SuaQuequan(char* fname, char* qq, char* qq_moi)
{
	FILE* fp;
	fopen_s(&fp,fname,"r+b");

	int vt = ViTriHS_QQ(fname,qq);
	//đọc thông tin của hs tại vị trí vt trên tập tin
	HS tam;
	if(fread(&tam,sizeof(HS),1,fp)==1)
	{
		strcpy(tam.qq,qq_moi);	//sửa lại thông tin quê quán
		//cập nhật lại lên tập tin
		//di chuyển con trỏ tập tin đến đúng vị trí muốn sửa
		fseek(fp,vt*sizeof(HS),SEEK_SET);
		//ghi thông tin mới lên vị trí của con trỏ tập tin
		fwrite(&tam,sizeof(HS),1,fp);
		fclose(fp);
	}
	else
	{
		cout<<"Khong the doc tap tin"<<endl;
		fclose(fp);
		return;
	}	
}