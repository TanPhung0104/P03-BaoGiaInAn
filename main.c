#include <stdio.h>
#include "common.h"

char maDon[MAX][10];
char tenDon[MAX][51];
int soTrang[MAX];
int soBan[MAX];
int loaiIn[MAX];
int n = 0;

int main() {
    int chon;

    do {
        printf("\n===== BAO GIA IN AN CHO CLB =====\n");
        printf("1. Them don in\n");
        printf("2. Sua don in\n");
        printf("3. Tinh bao gia\n");
        printf("4. So sanh ngan sach\n");
        printf("5. Tim kiem don in\n");
        printf("6. Xoa don in\n");
        printf("7. Sap xep don in\n");
        printf("8. Thong ke don in\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                printf("Chuc nang them don in\n");
                break;
            case 2:
                printf("Chuc nang sua don in\n");
                break;
            case 3:
                printf("Chuc nang tinh bao gia\n");
                break;
            case 4:
                printf("Chuc nang so sanh ngan sach\n");
                break;
            case 5:
                printf("Chuc nang tim kiem don in\n");
                break;
            case 6:
                printf("Chuc nang xoa don in\n");
                break;
            case 7:
                printf("Chuc nang sap xep don in\n");
                break;
            case 8:
                printf("Chuc nang thong ke don in\n");
                break;
            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);

    return 0;
}