#include <stdio.h>
#include <math.h>
#include "common.h"

#define EPSILON 1e-6

static void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void soSanhNganSach(void) {
    if (n <= 0) {
        printf("\n[Thong bao] Danh sach don in hien dang rong! Vui long them don truoc.\n");
        return;
    }

    double nganSach;
    int kqNhap;

    while (1) {
        printf("\nNhap ngan sach hien co cua CLB (nghin dong, >= 0): ");
        kqNhap = scanf("%lf", &nganSach);

        if (kqNhap == EOF) {
            printf("\n[Thong bao] Phat hien EOF. Quay ve menu chinh.\n");
            return;
        }

        if (kqNhap != 1 || !isfinite(nganSach) || nganSach < 0) {
            printf("[Loi] Ngan sach khong hop le! Vui long nhap mot so thuc >= 0.\n");
            xoaBoDem();
        } else {
            xoaBoDem();
            break;
        }
    }

    double tongChiPhi = 0.0;
    for (int i = 0; i < n; i++) {
        tongChiPhi += tinhGiaCuoi(i);
    }

    printf("\n================ KET QUA SO SANH NGAN SACH ================\n");
    printf("- So luong don in hien co : %d don\n", n);
    printf("- Tong chi phi cac don in : %.2f nghin dong\n", tongChiPhi);
    printf("- Ngan sach hien co       : %.2f nghin dong\n", nganSach);
    printf("-----------------------------------------------------------\n");

    double chenhLech = nganSach - tongChiPhi;

    if (fabs(chenhLech) <= EPSILON) {
        printf("=> KET LUAN: DU NGAN SACH (Vua du, so tien con du: 0.00 nghin dong).\n");
    } else if (chenhLech > EPSILON) {
        printf("=> KET LUAN: DU NGAN SACH.\n");
        printf("   So tien con du: %.2f nghin dong.\n", chenhLech);
    } else {
        printf("=> CANH BAO: VUOT NGAN SACH!\n");
        printf("   So tien con thieu: %.2f nghin dong.\n", fabs(chenhLech));
    }
    printf("===========================================================\n");
}