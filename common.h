#ifndef COMMON_H
#define COMMON_H

#define MAX 100

extern char maDon[MAX][10];
extern char tenDon[MAX][51];
extern int soTrang[MAX];
extern int soBan[MAX];
extern int loaiIn[MAX];
extern int n;

void themDon(int *n);
void suaDon(int n);

long long tinhSoTo(int i);
double tinhGiaTheoLoai(long long soTo, int loai);
double tinhGiaGoc(int i);
double tinhGiaCuoi(int i);

void soSanhNganSach(void);

int timViTri(char ma[]);
void lietKeDon(void);
void xoaDon(int *n);
void sapXepDon(void);
void thongKe(void);

#endif