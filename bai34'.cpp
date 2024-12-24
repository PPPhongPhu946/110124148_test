#include <stdio.h>
#include <string.h>
#define diemtoida 10
#define slltoida 100
void nhapSinhVien(struct SINH_VIEN *sv);
void xuatSinhVien(struct SINH_VIEN sv);
void nhapDanhSachSinhVien(struct SINH_VIEN sinhVien[], int *n);
struct SINH_VIEN* timSinhVienTheoMSSV(struct SINH_VIEN sinhVien[], int n, const char *mssv);
void timSinhVienTheoDiaChi(struct SINH_VIEN sinhVien[], int n, const char *dia_chi);
void timSinhVienTheoGioiTinh(struct SINH_VIEN sinhVien[], int n, const char *gioi_tinh);
void timSinhVienSinhThang8(struct SINH_VIEN sinhVien[], int n);
void timSinhVienTheoTen(struct SINH_VIEN sinhVien[], int n, const char *hoten);
struct NGAY_THANG
{
	int ngay;
	int thang;
	int nam;
};
struct MON_HOC
{
	char mamon[20];
	float diemso;
};

struct SINH_VIEN
{
	char hoten[30], diachi[100], gioitinh[4], mssv[10];
    struct NGAY_THANG ngaysinh;
    int somon;
    struct MON_HOC mon_hoc[diemtoida];
};


int main()
{
	SINH_VIEN sv,kq;
	nhapSinhVien(&sv);
    xuatSinhVien(sv);
    
    int n;
    struct SINH_VIEN sinhVien[slltoida];  
    nhapDanhSachSinhVien(sinhVien, &n);
    
    char mssv[10];
    printf("Nhap MSSV can tim: ");
    scanf("%s", mssv);
    struct SINH_VIEN *svTimThay = timSinhVienTheoMSSV(sinhVien, n, mssv);
    if (svTimThay != NULL) {
        printf("Thong tin sinh vien tim thay:\n");
        xuatSinhVien(*svTimThay);
    } else {
        printf("Khong tim thay sinh vien co MSSV '%s'.\n", mssv);
    }

    // Tìm sinh viên theo tên
    char hoten[30];
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    gets(hoten);
    timSinhVienTheoTen(sinhVien, n, hoten);

    // Tìm sinh viên sinh trong tháng 8
    timSinhVienSinhThang8(sinhVien, n);
    
    // Tìm sinh viên theo gioi tinh
    char gioitinh[4];
    printf("Nhap gioi tinh can tim (Nam/Nu): ");
    gets(gioitinh);
    timSinhVienTheoGioiTinh(sinhVien, n, gioitinh);

    // Tìm sinh viên theo dia chi
    char diachi[100];
    printf("Nhap dia chi can tim: ");
    gets(diachi);
    timSinhVienTheoDiaChi(sinhVien, n, diachi);
    
	return 0;
}

void timSinhVienTheoDiaChi(struct SINH_VIEN sinhVien[], int n, const char *dia_chi) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
	{
        if (strstr(sinhVien[i].diachi, dia_chi)) 
		{
            if (!found) 
			{
                printf("Danh sach sinh vien co dia chi '%s':\n", dia_chi);
                found = 1;
            }
            xuatSinhVien(sinhVien[i]);
        }
    }
    if (!found) 
	{
        printf("Khong tim thay sinh vien co dia chi '%s'.\n", dia_chi);
    }
}

void timSinhVienTheoGioiTinh(struct SINH_VIEN sinhVien[], int n, const char *gioi_tinh) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(sinhVien[i].gioitinh, gioi_tinh)) {
            if (!found) {
                printf("Danh sach sinh vien gioi tinh '%s':\n", gioi_tinh);
                found = 1;
            }
            xuatSinhVien(sinhVien[i]);
        }
    }
    if (!found) {
        printf("Khong co sinh vien gioi tinh '%s'.\n", gioi_tinh);
    }
}


void timSinhVienSinhThang8(struct SINH_VIEN sinhVien[], int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (sinhVien[i].ngaysinh.thang == 8) {
            if (!found) {
                printf("Danh sach sinh vien sinh trong thang 8:\n");
                found = 1;
            }
            xuatSinhVien(sinhVien[i]);
        }
    }
    if (!found) {
        printf("Khong co sinh vien sinh trong thang 8.\n");
    }
}

void timSinhVienTheoTen(struct SINH_VIEN sinhVien[], int n, const char *hoten) 
{
    int found = 0;
    for (int i = 0; i < n; i++) 
	{
        if (strstr(sinhVien[i].hoten, hoten)) 
		{
            if (!found) 
			{
                printf("Danh sach sinh vien co ten '%s':\n", hoten);
                found = 1;
            }
            xuatSinhVien(sinhVien[i]);
        }
    }
    if (!found) 
	{
        printf("Khong tim thay sinh vien co ten '%s'.\n", hoten);
    }
}

struct SINH_VIEN* timSinhVienTheoMSSV(struct SINH_VIEN sinhVien[], int n, const char *mssv) 
{
    for (int i = 0; i < n; i++) {
        if (strcmp(sinhVien[i].mssv, mssv) == 0) 
		{
            return &sinhVien[i];
        }
    }
    return NULL;
}

void nhapDanhSachSinhVien(struct SINH_VIEN sinhVien[], int *n) 
{
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) 
	{
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        nhapSinhVien(&sinhVien[i]);
    }
}


void xuatSinhVien(struct SINH_VIEN sv)
{
	printf("MSSV: %s\n", sv.mssv);
    printf("Ho Ten: %s\n", sv.hoten);
    printf("Ngay Sinh: %d/%d/%4d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi Tinh: %s\n", sv.gioitinh);
    printf("Dia Chi: %s\n", sv.diachi);
    printf("So Mon Hoc: %d\n", sv.somon);
    for (int i = 0; i < sv.somon; i++) 
	{
        printf("\tMon Hoc %d - Ma Mon: %s, Diem: %.2f\n", i + 1, sv.mon_hoc[i].mamon, sv.mon_hoc[i].diemso);	
	}
}


void nhapSinhVien(struct SINH_VIEN *sv) 
{
    printf("Nhap MSSV: ");
    fflush(stdin);
    scanf("%s", sv->mssv);  


    printf("Nhap Ho Ten: ");
    fflush(stdin);
    gets(sv->hoten);
    
    
    printf("Nhap Ngay Sinh (DD MM YYYY): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);


    printf("Nhap Gioi Tinh: ");
    getchar(); 
    gets(sv->gioitinh);
   
   
    printf("Nhap Dia Chi: ");
    gets(sv->diachi);


    printf("Nhap So Mon Hoc: ");
    scanf("%d", &sv->somon);


    for (int i = 0; i < sv->somon; i++) 
	{
        printf("Nhap Ma Mon Hoc %d: ", i + 1);
        scanf("%s", sv->mon_hoc[i].mamon);
        printf("Nhap Diem Mon Hoc %d: ", i + 1);
        scanf("%f", &sv->mon_hoc[i].diemso);
    }
}

