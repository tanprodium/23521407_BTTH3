#include <bits/stdc++.h>
#include "ThoiGian.h"

int main() {
    ThoiGian tg1(2, 30, 45); // Tạo đối tượng ThoiGian với 2 giờ, 30 phút, 45 giây
    ThoiGian tg2(1, 15, 15); // Tạo đối tượng ThoiGian với 1 giờ, 15 phút, 15 giây

    // Xuất thời gian
    std::cout << "Thoi gian 1: ";
    tg1.ThoiGianXuat();

    std::cout << "Thoi gian 2: ";
    tg2.ThoiGianXuat();

    // Cộng thêm giây
    ThoiGian tg3 = tg1 + 30; // Cộng 30 giây vào tg1
    std::cout << "Thoi gian 1 + 30 giay: ";
    tg3.ThoiGianXuat();

    // Trừ giây
    ThoiGian tg4 = tg1 - 15; // Trừ 15 giây từ tg1
    std::cout << "Thoi gian 1 - 15 giay: ";
    tg4.ThoiGianXuat();

    // Cộng 2 đối tượng ThoiGian
    ThoiGian tg5 = tg1 + tg2; // Cộng tg1 và tg2
    std::cout << "Thoi gian 1 + Thoi gian 2: ";
    tg5.ThoiGianXuat();

    // So sánh thời gian
    if (tg1 == tg2) {
        std::cout << "Thoi gian 1 bang Thoi gian 2." << std::endl;
    } else {
        std::cout << "Thoi gian 1 khong bang Thoi gian 2." << std::endl;
    }

    // Tăng giây
    tg1++;
    std::cout << "Thoi gian 1 sau khi tang 1 giay: ";
    tg1.ThoiGianXuat();

    // Giảm giây
    tg2--;
    std::cout << "Thoi gian 2 sau khi giam 1 giay: ";
    tg2.ThoiGianXuat();

    return 0;
}
