
#include <stdio.h>
#include <string.h>
#include "common.h"

// Xoa phan con lai trong bo dem ban phim
void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Nhap so nguyen hop le
int nhapSoNguyen(const char thongBao[]) {
    int x;
    int ketQua;

    while (1) {
        printf("%s", thongBao);
        ketQua = scanf("%d", &x);
        xoaBoDem();

        if (ketQua == 1)
            return x;

        printf("Du lieu khong hop le! Vui long nhap so.\n");
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

// Nhap thong tin don in
void nhapThongTin(int i, int soLuong, int choPhepDoiMa) {
    char ma[10];
    int x;

    // Nhap ma don
    if (choPhepDoiMa) {
        do {
            printf("Nhap ma don in: ");
            scanf("%9s", ma);
            xoaBoDem();

            if (maDonTonTai(ma, soLuong, i))
                printf("Ma don da ton tai! Vui long nhap lai.\n");

        } while (maDonTonTai(ma, soLuong, i));

        strcpy(maDon[i], ma);
    }

    // Nhap ten don
    printf("Nhap ten don in: ");
    fgets(tenDon[i], sizeof(tenDon[i]), stdin);
    tenDon[i][strcspn(tenDon[i], "\n")] = '\0';

    while (strlen(tenDon[i]) == 0) {
        printf("Ten don khong duoc de trong! Nhap lai: ");
        fgets(tenDon[i], sizeof(tenDon[i]), stdin);
        tenDon[i][strcspn(tenDon[i], "\n")] = '\0';
    }

    // Nhap so trang
    do {
        x = nhapSoNguyen("Nhap so trang: ");
        if (x <= 0)
            printf("So trang phai lon hon 0!\n");
    } while (x <= 0);
    soTrang[i] = x;

    // Nhap so ban
    do {
        x = nhapSoNguyen("Nhap so ban: ");
        if (x <= 0)
            printf("So ban phai lon hon 0!\n");
    } while (x <= 0);
    soBan[i] = x;

    // Nhap loai in
    do {
        x = nhapSoNguyen("Loai in (1. Den trang, 2. In mau): ");
        if (x != 1 && x != 2)
            printf("Loai in chi duoc chon 1 hoac 2!\n");
    } while (x != 1 && x != 2);
    loaiIn[i] = x;
}

// Chuc nang 1: Them don in
void themDon(int *n) {
    if (*n >= MAX) {
        printf("Danh sach da day, khong the them don!\n");
        return;
    }

    printf("\n===== THEM DON IN =====\n");
    nhapThongTin(*n, *n, 1);

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
    printf("Nhap ma don can sua: ");
    scanf("%9s", ma);
    xoaBoDem();

    // Tim don can sua
    for (i = 0; i < n; i++) {
        if (strcmp(maDon[i], ma) == 0)
            break;
    }

    if (i == n) {
        printf("Khong tim thay ma don %s!\n", ma);
        return;
    }

    printf("Nhap thong tin moi cho don %s:\n", maDon[i]);

    // Sua ten, so trang, so ban va loai in
    nhapThongTin(i, n, 0);

    printf("Sua don in thanh cong!\n");
}
