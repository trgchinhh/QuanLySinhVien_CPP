#include <bits/stdc++.h>
#include <conio.h> // lib xóa màn hình 
#define pb push_back
#define ___TruongChinh304___ signed main() // hàm main
using namespace std;

struct sinh_vien {
    string ho_ten;
    int tuoi;
    string mssv;
    float diem;
};

sinh_vien nhap_thong_tin();
vector<sinh_vien> doc_du_lieu_tu_file(const string& ten_file);
void ghi_vao_file(const string& ten_file, const vector<sinh_vien>& danh_sach);
void in_giua_man_hinh(const string& cau);
void in_theo_danh_sach(const vector<sinh_vien>& danh_sach);
void them_vao_danh_sach(vector<sinh_vien>& danh_sach);
void sua_danh_sach(vector<sinh_vien>& danh_sach);
void xoa_sinh_vien(vector<sinh_vien>& danh_sach);
void chuyen_ve_ky_tu_thuong(string& kytu);
void tim_kiem_sinh_vien(vector<sinh_vien>& danh_sach);
void thong_ke_danh_sach(vector<sinh_vien>& danh_sach);
