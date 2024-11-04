#include <iostream>
#include "NgayThangNam.h"

int main() {
    NgayThangNam n1(2023, 11, 4); // Ngày hiện tại
    NgayThangNam n2(2024, 1, 1);  // Ngày sau

    std::cout << "Ngay 1: ";
    n1.NgayThangNamXuat();
    std::cout << std::endl;

    std::cout << "Ngay 2: ";
    n2.NgayThangNamXuat();
    std::cout << std::endl;

    // Thêm ngày
    NgayThangNam n3 = n1 + 5; // Ngày 1 cộng 5 ngày
    std::cout << "Ngay 1 sau khi cong 5 ngay: ";
    n3.NgayThangNamXuat();
    std::cout << std::endl;

    // Giảm ngày
    NgayThangNam n4 = n2 - 2; // Ngày 2 giảm 2 ngày
    std::cout << "Ngay 2 sau khi giam 2 ngay: ";
    n4.NgayThangNamXuat();
    std::cout << std::endl;

    // So sánh
    if (n1 < n2) {
        std::cout << "Ngay 1 nho hon Ngay 2." << std::endl;
    } else {
        std::cout << "Ngay 1 khong nho hon Ngay 2." << std::endl;
    }

    // Nhập ngày từ người dùng
    NgayThangNam n5;
    std::cout << "Nhap ngay (theo dinh dang nam/thang/ngay): ";
    std::cin >> n5;
    std::cout << "Ngay vua nhap: " << n5 << std::endl;

    // Tính số ngày đã qua trong năm
    std::cout << "So ngay da qua trong nam: " << n1.TinhNgay() << std::endl;

    return 0;
}
