#include <stdio.h>
#include <math.h>

// Khai báo các hàm c?n dùng
void timSoNguyenTo();
void timUCLN_BCNN();
void tinhTienKaraoke();
void tinhTienDien();
void tinhTienVayNganHang();

// Hàm tìm UCLN (U?c chung l?n nh?t) - Thu?t toán Euclid
int UCLN(int a, int b) {
    while (b) {
        a %= b;
        // Hoán d?i a và b
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

// Hàm chính (Main Function)
int main() {
    int choice;
    
    do {
        // In Menu
        printf("\n========== MENU CHUONG TRINH ==========\n");
        printf("1. Chuc nang tim tinh nguyen (Kiem tra So Nguyen To)\n");
        printf("2. Chuc nang tim UCLN va BCNN\n");
        printf("3. Chuc nang tinh tien quan Karaoke\n");
        printf("4. Chuc nang tinh tien dien\n");
        printf("6. Chuc nang vay tien ngan hang\n");
        printf("0. Thoat chuong trinh\n");
        printf("=======================================\n");
        printf("Moi ban chon chuc nang: ");
        
        // Ki?m tra d?u vào h?p l?
        if (scanf("%d", &choice) != 1) {
            // X? lý khi ngu?i dùng nh?p ký t? thay vì s?
            while (getchar() != '\n');
            choice = -1; // Ð?t giá tr? không h?p l?
        }

        switch (choice) {
            case 1:
                timSoNguyenTo();
                break;
            case 2:
                timUCLN_BCNN();
                break;
            case 3:
                tinhTienKaraoke();
                break;
            case 4:
                tinhTienDien();
                break;
            case 6:
                tinhTienVayNganHang();
                break;
            case 0:
                printf("Da thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

// 1. Ch?c nang tìm tính nguyên (Ki?m tra S? Nguyên T?)
void timSoNguyenTo() {
    int n, i, isPrime = 1; // isPrime = 1 là true (là s? nguyên t?)
    printf("\n--- KIEM TRA SO NGUYEN TO ---\n");
    printf("Nhap so nguyen duong can kiem tra: ");
    scanf("%d", &n);

    if (n <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                isPrime = 0;
                break; 
            }
        }
    }

    if (isPrime)
        printf("%d LA so nguyen to.\n", n);
    else
        printf("%d KHONG phai la so nguyen to.\n", n);
}

// 2. Ch?c nang tìm UCLN và BCNN
void timUCLN_BCNN() {
    int a, b, ucln, bcnn;
    printf("\n--- TIM UCLN VA BCNN ---\n");
    printf("Nhap so nguyen duong thu nhat (a): ");
    scanf("%d", &a);
    printf("Nhap so nguyen duong thu hai (b): ");
    scanf("%d", &b);

    // Kiem tra du lieu dau vao
    if (a <= 0 || b <= 0) {
        printf("Vui long nhap cac so nguyen duong.\n");
        return;
    }

    // UCLN du?c tính b?ng hàm ph? tr? UCLN(a, b)
    ucln = UCLN(a, b); 
    // BCNN du?c tính theo công th?c: BCNN(a, b) = (|a * b|) / UCLN(a, b)
    bcnn = (a * b) / ucln; 

    printf("UCLN cua %d va %d la: %d\n", a, b, ucln);
    printf("BCNN cua %d va %d la: %d\n", a, b, bcnn);
}

// 3. Ch?c nang tính ti?n quán Karaoke (Gi? d?nh quy t?c tính)
void tinhTienKaraoke() {
    float hours, totalCost;
    // Gi? d?nh: 3 gi? d?u: 150k/gi?. Gi? sau: 120k/gi?.
    const float GIA_3_GIO_DAU = 150000.0;
    const float GIA_GIO_TIEP_THEO = 120000.0;
    const int GIO_NGUONG = 3;

    printf("\n--- TINH TIEN KARAOKE ---\n");
    printf("Nhap so gio su dung dich vu: ");
    scanf("%f", &hours);

    if (hours <= 0) {
        printf("So gio su dung khong hop le.\n");
        return;
    }

    if (hours <= GIO_NGUONG) {
        // Tinh theo gia 3 gio dau
        totalCost = hours * GIA_3_GIO_DAU;
    } else {
        // 3 gio dau tinh theo gia 150k, cac gio con lai tinh theo gia 120k
        totalCost = (GIO_NGUONG * GIA_3_GIO_DAU) + ((hours - GIO_NGUONG) * GIA_GIO_TIEP_THEO);
    }

    printf("Tong so tien Karaoke phai thanh toan la: %.0f VND\n", totalCost);
}

// 4. Ch?c nang tính ti?n di?n (Gi? d?nh 2 B?c thang)
void tinhTienDien() {
    float kWh, cost;
    // Gi? d?nh: B?c 1 (0-100 kWh) @ 1,734 VND/kWh. B?c 2 (>100 kWh) @ 2,014 VND/kWh.
    const float GIA_BAC_1 = 1734.0; 
    const float GIA_BAC_2 = 2014.0; 
    const int NGUONG_BAC_1 = 100;

    printf("\n--- TINH TIEN DIEN (2 Bac) ---\n");
    printf("Nhap so kWh tieu thu trong thang: ");
    scanf("%f", &kWh);

    if (kWh <= 0) {
        printf("So kWh tieu thu khong hop le. Tong tien: 0 VND\n");
        return;
    }
    
    if (kWh <= NGUONG_BAC_1) {
        cost = kWh * GIA_BAC_1;
    } else {
        // Tinh tien cho 100 kWh dau tien
        float tienBac1 = NGUONG_BAC_1 * GIA_BAC_1;
        // Tinh tien cho phan con lai o Bac 2
        float so_kWh_Bac2 = kWh - NGUONG_BAC_1;
        float tienBac2 = so_kWh_Bac2 * GIA_BAC_2;
        cost = tienBac1 + tienBac2;
    }

    printf("So kWh tieu thu: %.2f\n", kWh);
    printf("Tong tien dien phai thanh toan la: %.0f VND\n", cost);
}

// 6. Ch?c nang vay ti?n ngân hàng (Gi? d?nh Lãi su?t c? d?nh - Flat Rate)
void tinhTienVayNganHang() {
    double principal, years, totalInterest, totalRepayment, monthlyPayment;
    // Gi? d?nh: Lãi su?t c? d?nh 12%/nam
    const double LAI_SUAT_NAM = 0.12; 

    printf("\n--- TINH TIEN VAY NGAN HANG (Lai suat co dinh) ---\n");
    printf("Nhap so tien goc can vay (VND): ");
    scanf("%lf", &principal);
    printf("Nhap thoi han vay (Nam): ");
    scanf("%lf", &years);

    if (principal <= 0 || years <= 0) {
        printf("So tien vay va thoi han phai lon hon 0.\n");
        return;
    }

    int totalMonths = (int)(years * 12);
    
    // Tinh tong so tien lai phai tra: Goc * Lai suat nam * So nam
    totalInterest = principal * LAI_SUAT_NAM * years;

    // Tong so tien phai tra
    totalRepayment = principal + totalInterest;

    // So tien tra hang thang (Goc + Lai) / Tong so thang
    monthlyPayment = totalRepayment / totalMonths;

    printf("\n--- KET QUA VAY VON (Lai suat 12%%/nam - Co dinh) ---\n");
    printf("So tien goc: %.0f VND\n", principal);
    printf("Thoi han vay: %d thang\n", totalMonths);
    printf("Tong tien lai phai tra: %.0f VND\n", totalInterest);
    printf("Tong tien phai tra (Goc + Lai): %.0f VND\n", totalRepayment);
    printf("**So tien can tra hang thang: %.0f VND**\n", monthlyPayment);
}
