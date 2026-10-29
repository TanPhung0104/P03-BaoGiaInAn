
#include <stdio.h>
#include "common.h"

// HAM 1: TINH SO TO IN
// Tham so i la vi tri cua don hang trong mang.
// Lay so trang nhan voi so ban de tinh tong so to.
// Dung long long de luu ket qua co the len den 1.000.000 to.
long long tinhSoTo(int i) {
    return (long long)soTrang[i] * soBan[i];
}

// HAM 2: TINH GIA GOC
// Gia goc la gia tien truoc khi giam gia.
// Goi tinhSoTo(i) de lay tong so to cua don hang.
// Neu loai in bang 0 thi la in den trang, don gia 1.0 nghin dong/to.
// Neu loai in khac 0 thi tinh theo gia in mau, 3.0 nghin dong/to.
double tinhGiaGoc(int i) {
    long long soTo = tinhSoTo(i);
    double gia;

    if (loaiIn[i] == 0) {
        gia = soTo * 1.0;
    } else {
        gia = soTo * 3.0;
    }

    // Tra ve gia goc cua don hang.
    return gia;
}

// HAM 3: TINH GIA CUOI SAU KHI GIAM GIA
// Buoc 1: Tinh so to in.
// Buoc 2: Tinh gia goc.
// Buoc 3: Xac dinh muc giam dua tren so to.
// Duoi 100 to: khong giam.
// Tu 100 den 499 to: giam 5%.
// Tu 500 to tro len: giam 10%.
double tinhGiaCuoi(int i) {
    long long soTo = tinhSoTo(i);
    double giaGoc = tinhGiaGoc(i);
    double giamGia;

    if (soTo < 100) {
        giamGia = 0;
    } else if (soTo < 500) {
        giamGia = 0.05;
    } else {
        giamGia = 0.10;
    }

    // Cong thuc gia cuoi = gia goc * (1 - ty le giam).
    // Vi du giam 5% thi gia cuoi bang gia goc * 0.95.
    return giaGoc * (1 - giamGia);
}

// HAM 4: TINH GIA THEO LOAI IN DUOC TRUYEN VAO
// Tham so soTo: tong so to can in.
// Tham so loai: 0 la den trang, 1 la in mau.
// Ham nay tinh gia theo loai in duoc truyen vao,
// khong can thay doi loai in da luu trong don hang.
// Vi vay, ham co the ho tro so sanh hai phuong an in.
double tinhGiaTheoLoai(long long soTo, int loai) {
    double gia;
    double giamGia;

    // Xac dinh gia goc theo loai in.
    if (loai == 0) {
        gia = soTo * 1.0;
    } else {
        gia = soTo * 3.0;
    }

    // Xac dinh muc giam gia theo tong so to.
    if (soTo < 100) {
        giamGia = 0;
    } else if (soTo < 500) {
        giamGia = 0.05;
    } else {
        giamGia = 0.10;
    }

    // Tra ve gia sau khi ap dung muc giam gia.
    return gia * (1 - giamGia);
}
