#include<iostream>
#include<stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

struct SV{
	char hoten[51];
	float diem;
	char xeploai;	//A, B, C, D
};

typedef SV type;

struct NODE{
	type Info;
	NODE* pNext;
};

struct LIST{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode();	//hàm cấp phát vùng nhớ cho phần tử trong DSLK
void FreeNode(NODE* p);	//hàm hủy vùng nhớ của phần từ trong DSLK
//các thao tác trên DSLK
void Initialize(LIST& list);
bool isEmpty(LIST list);
int ListSize(LIST list);
NODE* NodePointer(LIST list, int pos);
int NodePosition(LIST list, NODE* p);
//thêm phần tử vao DSLK
void Push(LIST& list, type val);
void Push_back(LIST& list, type val);
void InsAfter(LIST& list, NODE* q, type val);
void Insert(LIST& list, type val, int pos);
//xóa phần tử khỏi DSLK
type Pop(LIST& list);
type Pop_back(LIST& list);
type DelAfter(LIST& list, NODE* q);
type Delete(LIST& list, int pos);
void Clear(LIST& list);

void NhapThongtin(SV& sv);
void Xeploai(SV& sv);
void XuatThongtin(SV sv);

void main()
{
	SV sv = {"Tran Van A",7,'A'};
	XuatThongtin(sv);
}

NODE* GetNode()
{
	return new NODE;
	//return (NODE*)malloc(sizeof(NODE));
}
void FreeNode(NODE* p)
{
	delete p;
	//free(p);
}
void Initialize(LIST& list)
{
	list.pHead = list.pTail = NULL;
}
bool isEmpty(LIST list)
{
	return (list.pHead == NULL && list.pTail == NULL);
}
int ListSize(LIST list)
{
	int count = 0;
	NODE* pNode;	//dùng để duyệt qua các phần tử trong DSLK
	pNode = list.pHead;
	while(pNode != NULL)
	{
		count++;
		pNode = pNode->pNext;	//di chuyển đến phần từ tiếp theo trong DSLK
	}
	return count;
}
NODE* NodePointer(LIST list, int pos)
{
	if(isEmpty(list) || pos < 0 || pos >= ListSize(list)) return NULL;
	NODE* pNode;
	pNode = list.pHead;
	int count = 0;
	while(count != pos && pNode != NULL)
	{
		pNode = pNode->pNext;
		count++;
	}
	return pNode;
}
int NodePosition(LIST list, NODE* p)
{
	if(isEmpty(list) || p == NULL) return NULL;
	NODE* pNode;
	pNode = list.pHead;
	int count = 0;
	while(pNode != p && pNode != NULL)
	{
		pNode = pNode->pNext;
		count++;
	}
	return count;
}
void Push(LIST& list, type val)
{
	NODE* pNode = GetNode();
	if(pNode == NULL) return;
	pNode->Info = val;
	pNode->pNext = NULL;
	if(isEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;	//nối phần tử mới vào phần tử đầu tiên trong DSLK
		list.pHead = pNode;	//cập nhật lại pHead
	}
}
void Push_back(LIST& list, type val)
{
	NODE* pNode = GetNode();
	if(pNode == NULL) return;
	pNode->Info = val;
	pNode->pNext = NULL;
	if(isEmpty(list))
		list.pHead = list.pTail = pNode;
	else
	{
		list.pTail->pNext = pNode;	//nối phần tử cuối của DSLK vào phần tử mới
		list.pHead = pNode;	//cập nhật lại pTail
	}
}
void InsAfter(LIST& list, NODE* q, type val)
{
	if(q == NULL)
	{
		Push(list,val);
		return;
	}
	NODE* pNode = GetNode();
	if(pNode == NULL) return;
	pNode->Info = val;
	pNode->pNext = NULL;

	pNode->pNext = q->pNext;	//nối phần tử mới vào phần tử đứng sau phần tử q
	q->pNext = pNode;	//nối phần tử q vào phần tử mới
}
void Insert(LIST& list, type val, int pos)
{
	if(pos < 0 || pos > ListSize(list)) return;
	InsAfter(list,NodePointer(list,pos-1),val);
}
type Pop(LIST& list)
{
	type val = {"",0,' '};	//SV voi thong tin mac dinh
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;		
	}
	else
	{	
		NODE* pNode = list.pHead;
		val = pNode->Info;
		if(list.pHead == list.pTail)
		{
			list.pHead = list.pTail = NULL;
		}
		else
		{
			list.pHead = pNode->pNext;	//cập nhật lại pHead
			pNode->pNext = NULL; //ngắt liên kết của phần tử bị xóa với phần tử khác
		}
		FreeNode(pNode);
	}
	return val;
}
type Pop_back(LIST& list)
{
	type val = {"",0,' '};	//SV voi thong tin mac dinh
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;		
	}
	else
	{
		NODE* pNode = list.pTail;
		val = pNode->Info;
		if(list.pHead == list.pTail)
		{
			list.pHead = list.pTail = NULL;
		}
		else
		{
			//tìm địa chỉ của phần tử đứng trước pNode
			NODE* q = list.pHead;
			while(q->pNext != pNode && q != NULL)
				q = q->pNext;
			list.pTail = q;
			q->pNext = NULL;
		}
		FreeNode(pNode);
	}
	return val;
}
type DelAfter(LIST& list, NODE* q)
{
	type val = {"",0,' '};	//SV voi thong tin mac dinh
	if(isEmpty(list) || q == list.pTail)
	{
		cout<<"Khong the xoa"<<endl;		
	}
	else
	{
		if(q == NULL) return Pop(list);		
		NODE* p = q->pNext;	//p là phần tử đứng sau phần tử q
		val = p->Info;
		if(p == list.pTail) return Pop_back(list);
		q->pNext = p->pNext;	//nối phần tử q vào phần tử đứng sau phần tử p
		p->pNext = NULL;
		FreeNode(p);
	}
	return val;
}
type Delete(LIST& list, int pos)
{
	type val = {"",0,' '};	//SV voi thong tin mac dinh
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;
	}
	else
		val = DelAfter(list,NodePointer(list,pos-1));	
	return val;
}
void Clear(LIST& list)
{
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;
	}
	else
	{
		while(!isEmpty(list))
			Pop(list);
	}
}

void NhapThongtin(SV& sv)
{
	fflush(stdin);	//xóa vùng nhớ đệm stdin
	cout<<"Ho ten: ";
	gets_s(sv.hoten);
	cout<<"Diem: ";
	cin>>sv.diem;
	Xeploai(sv);
}
void Xeploai(SV& sv)
{	
	//làm tròn điểm về số thực có 1 chữ số lẻ
	
	if(sv.diem<5.5) sv.xeploai='D';
	else if(sv.diem<=6.9) sv.xeploai='C';
	else if(sv.diem<=8.4) sv.xeploai='B';
	else sv.xeploai='A';
}
void XuatThongtin(SV sv)
{
	cout<<setw(-20);
	cout<<sv.hoten;
	cout<<setw(10);
	cout<<sv.diem;
	cout<<setw(20);
	switch(sv.xeploai)
	{
	case 'A':
		cout<<"Gioi";
		break;
	case 'B':
		cout<<"Kha";
		break;
	case 'C':
		cout<<"Trung binh";
		break;
	case 'D':
		cout<<"Khong dat";
	}
}