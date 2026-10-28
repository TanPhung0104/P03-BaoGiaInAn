
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "common.h"

#define EPSILON 1e-6

static void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void soSanhNganSach(void) {
    if (n <= 0) {
        printf("\nDanh sach don in dang rong! Vui long them don truoc.\n");
        return;
    }

    char ma[10];
    int viTri;
    double nganSach;
    int kqNhap;

    printf("\nNhap ma don in can so sanh: ");
    if (scanf("%9s", ma) != 1) {
        printf("Khong doc duoc ma don!\n");
        xoaBoDem();
        return;
    }
    xoaBoDem();

    viTri = timViTri(ma);

    if (viTri == -1) {
        printf("Khong tim thay don in co ma %s!\n", ma);
        return;
    }

    while (1) {
        printf("Nhap ngan sach (nghin dong, >= 0): ");
        kqNhap = scanf("%lf", &nganSach);

        if (kqNhap == EOF) {
            printf("\nDa gap EOF. Quay ve menu chinh.\n");
            return;
        }

        if (kqNhap != 1 || !isfinite(nganSach) || nganSach < 0) {
            printf("Ngan sach khong hop le! Hay nhap so thuc >= 0.\n");
            xoaBoDem();
        } else {
            xoaBoDem();
            break;
        }
    }

    long long soTo = tinhSoTo(viTri);

    double giaDenTrang = tinhGiaTheoLoai(soTo, 0);
    double giaMau = tinhGiaTheoLoai(soTo, 1);

    printf("\n======= SO SANH NGAN SACH =======\n");
    printf("Ma don in       : %s\n", maDon[viTri]);
    printf("Ten don in      : %s\n", tenDon[viTri]);
    printf("So to in        : %lld\n", soTo);
    printf("Ngan sach       : %.2f nghin dong\n", nganSach);

    printf("\n1. In den trang: %.2f nghin dong\n", giaDenTrang);
    if (giaDenTrang <= nganSach + EPSILON) {
        printf("   Ket qua: DU ngan sach\n");
        printf("   Con du: %.2f nghin dong\n",
               fmax(0.0, nganSach - giaDenTrang));
    } else {
        printf("   Ket qua: KHONG DU ngan sach\n");
        printf("   Con thieu: %.2f nghin dong\n",
               giaDenTrang - nganSach);
    }

    printf("\n2. In mau: %.2f nghin dong\n", giaMau);
    if (giaMau <= nganSach + EPSILON) {
        printf("   Ket qua: DU ngan sach\n");
        printf("   Con du: %.2f nghin dong\n",
               fmax(0.0, nganSach - giaMau));
    } else {
        printf("   Ket qua: KHONG DU ngan sach\n");
        printf("   Con thieu: %.2f nghin dong\n",
               giaMau - nganSach);
    }

    printf("\nChenh lech giua hai loai in: %.2f nghin dong\n",
           giaMau - giaDenTrang);
    printf("=================================\n");
}
