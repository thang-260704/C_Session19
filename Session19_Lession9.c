#include <stdio.h>
#include <string.h>

#define MAX_SV 100
#define MAX_TEN 50

typedef struct {
    char hoTen[MAX_TEN];
    int tuoi;
    float diemTB;
} SinhVien;

SinhVien danhSach[MAX_SV];
int soLuongSV = 0;

void hienThiDanhSach() {
    printf("\nDanh sách sinh viên:\n");
    printf("%-20s %-5s %-5s\n", "Họ Tên", "Tuổi", "Điểm TB");
    for (int i = 0; i < soLuongSV; i++) {
        printf("%-20s %-5d %-5.2f\n", danhSach[i].hoTen, danhSach[i].tuoi, danhSach[i].diemTB);
    }
}

void themSinhVien() {
    if (soLuongSV >= MAX_SV) {
        printf("\nKhông thể thêm, danh sách đã đầy!\n");
        return;
    }
    
    SinhVien sv;
    printf("\nNhập họ tên sinh viên: ");
    scanf("%s", sv.hoTen);
    printf("Nhập tuổi sinh viên: ");
    scanf("%d", &sv.tuoi);
    printf("Nhập điểm trung bình: ");
    scanf("%f", &sv.diemTB);

    danhSach[soLuongSV++] = sv;
    printf("\nThêm thành công!\n");
}
void suaThongTinSinhVien() {
    char hoTen[MAX_TEN];
    printf("\nNhập họ tên sinh viên cần sửa: ");
    scanf("%s", hoTen);

    for (int i = 0; i < soLuongSV; i++) {
        if (strcmp(danhSach[i].hoTen, hoTen) == 0) {
            printf("Nhập tuổi mới: ");
            scanf("%d", &danhSach[i].tuoi);
            printf("Nhập điểm trung bình mới: ");
            scanf("%f", &danhSach[i].diemTB);
            printf("\nCập nhật thành công!\n");
            return;
        }
    }

    printf("\nKhông tìm thấy sinh viên!\n");
}

void xoaSinhVien() {
    char hoTen[MAX_TEN];
    printf("\nNhập họ tên sinh viên cần xóa: ");
    scanf("%s", hoTen);

    for (int i = 0; i < soLuongSV; i++) {
        if (strcmp(danhSach[i].hoTen, hoTen) == 0) {
            for (int j = i; j < soLuongSV - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            soLuongSV--;
            printf("\nXóa thành công!\n");
            return;
        }
    }

    printf("\nKhông tìm thấy sinh viên!\n");
}

void timKiemSinhVien() {
    char hoTen[MAX_TEN];
    printf("\nNhập họ tên sinh viên cần tìm: ");
    scanf("%s", hoTen);

    for (int i = 0; i < soLuongSV; i++) {
        if (strcmp(danhSach[i].hoTen, hoTen) == 0) {
            printf("\nSinh viên tìm thấy:\n");
            printf("%-20s %-5d %-5.2f\n", danhSach[i].hoTen, danhSach[i].tuoi, danhSach[i].diemTB);
            return;
        }
    }

    printf("\nKhông tìm thấy sinh viên!\n");
}

void sapXepDanhSach() {
    for (int i = 0; i < soLuongSV - 1; i++) {
        for (int j = i + 1; j < soLuongSV; j++) {
            if (danhSach[i].diemTB < danhSach[j].diemTB) {
                SinhVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("\nDanh sách đã được sắp xếp!\n");
}

int main() {
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Hiển thị danh sách sinh viên\n");
        printf("2. Thêm sinh viên\n");
        printf("3. Sửa thông tin sinh viên\n");
        printf("4. Xóa sinh viên\n");
        printf("5. Tìm kiếm sinh viên\n");
        printf("6. Sắp xếp danh sách sinh viên\n");
        printf("7. Thoát\n");
        printf("\nLựa chọn của bạn: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiDanhSach();
                break;
            case 2:
                themSinhVien();
                break;
            case 3:
                suaThongTinSinhVien();
                break;
            case 4:
                xoaSinhVien();
                break;
            case 5:
                timKiemSinhVien();
                break;
            case 6:
                sapXepDanhSach();
                break;
            case 7:
                printf("\nThoát chương trình!\n");
                break;
            default:
                printf("\nLựa chọn không hợp lệ!\n");
                break;
        }
    } while (luaChon != 7);

    return 0;
}
