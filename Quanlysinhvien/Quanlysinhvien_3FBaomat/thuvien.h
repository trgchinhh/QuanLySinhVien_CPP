#include <conio.h>        // lib xóa màn hình 
#include <unistd.h>       // lib dừng chương trình 
#include <windows.h>      // lib dùng cho màu sắc
#include <bits/stdc++.h>
#define pb push_back
#define ___TruongChinh304___ signed main() // hàm main
using namespace std;

struct sinh_vien {
    string ho_ten;
    int tuoi;
    string mssv;
    float diem;
};

struct TaiKhoan {
    string ten_dang_nhap;
    string mat_khau;
};

sinh_vien nhap_thong_tin();                                                         // thêm thông tin  
vector<sinh_vien> doc_du_lieu_tu_file(const string& ten_file);                      // load dữ liệu file
void ghi_vao_file(const string& ten_file, const vector<sinh_vien>& danh_sach);      // ghi vào file 
void in_giua_man_hinh(const string& cau);                                           // in banner giữa màn hình 
void in_ra_banner_chinh();                                                          // banner chính 
void in_ra_banner_tam_biet();                                                       // banner tạm biệt
void tranh_loi_nhap_so();                                                           // tránh lỗi cin failbit
void in_theo_danh_sach(const vector<sinh_vien>& danh_sach);                         // in theo file
void them_vao_danh_sach(vector<sinh_vien>& danh_sach);                              // thêm vào file
void sua_danh_sach(vector<sinh_vien>& danh_sach);                                   // sửa thông tin
void xoa_sinh_vien(vector<sinh_vien>& danh_sach);                                   // xóa thông tin
void chuyen_ve_ky_tu_thuong(string& kytu);                                          // chuyển chữ hoa về chữ thường
void tim_kiem_sinh_vien(vector<sinh_vien>& danh_sach);                              // tìm kiếm thông tin
void thong_ke_danh_sach(vector<sinh_vien>& danh_sach);                              // thống kê thông tin
void sap_xep_danh_sach(vector<sinh_vien>& danh_sach);                               // sắp xếp thông tin
void chuong_trinh_dang_nhap();                                                      // đăng nhập (bảo mật)
void chuong_trinh_chinh(string ten_nguoi_dung);                                     // chương trình chính