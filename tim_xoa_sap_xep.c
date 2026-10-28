
#include <stdio.h>
#include <string.h>
#include "common.h"

// 1. Tim vi tri don in theo ma don
int timViTri(char ma[]) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(maDon[i], ma) == 0) {
            return i;
        }
    }

    return -1;
}

// 2. Liet ke danh sach don in
void lietKeDon(void) {
    int i;

    if (n == 0) {
        printf("Danh sach don in dang rong!\n");
        return;
    }

    printf("\n========== DANH SACH DON IN ==========\n");
    printf("%-10s %-25s %10s %10s %12s %15s\n",
           "Ma don", "Ten don", "So trang",
           "So ban", "Loai in", "Gia sau giam");

    for (i = 0; i < n; i++) {
        printf("%-10s %-25s %10d %10d %12s %15.2f\n",
               maDon[i],
               tenDon[i],
               soTrang[i],
               soBan[i],
               loaiIn[i] == 0 ? "Den trang" : "Mau",
               tinhGiaCuoi(i));
    }

    printf("Don vi gia: nghin dong\n");
}

// 3. Xoa don in theo ma don
void xoaDon(int *n) {
    char ma[10];
    char xacNhan;
    int viTri;
    int i;

    if (*n == 0) {
        printf("Danh sach don in dang rong!\n");
        return;
    }

    printf("Nhap ma don can xoa: ");
    if (scanf("%9s", ma) != 1) {
        printf("Loi nhap ma don!\n");
        return;
    }

    viTri = timViTri(ma);

    if (viTri == -1) {
        printf("Khong tim thay ma don %s!\n", ma);
        return;
    }

    printf("Ban co chac chan muon xoa don %s? (Y/N): ", ma);
    if (scanf(" %c", &xacNhan) != 1) {
        printf("Loi nhap xac nhan!\n");
        return;
    }

    if (xacNhan != 'Y' && xacNhan != 'y') {
        printf("Da huy thao tac xoa!\n");
        return;
    }

    // Don cac mang song song
    for (i = viTri; i < *n - 1; i++) {
        strcpy(maDon[i], maDon[i + 1]);
        strcpy(tenDon[i], tenDon[i + 1]);

        soTrang[i] = soTrang[i + 1];
        soBan[i] = soBan[i + 1];
        loaiIn[i] = loaiIn[i + 1];
    }

    (*n)--;

    printf("Xoa don thanh cong!\n");
}

// 4. Sap xep theo gia sau giam tang dan
// Neu gia bang nhau, sap xep theo ma don tang dan
void sapXepDon(void) {
    int i, j;
    int tam;
    int daDoiCho;
    double gia1, gia2;
    char maTam[10];
    char tenTam[51];

    if (n <= 0) {
        printf("Danh sach don in dang rong!\n");
        return;
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        daDoiCho = 0;

        for (j = 0; j < n - 1 - i; j++) {
            gia1 = tinhGiaCuoi(j);
            gia2 = tinhGiaCuoi(j + 1);

            if (gia1 > gia2 ||
                (gia1 == gia2 &&
                 strcmp(maDon[j], maDon[j + 1]) > 0)) {

                strcpy(maTam, maDon[j]);
                strcpy(maDon[j], maDon[j + 1]);
                strcpy(maDon[j + 1], maTam);

                strcpy(tenTam, tenDon[j]);
                strcpy(tenDon[j], tenDon[j + 1]);
                strcpy(tenDon[j + 1], tenTam);

                tam = soTrang[j];
                soTrang[j] = soTrang[j + 1];
                soTrang[j + 1] = tam;

                tam = soBan[j];
                soBan[j] = soBan[j + 1];
                soBan[j + 1] = tam;

                tam = loaiIn[j];
                loaiIn[j] = loaiIn[j + 1];
                loaiIn[j + 1] = tam;

                daDoiCho = 1;
            }
        }

        if (daDoiCho == 0) {
            break;
        }
    }

    printf("Sap xep thanh cong!\n");
    lietKeDon();
}

// 5. Thong ke tong gia tri bao gia theo loai in
void thongKe(void) {
    int i;
    int soDonDenTrang = 0;
    int soDonMau = 0;
    double tongDenTrang = 0;
    double tongMau = 0;

    if (n == 0) {
        printf("Danh sach don in dang rong!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (loaiIn[i] == 0) {
            soDonDenTrang++;
            tongDenTrang += tinhGiaCuoi(i);
        } else if (loaiIn[i] == 1) {
            soDonMau++;
            tongMau += tinhGiaCuoi(i);
        }
    }

    printf("\n========== THONG KE DON IN ==========\n");

    printf("Don in den trang:\n");
    printf("So don: %d\n", soDonDenTrang);
    printf("Tong gia tri bao gia: %.2f nghin dong\n",
           tongDenTrang);

    printf("\nDon in mau:\n");
    printf("So don: %d\n", soDonMau);
    printf("Tong gia tri bao gia: %.2f nghin dong\n",
           tongMau);

    printf("\nTong so don: %d\n", n);
    printf("Tong gia tri bao gia: %.2f nghin dong\n",
           tongDenTrang + tongMau);
}
