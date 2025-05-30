#include <bits/stdc++.h>
using namespace std;

struct TaiKhoan {
    string ten_dang_nhap;
    string mat_khau;
};

vector<TaiKhoan> kiem_tra_du_lieu_tu_file(const string& duong_dan) {
    vector<TaiKhoan> danh_sach;
    ifstream file(duong_dan);
    string dong;
    
    while(getline(file, dong)) {
        stringstream ss(dong);
        TaiKhoan tk;
        getline(ss, tk.ten_dang_nhap, ';');
        getline(ss, tk.mat_khau, ';');
        danh_sach.push_back(tk);
    }
    return danh_sach;
}

void ghi_thong_tin_vao_file(const string& duong_dan, const vector<TaiKhoan>& danh_sach) {
    ofstream file(duong_dan);
    for(const auto& tai_khoan : danh_sach) {
        file << tai_khoan.ten_dang_nhap << ';' << tai_khoan.mat_khau << ";\n";
    }
}

TaiKhoan nhap_thong_tin_dang_nhap(const vector<TaiKhoan>& danh_sach) {
    TaiKhoan tk;

    cout << "\n\tTen dang nhap: ";
    getline(cin, tk.ten_dang_nhap);
    cout << "\tMat khau: ";
    getline(cin, tk.mat_khau);
    
    for(const auto& tai_khoan : danh_sach) {
        if((tk.ten_dang_nhap == tai_khoan.ten_dang_nhap) && 
           (tk.mat_khau == tai_khoan.mat_khau)) {
            cout << "\t(*) Dang nhap thanh cong ! Vui long cho...\n";
            return tk;
        }
    }
    
    cout << "\t(!) Sai ten dang nhap hoac mat khau ! Vui long nhap lai\n";
    return nhap_thong_tin_dang_nhap(danh_sach);  
}

TaiKhoan nhap_thong_tin_dang_ky(const string& duong_dan, vector<TaiKhoan>& danh_sach) {
    TaiKhoan tk_moi;
    cout << "\n\t(?) Ten dang nhap: ";
    getline(cin, tk_moi.ten_dang_nhap);
    for(const auto& tai_khoan : danh_sach) {
        if(tk_moi.ten_dang_nhap == tai_khoan.ten_dang_nhap) {
            cout << "\t(!) Ten dang nhap ton tai ! Vui long chon ten khac\n";
            return nhap_thong_tin_dang_ky(duong_dan, danh_sach);
        }
    }
    cout << "\t(?) Mat khau: ";
    getline(cin, tk_moi.mat_khau);
    danh_sach.push_back(tk_moi);
    ghi_thong_tin_vao_file(duong_dan, danh_sach);    
    cout << "\t(*) Dang ky tai khoan thanh cong !\n";
    return tk_moi;
}