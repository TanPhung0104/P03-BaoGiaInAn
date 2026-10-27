
#include <stdio.h>
#include "common.h"

// Tinh so to in
long long tinhSoTo(int i) {
    return (long long)soTrang[i] * soBan[i];
}

// Tinh gia goc
double tinhGiaGoc(int i) {
    long long soTo = tinhSoTo(i);
    double gia;

    if (loaiIn[i] == 0) {
        gia = soTo * 1.0;
    } else {
        gia = soTo * 3.0;
    }

    return gia;
}

// Tinh gia cuoi sau khi giam gia
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

    return giaGoc * (1 - giamGia);
}

// Tinh gia theo loai in
double tinhGiaTheoLoai(long long soTo, int loai) {
    double gia;
    double giamGia;

    if (loai == 0) {
        gia = soTo * 1.0;
    } else {
        gia = soTo * 3.0;
    }

    if (soTo < 100) {
        giamGia = 0;
    } else if (soTo < 500) {
        giamGia = 0.05;
    } else {
        giamGia = 0.10;
    }

    return gia * (1 - giamGia);
}
