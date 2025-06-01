//                       ____ ___  ____  _____   ______   __
//                      / ___/ _ \|  _ \| ____| | __ ) \ / /
//                     | |  | | | | | | |  _|   |  _ \\ V / 
//                     | |__| |_| | |_| | |___  | |_) || |  
//                      \____\___/|____/|_____| |____/ |_|
//                  
//  _______ _____  _    _  ____  _   _  _____     _____ _    _ _____ _   _ _    _ 
// |__   __|  __ \| |  | |/ __ \| \ | |/ ____|   / ____| |  | |_   _| \ | | |  | |
//    | |  | |__) | |  | | |  | |  \| | |  __   | |    | |__| | | | |  \| | |__| |
//    | |  |  _  /| |  | | |  | | . ` | | |_ |  | |    |  __  | | | | . ` |  __  |
//    | |  | | \ \| |__| | |__| | |\  | |__| |  | |____| |  | |_| |_| |\  | |  | |
//    |_|  |_|  \_\\____/ \____/|_| \_|\_____|   \_____|_|  |_|_____|_| \_|_|  |_|

#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------
// CHỈ HASH MẬT KHẨU 
// -----------------------------------------------

// struct TaiKhoan {
//     string ten_dang_nhap;
//     string mat_khau;
// };

// string hash_password(const string& password){
//     hash<string> ham_hash;
//     size_t hash_password = ham_hash(password);
//     return to_string(hash_password);
// }

// vector<TaiKhoan> kiem_tra_du_lieu_tu_file(const string& duong_dan) {
//     vector<TaiKhoan> danh_sach;
//     ifstream file(duong_dan);
//     string dong;
//     while(getline(file, dong)) {
//         stringstream ss(dong);
//         TaiKhoan tk;
//         getline(ss, tk.ten_dang_nhap, ';');
//         getline(ss, tk.mat_khau, ';');
//         danh_sach.push_back(tk);
//     }
//     return danh_sach;
// }

// void ghi_thong_tin_vao_file(const string& duong_dan, const vector<TaiKhoan>& danh_sach) {
//     ofstream file(duong_dan);
//     for(const auto& tai_khoan : danh_sach) {
//         file << tai_khoan.ten_dang_nhap << ';' << tai_khoan.mat_khau << ";\n";
//     }
// }

// TaiKhoan nhap_thong_tin_dang_nhap(const vector<TaiKhoan>& danh_sach) {
//     TaiKhoan tk;
//     cout << "\n\tTen dang nhap: ";
//     getline(cin, tk.ten_dang_nhap);
//     cout << "\tMat khau: ";
//     getline(cin, tk.mat_khau);
//     string ma_hoa_mat_khau = hash_password(tk.mat_khau);
//     for(const auto& tai_khoan : danh_sach) {
//         if((tk.ten_dang_nhap == tai_khoan.ten_dang_nhap) && 
//            (ma_hoa_mat_khau == tai_khoan.mat_khau)) {
//             cout << "\t(*) Dang nhap thanh cong ! Vui long cho...\n";
//             return tk;
//         }
//     }
    
//     cout << "\t(!) Sai ten dang nhap hoac mat khau ! Vui long nhap lai\n";
//     return nhap_thong_tin_dang_nhap(danh_sach);  
// }

// TaiKhoan nhap_thong_tin_dang_ky(const string& duong_dan, vector<TaiKhoan>& danh_sach) {
//     TaiKhoan tk_moi;
//     cout << "\n\t(?) Ten dang nhap: ";
//     getline(cin, tk_moi.ten_dang_nhap);
//     for(const auto& tai_khoan : danh_sach) {
//         if(tk_moi.ten_dang_nhap == tai_khoan.ten_dang_nhap) {
//             cout << "\t(!) Ten dang nhap ton tai ! Vui long chon ten khac\n";
//             return nhap_thong_tin_dang_ky(duong_dan, danh_sach);
//         }
//     }
//     cout << "\t(?) Mat khau: ";
//     getline(cin, tk_moi.mat_khau);
//     tk_moi.mat_khau = hash_password(tk_moi.mat_khau);
//     danh_sach.push_back(tk_moi);
//     ghi_thong_tin_vao_file(duong_dan, danh_sach);    
//     cout << "\t(*) Dang ky tai khoan thanh cong !\n";
//     return tk_moi;
// }


// -----------------------------------------------
// HASH CẢ TÊN ĐĂNG NHẬP VÀ MẬT KHẨU 
// ----------------------------------------------- 

struct TaiKhoan {
    string ten_dang_nhap;
    string mat_khau;
};

string hash_password(const string& chuoi) {
    hash<string> ham_hash;
    size_t gia_tri_hash = ham_hash(chuoi);
    return to_string(gia_tri_hash);
}

vector<TaiKhoan> kiem_tra_du_lieu_tu_file(const string& duong_dan) {
    vector<TaiKhoan> danh_sach;
    ifstream file(duong_dan);
    string dong;
    while (getline(file, dong)) {
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
    for (const auto& tai_khoan : danh_sach) {
        file << tai_khoan.ten_dang_nhap << ';' << tai_khoan.mat_khau << ";\n";
    }
}

bool kiem_tra_file_rong(const string& duong_dan){
    ifstream file(duong_dan);
    if(file.peek() == ifstream::traits_type::eof()) return true;
    else return false;
}

TaiKhoan nhap_thong_tin_dang_nhap(const vector<TaiKhoan>& danh_sach) {
    TaiKhoan tk;
    cout << "\n\t(?) Ten dang nhap: ";
    getline(cin, tk.ten_dang_nhap);
    cout << "\t(?) Mat khau: ";
    getline(cin, tk.mat_khau);
    string ten_dn_ma_hoa = hash_password(tk.ten_dang_nhap);
    string mat_khau_ma_hoa = hash_password(tk.mat_khau);
    for (const auto& tai_khoan : danh_sach) {
        if ((ten_dn_ma_hoa == tai_khoan.ten_dang_nhap) &&
            (mat_khau_ma_hoa == tai_khoan.mat_khau)) {
            cout << "\t(*) Dang nhap thanh cong ! Vui long cho trong giay lat ...\n";
            return tk;
        }
    }
    cout << "\t(!) Sai ten dang nhap hoac mat khau Vui long thu lai\n";
    return nhap_thong_tin_dang_nhap(danh_sach);
}

TaiKhoan nhap_thong_tin_dang_ky(const string& duong_dan, vector<TaiKhoan>& danh_sach) {
    TaiKhoan tk_moi;
    cout << "\n\t(?) Ten dang nhap: ";
    getline(cin, tk_moi.ten_dang_nhap);
    string ten_dn_ma_hoa = hash_password(tk_moi.ten_dang_nhap);
    for (const auto& tai_khoan : danh_sach) {
        if (ten_dn_ma_hoa == tai_khoan.ten_dang_nhap) {
            cout << "\t(!) Ten dang nhap da ton tai Vui long chon ten khac\n";
            return nhap_thong_tin_dang_ky(duong_dan, danh_sach);
        }
    }
    cout << "\t(?) Mat khau: ";
    getline(cin, tk_moi.mat_khau);
    tk_moi.ten_dang_nhap = ten_dn_ma_hoa;
    tk_moi.mat_khau = hash_password(tk_moi.mat_khau);
    danh_sach.push_back(tk_moi);
    ghi_thong_tin_vao_file(duong_dan, danh_sach);
    cout << "\t(*) Dang ky tai khoan thanh cong\n";
    return tk_moi;
}
