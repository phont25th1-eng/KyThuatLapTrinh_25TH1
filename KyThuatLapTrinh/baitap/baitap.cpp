

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct SinhVien {
    string maSo;
    string hoTen;
    float diemChuyenCan;
    float diemGiuaKy;
    float diemCuoiKy;
    float diemHocPhan;

    void tinhDiemHP() {
        diemHocPhan = (diemChuyenCan * 0.1) + (diemGiuaKy * 0.3) + (diemCuoiKy * 0.6);
    }
};

void nhapSinhVien(SinhVien& sv) {
    cout << "Nhap ma so: "; cin >> sv.maSo;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, sv.hoTen);
    cout << "Nhap diem chuyen can: "; cin >> sv.diemChuyenCan;
    cout << "Nhap diem giua ky: "; cin >> sv.diemGiuaKy;
    cout << "Nhap diem cuoi ky: "; cin >> sv.diemCuoiKy;
    sv.tinhDiemHP();
}


void xuatDanhSach(SinhVien ds[], int n) {
    cout << "\n" << setw(10) << "MSSV" << setw(20) << "Ho Ten" << setw(15) << "Diem HP" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(10) << ds[i].maSo << setw(20) << ds[i].hoTen << setw(15) << fixed << setprecision(2) << ds[i].diemHocPhan << endl;
    }
}

void sapXepGiamDiemHP(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemHocPhan < ds[j].diemHocPhan) {
                swap(ds[i], ds[j]);
            }
        }
    }
}


void sapXepTangMaSo(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].maSo > ds[j].maSo) {
                swap(ds[i], ds[j]);
            }
        }
    }
}


int timKiemNhiPhan(SinhVien ds[], int n, string x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].maSo == x) return mid;
        if (ds[mid].maSo < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        nhapSinhVien(ds[i]);
    }
    sapXepGiamDiemHP(ds, n);
    cout << "\n--- Danh sach sau khi sap xep giam dan theo diem HP ---";
    xuatDanhSach(ds, n);
    sapXepTangMaSo(ds, n);
    string x;
    cout << "\nNhap ma so sinh vien can tim (X): ";
    cin >> x;

    int res = timKiemNhiPhan(ds, n, x);
    if (res != -1) {
        cout << "Tim thay sinh vien: " << ds[res].hoTen << " | Diem HP: " << ds[res].diemHocPhan << endl;
    }
    else {
        cout << "Khong tim thay sinh vien co ma so " << x << endl;
    }

    return 0;
}


