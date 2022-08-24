const int MaxMaVT = 10;
const int MaxTenVT = 30;
const int MaxDVT = 10;
const int MaxSLT = 10;
const int MaxVT = 100;
const int MaxMaNV = 10;
const int MaxNV=500;
const int MaxHo = 30;
const int MaxTen = 10;
const int MaxPhai = 4;
const int MaxSoHD = 20; 
const int Maxchuoi =16;
const int trucx=1280;
const int trucy=780;
int top1[10],left1[10],right1[10],bottom1[10],top2[10],left2[10],right2[10],bottom2[10];

struct VATTU{
	char MaVT [MaxMaVT];
	char TenVT[MaxTenVT];
	char DonViTinh[MaxDVT];
	int SoLuongTon;
	VATTU *left;
	VATTU *right;
};
typedef VATTU *TREE; 

struct CT_HOADON{
	char MaVT[MaxMaVT];
	int SoLuong;
	double DonGia;
	int VAT;	
};
const int MAX_VT_1_HD=20;
struct DS_CTHoaDon
{
	CT_HOADON DSCT[MAX_VT_1_HD];
	int sl=0; 
};

struct NGAY{
	int Ngay,Thang,Nam;
};
struct HOADON{
	char SoHD[MaxSoHD];
	NGAY ngay;
	char Loai; 
	DS_CTHoaDon ds;
	
};

struct Node_HoaDon{
	HOADON hd;
	Node_HoaDon *next;
};
typedef struct Node_HoaDon *PTRNODE_HD;


struct NHANVIEN{
	char MaNV[MaxMaNV];
	char Ho[MaxHo];
	char Ten[MaxTen];
	char Phai[MaxPhai];
	PTRNODE_HD dshd = NULL; 
};
struct DS_NHANVIEN{
	NHANVIEN *node[MaxNV]; 
	int sl = 0; 
};

char *filevt="ds_vattu.txt";
char *filenv="ds_nhanvien.txt";
char *filehd="ds_hoadon.txt";
char *filemavt="mavt.txt";

