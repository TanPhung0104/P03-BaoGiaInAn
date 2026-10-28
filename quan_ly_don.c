
#include <stdio.h>
#include <string.h>
#include "common.h"

// Xoa phan con lai trong bo dem ban phim
void xoaBoDem(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Nhap so nguyen hop le
int nhapSoNguyen(const char thongBao[]) {
    int x;
    int ketQua;

    while (1) {
        printf("%s", thongBao);
        ketQua = scanf("%d", &x);

        if (ketQua == EOF) {
            printf("\nKet thuc nhap du lieu.\n");
            return -1;
        }

        xoaBoDem();

        if (ketQua == 1)
            return x;

        printf("Du lieu khong hop le! Vui long nhap so nguyen.\n");
    }
}

// Kiem tra ma don da ton tai hay chua
int maDonTonTai(char ma[], int soLuong, int boQua) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (i != boQua && strcmp(maDon[i], ma) == 0)
            return 1;
    }

    return 0;
}

// Nhap chuoi khong rong, co xu ly chuoi qua dai
int nhapChuoi(char thongBao[], char chuoi[], int kichThuoc) {
    int c;
    size_t doDai;

    while (1) {
        printf("%s", thongBao);

        if (fgets(chuoi, kichThuoc, stdin) == NULL)
            return 0;

        doDai = strlen(chuoi);

        if (doDai > 0 && chuoi[doDai - 1] == '\n') {
            chuoi[doDai - 1] = '\0';
        } else {
            c = getchar();

            if (c != '\n' && c != EOF) {
                while ((c = getchar()) != '\n' && c != EOF) {
                }

                printf("Du lieu qua dai! Vui long nhap lai.\n");
                continue;
            }
        }

        if (strlen(chuoi) == 0) {
            printf("Khong duoc de trong! Vui long nhap lai.\n");
            continue;
        }

        return 1;
    }
}

// Nhap thong tin don in vao vi tri i
// choPhepDoiMa = 1: nhap ma moi
// choPhepDoiMa = 0: giu nguyen ma cu
int nhapThongTin(int i, int soLuong, int choPhepDoiMa) {
    char ma[10];
    char ten[51];
    int x;

    // Nhap ma don
    if (choPhepDoiMa) {
        while (1) {
            if (!nhapChuoi("Nhap ma don in: ", ma, sizeof(ma)))
                return 0;

            if (maDonTonTai(ma, soLuong, i)) {
                printf("Ma don da ton tai! Vui long nhap lai.\n");
            } else {
                break;
            }
        }
    }

    // Nhap ten don
    if (!nhapChuoi("Nhap ten don in: ", ten, sizeof(ten)))
        return 0;

    // Nhap so trang: 1 den 1000
    while (1) {
        x = nhapSoNguyen("Nhap so trang (1-1000): ");

        if (x == -1)
            return 0;

        if (x >= 1 && x <= 1000)
            break;

        printf("So trang phai tu 1 den 1000!\n");
    }

    // Nhap so ban: 1 den 1000
    int soBanMoi;

    while (1) {
        soBanMoi = nhapSoNguyen("Nhap so ban (1-1000): ");

        if (soBanMoi == -1)
            return 0;

        if (soBanMoi >= 1 && soBanMoi <= 1000)
            break;

        printf("So ban phai tu 1 den 1000!\n");
    }

    // Nhap loai in theo quy uoc chung cua nhom
    int loaiMoi;

    while (1) {
        loaiMoi = nhapSoNguyen(
            "Loai in (0. Den trang, 1. In mau): "
        );

        if (loaiMoi == -1)
            return 0;

        if (loaiMoi == 0 || loaiMoi == 1)
            break;

        printf("Loai in chi duoc chon 0 hoac 1!\n");
    }

    // Chi cap nhat du lieu sau khi tat ca thong tin hop le
    if (choPhepDoiMa)
        strcpy(maDon[i], ma);

    strcpy(tenDon[i], ten);
    soTrang[i] = x;
    soBan[i] = soBanMoi;
    loaiIn[i] = loaiMoi;

    return 1;
}

// Chuc nang 1: Them don in
void themDon(int *n) {
    if (*n >= MAX) {
        printf("Danh sach da day, khong the them don!\n");
        return;
    }

    printf("\n===== THEM DON IN =====\n");

    if (!nhapThongTin(*n, *n, 1)) {
        printf("Khong them duoc don in.\n");
        return;
    }

    (*n)++;

    printf("Them don in thanh cong!\n");
}

// Chuc nang 2: Sua don in
void suaDon(int n) {
    char ma[10];
    int i;

    if (n <= 0) {
        printf("Danh sach chua co don in!\n");
        return;
    }

    printf("\n===== SUA DON IN =====\n");

    if (!nhapChuoi("Nhap ma don can sua: ", ma, sizeof(ma))) {
        printf("Khong doc duoc ma don.\n");
        return;
    }

    // Tim don can sua
    for (i = 0; i < n; i++) {
        if (strcmp(maDon[i], ma) == 0)
            break;
    }

    if (i == n) {
        printf("Khong tim thay ma don %s!\n", ma);
        return;
    }

    // Luu du lieu cu de khoi phuc neu nhap that bai
    char maCu[10];
    char tenCu[51];
    int trangCu = soTrang[i];
    int banCu = soBan[i];
    int loaiCu = loaiIn[i];

    strcpy(maCu, maDon[i]);
    strcpy(tenCu, tenDon[i]);

    printf("Nhap thong tin moi cho don %s:\n", maDon[i]);

    if (!nhapThongTin(i, n, 0)) {
        strcpy(maDon[i], maCu);
        strcpy(tenDon[i], tenCu);
        soTrang[i] = trangCu;
        soBan[i] = banCu;
        loaiIn[i] = loaiCu;

        printf("Sua khong thanh cong. Da khoi phuc du lieu cu.\n");
        return;
    }

    printf("Sua don in thanh cong!\n");
}
