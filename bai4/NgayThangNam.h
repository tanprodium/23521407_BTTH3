#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>
#include <iomanip>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int nam, int thang, int ngay);

    void NgayThangNamXuat() const; // Xuất ngày
    int TinhNgay() const;           // Tính số ngày đã qua trong năm

    // Các toán tử
    NgayThangNam operator+(int ngay) const;            // Cộng ngày
    NgayThangNam operator-(int ngay) const;            // Giảm ngày
    int operator-(const NgayThangNam& a) const;       // Trừ hai ngày để tính số ngày
    NgayThangNam& operator++();                         // Tiền tăng
    NgayThangNam operator++(int);                       // Hậu tăng
    NgayThangNam& operator--();                         // Tiền giảm
    NgayThangNam operator--(int);                       // Hậu giảm

    bool operator==(const NgayThangNam& a) const;      // So sánh bằng
    bool operator!=(const NgayThangNam& a) const;      // So sánh khác
    bool operator>(const NgayThangNam& a) const;       // So sánh lớn hơn
    bool operator<(const NgayThangNam& a) const;       // So sánh nhỏ hơn
    bool operator>=(const NgayThangNam& a) const;      // So sánh lớn hơn hoặc bằng
    bool operator<=(const NgayThangNam& a) const;      // So sánh nhỏ hơn hoặc bằng

    friend std::istream& operator>>(std::istream& is, NgayThangNam& a); // Nhập từ bàn phím
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& a); // Xuất ra màn hình
};

#endif // NGAYTHANGNAM_H
