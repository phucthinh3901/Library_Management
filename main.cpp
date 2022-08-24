#include <iostream>
#include <graphics.h>
#include "CTDL.h"
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
//=========================
void normal_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc_t, int kc_ngang);
void highlight_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc_d);
void insotrang(int,int);
void xl_phim();
void xoa_mh();
void mhchinh();
void Reset_String(char );
void xoatb();
void tb(int,int,char*);
int min(int,int);
char *viethoa(char *S);
void Form_Xoa();
void nhapChar(char*&,int,int,int,int,int,int,int,int);
void nhaplieu(char*&,int,int,int,int,int,int,int,int);
void nhapso(char*,int,int,int,int,int,int,int,int);
//========VATTU==========
void mh_dsvt();
void in_dsvt(VATTU *,int,int,int,int);
void Form_Them_VT();
void Form_Sua_VT();
void chuyencaysangmang(TREE root,VATTU* ds[],int &nds);
void Run_VT(TREE &tree,DS_NHANVIEN DSNV);
void Xoa_mangVT(VATTU ds[], int vitrixoa,int &nds);
void Initialize(TREE &);
void Insert_node(TREE,char,char,int,char);
void insert_mang(VATTU *,char,char,int,char,int);
void duyet(TREE &, fstream &);
void Reset_filevt(TREE);
void remove_case_3(TREE  &);
void remove (char *,TREE &);
void demslvt(TREE ,int &);
void giaiphong_dsvt(VATTU * ds[], int &nds);
void swapvt(VATTU *,VATTU *);
void sapxepdsvt(VATTU* ds[],int nds);
void Create_Tree(TREE &);
void giaiphongcay(TREE);
void giaiphong(DS_NHANVIEN ,TREE , PTRNODE_HD );
TREE Search (TREE ,char );
void ramdommavt(TREE , char );
int mouse_VT(int &);
//=======NHANVIEN=========
void Form_NhanVien();
void Form_ThemNV();
void Form_HieuchinhNV();
void swap_NV(NHANVIEN *,NHANVIEN *);
void sapxep_dsnv(DS_NHANVIEN &);
void IN_DSNV(DS_NHANVIEN,int,int,int,int);
void docFile_NV(DS_NHANVIEN &);
void ghiFile_NV(DS_NHANVIEN &);
void resetfile_NV(DS_NHANVIEN &);
void taoma_nv(DS_NHANVIEN &,char*);
int timkiem_NV(DS_NHANVIEN &,char*);
void themnv(DS_NHANVIEN &,char *,char *,char *,char *);
void xoa_NV(DS_NHANVIEN &,int);
void Run_NV(DS_NHANVIEN &);
int mouse_NV(int &);
//=========HOADON===============
void mh_hd();
bool ktsohd(DS_NHANVIEN , char *);
char * random_sohd();
bool ktngay(NGAY,tm*);
bool ngaydung(NGAY);
void capnhatvt(TREE &,DS_CTHoaDon,int );
void mhnhapxuat(int,DS_NHANVIEN &,TREE);
void themnodehd(DS_NHANVIEN &,int ,PTRNODE_HD );
void mh_inhd(DS_NHANVIEN,TREE);
void themhd(PTRNODE_HD &,HOADON );
void docfilehd(DS_NHANVIEN &);
void ghifilehd(HOADON,char*);
void themcthd(DS_CTHoaDon &,char *,int ,double ,int );
void incthd(int , int , DS_CTHoaDon , TREE,int,int);
PTRNODE_HD timkiem_soHd(DS_NHANVIEN ,char *,int &);
bool Sosanh_Ngay(NGAY,NGAY);
void in_HoadonNX(int , int , DS_CTHoaDon , TREE );
void in_Hoadon(int , int );
void Run_HD(DS_NHANVIEN &,TREE );
int mouse_HD(int &);
//===========THONGKE=============
void In_Ngay(int ,int ,NGAY );
void In_Tongtien(DS_CTHoaDon ,int ,int );
void In_HDTK(DS_NHANVIEN ,NGAY ,NGAY ,int , int );
void mh_InTopvt();
void InTopvt(VATTU *,long long );
void Swap_tong(long long &,long long &);
void Sapxep_Vattu(VATTU* ,long long , int );
void bang_tkhd();
void mh_TKHD();
void capnhathd(VATTU*, DS_NHANVIEN,long long[],int,int,NGAY,NGAY);
int mouse_TK();
//==============================
void normal_text(int color_bk = 8, int color = 0){ 
	setbkcolor(color_bk);
	setcolor(color);
}
void insotrang(int so, int nds,int x, int y){
	
	char *a=new char;
	outtextxy(x+505,y+634,"/");
	if(nds%10==0)
		itoa(nds/10,a,10);
	else
		itoa(nds/10+1,a,10);
	outtextxy(x+520,y+634,a);
	itoa(so,a,10);
	outtextxy(x+490,y+634,a);
	delete a;
};
void xoa_mh(){ 
	setfillstyle(1,8);
	bar(0,100,1270,767);
}
void xoatb(int l, int t,int r, int b, int mau)
{
	setfillstyle(1,mau);
	bar(l,t,r,b);
	
}
void mhchinh(){

	setfillstyle(1,7);
	bar3d(0,35,1270,100,0,0);
	setbkcolor(7);
	 
	bar(1120,5,1270,33);
	settextstyle(1,0,2);
	normal_text(7,12);
	outtextxy(1140,8,"THOAT");
	normal_text(8,14);
	outtextxy(500,8,"QUAN LY VAT TU");
	
	normal_text();
    normal_box(40,50,260,90,"VAT TU",3,3,8,50);
	normal_box(360,50,580,90,"NHAN VIEN",3,3,8,30);
	normal_box(680,50,900,90,"HOA DON",3,3,8,30);
	normal_box(1000,50,1220,90,"THONG KE",3,3,8,30);

}
void normal_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc_t, int kc_ngang){
	setfillstyle(1,11);
    bar3d(l,t,r,b,8,1);
    setbkcolor(11);
    settextstyle(font,0,f_size);
    outtextxy(l+8+kc_ngang,t+kc_t,s);
}
void highlight_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc_d,int kc_ngang){
	setfillstyle(1,7);
    bar3d(l,t-8,r+8,b,0,0);
	setfillstyle(1,10);
    bar3d(l+4,t-4,r+4,b-4,0,1);
    setbkcolor(10);
    settextstyle(font,0,f_size);
    outtextxy(l+8+kc_ngang,t+kc_d,s);
}
void tb(int x,int y,char *a){
	setbkcolor(7);
	outtextxy(x,y,a);
}
void xoa_tb(int l,int t,int r,int b){
	setfillstyle(1,7);
	bar(l,t,r,b);
	setfillstyle(1,15);

}
int min(int a,int b){
	if(a<b)	return a;
	return b;
}
void xl_phim(){
	while(1)
	  {
	  	if (kbhit())	
		  char cs=getch();
	  	else   return;
	  }
}
void Reset_String(char a[]){
	a[0]='\0';
}
char* viethoa(char *S){
    char *ketQua = new char[strlen(S)];

    if(S[0] != ' ' && S[0] >= 97)
        ketQua[0] = S[0] - 32;
    else
        ketQua[0] = S[0]; 
	for(int i = 1; i < strlen(S); i++)
	{
		if(S[i] != ' ' && S[i] < 97)
		S[i] = S[i] + 32;
	}
    for(int i = 1; i < strlen(S); i++)
	{
        ketQua[i] = S[i];
        if(S[i] == ' ' && S[i+1] != ' ' && S[i+1] >= 97) 
		{
            ketQua[i+1] = S[i+1] - 32;
            i++;
        }
    }
	ketQua[strlen(S)] = '\0';

    return ketQua;
}
void nhapChar(char  *&c,int x,int y,int max,int vh,int left,int top,int right,int bottom){
	setbkcolor(15);
	bar3d(left,top,right,bottom,0,1);
	
	y=y+3;
	x=x+5;
	outtextxy(x,y,"|");
	for(int i=0;i<max;i++) 
		c[i]='\0';
	int a,i=0;
	while(i<max)
	{
		delay(1);
		if(kbhit())
		{
			
			c[i]=getch();
			if(i<max-2) c[i+1]='|';
			a=c[i];
			if(a==8&&i>0)
			{
				c[i-1]='|';c[i]='\0';c[i+1]='\0';
				bar3d(left,top,right,bottom,0,1);
				
				i--;
				outtextxy(x,y,c);
				
			}
			if (c[i]>='0'&&c[i]<='9'||(c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))
			{
				
				outtextxy(x,y,c);
				i++;
			}
			if(a==13)
			{
				//c[i+1]='\0';
				c[i]='\0';
				if(vh==1)
				c=viethoa(c);
				bar3d(left,top,right,bottom,0,1);
				outtextxy(x,y,c);
				
				break;
			}	
		}
	}	
	if(vh==1&&i==max)	// Neu viet du ki tu thi no viet hoa luon
	{
		c=viethoa(c);
		outtextxy(x,y,c);
	}
}
void nhapso(char  *c,int x,int y,int max,int ch,int left,int top,int right,int bottom){
	setbkcolor(15);
	bar3d(left,top,right,bottom,0,1);
	y=y+3;
	x=x+5;
	outtextxy(x,y,"|");
	for(int i=0;i<max;i++) c[i]='\0';
	int a,i=0;
	while(i<max-1)
	{
		delay(0.1);
		if(kbhit())
		{
			
			c[i]=getch();
			if(i<max-2) c[i+1]='|';
			a=c[i];
			if(a==8&&i>0)
			{
				c[i-1]='|';c[i]='\0';c[i+1]='\0';
				bar3d(left,top,right,bottom,0,1);
				i--;
				outtextxy(x,y,c);
				
			}
			if (c[i]>='0'&&c[i]<='9')
			{
				
				outtextxy(x,y,c);
				i++;
			}
			if(a==13)
			{
				//c[i+1]='\0';
				c[i]='\0';
				bar3d(left,top,right,bottom,0,1);
				outtextxy(x,y,c);
				break;	
			}				
		}
	}	
}
void nhaplieu(char  *&c,int x,int y,int max,int vh,int left,int top,int right,int bottom){
	setbkcolor(15);
	setfillstyle(1,15);
	bar3d(left,top,right,bottom,0,1);
	y=y+3;
	x=x+5;
	outtextxy(x,y,"|");
	
	for(int i=0;i<max;i++) c[i]='\0';
	int a,i=0;
	while(i<max)
	{
		delay(1);
		if(kbhit())
		{
			
			c[i]=getch();
			if(i<max-1) c[i+1]='|';
			if(c[i-1]==' '&&c[i]==' '||c[i]==' '&&i==0)
			{
				c[i]='\0';
			}
			a=c[i];
			if(a==8&&i>0)
			{
				c[i-1]='|';c[i]='\0';c[i+1]='\0';
				bar3d(left,top,right,bottom,0,1);
				i--;
				outtextxy(x,y,c);
				
			}
			if ((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')||c[i]==' ')
			{
				outtextxy(x,y,c);
				i++;
			}
			if(a==13)
			{
			
				c[i]='\0';
				if(vh==1)
				c=viethoa(c);
				bar3d(left,top,right,bottom,0,1);
				outtextxy(x,y,c);					
				break;
			}	
		}
	}
	if(vh==1&&i==max)	
	{
		c=viethoa(c);
		outtextxy(x,y,c);
	}
	
}
//==========VATTU==========
void mh_dsvt(){
	int x = 0, y = 70;
	xoa_mh();
	normal_text(8,15);
	settextstyle(1,0,2);
	outtextxy(20,120,"DANH SACH VAT TU");
	setfillstyle(1,15);
	bar3d(450,120,640,155,0,1);
	normal_text();
	normal_box(1000,120,1260,155,"THEM VAT TU",0,2,8,15);
	normal_box(680,120,900,155,"TIM KIEM",0,2,8,15);
	setfillstyle(1,15);
	bar(x,y+100,x+1280,y+710);
	setfillstyle(1,12);
	bar(x+5,y+110,x+1260,y+150);
	line(x+5,y+150,x+1260,y+150);
	setbkcolor(7);
	settextstyle(1,0,1);
	rectangle(5,y+110,250,y+650);
	rectangle(250,y+110,600,y+650);
	rectangle(600,y+110,825,y+650);
	rectangle(825,y+110,1050,y+650);
	rectangle(1050,y+110,1260,y+650);
	normal_text(12,0);
	outtextxy(40,y+120,"Ma Vat Tu");
	outtextxy(350,y+120,"Ten Vat Tu");
	outtextxy(625,y+120,"So Luong Ton");
	outtextxy(860,y+120,"Don Vi Tinh");
	outtextxy(1085,y+120,"Chuc Nang");
	setfillstyle(1,12);
	int *a=new int[6]{580,735,530,745,580,755};
	fillpoly(3,a);
	int *b=new int[6]{650,735,700,745,650,755};
	fillpoly(3,b);
	delete []a;
	delete []b;
	normal_text(15,0);
}
void in_dsvt(VATTU *ds[],int x, int y,int start,int nds){

	char *a=new char[Maxchuoi];
	int j=0;
	for(int i=0; i<10;i++){
		left1[i]=0;top1[i]=0;right1[i]=0;bottom1[i]=0;
		left2[i]=0;top2[i]=0;right2[i]=0;bottom2[i]=0;
	}

	for(int i=start;i<nds;i++)
	{	
		Reset_String(a);
		outtextxy(x-65,y+52,ds[i]->MaVT);
		outtextxy(x+270,y+52,ds[i]->TenVT);
		itoa(ds[i]->SoLuongTon,a,10);
		outtextxy(x+600,y+52,a);	
		outtextxy(x+800,y+52,ds[i]->DonViTinh);
		rectangle(x-100,y+90,x+1155,y+90);	
		normal_box(x+965,y+52,x+1035,y+77,"Sua",1,1,4,4);
		left1[j]=x+965;top1[j]=y+52;right1[j]=x+1035;bottom1[j]=y+77;
		normal_box(x+1065,y+52,x+1135,y+77,"Xoa",1,1,4,4);		
		left2[j]=x+1065;top2[j]=y+52;right2[j]=x+1135;bottom2[j]=y+77;
		setbkcolor(15);
		setfillstyle(1,15);
		y+=50;
		j++;
		//cout<<"j: "<<j<<" - "<<"i: "<<i<<endl;
	}	
	delete []a;
}
void Form_Them_VT(){
	xoa_mh();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,980,720,0,1);
	normal_box(850,670,920,700,"Luu",1,2,3,3);
	normal_box(750,670,825,700,"Huy",1,2,3,3);
	setbkcolor(7);
	settextstyle(3,0,5);
	outtextxy(500,215,"Them Vat Tu");
	settextstyle(1,0,1);
	setfillstyle(1,15);
	outtextxy(310,280,"Ma Vat Tu");
	bar3d(500,275,900,305,0,1);
	outtextxy(310,380,"Ten Vat Tu");
	bar3d(500,375,900,405,0,1);
	outtextxy(310,480,"So Luong");
	bar3d(500,475,900,505,0,1);
	outtextxy(310,580,"Don Vi Tinh");
	bar3d(500,575,900,605,0,1);
	normal_text();
}
void Form_Sua_VT(){
	xoa_mh();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,980,720,0,1);
	normal_box(850,670,920,700,"Luu",1,2,3,3);
	normal_box(750,670,825,700,"Huy",1,2,3,3);
	setbkcolor(7);
	settextstyle(3,0,5);
	outtextxy(500,215,"Hieu Chinh Vat Tu");
	settextstyle(1,0,1);
	setfillstyle(1,15);
	outtextxy(310,280,"Ma Vat Tu");
	bar3d(500,275,900,305,0,1);
	outtextxy(310,380,"Ten Vat Tu");
	bar3d(500,375,900,405,0,1);
	outtextxy(310,480,"So Luong");
	bar3d(500,475,900,505,0,1);
	outtextxy(310,580,"Don Vi Tinh");
	bar3d(500,575,900,605,0,1);
	normal_text();
}
void Form_Xoa(char s[]){
	xoa_mh();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,980,720,0,1);
	normal_box(850,670,920,700,"Co",1,2,3,3);
	normal_box(750,670,825,700,"Huy",1,2,3,3);
	setbkcolor(7);
	settextstyle(1,0,4);
	char char_temp[20]="BAN CO MUON XOA";
	outtextxy(350,215,char_temp);
	outtextxy(450,315,s);
	char char_t[20]="KHONG ???";
	outtextxy(450,415,char_t);
}
void Initialize(TREE &root){
   root = NULL;
}
void Insert_node(TREE &p, char MaVT[], char TenVT[], int SL,char DonViTinh[]){ 
   if(p == NULL)    
   {
	    p = new VATTU;
	    strcpy(p->MaVT,MaVT);     strcpy(p->TenVT,TenVT);  	strcpy(p->DonViTinh,DonViTinh); p->SoLuongTon = SL;
	    p->left = NULL;     p->right = NULL;  
   }
   else
    if(strcmp(MaVT,p->MaVT)<0 )
      Insert_node(p->left, MaVT, TenVT,SL,DonViTinh);
    else if(strcmp(MaVT,p->MaVT)>0 )	    Insert_node(p->right, MaVT, TenVT,SL,DonViTinh);
}
void insert_mang(VATTU *ds[], char MaVT[], char TenVT[], int SL,char DonViTinh[],int &nds){
	ds[nds] = new VATTU;
	strcpy(ds[nds]->MaVT, MaVT);
	strcpy(ds[nds]->TenVT, TenVT);
	strcpy(ds[nds]->DonViTinh, DonViTinh);
	ds[nds]->SoLuongTon=SL;
	nds++;
	
}
void duyet(TREE &p, fstream &f){
	if(p != NULL)
	{
		f<<"\n"<<p->MaVT<<"\n";
	    f<<p->TenVT<<"\n";
		f<<p->SoLuongTon<<"\n";
		f<<p->DonViTinh;
		duyet(p->left,f);
		duyet(p->right,f);
	}
}
void Reset_filevt(TREE p){
	fstream f;
	f.open(filevt,ios_base::out|ios::trunc);
	f.close();
	f.open(filevt,ios_base::out|ios::out); 
	duyet(p,f);
	f.close();
}
bool ktxoavattu(DS_NHANVIEN ds_nv,char *mavt)
{
	PTRNODE_HD p;
	for(int i = 0;i<ds_nv.sl;i++)
	{
		for(p=ds_nv.node[i]->dshd;p!=NULL;p=p->next)
		{
			for(int j=0;j<p->hd.ds.sl;j++)
			{
				if(strcmp(p->hd.ds.DSCT[j].MaVT,mavt)==0)	return false;
			}
		}
		
	}
	return true;
}
TREE rp;
void  remove_case_3 ( TREE  &r ){
  if (r->left != NULL)
     remove_case_3 (r->left);
   //den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
    else 
	{
		
		strcpy(rp->MaVT,r->MaVT);
		strcpy(rp->TenVT,r->TenVT);  	//Chep noi dung cua r sang rp ";
		rp->SoLuongTon =r->SoLuongTon;
		strcpy(rp->DonViTinh,r->DonViTinh); 	//  de lat nua free(rp)
		rp = r;           	
		r=rp->right;
	}
}
void  remove (char * x ,  TREE &p ){
	if (p == NULL)  return;
	else
	if (strcmp(x,p->MaVT)<0)   		  remove (x, p->left);
	else if (strcmp(x,p->MaVT)>0)	  remove (x, p->right);
	else   	// p->key = x
	{
		rp = p;
	    if (rp->right == NULL)  p = rp->left;   
		// p là nút lá hoac la nut chi co cay con ben trai
		else 	if (rp->left == NULL)
		p = rp->right;  // p là nut co cay con ben phai
		else remove_case_3 (rp->right);
	//	delete rp;
	}
}
void chuyencaysangmang(TREE root,VATTU* ds[],int &nds){

	if(root != NULL)
	{
		ds[nds] = new VATTU;
		strcpy(ds[nds]->MaVT, root->MaVT);
		strcpy(ds[nds]->TenVT, root->TenVT);
		strcpy(ds[nds]->DonViTinh, root->DonViTinh);
		ds[nds]->SoLuongTon=root->SoLuongTon;
		nds++;
		chuyencaysangmang(root->left,ds,nds);
		chuyencaysangmang(root->right,ds,nds);
		
	}
}
void demslvt(TREE root,int &nds){
	if(root != NULL)
	{
		nds++;
		demslvt(root->left,nds);
		demslvt(root->right,nds);
	}
}
void giaiphong_dsvt(VATTU * ds[], int &nds){
	for(int i=0; i<nds; i++){
		delete ds[i];
	}
	nds=0;
}
void swapvt(VATTU *a,VATTU *b){
	VATTU *tam=new VATTU;
	strcpy(tam->MaVT, a->MaVT);
	strcpy(tam->TenVT, a->TenVT);
	strcpy(tam->DonViTinh, a->DonViTinh);
	tam->SoLuongTon=a->SoLuongTon;
	
	strcpy(a->MaVT, b->MaVT);
	strcpy(a->TenVT, b->TenVT);
	strcpy(a->DonViTinh, b->DonViTinh);
	a->SoLuongTon=b->SoLuongTon;

	
	strcpy(b->MaVT, tam->MaVT);
	strcpy(b->TenVT, tam->TenVT);
	strcpy(b->DonViTinh, tam->DonViTinh);
	b->SoLuongTon=tam->SoLuongTon;
	delete tam;
	
}
void sapxepdsvt(VATTU* ds[],int nds){
	for(int i=0;i<nds-1;i++)
	{
		for(int j=i+1;j<nds;j++)
		{
			if(strcmp(ds[i]->TenVT,ds[j]->TenVT)>0)
			swapvt(ds[i],ds[j]);
		}
	}
}
void Create_Tree(TREE &root){	
	char MaVT[MaxMaVT];
	char TenVT[MaxTenVT];
	char DonViTinh[MaxDVT];
	int SL;

	fstream f;
	f.open(filevt,ios::in);	
	
	while(!f.eof())	
	{
		f>>MaVT;
		//cout<<"mavt:"<<MaVT;
		if(f.eof()) break;
		f.ignore();
		f.getline(TenVT,MaxTenVT);		
		f>>SL;
		f>>DonViTinh;
		cout<<"mavt:"<<MaVT<<"\ntenvt:"<<TenVT<<"\nsl:"<<SL<<"\ndonvitinh:"<<DonViTinh<<"\n-======-\n";
		Insert_node(root,MaVT,TenVT,SL,DonViTinh);
	}
	f.close();
}
void giaiphongcay(TREE dsvt){
    if(dsvt == NULL) return;
    giaiphongcay(dsvt->left);
    giaiphongcay(dsvt->right);
    delete dsvt;
}
void giaiphong(DS_NHANVIEN dsnv,TREE dsvt, PTRNODE_HD hd){
	for(int i=0;i<dsnv.sl;i++){
		delete dsnv.node[i];
	}
	
	PTRNODE_HD temp;
	while(hd= NULL)
	{
		temp = hd;
		hd = hd->next;
		delete temp;	
	} 
	giaiphongcay(dsvt);
	dsvt=NULL;
}
void xoavt(VATTU *vt[],int vitri,int &nds)
{
	int j;
	for(j = vitri+1;  j< nds ; j++){
		strcpy(vt[j-1]->MaVT,vt[j]->MaVT);	
		strcpy(vt[j-1]->TenVT,vt[j]->TenVT);
		strcpy(vt[j-1]->DonViTinh,vt[j]->DonViTinh);
		vt[j-1]->SoLuongTon = vt[j]->SoLuongTon;
	}
	nds--;
}
void timkiemvt_ten(VATTU *ds[],int &nds, char * nhap,int so){
	int i=0;
	while(i<nds){
		if(strstr(ds[i]->TenVT,nhap)==NULL){
			xoavt(ds,i,nds);
		}
		else
		i++;
	}
	mh_dsvt();
	so = 0;
	insotrang(so+1,nds,100,100);
	in_dsvt(ds,105,180,so*10,nds);
}

TREE Search (TREE root, char x[10]){
   TREE p;
   p = root;
   while (p != NULL && strcmp(x,p->MaVT)!=0)
    	if(strcmp(x,p->MaVT)<0)
        	p = p->left;
    	else
        	p = p->right;
	return (p); 
}
void ramdommavt(TREE p, char x[10]){
	fstream f;
	f.open(filemavt,ios::in);
	f>>x;
	while(Search(p,x)!=NULL&&f.eof()==false)
	f>>x;	
}
void Run_VT(TREE &tree,DS_NHANVIEN DSNV){			
	
	int x,y;		
	x=mousex();
	y=mousey();		
	int tempsl;
	int start = 0;
	char *MaVT = new char[MaxMaVT];
	char *TenVT = new char[MaxTenVT];
	char *SL = new char [MaxSLT];
	char *DVT = new char[MaxDVT];
	VATTU  *ds[MaxVT];
	int nds=0,so=0;			
	chuyencaysangmang(tree,ds,nds);
	sapxepdsvt(ds,nds);
	insotrang(so+1,nds,100,100);
	in_dsvt(ds,105,180,so,min(10*(so+1),nds));
	Reset_String(TenVT);
	while(1){
		delay(1);
		if(mouse_VT(start) == 5)
		{
			highlight_box(1000,120,1260,155,"THEM VAT TU",0,2,8,15);
			delay(100);
			Form_Them_VT();
			normal_text(15,0);
			ramdommavt(tree,MaVT);
			outtextxy(505,278,MaVT);					
			Reset_String(TenVT);
			Reset_String(SL);
			Reset_String(DVT);
		//	cout<<x<<"-"<<y<<"  RT "<<mouse_VT(start)<<endl;
			clearmouseclick(WM_LBUTTONDOWN);
				while(1){
					delay(1);
					if(mouse_VT(start) == 20)
					{					
						Reset_String(MaVT);
						xoa_tb(510,330,900,350);
					
						xl_phim();
						nhapChar(MaVT,500,275,MaxMaVT,0,500,275,900,305);						
						cout<<x<<"-"<<y<<"  RT mavt"<<endl; 
						normal_text(7,12);
						normal_text(7,15);
						if(MaVT[0]!='\0'&&Search(tree,MaVT)==NULL)					
							tb(510,330,"Ma vat tu hop le!");
						else if(MaVT[0]=='\0')
							tb(510,330,"Ma vat tu khong duoc trong!");	
						else if(Search(tree,MaVT)!=NULL)
							tb(510,330,"Ma vat tu bi trung!");
							normal_text(7,0);									
						clearmouseclick(WM_LBUTTONDOWN);
					}
				 	if(mouse_VT(start) == 21){
				 		Reset_String(TenVT);
				 		xoa_tb(505,430,900,450);
						xl_phim();
						nhaplieu(TenVT,500,375,MaxTenVT,1,500,375,900,405); 
						cout<<x<<"-"<<y<<"  RT tenvt"<<endl;
						if(TenVT[0]!='\0')					
							tb(510,430,"Ten vat tu hop le!");
						else 
							tb(510,430,"Ten vat tu khong duoc trong!");	
						normal_text(7,0);							
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_VT(start) == 22){
						Reset_String(SL);
						xoa_tb(505,530,900,550);
						xl_phim();
						nhapso(SL,500,475,MaxSLT,0,500,475,900,505); 
						cout<<x<<"-"<<y<<"  RT sl"<<endl;		
						if(SL[0]!='\0')					
							tb(510,530,"Sl vat tu hop le!");
						else 
							tb(510,530,"Sl vat tu khong duoc trong!");
						tempsl = atoi(SL);											
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_VT(start) == 23){
						Reset_String(DVT);
						xl_phim();
						xoa_tb(505,630,900,650);
						nhaplieu(DVT,500,575,MaxDVT,1,500,575,900,605); 
						cout<<x<<"-"<<y<<"  RT dvt"<<endl;	
						if(DVT[0]!='\0')					
							tb(510,630,"DVT vat tu hop le!");
						else 
							tb(510,630,"DVT vat tu khong duoc trong!");							
						clearmouseclick(WM_LBUTTONDOWN);						
					}
					if(mouse_VT(start) == 24){
						highlight_box(850,670,920,700,"Luu",1,2,3,3);
						delay(500);	
					
					if(MaVT[0]!='\0'&&TenVT[0]!='\0'&&SL[0]!='\0'&&DVT[0]!='\0'&&Search(tree,MaVT)==NULL)
					{			
						tb(800,150,"Luu Thanh Cong!");
						cout<<"Luu thanh cong";
							//	delay(200);
						Insert_node(tree,MaVT,TenVT,tempsl,DVT);
						cout<<MaVT<<"-"<<TenVT<<"-"<<DVT<<"-"<<SL<<endl;
						insert_mang(ds,MaVT,TenVT,tempsl,DVT,nds);
						
						Reset_filevt(tree);		
						delay(500);
						Form_Them_VT();
						normal_text(15,0);
						ramdommavt(tree,MaVT);
						outtextxy(505,278,MaVT);
						setbkcolor(15);					
						Reset_String(TenVT);
						Reset_String(SL);
						Reset_String(DVT);
					}
					else 
					{							
						//normal_text(14,12);							
						tb(800,150,"Loi!");
						delay(500);
						Form_Them_VT();
						normal_text(15,0);
						ramdommavt(tree,MaVT);
						outtextxy(505,278,MaVT);						
						Reset_String(TenVT);
						Reset_String(SL);
						Reset_String(DVT);			
					}
					cout<<x<<"-"<<y<<"  RT nut luu"<<endl;								
					clearmouseclick(WM_LBUTTONDOWN);
				}
				if(mouse_VT(start) == 25){
					highlight_box(750,670,825,700,"Huy",1,2,3,3);
					Reset_String(MaVT);
					Reset_String(TenVT);
					Reset_String(SL);
					Reset_String(DVT);						
					delay(100);
					mh_dsvt();
					sapxepdsvt(ds,nds);
					so=0;
					insotrang(so+1,nds,100,100);					
					in_dsvt(ds,105,180,so,min(10*(so+1),nds));
					cout<<x<<"-"<<y<<"  RT nut huy"<<endl;								
					clearmouseclick(WM_LBUTTONDOWN);
					break;						
				}
			}
			
			if (mouse_VT(start)<5&&mouse_VT(start)>-1)	break;			
		}
		if(mouse_VT(start)==6){
		
			highlight_box(left1[start],top1[start],right1[start],bottom1[start],"Sua",1,1,4,4);
			delay(100);
			TREE p;
			p=Search(tree,ds[so*10+start]->MaVT);
			Form_Sua_VT();
			//bar3d(500,275,900,305,0,1);
			normal_text(15,0);
			outtextxy(505,278,ds[so*10+start]->MaVT);
			//cout<<"========="<<ds[so*10+start]->MaVT<<"=========\n";
            outtextxy(505,378,ds[so*10+start]->TenVT);	
			itoa(ds[so*10+start]->SoLuongTon,SL,10);
			outtextxy(505,478,SL);
			outtextxy(505,578,ds[so*10+start]->DonViTinh);
			Reset_String(TenVT);
			Reset_String(DVT);
			clearmouseclick(WM_LBUTTONDOWN);
			while(1){
				delay(10);
				if(mouse_VT(start) == 21){
				 		Reset_String(TenVT);
				 		xoa_tb(505,430,900,450);
						xl_phim();
						nhaplieu(TenVT,500,375,MaxTenVT,1,500,375,900,405); 
						cout<<x<<"-"<<y<<"  RT tenvt"<<endl;
						if(TenVT[0]!='\0')					
							tb(510,430,"Ten vat tu hop le!");
						normal_text(7,0);							
						clearmouseclick(WM_LBUTTONDOWN);
					}					
					if(mouse_VT(start) == 23){
						Reset_String(DVT);
						xl_phim();
						xoa_tb(505,630,900,650);
						nhaplieu(DVT,500,575,MaxDVT,1,500,575,900,605); 
						cout<<x<<"-"<<y<<"  RT dvt"<<endl;	
						if(DVT[0]!='\0')					
							tb(510,630,"DVT vat tu hop le!");					
						clearmouseclick(WM_LBUTTONDOWN);						
					}
					if(mouse_VT(start) == 24){
						highlight_box(850,670,920,700,"Luu",1,2,3,3);
						delay(500);	
						if((TenVT[0]!='\0'&& DVT[0]!='\0') || (TenVT[0]=='\0'&& DVT[0]!='\0') || (TenVT[0]!='\0'&& DVT[0]=='\0'))					
					    {		
							tb(800,150,"Luu thanh cong");
							delay(200);
							if(TenVT[0]!='\0')		
							{
								strcpy(p->TenVT,TenVT);
								strcpy(ds[so*10+start]->TenVT,TenVT);
							}
							if(DVT[0]!='\0')
							{
								strcpy(p->DonViTinh,DVT);
								strcpy(ds[so*10+start]->DonViTinh,DVT);
							}								
							Reset_filevt(tree);
							//delay(200);
							mh_dsvt();
							giaiphong_dsvt(ds,nds);
							chuyencaysangmang(tree,ds,nds);
							sapxepdsvt(ds,nds);
							so = 0;
							insotrang(so+1,nds,100,100);
							in_dsvt(ds,105,180,so,min(10*(so+1),nds));
							//Reset_String(MaVT);
							Reset_String(TenVT);			
							Reset_String(DVT);
							break;
						}
						else if(TenVT[0]=='\0'&&DVT[0]=='\0')
						{
							tb(800,150,"Khong thay doi du lieu");
							delay(500);
							mh_dsvt();
							
							giaiphong_dsvt(ds,nds);
							chuyencaysangmang(tree,ds,nds);
							sapxepdsvt(ds,nds);
							so = 0;
							insotrang(so+1,nds,100,100);
							in_dsvt(ds,105,180,so,min(10*(so+1),nds));
							//Reset_String(MaVT);
							Reset_String(TenVT);			
							Reset_String(DVT);
							break;
						}						
					cout<<x<<"-"<<y<<"  RT nut luu"<<endl;								
					clearmouseclick(WM_LBUTTONDOWN);
				}
				if(mouse_VT(start) == 25){	
					highlight_box(750,670,825,700,"Huy",1,2,3,3);					
					delay(200);
					mh_dsvt();
					
					giaiphong_dsvt(ds,nds);
					chuyencaysangmang(tree,ds,nds);	
					so=0;
					insotrang(so+1,nds,100,100);
					sapxepdsvt(ds,nds);				
					in_dsvt(ds,105,180,so,min(10*(so+1),nds));
					cout<<x<<"-"<<y<<"  RT nut huy"<<endl;	
					Reset_String(MaVT);
					Reset_String(TenVT);
					Reset_String(SL);
					Reset_String(DVT);								
					clearmouseclick(WM_LBUTTONDOWN);
					break;						
				}
			}			
		}
		if(mouse_VT(start)==7){
			highlight_box(left2[start],top2[start],right2[start],bottom2[start],"Xoa",1,1,4,4);
			delay(100);
			cout<<"-nds- :"<<nds<<endl;
			char temp[]="Vat tu : ";
			strcat(temp,ds[so*10+start]->TenVT);
			Form_Xoa(temp);
			clearmouseclick(WM_LBUTTONDOWN);
			while(1){
				delay(1);
				if(mouse_VT(start)==24){
					highlight_box(850,670,920,700,"Co",1,2,3,3);
					delay(200);			
					if(ktxoavattu(DSNV,ds[so*10+start]->MaVT)==true)
					{
						nds=0;
						demslvt(tree,nds);
						tb(800,150,"Xoa Thanh Cong");
						delay(300);
						remove(ds[so*10+start]->MaVT,tree);
						giaiphong_dsvt(ds,nds);
						chuyencaysangmang(tree,ds,nds);
						Reset_filevt(tree);
						mh_dsvt();
						so = 0;
						insotrang(so+1,nds,100,100);
						sapxepdsvt(ds,nds);
						in_dsvt(ds,105,180,so,min(10*(so+1),nds));
					}
					else 
					{
						tb(600,150,"Vat tu nam trong danh sach hoa don!");
						delay(700);
						mh_dsvt();
						nds= 0;
						demslvt(tree,nds);
						cout<<nds;
						giaiphong_dsvt(ds,nds);
						chuyencaysangmang(tree,ds,nds);
						so = 0;
						insotrang(so+1,nds,100,100);			
						sapxepdsvt(ds,nds);					
						in_dsvt(ds,105,180,so,min(10*(so+1),nds));
					}
					clearmouseclick(WM_LBUTTONDOWN);
					break;
				}
				if(mouse_VT(start)==25){
					highlight_box(750,670,825,700,"Huy",1,2,3,3);					
					delay(100);
					mh_dsvt();
					nds= 0;
					demslvt(tree,nds);
					cout<<nds;
					giaiphong_dsvt(ds,nds);
					chuyencaysangmang(tree,ds,nds);
					so = 0;
					insotrang(so+1,nds,100,100);			
					sapxepdsvt(ds,nds);					
					in_dsvt(ds,105,180,so,min(10*(so+1),nds));								
					clearmouseclick(WM_LBUTTONDOWN);
					break;						
				}
			}
			
		}
		if(mouse_VT(start)==8)
		{	
				if(so>0) 
				{
					mh_dsvt();
					so--;
					insotrang(so+1,nds,100,100);
					in_dsvt(ds,105,180,so*10,min(10*(so+1),nds));
				}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_VT(start)==9)
		{
			if((so<(nds/10) && nds%10!=0) || ((nds%10==0)&& (so<(nds/10)-1)))
			{	
				mh_dsvt();
				so++;
				insotrang(so+1,nds,100,100);
				in_dsvt(ds,105,180,so*10,min(10*(so+1),nds));
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_VT(start)==10){
			highlight_box(680,120,900,155,"TIM KIEM",0,2,8,15);
			delay(200);
			cout<<"MDSS LS:"<<nds<<"\n";
			if(TenVT[0]!='\0')	timkiemvt_ten(ds,nds,TenVT,so);	
			else
			{
				Reset_String(TenVT);
				mh_dsvt();
				so = 0;
				cout<<"nds"<<nds;
				nds=0;
				insotrang(so+1,1,100,100);
				in_dsvt(ds,105,180,so*10,nds);
			}
			setfillstyle(1,11);
			bar3d(643,120,678,155,0,1);
			normal_text(11,0);
			outtextxy(648,130,"X");
			normal_text(15,0);
			clearmouseclick(WM_LBUTTONDOWN);
			while(1){
				delay(10);
				if(mouse_VT(start)==26){
					mh_dsvt();
					nds= 0;
					demslvt(tree,nds);
					//cout<<nds;
					giaiphong_dsvt(ds,nds);
					chuyencaysangmang(tree,ds,nds);
					so = 0;
					insotrang(so+1,nds,100,100);			
					sapxepdsvt(ds,nds);					
					in_dsvt(ds,105,180,so,min(10*(so+1),nds));	
					Reset_String(TenVT);							
					clearmouseclick(WM_LBUTTONDOWN);
					break;			
				}	
			if (mouse_VT(start) < 26 && mouse_VT(start)!=-1)	break;
			}
		}
		if(mouse_VT(start)==11){
			Reset_String(TenVT);
			normal_text(15,0);
			xl_phim();
			nhaplieu(TenVT,450,120,MaxTenVT,1,450,120,640,155); 
			if(TenVT[0] == '\0')
			{
				tb(400,150,"Loi");
				delay(200);
				xoatb(399,148,450,169,8);
			}		
			clearmouseclick(WM_LBUTTONDOWN);
		}	
		if (mouse_VT(start) < 5 && mouse_VT(start)!=-1)	break;	
	}
	delete []MaVT;
	delete []TenVT;
	delete []SL;
	delete []DVT;	
	giaiphong_dsvt(ds,nds);
}
//=======NHANVIEN============
void Form_NhanVien(){
	xoa_mh();
	int y = 98;
	normal_text(8,15);
	settextstyle(3,0,2);
	outtextxy(20,120,"DANH SACH NHAN VIEN");
	normal_text(12,0);
	normal_box(1000,120,1180,155,"THEM NV",1,1,8,8);
	normal_box(680,120,900,155,"TIM KIEM",0,2,8,15);
	setfillstyle(1,15);
	bar3d(450,120,640,155,0,1);
	setfillstyle(1,12);
	bar3d(0,185,1270,225,0,0);
	setbkcolor(12);
	settextstyle(1,0,1);
	outtextxy(70,y+95,"MA NV");
	outtextxy(370,y+95,"HO NV");		
	outtextxy(600,y+95,"TEN NV");
	outtextxy(790,y+95,"PHAI");
	outtextxy(1000,y+95,"Chuc Nang");
	settextstyle(3,0,1);

	setfillstyle(1,15);	

	bar3d(0,220,1270,725,0,0);
	rectangle(2,y+123,230,y+625);	
	rectangle(230,y+123,550,y+625);	
	rectangle(550,y+123,765,y+625);
	rectangle(765,y+123,880,y+625);
	rectangle(880,y+123,1270,y+625);
	setfillstyle(1,12);
	bar3d(510,730,540,760,0,1); 
	bar3d(670,730,700,760,0,1);
	normal_text(12,0);
	outtextxy(518,735,"<");
	outtextxy(678,735,">");
}
void Form_ThemNV(){
	xoa_mh();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,720,0,1);
	normal_box(850,670,920,700,"Luu",3,2,3,1);
	normal_box(750,670,825,700,"Huy",3,2,3,1);
	setbkcolor(7);
	settextstyle(1,0,3);
	outtextxy(450,215,"Them nhan vien");
	settextstyle(10,0,1);
	setfillstyle(1,15);
	outtextxy(310,270,"Ma Nhan vien:");
	bar3d(470,270-5,940,270+25,0,1);
	
	outtextxy(310,340,"Ho Nhan vien:");
	bar3d(470,335,940,365,0,1);
	
	outtextxy(310,410,"Ten nhan vien:");
	bar3d(470,405,940,435,0,1);
	
	outtextxy(310,490,"GIOI TINH:");
	bar3d(450,485,500,515,0,1);
	bar3d(550,485,600,515,0,1);
	setbkcolor(15);
	outtextxy(458,490,"NAM");
	outtextxy(558,490,"NU");
	normal_text();
}
void Form_HieuchinhNV(){
	xoa_mh();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,720,0,1);
	normal_box(850,670,920,700,"Luu",3,2,3,1);
	normal_box(750,670,825,700,"Huy",3,2,3,1);	
	setbkcolor(7);
	settextstyle(1,0,3);
	
	outtextxy(450,215,"Hieu chinh nhan vien");
	settextstyle(10,0,1);
	setfillstyle(1,15);
	
	outtextxy(310,340,"Ho Nhan vien:");
	bar3d(470,335,940,365,0,1);	
	
	outtextxy(310,410,"Ten nhan vien:");
	bar3d(470,405,940,435,0,1);
	
	outtextxy(310,490,"GIOI TINH:");
	bar3d(450,485,500,515,0,1);
	bar3d(550,485,600,515,0,1);
	setbkcolor(15);
	outtextxy(458,490,"NAM");
	outtextxy(558,490,"NU");
	normal_text();
}
void swap_NV(NHANVIEN *a,NHANVIEN *b){
	NHANVIEN *temp= new NHANVIEN;	
	strcpy(temp->MaNV,a->MaNV);strcpy(a->MaNV,b->MaNV);strcpy(b->MaNV,temp->MaNV);		
	strcpy(temp->Ho,a->Ho);strcpy(a->Ho,b->Ho);strcpy(b->Ho,temp->Ho);	
	strcpy(temp->Ten,a->Ten);strcpy(a->Ten,b->Ten);strcpy(b->Ten,temp->Ten);	
	strcpy(temp->Phai,a->Phai);strcpy(a->Phai,b->Phai);strcpy(b->Phai,temp->Phai);	
	temp->dshd=a->dshd;	a->dshd=b->dshd;b->dshd=temp->dshd;	
	delete temp;
}
void sapxep_dsnv(DS_NHANVIEN &ds_nv){
	for(int i=0;i<ds_nv.sl-1;i++)
	{
		for(int j=i+1;j<ds_nv.sl;j++)
		{
			if(strcmp(ds_nv.node[i]->Ten,ds_nv.node[j]->Ten)>0)			
				swap_NV(ds_nv.node[i],ds_nv.node[j]);
			
			else if(strcmp(ds_nv.node[i]->Ten,ds_nv.node[j]->Ten)==0)
			{
				if(strcmp(ds_nv.node[i]->Ho,ds_nv.node[j]->Ho)>0)				
					swap_NV(ds_nv.node[i],ds_nv.node[j]);
				
				else if(strcmp(ds_nv.node[i]->Ho,ds_nv.node[j]->Ho)==0)
				{
					if(strcmp(ds_nv.node[i]->MaNV,ds_nv.node[j]->MaNV)>0)
						swap_NV(ds_nv.node[i],ds_nv.node[j]);
				}
			}
		}
	}			
}
int timkiem(DS_NHANVIEN ds_nv,char *c)
{
	for(int i = 0;i<ds_nv.sl;i++)
	{
		if(strcmp(ds_nv.node[i]->MaNV,c)==0)
		return i;
	}
	return -1;
}
void IN_DSNV(DS_NHANVIEN ds_nv,int x, int y,int bd,int nds){  
	int j = 0;
	for(int i=0; i<10;i++){
		left1[i]=0;top1[i]=0;right1[i]=0;bottom1[i]=0;
		left2[i]=0;top2[i]=0;right2[i]=0;bottom2[i]=0;
	}
	for(int i=bd;i<nds;i++)
	{		
		normal_text(15,0);
		settextstyle(1,0,1);
		outtextxy(x+10,y-15,ds_nv.node[i]->MaNV);
		outtextxy(x+300,y-15,ds_nv.node[i]->Ho);
		outtextxy(x+570,y-15,ds_nv.node[i]->Ten);
		outtextxy(x+750,y-15,ds_nv.node[i]->Phai);
				
		
		normal_box(x+880,y-20,x+1040,y+8,"Hieu chinh",1,1,4,4);
		left1[j]=x+880;top1[j]=y-15;right1[j]=x+1040;bottom1[j]=y+8;
		normal_box(x+1090,y-20,x+1170,y+8,"Xoa",1,1,4,4);		
		left2[j]=x+1090;top2[j]=y-15;right2[j]=x+1170;bottom2[j]=y+8;
		rectangle(x-95,y+25,x+1220,y+700);
		y=y+50;	
		j++;
		//cout<<"j: "<<j<<" - "<<"i: "<<i<<endl;		
	}
}
void docFile_NV(DS_NHANVIEN &node_nv){
	fstream file;
	file.open(filenv,ios::in);
	while(file.eof() == false) // doc chua het file
	{
		node_nv.node[node_nv.sl] = new NHANVIEN;
		file>>node_nv.node[node_nv.sl]->MaNV;
		if(file.eof()==true) break;

		file.ignore();
		file.getline(node_nv.node[node_nv.sl]->Ho,MaxHo);		
		file>>node_nv.node[node_nv.sl]->Ten;						
		file>>node_nv.node[node_nv.sl]->Phai;	
		node_nv.sl++;
	}	
	file.close();
}
//void ghiFile_NV(DS_NHANVIEN &node_nv){
//	fstream file;	
//	file.open(filenv,ios::app);	
//		file<<node_nv.node[node_nv.sl-1]->MaNV<<endl;
//		file<<node_nv.node[node_nv.sl-1]->Ho<<endl;
//		file<<node_nv.node[node_nv.sl-1]->Ten<<endl;
//		cout<<"loias"<<endl;
//		file<<node_nv.node[node_nv.sl-1]->Phai<<endl;		
//		cout<<"loidsa"<<endl;
//		file.close();
//	
//}
void resetfile_NV(DS_NHANVIEN &ds_nv){
	fstream file;
	file.open(filenv,ios_base::trunc);// xoa truoc khi mo file
	file.close();
	file.open(filenv,ios_base::out);
	for(int i=0;i<ds_nv.sl;i++)
	{
		file<<ds_nv.node[i]->MaNV<<"\n";
		file<<ds_nv.node[i]->Ho<<"\n";
		file<<ds_nv.node[i]->Ten<<"\n";
		file<<ds_nv.node[i]->Phai<<"\n";
	}
	file.close();
}
void taoma_nv(DS_NHANVIEN &ds_nv,char *s){
	char a[6] ="NV000"; 
	do{
		for(int i = 2;a[i]!='\0';i++)
		{
			a[i]= rand() % (57-48+1)+ 48;
		}
	}while(timkiem(ds_nv,a) !=-1);	
	strcpy(s,a);
}
//void themnv(DS_NHANVIEN &ds_nv,char *a,char *b,char *c,char *d){
//	
//	
//	ds_nv.node[ds_nv.sl]=new NHANVIEN;
//	cout<<"inadsasd"<<endl;
//	strcpy(ds_nv.node[ds_nv.sl]->MaNV,a);
//	cout<<a<<"\n";
//	//cin.ignore();// xoa bo nhodem
//	strcpy(ds_nv.node[ds_nv.sl]->Ho,b);	
//	cout<<b<<"\n";
//	strcpy(ds_nv.node[ds_nv.sl]->Ten,c);
//	cout<<c<<"\n";
//	strcpy(ds_nv.node[ds_nv.sl]->Phai,d);
//	cout<<d<<"\n"<<"=============="<<"\n";
//	ds_nv.sl++;
// 
//}
void Insert_item(DS_NHANVIEN &ds_nv, int i,char *a,char *b,char *c,char *d)
{  	
	ds_nv.node[ds_nv.sl]=new NHANVIEN;
	for(int j = ds_nv.sl-1; j >= i; j--){
		strcpy(ds_nv.node[j+1]->MaNV,ds_nv.node[j]->MaNV);
		strcpy(ds_nv.node[j+1]->Ho,ds_nv.node[j]->Ho);
		strcpy(ds_nv.node[j+1]->Ten,ds_nv.node[j]->Ten);
		strcpy(ds_nv.node[j+1]->Phai,ds_nv.node[j]->Phai);
	}	
	strcpy(ds_nv.node[i]->MaNV,a);
	cout<<a<<"\n";
	//cin.ignore();// xoa bo nho dem
	strcpy(ds_nv.node[i]->Ho,b);	
	cout<<b<<"\n";
	strcpy(ds_nv.node[i]->Ten,c);
	cout<<c<<"\n";
	strcpy(ds_nv.node[i]->Phai,d);
	cout<<d<<"\n"<<"=============="<<"\n";
	ds_nv.sl++;
	
}
int Insert_Order(DS_NHANVIEN &ds_nv,char *a,char *b,char *c,char *d){
	  if (ds_nv.sl==MaxNV ) return 0;
	  if(ds_nv.sl == 0){
	  	 Insert_item(ds_nv,0,a,b,c,d); 
	  	 return 0;
	  }
	  int i=0;
	  for (  ;i <ds_nv.sl &&((strcmp(ds_nv.node[i]->Ten,c)<0) || ((strcmp(ds_nv.node[i]->Ten,c)==0) && (strcmp(ds_nv.node[i]->Ho,b)<0))); i++);	  	
	  Insert_item(ds_nv,i,a,b,c,d);
}
void xoa_NV(DS_NHANVIEN &ds_nv,int vitri){	
			
	for(int j =vitri+1;  j< ds_nv.sl ; j++)
	{
		strcpy(ds_nv.node[j-1]->MaNV,ds_nv.node[j]->MaNV);
		strcpy(ds_nv.node[j-1]->Ho,ds_nv.node[j]->Ho);
		strcpy(ds_nv.node[j-1]->Ten,ds_nv.node[j]->Ten);
		strcpy(ds_nv.node[j-1]->Phai,ds_nv.node[j]->Phai);
	}	
    ds_nv.sl--;
}
void timkiemNV_theoten(DS_NHANVIEN ds_nv, char * nhap,int so){
	int i=0;
	char temp[MaxHo+MaxTen]; 
	while(i<ds_nv.sl){	
		Reset_String(temp);	
		strcat(temp,ds_nv.node[i]->Ho);
		strcat(temp," ");
		strcat(temp,ds_nv.node[i]->Ten);
		if(strstr(temp,nhap)==NULL)
		{
			xoa_NV(ds_nv,i);
		}
			else
			i++;
		}
	Form_NhanVien();
	so = 0;
	insotrang(so+1,ds_nv.sl,100,100);
	IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
}
void Run_NV(DS_NHANVIEN &ds_nv)
{
		char *a = new char[MaxMaNV];
		char *b = new char[MaxHo];
		char *c = new char[MaxTen];
		char *d = new char[MaxPhai];
		int start = 0; // vi tri con chuot tren mh
		int so = 0;
		int	x = mousex();
		int	y = mousey();	
		int vt = 0; // vi tri con 
		bool checktimkiem = false;
		DS_NHANVIEN nv;	
		Reset_String(c);					
		while(1)
		{
		delay(10);	
				
			if(mouse_NV(start) == 20)
			{
				
				int so=0;					
				insotrang(so+1,ds_nv.sl,100,100);
				Reset_String(a);
				Reset_String(b);
				Reset_String(c);
				Reset_String(d);
				
				highlight_box(1000,120,1180,155,"THEM NV",1,1,8,8);
				delay(100);				
				Form_ThemNV();				
				taoma_nv(ds_nv,a);					
				normal_text(15,0);
				outtextxy(475,270,a);							
				clearmouseclick(WM_LBUTTONDOWN);
				while(1)
				{
					delay(10);
					if(mouse_NV(start) == 40)
					{
					Reset_String(a);
					tb(470,300,"           ");							
					xl_phim();
					nhapChar(a,470,265,MaxMaNV,0,470,265,940,295); 
					if(a[0]!='\0' && timkiem(ds_nv,a)==-1)    
					{
						tb(470,300,"           ");
					} 
					else 
					{
						tb(470,300,"NHAP LAI");
					}
				
					clearmouseclick(WM_LBUTTONDOWN);
					}
					else if(mouse_NV(start) == 41)
					{
						Reset_String(b);				
						tb(470,350,"   ");		
						xl_phim();
						nhaplieu(b,470,335,MaxHo,1,470,335,940,365);
						if(b[0]!='\0')
						{
							tb(470,370,"               ");
						}
						else(tb(470,370,"NHAP LAI"));
						clearmouseclick(WM_LBUTTONDOWN);
					}
					else if(mouse_NV(start) == 42)
					{
						Reset_String(c);						
						tb(470,405,"   ");					
						xl_phim();
						nhaplieu(c,470,405,MaxTen,1,470,405,940,435); //470,405,940,435
							if(c[0]!='\0')
							{
								tb(470,440,"          ");
							}
							else(tb(470,440,"NHAP LAI"));
							clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==43)
					{													
						Reset_String(d);																																	
						setbkcolor(12);
						outtextxy(458,490,"NAM");							
						setbkcolor(15);
						outtextxy(558,490,"NU");
						strcpy(d,"NAM");
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==44)
					{						
						Reset_String(d);											
						setbkcolor(12);				
						outtextxy(558,490,"NU");
						setbkcolor(15);
						outtextxy(458,490,"NAM");
						strcpy(d,"NU");	
						cout<<"nu"<<endl;		
					clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==45)
					{
						//clearmouseclick(WM_LBUTTONDOWN);
						
						if(a[0]!='\0'&&b[0]!='\0'&&c[0]!='\0'&&d[0]!='\0' && timkiem(ds_nv,a)==-1)
						{
							tb(780,450,"LUU THANH CONG");
							delay(1000);
						
						//	themnv(ds_nv,a,b,c,d);			
							Insert_Order(ds_nv,a,b,c,d);
							cout<<"insertoder"<<endl;			
							Reset_String(a);															
						//	ghiFile_NV(ds_nv);	
							resetfile_NV(ds_nv);
							cout<<"resetfile_NV"<<endl;
							Form_ThemNV();
							normal_text(15,0);
							taoma_nv(ds_nv,a);
							cout<<"ma nv: "<<a<<endl;	
							outtextxy(475,270,a);
						//	Reset_String(a);
							Reset_String(b);
							cout<<"resettringb"<<endl;
							Reset_String(c);	cout<<"resettringc"<<endl;
							Reset_String(d);			cout<<"resettringd"<<endl;
							
						}
						else
						{
							tb(780,450,"LOI");
						}
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==46) 
					{
						Form_NhanVien();						
						int so=0;
						insotrang(so+1,ds_nv.sl,100,100); 				
						IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						break;
					}		
					if(mouse_NV(start) < 40 && mouse_NV(start) != -1 ) break;	
				}
			}	
			if(mouse_NV(start) == 21)
			{
				highlight_box(680,120,900,155,"TIM KIEM",0,2,8,15);			
				delay(200);							
				checktimkiem = true;
								
				for(int i=0;i<ds_nv.sl;i++)
				{
					
					nv.node[nv.sl] = new NHANVIEN;
					strcpy(nv.node[i]->MaNV,ds_nv.node[i]->MaNV);
					strcpy(nv.node[i]->Ho,ds_nv.node[i]->Ho);
					strcpy(nv.node[i]->Ten,ds_nv.node[i]->Ten);
					strcpy(nv.node[i]->Phai,ds_nv.node[i]->Phai);
					nv.sl++;
				}
				if(c[0] != '\0')	timkiemNV_theoten(nv,c,so);					
				else 
				{
					
					Form_NhanVien();						
					so=0;
					nv.sl=0;
					insotrang(so+1,1,100,100); 
					cout<<"in so trang "<<endl;				
					IN_DSNV(nv,50,250,so,min(10*(so+1),nv.sl));					
				}
				
				Reset_String(c);
				setfillstyle(1,11);
				bar3d(643,120,678,155,0,1);
				normal_text(11,0);
				outtextxy(648,130,"X");				
				normal_text(12,0);
				clearmouseclick(WM_LBUTTONDOWN);			
				while(1)
				{
					
					delay(10);
					if(mouse_NV(start)==22){												
						delay(100);
						checktimkiem = false;
						Form_NhanVien();								
						so=0;
						insotrang(so+1,ds_nv.sl,100,100); 				
						IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						clearmouseclick(WM_LBUTTONDOWN);
						for(int i = 0;i<nv.sl;i++)
						{
							delete nv.node[i];
						}
						nv.sl = 0;
						break;										
					}
					if(mouse_NV(start) < 70 && mouse_NV(start) != -1) break;
				}				
			}
			if(mouse_NV(start) == 53)
			{
				Reset_String(c);
				xl_phim();
				nhaplieu(c,450,120,MaxTen+MaxHo,1,450,120,640,155);	
				if(c[0] == '\0')
				{
					tb(400,150,"Loi");
					delay(200);
					xoatb(399,148,450,170,8);
				}	
				clearmouseclick(WM_LBUTTONDOWN);
			}
			if(mouse_NV(start)== 38)
			{		
				if(so > 0) 
				{								
					so--;
					Form_NhanVien();
					insotrang(so+1,ds_nv.sl,100,100);
					IN_DSNV(ds_nv,50,250,so*10,min(10*(so+1),ds_nv.sl));
				}
					clearmouseclick(WM_LBUTTONDOWN);
			}
			if(mouse_NV(start)==39)
			{			
						
				if((so<(ds_nv.sl/10) && ds_nv.sl%10!=0) || ((ds_nv.sl%10==0)&& (so<(ds_nv.sl/10)-1)))
				{
					so++;
					Form_NhanVien();
					insotrang(so+1,ds_nv.sl,100,100);
					IN_DSNV(ds_nv,50,250,so*10,min(10*(so+1),ds_nv.sl));
					
				}					
				clearmouseclick(WM_LBUTTONDOWN);
			}	
			if(mouse_NV(start) == 50)
			{								
				highlight_box(left1[start],top1[start],right1[start],bottom1[start],"Hieu chinh",1,1,8,8);
				int check = 0;
				if(checktimkiem == true)
				{
					vt = timkiem(ds_nv,nv.node[so*10+start]->MaNV); // lay ra vi tri nhan vien trong mang chinh, tim bang cach lay nhan vien trong mang tam tim mang chinh			
				}
				else 
				{
					vt = so*10+start; //
				}
				cout<<"vi tri:"<<vt<<endl;
				Form_HieuchinhNV();
				delay(100);
				normal_text(7,0);
				outtextxy(310,270,"Ma Nhan vien:");				
				bar3d(470,270-5,940,270+25,0,1);					
				normal_text(15,0);
				outtextxy(475,270,ds_nv.node[vt]->MaNV);
				outtextxy(475,338,ds_nv.node[vt]->Ho);
				outtextxy(475,408,ds_nv.node[vt]->Ten);
				if(strcmp(ds_nv.node[vt]->Phai,"NAM") == 0)
				{
					setbkcolor(12);
					outtextxy(458,490,"NAM");							
					setbkcolor(15);
					outtextxy(558,490,"NU");
				}
				else
				{
					setbkcolor(12);				
					outtextxy(558,490,"NU");
					setbkcolor(15);
					outtextxy(458,490,"NAM");
				}
				Reset_String(b);
				Reset_String(c);
				Reset_String(d);						
				clearmouseclick(WM_LBUTTONDOWN);
				while(1)
				{
					delay(10);												
					if(mouse_NV(start) == 41)
					{
						Reset_String(b);				
						tb(470,350,"   ");		
						xl_phim();
						nhaplieu(b,470,335,MaxHo,1,470,335,940,365);
						if(b[0]!='\0')
						{
							tb(470,370,"               ");
						}
						else(tb(470,370,"NHAP LAI"));
						clearmouseclick(WM_LBUTTONDOWN);
					}
					else if(mouse_NV(start) == 42)
					{	
						Reset_String(c);						
						tb(470,405,"   ");					
						xl_phim();
						nhaplieu(c,470,405,MaxTen,1,470,405,940,435); //470,405,940,435
							if(c[0]!='\0')
							{
								tb(470,440,"          ");
							}
							else(tb(470,440,"NHAP LAI"));
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==43)
					{				
							check = 1;									
							Reset_String(d);																																	
							setbkcolor(12);
							outtextxy(458,490,"NAM");							
							setbkcolor(15);
							outtextxy(558,490,"NU");
							strcpy(d,"NAM");

							clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==44)
					{				
							check = 2;
							Reset_String(d);											
							setbkcolor(12);				
							outtextxy(558,490,"NU");
							setbkcolor(15);
							outtextxy(458,490,"NAM");
							strcpy(d,"NU");	
							cout<<"nu"<<endl;		
							clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==45)
					{											
					//	if((b[0]!='\0'&&check != 0) || (c[0]!='\0'&&check != 0) || check == 0 || (b[0]=='\0' && c[0]=='\0' && check != 0))
					//	if((b[0]!='\0' || c[0]!='\0' && check != 0) || check == 0 || (b[0]=='\0' && c[0]=='\0' && check != 0))											
							tb(780,450,"LUU THANH CONG");
							delay(1000);
													
							if(b[0]!='\0')	strcpy(ds_nv.node[vt]->Ho,b);	
														
							if(c[0]!='\0')	strcpy(ds_nv.node[vt]->Ten,c);
														 																													
							if(check == 1)	strcpy(ds_nv.node[vt]->Phai,"NAM");	
																						
							else if(check ==2)	strcpy(ds_nv.node[vt]->Phai,"NU");
																													
							resetfile_NV(ds_nv);
							sapxep_dsnv(ds_nv);
							Form_NhanVien();
							so = 0;
							insotrang(so+1,ds_nv.sl,100,100);
							IN_DSNV(ds_nv,50,250,so*10,min(10*(so+1),ds_nv.sl));
							Reset_String(b);
							Reset_String(c);
							break;											

							clearmouseclick(WM_LBUTTONDOWN);
					}
					if(mouse_NV(start)==46) 
					{
						Form_NhanVien();											
						so=0;
						insotrang(so+1,ds_nv.sl,100,100); 				
						IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						break;
					}
					if(mouse_NV(start) < 40 && mouse_NV(start) != -1 ) break;		
				}
			}
			if(mouse_NV(start) == 51)
			{
				
				highlight_box(left2[start],top2[start],right2[start],bottom2[start],"Xoa",1,1,4,4);	
				delay(200);	
				if(checktimkiem == true)
				{
					vt = timkiem(ds_nv,nv.node[so*10+start]->MaNV); // lay ra vi tri					
				}
				else 
				{
					vt = so*10+start; //
				}
				char temp[]="Nhan Vien : ";
				strcat(temp,ds_nv.node[vt]->Ten);
				Form_Xoa(temp);				
				clearmouseclick(WM_LBUTTONDOWN);
				while(1)
				{
					delay(100);				
					if(mouse_NV(start)==45)
					{			
						delay(100);	
						if(ds_nv.node[vt]->dshd == NULL)
						{
							xoa_NV(ds_nv,vt);
							resetfile_NV(ds_nv);				
							tb(380,150,"Xoa nhan vien thanh cong!");
							delay(800);	
							Form_NhanVien();
							so=0;
							insotrang(so+1,ds_nv.sl,100,100); 				
							IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						}
						else
						{
							tb(380,150,"Nhan vien da in hoa don khong the xoa!");
							delay(1500);
							Form_NhanVien();								
							so=0;
							insotrang(so+1,ds_nv.sl,100,100); 				
							IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						}
						clearmouseclick(WM_LBUTTONDOWN);
						break;
					}
					if(mouse_NV(start)==46)
					{					
						highlight_box(750,670,825,700,"Huy",3,2,3,1);	
						delay(100);
						Form_NhanVien();								
						so=0;
						insotrang(so+1,ds_nv.sl,100,100); 				
						IN_DSNV(ds_nv,50,250,so,min(10*(so+1),ds_nv.sl));
						clearmouseclick(WM_LBUTTONDOWN);
						break;
					}					
				}
			}
			if(mouse_NV(start) < 20 && mouse_NV(start) != -1 ) break;
		}		
		delete []a;
		delete []b;
		delete []c;
		delete []d;
}
//==========HOADON==============
void mh_hd(){
	int x =0,y=100;
	setfillstyle(1,8);
	bar(1,100,1280,770);
	setcolor(0);
	normal_box(5,120,105,155,"NHAP",0,2,8,15);
	normal_box(150,120,250,155,"XUAT",0,2,8,15);
	normal_box(300,120,500,155,"IN HOA DON",0,2,8,15);
}
bool ktsohd(DS_NHANVIEN ds_nv, char *a){
	PTRNODE_HD p;
	for(int i=0;i<ds_nv.sl;i++)
	{
		for (p=	ds_nv.node[i]->dshd;  p  != NULL ; p=p->next ) 
	    if ( strcmp(p->hd.SoHD ,a  )==0) return false;
	}
	return true;
}
char * randomsohd(){
	char *a=new char[20];
	a[0]='H';
	a[1]='D';
	for(int i=2;i<20;i++)	a[i]='\0';
	char b[4];
	int so;
	so=rand() % (9999 - 1000 + 1) + 1000;
	strcat(a,itoa(so,b,10));
	return a;
}
bool ktngay(NGAY ng,tm* md){
	if(ng.Nam>1900+md->tm_year)
	{
		return false;
	}
	if(ng.Nam==1900+md->tm_year)
	{
		if(ng.Thang>1+md->tm_mon)
		{
			return false;
		}
		if (ng.Thang==1+md->tm_mon)
		{
			if(ng.Ngay>md->tm_mday)
			return false;
		}
	}
	return true;
}
bool ngaydung(NGAY ng){
	int songay[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	if(ng.Ngay==0||ng.Thang==0||ng.Nam==0)	return false;
	if(ng.Thang>12)	return false;
	if(ng.Ngay>songay[ng.Thang-1])	return false;
	if(ng.Thang==2&&ng.Ngay==29)
	{
		if(ng.Nam%4!=0||(ng.Nam%400!=0&&ng.Nam%100==0))	return false;
	}
	return true;
}
void themhd(PTRNODE_HD &first,HOADON hoadon)
{
	PTRNODE_HD p=new Node_HoaDon;
	p->hd=hoadon;
	p->next=first;
	first=p;
	
}
void capnhatvt(TREE &root,DS_CTHoaDon ds,int kieu)
{
	for(int i=0;i<ds.sl;i++)
	{
		rp=Search(root,ds.DSCT[i].MaVT);
		if(kieu==0)
		{
			rp->SoLuongTon=rp->SoLuongTon+ds.DSCT[i].SoLuong;
		}
		else
		{
			rp->SoLuongTon=rp->SoLuongTon-ds.DSCT[i].SoLuong;
		}
	}
}
void themnodehd(DS_NHANVIEN &ds_nv,int so,PTRNODE_HD p)
{
	p->next=ds_nv.node[so]->dshd;
	ds_nv.node[so]->dshd=p;
}

void ghifilehd(HOADON hd,char* nv){
	fstream f;
	f.open(filehd,ios::app);
	f<<nv<<"\n";
	f<<hd.SoHD<<"\n";
	f<<hd.Loai<<"\n";
	f<<hd.ngay.Ngay<<" ";
	f<<hd.ngay.Thang<<" ";
	f<<hd.ngay.Nam<<"\n";
	for(int i=0;i<hd.ds.sl;i++)
	{
		f<<hd.ds.DSCT[i].MaVT<<"\n";
		f<<hd.ds.DSCT[i].SoLuong<<"\n";
		f<<hd.ds.DSCT[i].DonGia<<"\n";
		f<<hd.ds.DSCT[i].VAT<<"\n";
	}
	f<<"<<>>"<<"\n";

	f.close();
}
void docfilehd(DS_NHANVIEN &ds_nv){
	fstream f;
	char MaNV[6];
	char SoHD[20];
	char MaVT[10];
	int nv=-1;
	f.open(filehd,ios::in);
	while(f.eof()==false)
	{
		PTRNODE_HD p=new Node_HoaDon;
		
		f>>MaNV;
		if(f.eof()==true) break;
		nv=timkiem(ds_nv,MaNV);
		
		f>>p->hd.SoHD;
		f>>p->hd.Loai;
		f>>p->hd.ngay.Ngay;
		f>>p->hd.ngay.Thang;
		f>>p->hd.ngay.Nam;
		while(1)
		{
			f>>MaVT;
			if(strcmp(MaVT,"<<>>")==0)	break;
			strcpy(p->hd.ds.DSCT[p->hd.ds.sl].MaVT,MaVT);
			f>>p->hd.ds.DSCT[p->hd.ds.sl].SoLuong;
			f>>p->hd.ds.DSCT[p->hd.ds.sl].DonGia;
			f>>p->hd.ds.DSCT[p->hd.ds.sl].VAT;
			p->hd.ds.sl++;		
		}
		if(nv!=-1)	themnodehd(ds_nv,nv,p);	 // 
	}	
	f.close();
}
void incthd(int x, int y, DS_CTHoaDon ds, TREE root, int sl, int start){

	int j=0;
	for(int i=0; i<10;i++){
		left2[i]=0;top2[i]=0;right2[i]=0;bottom2[i]=0;
	}
		
	char *a=new char[MaxSLT];
	long tien;
	long tong=0;
	for(int i=start;i<sl;i++)
	{
		normal_text(15,0);
		outtextxy(x+20,y+4,ds.DSCT[i].MaVT);
		outtextxy(x+200,y+4,Search(root,ds.DSCT[i].MaVT)->TenVT);
		itoa(ds.DSCT[i].SoLuong,a,10);
		outtextxy(x+470,y+4,a);
		itoa(ds.DSCT[i].DonGia,a,10);
		outtextxy(x+590,y+4,a);
		itoa(ds.DSCT[i].VAT,a,10);
		outtextxy(x+760,y+4,a);
		tien=(ds.DSCT[i].SoLuong) * (ds.DSCT[i].DonGia)/100*(ds.DSCT[i].VAT+100);
		itoa(tien,a,10);
		outtextxy(x+850,y+4,a);
		rectangle(x,y,x+1240,y+35);
		setbkcolor(15);
		setfillstyle(1,15);
		bar3d(x+1216,y+5,x+1235,y+24,0,1);
		outtextxy(x+1218,y+5,"X");
		left2[j]=x+1216;top2[j]=y+5;right2[j]=x+1235;bottom2[j]=y+24;
		j++;
		y+=35;
		setbkcolor(15);
	}	y-=35;
	for(int i=0;i<ds.sl;i++){
	
		tien=(ds.DSCT[i].SoLuong) * (ds.DSCT[i].DonGia)/100*(ds.DSCT[i].VAT+100);
		tong=tong+tien;
		itoa(tong,a,10);
		outtextxy(x+160,725,a);
	}	
	delete []a;
	
}
void themcthd(DS_CTHoaDon &ds,char *a,int sl,double dg,int vat)
{
	
	strcpy(ds.DSCT[ds.sl].MaVT,a);
	ds.DSCT[ds.sl].SoLuong=sl;
	ds.DSCT[ds.sl].DonGia=dg;
	ds.DSCT[ds.sl].VAT=vat;
	ds.sl++;
}
void xoacthd(DS_CTHoaDon &ds, int i)
{

	int j;
	for(j = i+1;  j< ds.sl ; j++)
		ds.DSCT[j-1] = ds.DSCT[j];
	ds.sl--;
	
}

void resetcthd(int x, int y)
{	
	setfillstyle(1,15);
	bar(1,310,1280,770);
	normal_text(15,0);
	settextstyle(0,0,2);
	setfillstyle(1,12);
	normal_text(12,0);
	bar3d(x+70,y+200,x+1310,y+250,0,1);
	rectangle(x+70,y+200,x+250,y+600);outtextxy(x+80,y+215,"MA VAT TU");
	rectangle(x+250,y+200,x+500,y+600);outtextxy(x+300,y+215,"TEN VAT TU");
	rectangle(x+500,y+200,x+650,y+600);outtextxy(x+510,y+215,"SO LUONG");
	rectangle(x+650,y+200,x+800,y+600);outtextxy(x+670,y+215,"DON GIA");
	rectangle(x+800,y+200,x+900,y+600);outtextxy(x+820,y+215,"VAT%");
	rectangle(x+900,y+200,x+1281,y+600);outtextxy(x+950,y+215,"THANH TIEN");
	rectangle(x+1281,y+250,x+1310,y+600);outtextxy(x+1190,y+215,"");
	normal_box(x+1150,y+150,x+1255,y+180,"THEM",0,2,8,15);
	rectangle(x+70,y+600,x+1310,y+645);outtextxy(x+80,y+615,"TONG:");
	rectangle(x+180,y+600,x+650,y+645);outtextxy(x+580,y+615,"VND");
	setbkcolor(11);
	settextstyle(0,0,3);
	normal_box(x+670,y+610,x+880,y+640,"THANH TOAN",0,2,8,15);
	setfillstyle(1,12);
	int *a=new int[6]{1130,725,1080,735,1130,745};
	fillpoly(3,a);
	int *b=new int[6]{1200,725,1250,735,1200,745};
	fillpoly(3,b);
	delete []a;
	delete []b;
	normal_text(15,0);

}
void mhnhapxuat(int kieu,DS_NHANVIEN &DSNV,TREE tree){
	char loai;
	setfillstyle(1,15);
	bar(1,165,1280,770);
	settextstyle(0,0,3);
	setfillstyle(1,14);
	int x=-49,y=115;
	int start = 0;
	int so = 0;
	settextstyle(0,0,3);		
	setbkcolor(11);
	if(kieu==0)
	{
		loai='N';
		highlight_box(5,120,105,155,"NHAP",0,2,8,15);
		delay(200);
		settextstyle(0,0,2);
		setbkcolor(12);
		rectangle(x+59,y+51,x+450,y+120);outtextxy(x+75,y+67,"HOA DON NHAP");	
	}
	if(kieu==1)
	{
		loai='X';
		highlight_box(150,120,250,155,"XUAT",0,2,8,15);
		delay(200);
		settextstyle(0,0,2);
		setbkcolor(14);
		rectangle(x+59,y+51,x+450,y+120);outtextxy(x+75,y+67,"HOA DON XUAT");
	}
	
	settextstyle(0,0,2);
	setbkcolor(15);
	rectangle(x+70,y+90,x+400,y+115);// so hoa don
	x=101;
	rectangle(x+300,y+81,x+550,y+120);outtextxy(x+303,y+67,"MA NHAN VIEN:");	rectangle(x+320,y+90,x+520,y+115);

	rectangle(x+550,y+81,x+750,y+120);outtextxy(x+570,y+67,"NGAY:");			rectangle(x+570,y+90,x+670,y+115);

	rectangle(x+750,y+81,x+950,y+120);outtextxy(x+770,y+67,"THANG:");			rectangle(x+770,y+90,x+870,y+115);
	
	rectangle(x+950,y+81,x+1140,y+120);outtextxy(x+970,y+67,"NAM:");			rectangle(x+970,y+90,x+1070,y+115);

	x=-60;
	rectangle(x+70,y+51,x+1310,y+600);
	outtextxy(x+80,y+130,"Ma vat tu:");rectangle(x+80,y+150,x+350,y+180);
	outtextxy(x+400,y+130,"So luong:");rectangle(x+400,y+150,x+650,y+180);
	outtextxy(x+700,y+130,"Don gia:");rectangle(x+700,y+150,x+950,y+180);
	outtextxy(x+1020,y+130,"VAT%:");rectangle(x+1020,y+150,x+1080,y+180);

	setfillstyle(1,12);
	normal_text(12,0);
	bar3d(x+70,y+200,x+1310,y+250,0,1);
	rectangle(x+70,y+200,x+250,y+600);outtextxy(x+80,y+215,"MA VAT TU");
	rectangle(x+250,y+200,x+500,y+600);outtextxy(x+300,y+215,"TEN VAT TU");
	rectangle(x+500,y+200,x+650,y+600);outtextxy(x+510,y+215,"SO LUONG");
	rectangle(x+650,y+200,x+800,y+600);outtextxy(x+670,y+215,"DON GIA");
	rectangle(x+800,y+200,x+900,y+600);outtextxy(x+820,y+215,"VAT%");
	rectangle(x+900,y+200,x+1310,y+600);outtextxy(x+950,y+215,"THANH TIEN");
	rectangle(x+1281,y+250,x+1310,y+600);outtextxy(x+1190,y+215,"");
	normal_box(x+1150,y+150,x+1255,y+180,"THEM",0,2,8,15);
	rectangle(x+70,y+600,x+1310,y+645);outtextxy(x+80,y+615,"TONG:");
	rectangle(x+180,y+600,x+650,y+645);outtextxy(x+580,y+615,"VND");
	setbkcolor(11);
	settextstyle(0,0,3);
	normal_box(x+670,y+610,x+880,y+640,"THANH TOAN",0,2,8,15);
	setfillstyle(1,12);
	int *a=new int[6]{1130,725,1080,735,1130,745};
	fillpoly(3,a);
	int *b=new int[6]{1200,725,1250,735,1200,745};
	fillpoly(3,b);
	delete []a;
	delete []b;
	normal_text(15,0);
	
	char *SoHD = new char[MaxSoHD];
	char* MaNV=new char[MaxMaNV];
	char *ngay=new char[3];
	char *thang=new char[3];
	char *nam=new char[5];
	char *MaVT=new char[MaxMaVT];
	char *sl=new char[MaxSLT];
	char *DonGia=new char[MaxSLT];
	char *VAT=new char[5];
	int nhanvien;
	long tong=0;
	long thanhtien;
	x=115;
	HOADON p;
	p.Loai = loai;
	NGAY ng;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	ng.Nam=1900   + ltm->tm_year;
	ng.Thang= 1 + ltm->tm_mon;
	ng.Ngay=ltm->tm_mday;
	itoa(ng.Ngay,ngay,10);
	itoa(ng.Thang,thang,10);
	itoa(ng.Nam,nam,10);
	normal_text(15,0);
	outtextxy(x+585,y+94,ngay);
	outtextxy(x+790,y+94,thang);
	outtextxy(x+970,y+94,nam);
	if(p.ds.sl ==0){
		insotrang(so+1,1,650,95);
	}
	
	strcpy(p.SoHD,randomsohd());
	while(ktsohd(DSNV,SoHD)==false)
	{
		strcpy(p.SoHD,randomsohd());
	}
	outtextxy(30,210,p.SoHD);
	strcpy(SoHD,p.SoHD);
	clearmouseclick(WM_LBUTTONDOWN);
	while(1){
		delay(10);
		if(mouse_HD(start)==8){
			//highlight_box(5,120,105,155,"NHAP",0,2,8,15);
			//delay(100);
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapChar(SoHD,21,205,MaxSoHD,0,21,205,400-49,230);
			if(ktsohd(DSNV,SoHD)==false)
			{
				outtextxy(870,145,"Ma hoa don da co roi");
				Reset_String(SoHD);
			}
			else
			{
				strcpy(SoHD,p.SoHD);
				cout<<"so hd"<<SoHD<<"\n";
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==9){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapChar(MaNV,421,205,MaxMaNV,0,421,205,621,230);
			if(timkiem(DSNV,MaNV)==-1){
				outtextxy(870,140,"Khong co nhan vien nay");
				Reset_String(MaNV);
			}
			else	
				nhanvien=timkiem(DSNV,MaNV);
				
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==10){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapso(ngay,671,205,3,0,671,205,771,230);
			ng.Ngay=atoi(ngay);
			if(ktngay(ng,ltm)==false)
			{
				outtextxy(870,140,"Hoa don o tuong lai?");	
			}
				else if(ngaydung(ng)==false)
			{
				outtextxy(870,140,"Thoi gian sai");
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==11){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapso(thang,871,205,3,0,871,205,971,230);
			ng.Thang=atoi(thang);
			if(ktngay(ng,ltm)==false)
			{
				outtextxy(870,140,"Hoa don o tuong lai?");
			}
				else if(ngaydung(ng)==false)
			{
				outtextxy(870,140,"Thoi gian sai");
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==12){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapso(nam,1071,205,5,0,1071,205,1171,230);
			ng.Nam=atoi(nam);
			if(ktngay(ng,ltm)==false)
			{
				outtextxy(870,140,"Hoa don o tuong lai?");	
			}
				else if(ngaydung(ng)==false)
			{
				outtextxy(870,140,"Thoi gian sai");
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==13){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapChar(MaVT,20,265,MaxMaVT,0,20,265,290,295);
			
			rp=Search(tree,MaVT);
			if(rp==NULL)
			{
				outtextxy(870,140,"Khong co vat tu nay");
				Reset_String(MaVT);
				
			}	
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==14){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapso(sl,340,265,MaxSLT,0,340,265,590,295);
			if(atoi(sl)==0)
			{
				outtextxy(870,140,"So luong > 0");
				Reset_String(sl);
			}
			else if(rp!=NULL)
			{
				if(kieu==0)
				{
					if(atoi(sl)+rp->SoLuongTon>999999999)
					{
						outtextxy(870,140,"So luong them qua nhieu");
						Reset_String(sl);
					}
				}
				else
				{
					if(atoi(sl)>rp->SoLuongTon)
					{
						outtextxy(870,140,"Khong du vat tu");
						Reset_String(sl);
					}
				}
			}	
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==15){
			xl_phim();
			xoatb(869,139,1270,158,8);
			setfillstyle(1,15);
			nhapso(DonGia,640,265,MaxSLT,0,640,265,890,295);
			if(atoi(DonGia)<100)
			{
				outtextxy(870,140,"Don gia >= 100");
				Reset_String(DonGia);
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==16){
			xl_phim();
			setfillstyle(1,15);
			nhapso(VAT,960,265,4,0,960,265,1020,295);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==17){
			delay(1);
			xoatb(869,139,1270,158,8);
			if(p.ds.sl<20)
			{	
				thanhtien=atoi(sl)*atoi(DonGia)/100*(atoi(VAT)+100);
				tong=tong+thanhtien;
				if(tong>999999999)
				{
					outtextxy(870,140,"Tong tien <=999.999.999");
					tong=tong-thanhtien;
				}
				
				else if(MaVT[0]=='\0'||sl[0]=='\0'||DonGia[0]=='\0'||VAT[0]=='\0')
				{
					outtextxy(870,140,"Thong tin sai/thieu");
				}
				else
				{
					themcthd(p.ds,MaVT,atoi(sl),atoi(DonGia),atoi(VAT));
					insotrang(so+1,p.ds.sl,650,95);
					incthd(10,y+250,p.ds,tree,min(10*(so+1),p.ds.sl),so*10);
					Reset_String(MaVT);
					Reset_String(sl);
					Reset_String(DonGia);
					Reset_String(VAT);
					setfillstyle(1,15);
					bar3d(20,y+150,290,y+180,0,1);
					bar3d(340,y+150,590,y+180,0,1);
					bar3d(640,y+150,890,y+180,0,1);
					bar3d(960,y+150,1020,y+180,0,1);		
				}
			}
			else 
				outtextxy(870,140,"Da du 20 vat tu");
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_HD(start)==18){
			xoacthd(p.ds,start);
			cout<<"stt:"<<start<<endl;
			resetcthd(-60,115);	
			so = 0;
			insotrang(so+1,p.ds.sl,650,95);
			if(p.ds.sl == 0){
				insotrang(so+1,1,650,95);	
			}
			incthd(10,y+250,p.ds,tree,min(10*(so+1),p.ds.sl),so*10);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==19){
			xoatb(869,139,1270,158,8);
			cout<<"MaNV:"<<MaNV<<" - sl:"<<p.ds.sl<<" - soHD:"<<SoHD<<" - ktNgay:"<<ktngay(ng,ltm);
			if(MaNV[0]!='\0' && p.ds.sl>0 && SoHD[0]!='\0' && ktngay(ng,ltm)==true)
			{
				p.ngay=ng;
				ghifilehd(p,MaNV);
				themhd(DSNV.node[nhanvien]->dshd,p);
				outtextxy(870,140,"Thanh toan thanh cong");
				Reset_String(SoHD);
				Reset_String(MaVT);
				if(kieu==0)	capnhatvt(tree,p.ds,0);
				else	capnhatvt(tree,p.ds,1);
				Reset_filevt(tree);
			}
			else
				outtextxy(870,140,"Thieu/sai thong tin");
			
			
			strcpy(p.SoHD,randomsohd());
			while(ktsohd(DSNV,SoHD)==false)
			{
				strcpy(p.SoHD,randomsohd());
			}
			outtextxy(30,210,p.SoHD);
			strcpy(SoHD,p.SoHD);
			
			p.ds.sl = 0;
			resetcthd(-60,115);	
			delay(500);
			xoatb(869,139,1270,158,8);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==20)
		{	
			if(so>0) 
			{
				resetcthd(-60,115);	
				so--;
				insotrang(so+1,p.ds.sl,650,95);
				incthd(10,y+250,p.ds,tree,min(10*(so+1),p.ds.sl),so*10);
			}
		clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)==21)
		{
			if((so<(p.ds.sl/10) && p.ds.sl%10!=0) || ((p.ds.sl%10==0)&& (so<(p.ds.sl/10)-1)))
			{	
				resetcthd(-60,115);	
				so++;
				insotrang(so+1,p.ds.sl,650,95);
				incthd(10,y+250,p.ds,tree,min(10*(so+1),p.ds.sl),so*10);
			}
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start)< 8 && mouse_HD(start)!=-1)	break;
	}
	delete []SoHD;
	delete []MaNV;
	delete []ngay;
	delete []thang;
	delete []nam;
	delete []MaVT;
	delete []sl;
	delete []DonGia;
	delete []VAT;
}
bool Sosanh_Ngay(NGAY tu,NGAY den)
{
	if(tu.Nam>den.Nam)
	{
		return false;
	}
	else if(tu.Nam==den.Nam)
	{
		if(tu.Thang>den.Thang)
		{
			return false;
		}
		else if(tu.Thang==den.Thang)
		{
			if(tu.Ngay>den.Ngay)	return false;
		}
	}
	return true;
}
void in_HoadonNX(int x, int y, DS_CTHoaDon ds, TREE root)
{
	
	char *a=new char[MaxSLT];
	long tien;
	long tong=0;
	int kc=20;
	for(int i=0;i<ds.sl;i++)
	{
		normal_text(15,0);
		line(x,0,x+1280,0);
		outtextxy(x+40,y+i*kc,ds.DSCT[i].MaVT);
		outtextxy(x+280,y+i*kc,Search(root,ds.DSCT[i].MaVT)->TenVT);
		itoa(ds.DSCT[i].SoLuong,a,10);
		outtextxy(x+580,y+i*kc,a);
		itoa(ds.DSCT[i].DonGia,a,10);
		outtextxy(x+750,y+i*kc,a);
		itoa(ds.DSCT[i].VAT,a,10);
		outtextxy(x+930,y+i*kc,a);
		tien=(ds.DSCT[i].SoLuong) * (ds.DSCT[i].DonGia)/100*(ds.DSCT[i].VAT+100);
		tong=tong+tien;
		itoa(tien,a,10);
		outtextxy(x+1080,y+i*kc,a);
		rectangle(1+x,y+i*kc-4,x+1251,y+i*kc+kc-4);
		setbkcolor(11);
		setfillstyle(1,14);	
		setbkcolor(15);
	}
	itoa(tong,a,10);
	outtextxy(x+140,y+435,a);
	delete []a;
	
}
void in_Hoadon(int x, int y)
{
	y = 55;
	setfillstyle(1,15);
	bar(x+50,y+200,x+1350,y+710);
	setbkcolor(15);
	rectangle(x+50,y+200,x+1300,y+250);
	rectangle(x+50,y+200,x+250,y+680);outtextxy(x+70,y+216,"MA VAT TU");
	rectangle(x+250,y+200,x+550,y+680);outtextxy(x+320,y+215,"TEN VAT TU");
	rectangle(x+550,y+200,x+750,y+680);outtextxy(x+590,y+215,"SO LUONG");
	rectangle(x+750,y+200,x+950,y+680);outtextxy(x+790,y+215,"DON GIA");
	rectangle(x+950,y+200,x+1050,y+680);outtextxy(x+970,y+215,"VAT%");
	rectangle(x+1050,y+200,x+1300,y+680);outtextxy(x+1100,y+215,"THANH TIEN");
	rectangle(x+50,y+680,x+1300,y+710);outtextxy(x+60,y+690,"TONG:");
	rectangle(x+150,y+680,x+650,y+710);outtextxy(x+700,y+690,"VND");
	
	setbkcolor(12);
	settextstyle(0,0,3);
	setbkcolor(15);	
	settextstyle(0,0,2);

}
PTRNODE_HD timkiem_soHd(DS_NHANVIEN ds_nv,char *sohd,int &vt)
{
	PTRNODE_HD p;
	for(int i=0;i<ds_nv.sl;i++)
	{
		for(p=ds_nv.node[i]->dshd;p!=NULL;p=p->next)
		if(strcmp(p->hd.SoHD,sohd)==0)
		{
			vt=i;
			return p;
		}
	}	
	return NULL;
}
void mh_inhd(DS_NHANVIEN ds_nv,TREE tree){
	int	y=70;	
	setfillstyle(1,15);
	bar(1,165,1344,800);
	char *sohd=new char[MaxSoHD];
	char*ten=new char[40];
	int vt;
	PTRNODE_HD p;			
	int start = 0;												
	setbkcolor(15);
	settextstyle(0,0,3);
	
	outtextxy(500,y+270,"NHAP SO HOA DON :");
	rectangle(350,y+250,1050,y+450);
	setfillstyle(1,15);
	bar3d(450,y+325,950,y+375,0,1);
	setbkcolor(15);
	
	normal_box(625,y+400,700,y+435,"OK",0,2,8,15);
	setbkcolor(15);
	Reset_String(sohd);
	clearmouseclick(WM_LBUTTONDOWN);
	while(1)
	{
		delay(1);
		if(mouse_HD(start) == 30)
		{
			Reset_String(sohd);
		
			xl_phim();
			setfillstyle(1,15);						
			nhapChar(sohd,460,y+335,MaxSoHD,0,450,395,950,445);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(mouse_HD(start) == 31)
		{
			highlight_box(625,y+400,700,y+435,"OK",0,2,8,15);
			delay(200);
			p = timkiem_soHd(ds_nv,sohd,vt);				
			if(sohd[0]=='\0')
			{
				outtextxy(800,200,"Chua nhap so hoa don!");
				delay(1000);
				mh_inhd(ds_nv,tree);	
			}
			else if(p == NULL)
			{
				outtextxy(800,200,"Hoa don nay chua duoc lap!");
				delay(1000);
				mh_inhd(ds_nv,tree);
			}
			else
			{
				int x=20; y=50;
				Reset_String(ten);
				in_Hoadon(x-49,y+71-100);
				in_HoadonNX(x,y+260,p->hd.ds,tree);
				setbkcolor(15);
				setfillstyle(0,15);
				
				outtextxy(x,170,"So hoa don    :");outtextxy(x+250,170,sohd);			     outtextxy(x+600,200,"Ngay :   /   /  ");
				outtextxy(x,200,"Ma nhan vien  :");outtextxy(x+250,200,ds_nv.node[vt]->MaNV); outtextxy(x+600,230,"Loai :");
				outtextxy(x,230,"Ten nhan vien :");												
				strcat(ten,ds_nv.node[vt]->Ho);	
				strcat(ten," ");	
				strcat(ten,ds_nv.node[vt]->Ten);			
				outtextxy(x+250,230,ten);										
				outtextxy(x+700,200,itoa(p->hd.ngay.Ngay,ten,10));						
				outtextxy(x+766,200,itoa(p->hd.ngay.Thang,ten,10));
				outtextxy(x+833,200,itoa(p->hd.ngay.Nam,ten,10));										
				if(p->hd.Loai=='N')
				{
					outtextxy(x+700,230,"Nhap");
				}
				else outtextxy(x+700,230,"Xuat");
				clearmouseclick(WM_LBUTTONDOWN);
			}				
		}
		if(mouse_HD(start)<30&&mouse_HD(start)!=-1) break;			
	}
	delete []sohd;
	delete []ten;		
}
void resetBarHD(){
	setfillstyle(1,8);
	bar(5,100,600,160);
	normal_box(5,120,105,155,"NHAP",0,2,8,15);
	normal_box(300,120,500,155,"IN HOA DON",0,2,8,15);
	normal_box(150,120,250,155,"XUAT",0,2,8,15);
}

void Run_HD(DS_NHANVIEN &DSNV,TREE tree){
	int x=0,y=71;
	int start = 0;
	while(1)
	{
		delay(1);
		if(mouse_HD(start)==5)
		{
			mhnhapxuat(0,DSNV,tree);
			resetBarHD();
			
		}
		if(mouse_HD(start)==6)
		{
			mhnhapxuat(1,DSNV,tree);
			resetBarHD();
			
		}
		if(mouse_HD(start)==7)
		{
			highlight_box(300,120,500,155,"IN HOA DON",0,2,8,15);
			delay(50);
			mh_inhd(DSNV,tree);
			resetBarHD();
			settextstyle(0,0,2);
			setbkcolor(15);
		}
		if(mouse_HD(start)<5&&mouse_HD(start)!=-1) break;
	}
}
//=======================ThongKe======================
void mh_TKHD()
{
	setfillstyle(1,15);
	bar(1,105,1344,800);
	int x=0,y=110;
	setbkcolor(12);	
	settextstyle(0,0,2);
	setbkcolor(15);
	settextstyle(0,0,3);

	rectangle(x+200,y+100,x+1100,y+400);
	outtextxy(x+500,y+80,"NHAP THOI GIAN");

	outtextxy(x+250,y+150,"TU:");
	outtextxy(x+350,y+150,"Ngay");rectangle(470,260,530,290);
	
	outtextxy(x+550,y+150,"Thang");rectangle(x+720,y+150,x+780,y+180);
	outtextxy(x+800,y+150,"Nam");rectangle(x+910,y+150,x+1030,y+180);	
	outtextxy(x+250,y+300,"Den:");
	outtextxy(x+350,y+300,"Ngay");rectangle(x+470,y+300,x+530,y+330);
	outtextxy(x+550,y+300,"Thang");rectangle(x+720,y+300,x+780,y+330);
	outtextxy(x+800,y+300,"Nam");rectangle(x+910,y+300,x+1030,y+330);
	normal_box(x+375,y+350,x+620,y+390,"THONG KE",3,3,8,50);
	normal_box(x+725,y+350,x+990,y+390,"TOP 10 VT",3,3,8,50);
	
	setfillstyle(1,15);
	setbkcolor(15);
}
void bang_tkhd()
{	
	setfillstyle(1,15);
	bar(1,100,1300,800);
	setbkcolor(15);
	settextstyle(0,0,3);
	outtextxy(400,100,"BANG LIET KE CAC HOA DON");
	settextstyle(0,0,2);
	outtextxy(100,150,"SO HD");
	outtextxy(320,150,"NGAY LAP");
	outtextxy(520,150,"LOAI");
	outtextxy(680,150,"HO TEN NV LAP");
	outtextxy(1000,150,"TRI GIA HD");
	rectangle(48,170,270,750);
	rectangle(270,170,500,750);
	rectangle(500,170,630,750);
	rectangle(630,170,950,750);
	rectangle(950,170,1225,750);
}
void In_Ngay(int x,int y,NGAY ngay)
{
	char *a=new char[5];
	outtextxy(x,y,"  /  /");
	outtextxy(x,y,itoa(ngay.Ngay,a,10));
	outtextxy(x+49,y,itoa(ngay.Thang,a,10));
	outtextxy(x+98,y,itoa(ngay.Nam,a,10));
	delete a;
}
void In_Tongtien(DS_CTHoaDon ds,int x,int y)
{
	int tong=0;
	char *a=new char[10];
	for(int i=0;i<ds.sl;i++)
	tong=tong+ds.DSCT[i].SoLuong*ds.DSCT[i].DonGia/100*(ds.DSCT[i].VAT+100);
	cout<<"tong: "<<tong<<endl;
	outtextxy(x,y,itoa(tong,a,10));
	delete a;
}
void In_HDTK(DS_NHANVIEN ds_nv,NGAY tu,NGAY den,int x, int y)
{
	PTRNODE_HD p;int kc=20,so=0;
	char*a=new char[40];
	char b[40];
	b[0]='\0';
	for(int i=0;i<ds_nv.sl;i++)
	{
		for(p=ds_nv.node[i]->dshd;p!=NULL;p=p->next)
		{
			if(Sosanh_Ngay(tu,p->hd.ngay)==true&&Sosanh_Ngay(p->hd.ngay,den)==true)
			{
				outtextxy(x+100,y+kc*so,p->hd.SoHD);			
				cout<<"so hd: "<<p->hd.SoHD<<endl;
				outtextxy(x+333-30,y+kc*so,"  /  /");
				outtextxy(x+333-30,y+kc*so,itoa(p->hd.ngay.Ngay,a,10));
				outtextxy(x+382-30,y+kc*so,itoa(p->hd.ngay.Thang,a,10));
				outtextxy(x+431-30,y+kc*so,itoa(p->hd.ngay.Nam,a,10));
				if(p->hd.Loai=='N')
				{
					outtextxy(x+520,y+kc*so,"Nhap");
				}
				else	
				outtextxy(x+520,y+kc*so,"Xuat");
				strcat(b,ds_nv.node[i]->Ho);
				strcat(b," ");
				strcat(b,ds_nv.node[i]->Ten);
				cout<<"a :"<<b<<endl;
				outtextxy(x+650,y+kc*so,b);
				In_Tongtien(p->hd.ds,x+980,y+kc*so);
				rectangle(48,170+kc*so,1225,170+kc*so+kc);
				so++;
				b[0]='\0';
			}
		}
	}
	delete a;	
}
void mh_InTopvt()
{	
		setfillstyle(1,15);
		bar(1,100,1300,800);
		setbkcolor(15);
		settextstyle(0,0,3);
		outtextxy(300,120,"TOP 10 VAT TU CO DOANH THU CAO NHAT");
		int y=120;		
		settextstyle(0,0,2);
		rectangle(5,y+70,1280,y+600);
		rectangle(5,y+70,1280,y+120);		
		outtextxy(80,y+90,"MA VT");
		rectangle(5,y+70,250,y+600);
		outtextxy(370,y+90,"TEN VAT TU");
		rectangle(250,y+70,700,y+600);
		outtextxy(785,y+90,"SO LUONG");
		rectangle(700,y+70,1000,y+600);
		outtextxy(1080,y+90,"DOANH THU");
		rectangle(1000,y+70,1280,y+600);
}
void InTopvt(VATTU *ds[],long long tongdt[])
{
	
	int x=100,y=250;
	char *temp=new char[11];
	for(int i=0;i<10;i++)
	{		
		if(tongdt[i]==0)
		break;
		outtextxy(x+1-40,y,ds[i]->MaVT);
		outtextxy(x+220,y,ds[i]->TenVT);			
		itoa(ds[i]->SoLuongTon,temp,10);
		outtextxy(x+650,y,temp);				
		outtextxy(x+950,y,itoa(tongdt[i],temp,10));
		rectangle(x-95,y+30,x+1180,y+30);
		y=y+40;	
	}
}
void capnhathd(VATTU* ds[],DS_NHANVIEN ds_nv,long long a[],int slvt,NGAY tu,NGAY den)
{
	PTRNODE_HD p;
	for(int j=0;j<slvt;j++)
	{
		for(int i=0;i<ds_nv.sl;i++)
		{
			for(p=ds_nv.node[i]->dshd;p!=NULL;p=p->next)
			{
				if(Sosanh_Ngay(tu,p->hd.ngay)==true&&Sosanh_Ngay(p->hd.ngay,den)==true && p->hd.Loai=='X')
				{
					for (int k=0;k<p->hd.ds.sl;k++)
					{
						if((strcmp(ds[j]->MaVT,p->hd.ds.DSCT[k].MaVT)==0)) 
						{
							ds[j]->SoLuongTon=ds[j]->SoLuongTon+p->hd.ds.DSCT[k].SoLuong; // so luong ban ra 
							a[j]=a[j]+p->hd.ds.DSCT[k].SoLuong*p->hd.ds.DSCT[k].DonGia/100*(p->hd.ds.DSCT[k].VAT+100); // thanh tien
							
						}
					}
				}
							
			}
		}
	}
	
}
void Swap_tong(long long &a,long long &b)
{
	long long tam=a;
	a=b;
	b=tam;
}
void Sapxep_Vattu(VATTU* ds[],long long a[], int sl)
{
	for(int i=0;i<sl-1;i++)
	{
		for(int j=i+1;j<sl;j++)
		{
			if(a[i]<a[j])
			{
				swapvt(ds[i],ds[j]);
				Swap_tong(a[i],a[j]);
			}
		}
	}
}
void Run_TK(DS_NHANVIEN ds_nv,TREE tree)
{
	int x=0,y=110;
	char *nam=new char[5];
	char *ngay=new char[3];
	NGAY tu;
	NGAY den;	
	settextstyle(0,0,3);
	clearmouseclick(WM_LBUTTONDOWN);
	while(1)
	{
		delay(1);
		if(mouse_TK()==5)
		{	
			xl_phim();
			nhapso(ngay,x+470,y+148,3,0,470,260,530,290);	
			tu.Ngay=atoi(ngay);		
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_TK()==6)
		{			
			xl_phim();
			nhapso(ngay,x+720,y+148,3,0,x+720,y+150,x+780,y+180);	
			tu.Thang=atoi(ngay);			
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_TK()==7)
		{			
			xl_phim();
			nhapso(nam,x+910,y+148,5,0,x+910,y+150,x+1030,y+180);	
			tu.Nam=atoi(nam);			
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_TK()==8)
		{			
			xl_phim();
			nhapso(ngay,x+470,y+298,3,0,x+470,y+300,x+530,y+330);	
			den.Ngay=atoi(ngay);
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_TK()==9)
		{
			xl_phim();
			nhapso(ngay,x+720,y+298,3,0,x+720,y+300,x+780,y+330);	
			den.Thang=atoi(ngay);
			clearmouseclick(WM_LBUTTONDOWN);		
		}
		if(mouse_TK()==10)
		{			
			xl_phim();
			nhapso(nam,x+910,y+298,5,0,x+910,y+300,x+1030,y+330);	
			den.Nam=atoi(nam);
			clearmouseclick(WM_LBUTTONDOWN);	
		}
		if(mouse_TK()==11)
		{			
			if(ngaydung(tu)==false || ngaydung(den)==false || Sosanh_Ngay(tu,den)==false )
			{
				outtextxy(800,150,"Thoi gian sai!");
				delay(1000);	
				xoatb(799,148,1270,180,15);
				setbkcolor(15);			
				normal_text(15,0);					
				setbkcolor(15);					
			}
			else 
			{
				bang_tkhd();
				outtextxy(350,125,"Tu ngay:");
				In_Ngay(500,125,tu);
				outtextxy(730,125,"Den:");
				In_Ngay(800,125,den);				
				In_HDTK(ds_nv,tu,den,x,y+60);			
			}
			clearmouseclick(WM_LBUTTONDOWN);	
		}		
		if(mouse_TK()==12)
		{			
			if(ngaydung(tu)==false || ngaydung(den)==false || Sosanh_Ngay(tu,den)==false )
			{
				outtextxy(800,150,"Thoi gian sai!");
				delay(1000);	
				xoatb(799,148,1270,180,15);	
				normal_text(15,0);				
				setbkcolor(15);	
			}
			else 
			{
				delay(1000);			
				mh_InTopvt();
				outtextxy(350,150,"Tu ngay:");
				In_Ngay(500,150,tu);
				outtextxy(730,150,"Den:");
				In_Ngay(800,150,den);
				setbkcolor(15);
				int nds = 0;
				demslvt(tree,nds);		
				VATTU *ds[nds];							
				long long tongdt[nds]={0};							
				nds = 0;							
				chuyencaysangmang(tree,ds,nds);											
				for(int i=0;i<nds;i++) // reset slt
				{
					ds[i]->SoLuongTon=0;
				}				
				capnhathd(ds,ds_nv,tongdt,nds,tu,den);				
				Sapxep_Vattu(ds,tongdt,nds);				
				InTopvt(ds,tongdt);
			}						
			clearmouseclick(WM_LBUTTONDOWN);		
		}
		if(mouse_TK()<5&&mouse_TK()!=-1) break;
	}
	delete []nam;
	delete []ngay;
}
//====================================================
void Run(DS_NHANVIEN &DSNV,TREE tree, PTRNODE_HD hd){
	initwindow(trucx,trucy);		
	setbkcolor(8);					
	cleardevice();	
	mhchinh();
	int start = 0;
	while(1)
	{
		delay(1);
		int x=50,y=0;
		settextstyle(0,0,2);	
		{
			if(mouse_VT(start)==0)
			{
				highlight_box(40,50,260,90,"VAT TU",3,3,8,50);
				delay(200);
				system("cls");	
				mhchinh();
				normal_box(40,50,260,90,"VAT TU",3,3,8,50);
				mh_dsvt();
				clearmouseclick(WM_LBUTTONDOWN);				
				Run_VT(tree,DSNV);
			}			
			else if (mouse_NV(start)==1)
			{
				highlight_box(360,50,580,90,"NHAN VIEN",3,3,8,30);	
				delay(200);
				system("cls");	
				mhchinh();
				normal_box(360,50,580,90,"NHAN VIEN",3,3,8,30);			
				Form_NhanVien();
				sapxep_dsnv(DSNV);	// luc bat lên nut nv								
				int so=0;
				insotrang(so+1,DSNV.sl,100,100); 				
				IN_DSNV(DSNV,x,y+250,so,min(10*(so+1),DSNV.sl));
				clearmouseclick(WM_LBUTTONDOWN);
				Run_NV(DSNV);																			
			}
			else if(mouse_VT(start)==2)
			{
				highlight_box(680,50,900,90,"HOA DON",3,3,8,30);
				delay(200);		
				system("cls");	
				mhchinh();
				normal_box(680,50,900,90,"HOA DON",3,3,8,30);
				mh_hd();
				clearmouseclick(WM_LBUTTONDOWN);				
				Run_HD(DSNV,tree);		 	
			}
			else if (mouse_VT(start)==3)
			{
				highlight_box(1000,50,1220,90,"THONG KE",3,3,8,30);
				delay(200);
				system("cls");	
				mhchinh();
				normal_box(1000,50,1220,90,"THONG KE",3,3,8,30);
				mh_TKHD();	
				clearmouseclick(WM_LBUTTONDOWN);
				Run_TK(DSNV,tree);
			}
			else if(mouse_VT(start)==4)
			{
				delay(100);			
				system("cls");
				giaiphong(DSNV,tree,hd);
				clearmouseclick(WM_LBUTTONDOWN);
				cout<<"KET THUC CHUONG TRINH";
				closegraph();
				return;
			}
		}		
		
	}
}
int mouse_VT(int &vitri){
	int x,y;
	x=mousex();
	y=mousey();
	if(ismouseclick(WM_LBUTTONDOWN)){
		if(y>=50 && y<=90){
			if(x>=40 && x<= 260) return 0; 
			else if(x>=360 && x<= 580) return 1;
			else if(x>=680 && x<= 900) return 2;
			else if(x>=1000 && x<= 1220) return 3;	
		}	
		else if(y>=5 && y<=33 && x>=1120 && x<=1170) return 4; //thoat ung dung
		else if (y>=120 && y<= 155){
			 if (x>=1000 && x<= 1260) return 5; //them vat tu
		}
		if(x>=1050 && x<= 1260 && y>=180 && y<= 720){	
			for(int i = 0;i<10;i++)// Sua
			{
				if(y >= top1[i]&& y<= bottom1[i] && x>= left1[i] && x<=right1[i])
				{
						vitri = i;						
						return 6;
				}							
			}	
			for(int i = 0;i<10;i++)// Xoa
			{
				if(y >= top2[i]&& y<= bottom2[i] && x>= left2[i] && x<=right2[i])
				{
						vitri = i;
						return 7;
				}			
			}
		}	
		else if(y>=735 && y<= 755){
			 if(x>=530 && x<= 580) return 8;//trang --
			 else if(x>=650 && x<= 700) return 9; //trang ++
		}	
		else if(x>=680 && x<=900 && y>=120 && y<= 155) return 10;// nut tim kiem
		else if(x>=450 && x<=640 && y>=120 && y<= 155) return 11;//bar tim kiem	
		else if (y>=275 && y<= 305&&x>=500 && x<= 900) return 20;//ma vt 
		else if (y>=375 && y<= 405&&x>=500 && x<= 900) return 21;//ten vt
		else if (y>=475 && y<= 505&&x>=500 && x<= 900) return 22;//sl vt
		else if (y>=575 && y<= 605&&x>=500 && x<= 900) return 23;//dvt
		else if (y>=670 && y<=700){
			 if (x>=850 && x<=920) return 24;//nut luu vt/xac nhan xoa
			 else if(x>=750 && x<=825) return 25;//nut huy vt/huy xoa
		}
		else if(x>=643 && x<=678 && y>=120 && y<=155) return 26;
		clearmouseclick(WM_LBUTTONDOWN);
	}		
	return -1;
}
int mouse_NV(int &vitri){
	int x,y;
	x=mousex();
	y=mousey();	
	
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		if(y>=50 && y<=90){
			if(x>=40 && x<= 260) return 0;
			else if(x>=360 && x<= 580) return 1;
			else if(x>=680 && x<= 900) return 2;
			else if(x>=1000 && x<= 1220) return 3;			
		}
		else if(y>=5 && y<=33 && x>=1120 && x<=1170) return 4; // thoat ung dung	
		else if(y>= 120 && y <= 155){
			if(x >= 1000 && x<= 1180) return 20; // them nv
			if(x>= 680 && x<= 900) return 21;// tim kiem
			if(x>=643 && x<= 678) return 22; // x
		}
		else if(x>=510&&x<=540&&y>=730&&y<=760)	return 38; // trang --
		else if(x>=670&&x<=700&&y>=730&&y<=760) return 39; // trang ++			
		else if(x >= 470 && x <= 940 ) 
		{
			if(y >= 265 && y <= 295) return 40; // mã nv
			else if(y >= 335 && y <= 365) return 41; // ho nv
			else if(y >= 405 && y<= 435) return 42; // tennv			
		}
		if( y>=485 && y<=515)  
		{
			if(x >= 450 && x <= 500) return 43; // nam 
			if(x >= 550 && x <= 600) return 44;// nu	
		}
		if( y>=670 && y<=700) 
		{
			if(x >= 850 && x<=920) return 45; // luu
			else if( x >= 750 && x<=825) return 46; // thoat 
		}			
		for(int i = 0;i<10;i++) // lay vi tri nut hieu chinh
		{
			if(y >= top1[i]&& y<= bottom1[i] && x>= left1[i] && x<=right1[i])
			{
					vitri = i;
					return 50;
			}			
		}	
		for(int i = 0;i<10;i++) // vi tri nut xoa
		{
			if(y >= top2[i]&& y<= bottom2[i] && x>= left2[i] && x<=right2[i])
			{
					vitri = i;
					return 51;
			}			
		}
		if(y>=120 && y<=155 && x>=450 && x<=640) return 53; // nhap timkiem	
		
		clearmouseclick(WM_LBUTTONDOWN);	
	}
	return -1;
}
int mouse_HD(int &vitri){
	int x,y;
	x=mousex();
	y=mousey();
	if(ismouseclick(WM_LBUTTONDOWN)){
		if(y>=50 && y<=90){
			if(x>=40 && x<= 260) return 0; 
			else if(x>=360 && x<= 580) return 1;
			else if(x>=680 && x<= 900) return 2;
			else if(x>=1000 && x<= 1220) return 3;	
		}	
		else if(y>=5 && y<=33 && x>=1120 && x<=1170) return 4; //thoat ung dung
		else if(y>=120 && y<=155){
			 if(x>=5 && x<=105) return 5; //nhap
			else if(x>=150 && x<=250) return 6;//xuat
			else if(x>=300 && x<=500) return 7;//in hoa don
		}
		else if(y>=205 && y<=230){ 
			 if (x>=21 && x<= 351) return 8;//soHD
			 else if(x>=421 && x<=621) return 9; //Ma NV
			 else if(x>=671 && x<=771) return 10;//ngay 
			 else if(x>=871 && x<= 971) return 11;//thang 
			 else if(x>=1071 && x<= 1171) return 12;//nam
		}
		else if(y>=265 && y<=295)
		{
		 	if(x>= 20 && x<= 290) return 13;//mavt
		 	else if(x>=340 && x<= 590) return 14;//soluong
		 	else if(x>=640 && x<= 890)	return 15;//don gia
		 	else if(x>=960 && x<= 1020) return 16;//VAT
		 	else if(x>=1090 && x<=1205) return 17;//them
		}
		else if(x>=610 && x<=820 &&y>=725 &&y<=755) return 19;//thanh toan
		if(x>=1140 && x<= 1250 && y>=315 && y<= 715){	
			for(int i = 0;i<10;i++)// Xoa
			{
				if(y >= top2[i]&& y<= bottom2[i] && x>= left2[i] && x<=right2[i])
				{
						vitri = i;					
						return 18;
				}					
			}	
		}
		else if(y>=725 && y<=745){
			 if(x>=1080 && x<= 1130) return 20;//trang--
			 else if(x>=1200 && x<=1250) return 21;//trang
		}
		if(x>=450 && x<=950 && y>=395 && y<=445) return 30; 
		if (x>=625 && x<=700 && y>=470 && y<=505) return 31;
		clearmouseclick(WM_LBUTTONDOWN);
	}
	return -1;
}
int mouse_TK()
{
	int x,y;
	x=mousex();
	y=mousey();
	if(ismouseclick(WM_LBUTTONDOWN))
	{
		if(y>=50 && y<=90){
			if(x>=40 && x<= 260) return 0; 
			else if(x>=360 && x<= 580) return 1;
			else if(x>=680 && x<= 900) return 2;
			else if(x>=1000 && x<= 1220) return 3;	
		}	
		else if(y>=5 && y<=33 && x>=1120 && x<=1170) return 4; //thoat ung dung
		if(y>=260 && y<=290)
		{
			if(x >= 470 && x<= 530) return 5;
			else if(x>=720 && x<=780) return 6;
			else if(x>=910 && x<=1030) return 7;
		}
		if(y>=410&&y<=440)
		{
			if(x>=470 && x<=530) return 8;
			else if(x>=720 && x<=780) return 9;			
			else if(x>=910 && x<=1030) return 10;		
		}
		if(y>=460&&y<=500)
		{
			if(x>=375&&x<=620) return 11;//tkvt
			else if(x>=725&&x<=1100) return 12; // tk top10 vt 
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{	
	TREE tree = NULL;
	DS_NHANVIEN DSNV;
	PTRNODE_HD hd;
	Create_Tree(tree);	
	docFile_NV(DSNV);
	docfilehd(DSNV);
	Run(DSNV,tree,hd);
	getch();	
	return 0;
}
