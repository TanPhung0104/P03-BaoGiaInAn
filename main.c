
#include <stdio.h>
#include "common.h"

char maDon[MAX][10];
char tenDon[MAX][51];
int soTrang[MAX];
int soBan[MAX];
int loaiIn[MAX];
int n = 0;

// Xoa phan con lai trong bo dem ban phim
void xoaBoDemMain(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {
    int chon;
    int ketQua;

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

        ketQua = scanf("%d", &chon);

        if (ketQua == EOF) {
            printf("\nKet thuc chuong trinh!\n");
            break;
        }

        xoaBoDemMain();

        if (ketQua != 1) {
            printf("Lua chon phai la so nguyen!\n");
            continue;
        }

        switch (chon) {
            case 1:
                themDon(&n);
                break;

            case 2:
                suaDon(n);
                break;

            case 3:
                lietKeDon();
                break;

            case 4:
                soSanhNganSach();
                break;

            case 5: {
                char ma[10];

                printf("Nhap ma don can tim: ");
                if (scanf("%9s", ma) != 1) {
                    printf("Khong doc duoc ma don!\n");
                    break;
                }

                xoaBoDemMain();

                int viTri = timViTri(ma);

                if (viTri == -1) {
                    printf("Khong tim thay don in!\n");
                } else {
                    printf("\n===== THONG TIN DON IN =====\n");
                    printf("Ma don: %s\n", maDon[viTri]);
                    printf("Ten don: %s\n", tenDon[viTri]);
                    printf("So trang: %d\n", soTrang[viTri]);
                    printf("So ban: %d\n", soBan[viTri]);
                    printf("Loai in: %s\n",
                           loaiIn[viTri] == 0 ? "Den trang" : "In mau");
                    printf("So to: %lld\n", tinhSoTo(viTri));
                    printf("Gia cuoi: %.2f nghin dong\n",
                           tinhGiaCuoi(viTri));
                }
                break;
            }

            case 6:
                xoaDon(&n);
                break;

            case 7:
                sapXepDon();
                printf("Da sap xep danh sach theo gia cuoi.\n");
                lietKeDon();
                break;

            case 8:
                thongKe();
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
