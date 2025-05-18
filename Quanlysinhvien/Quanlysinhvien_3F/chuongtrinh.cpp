#include "thuvien.h"

___TruongChinh304___ {
    while (true) {
        in_giua_man_hinh("CHUONG TRINH QUAN LY DANH SACH SINH VIEN\n");
        cout << "1 - In theo danh sach\n";
        cout << "2 - Them\n";
        cout << "3 - Sua\n";
        cout << "4 - Xoa\n";
        cout << "5 - Tim kiem\n";
        cout << "6 - Sap xep\n";
        cout << "7 - Thong ke\n";
        cout << "8 - Thoat\n";
        cout << "[-->] Nhap lenh: ";
        int lua_chon; cin >> lua_chon;
        cin.ignore();
        vector<sinh_vien> danh_sach = doc_du_lieu_tu_file("D:\\Quanlysinhvien\\Quanlysinhvien_3F\\danhsach.txt"); // load danh sach tu file (update liên tục)
        if (lua_chon == 1) {
            cout << "\n[" << lua_chon << "] In danh sach sinh vien\n";
            in_theo_danh_sach(danh_sach);
        } else if (lua_chon == 2){
            cout << "\n[" << lua_chon << "] Them vao danh sach sinh vien\n";
            them_vao_danh_sach(danh_sach);
        } else if (lua_chon == 3){
            cout << "\n[" << lua_chon << "] Sua danh sach sinh vien\n";
            sua_danh_sach(danh_sach);
        } else if (lua_chon == 4){
            cout << "\n[" << lua_chon << "] Xoa sinh vien khoi danh sach\n";
            xoa_sinh_vien(danh_sach);
        } else if (lua_chon == 5){
            cout << "\n[" << lua_chon << "] Tim kiem sinh vien tu danh sach\n";
            tim_kiem_sinh_vien(danh_sach);    
        } else if (lua_chon == 6){
            cout << "\n[" << lua_chon << "] Sap xep sinh vien tu danh sach\n";
            //sap_xep_danh_sach(danh_sach);
            cout << "Tinh nang dang duoc bao tri !\n";
        } else if (lua_chon == 7){
            cout << "\n[" << lua_chon << "] Thong ke danh sach sinh vien\n";
            thong_ke_danh_sach(danh_sach);
        } else if (lua_chon == 8){
            cout << "\n[" << lua_chon << "] Ban chon thoat chuong trinh\n";
            in_giua_man_hinh("HEN GAP LAI BAN !");
            return 0; // thoat khoi chuong trinh (có thể thay bằng exit(0))
        } else cout << "\nNhap sai vui long nhap lai ! \n";
        cout << "\nPress any key to continue ...";
        getch(); // bắt phím bất kỳ 
        system("cls"); // xóa màn hình cũ để hiển thị màn hình mới     
    }    
    return 0; 
}
