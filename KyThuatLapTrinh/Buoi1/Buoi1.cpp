#include <iostream>
#include <vector>
using namespace std;
struct Sinhvien {
	string hoten;
	int tuoi;
	bool gioitinh;
	string diachi;
};

int main () {
	Sinhvien b;
	b.hoten = "Nguyen Thi Kim Pho";
	b.tuoi = 19;
	b.gioitinh = true;
	b.diachi = "Tay Ninh";

	Sinhvien c;
	c.hoten = "Nguyen Thi Ngoc Tuyet";
	c.tuoi = 19;
	c.gioitinh = true;
	c.diachi = "Tay Ninh";

	Sinhvien d;
	d.hoten = "Nguyen Tuong Van";
	d.tuoi = 19;
	d.gioitinh = true;
	d.diachi = "Dong Thap";

	Sinhvien e;
	e.hoten = " Le Chi Thien";
	e.tuoi = 19;
	e.gioitinh = false;
	e.diachi = "Tay Ninh";


		//Sinhvien ds[50];
		vector <Sinhvien> mang;
		mang.push_back(b);
		mang.push_back(c);
		mang.push_back(d);
		mang.push_back(e);
		for (int i = 0; i < mang.size(); i++) {
			cout << "Sinh vien " << (i + 1) << endl;
			cout << "\t+ Ho ten: " << mang[i].hoten << endl;
			cout << "\t+ Tuoi: " << mang[i].tuoi << endl;
			cout << "\t+ Gioi tinh " << mang[i].gioitinh << endl;
			cout << "\t+ Dia chi " << mang[i].diachi << endl;
		}

  
	/*int a = 5;
	int* p = &a;
	a += 6;
	a = *p + 2;
	cout << *p;*/


	/*vector <float> diemthi;
	diemthi.push_back(5.5);
	diemthi.push_back(4);
	diemthi.push_back(6);
	diemthi.pop_back();
	for (int i = 0; i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}*/


}