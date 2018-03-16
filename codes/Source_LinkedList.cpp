#include<iostream>
#include<stdlib.h>

using namespace std;

typedef int type;

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

NODE* Search(LIST& list, type val);
int Dem(LIST& list);
bool SNT(int val);
double TBCSNT(LIST& list);
int SNTLonnhat(LIST& list);
int DemSNTPhanbiet(LIST& list);
bool Ktra(LIST& list, NODE* pNode);
void TachDSKhongSNT(LIST& list1, LIST& list2);

void main()
{
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
	type val;
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;
		val = -1;
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
	type val;
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;
		val = -1;
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
	type val;
	if(isEmpty(list) || q == list.pTail)
	{
		cout<<"Khong the xoa"<<endl;
		val = -1;
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
	type val;
	if(isEmpty(list))
	{
		cout<<"Danh sach rong, khong the xoa"<<endl;
		val = -1;
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

NODE* Search(LIST& list, type val)
{
	NODE* pNode = list.pHead;
	while(pNode!=NULL && pNode->Info!=val)
	{
		pNode = pNode->pNext;
	}
	return pNode;
}
int Dem(LIST& list)
{
	NODE* pNode = list.pHead;
	int dem = 0;
	while(pNode!=NULL)
	{
		if(pNode->Info%10==7 && pNode->Info%7==0) dem++;
		pNode = pNode->pNext;
	}
	return dem;
}
bool SNT(int val)
{
	if(val < 2) return false;
	if(val == 2 || val == 3) return true;
	for(int i=2; i<val; i++)
	{
		if(val%i==0) return false;
	}
	return true;
}
double TBCSNT(LIST& list)
{
	NODE* pNode = list.pHead;
	double tong = 0;
	int dem = 0;
	while(pNode!=NULL)
	{
		if(SNT(pNode->Info))
		{
			tong+=pNode->Info;
			dem++;
		}
		pNode = pNode->pNext;
	}
	return tong/dem;
}
int SNTLonnhat(LIST& list)
{
	NODE* pNode = list.pHead;
	int MAX = 0;
	while(pNode!=NULL)
	{
		if(SNT(pNode->Info) && pNode->Info > MAX) MAX = pNode->Info;
		pNode = pNode->pNext;
	}
	return MAX;
}
int DemSNTPhanbiet(LIST& list)
{
	NODE* pNode = list.pHead;
	int dempb = 0;
	while(pNode!=NULL)
	{
		if(Ktra(list,pNode)) dempb++;
		pNode = pNode->pNext;
	}
	return dempb;
}
bool Ktra(LIST& list, NODE* pNode)
{
	NODE* p = list.pHead;
	while(p!=pNode && p!=NULL)
	{
		if(p->Info == pNode->Info) return true;
	}
	return false;
}
void TachDSKhongSNT(LIST& list1, LIST& list2)
{
	NODE* pNode = list1.pHead;
	Initialize(list2);
	while(pNode!=NULL)
	{
		if(!SNT(pNode->Info)) Push_back(list2,pNode->Info);
		pNode = pNode->pNext;
	}
}