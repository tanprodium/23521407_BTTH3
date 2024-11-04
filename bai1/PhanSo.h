#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu;    // Tử số
    int iMau;   // Mẫu số

    void RutGon();  // Hàm rút gọn phân số

public:
    PhanSo();                    // Hàm dựng mặc định
    PhanSo(int tu, int mau);     // Hàm dựng với tham số

    // Toán tử cộng hai phân số
    PhanSo operator+(const PhanSo& ps) const;

    // Toán tử trừ hai phân số
    PhanSo operator-(const PhanSo& ps) const;

    // Toán tử nhân hai phân số
    PhanSo operator*(const PhanSo& ps) const;

    // Toán tử chia hai phân số
    PhanSo operator/(const PhanSo& ps) const;

    // Các toán tử so sánh
    bool operator==(const PhanSo& ps) const;
    bool operator!=(const PhanSo& ps) const;
    bool operator> (const PhanSo& ps) const;
    bool operator< (const PhanSo& ps) const;
    bool operator>=(const PhanSo& ps) const;
    bool operator<=(const PhanSo& ps) const;

    // Toán tử nhập và xuất phân số
    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
};

#endif
