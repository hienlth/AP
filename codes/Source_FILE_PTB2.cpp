#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define VOSONGHIEM -1
#define VONGHIEM 0
#define CO1NGHIEM 1
#define CO2NGHIEM 2

struct PTB2{
	double A, B, C;	//hệ số PTB2
	int sn;	//số nghiệm: -1 (vô số nghiệm); 0 (vô nghiệm); 1 (có 1 nghiệm), 2 (có 2 nghiệm)
	double X1, X2;	//giá trị nghiệm
};

struct DSPTB2{
	PTB2 a[MAX];
	int n;
};

void DocTaptin(char* fname, DSPTB2& ds);
void GhiTaptin(char* fname, DSPTB2 ds);
void GiaiPTB2(PTB2& pt);

void main()
{
	DSPTB2 ds;
	DocTaptin("PTB2.txt",ds);
	for(int i=0; i<ds.n; i++)
		GiaiPTB2(ds.a[i]);
	GhiTaptin("GiaiPTB2.txt",ds);
}

void DocTaptin(char* fname, DSPTB2& ds)
{
	FILE* fp;	
	fopen_s(&fp,fname,"rt");	//fp = fopen(fname,"rt");
	//đọc dữ liệu PTB2 từ tập tin
	fscanf_s(fp,"%d",&ds.n);
	for(int i=0; i<ds.n; i++)
	{
		fscanf_s(fp,"%lf%lf%lf",&ds.a[i].A,&ds.a[i].B,&ds.a[i].C);
	}
	fclose(fp);
}
void GhiTaptin(char* fname, DSPTB2 ds)
{
	FILE* fp;	
	fopen_s(&fp,fname,"wt");	//fp = fopen(fname,"rt");
	//ghi dữ liệu PTB2 ra tập tin	
	for(int i=0; i<ds.n; i++)
	{
		switch(ds.a[i].sn)
		{
		case VOSONGHIEM:
			fprintf(fp,"VO SO NGHIEM\n");
			break;
		case VONGHIEM:
			fprintf(fp,"VO NGHIEM\n");
			break;
		case CO1NGHIEM:
			fprintf(fp,"X = %.2lf\n",ds.a[i].X1);
			break;
		case CO2NGHIEM:
			fprintf(fp,"X1 = %.2lf X2 = %.2lf\n",ds.a[i].X1,ds.a[i].X2);
			break;
		}		
	}
	fclose(fp);
}