#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dThuc;  // Phần thực
    double dAo;    // Phần ảo

public:
    SoPhuc();                      // Hàm dựng mặc định
    SoPhuc(double thuc, double ao); // Hàm dựng với tham số

    // Toán tử cộng hai số phức
    SoPhuc operator+(const SoPhuc& sp) const;

    // Toán tử trừ hai số phức
    SoPhuc operator-(const SoPhuc& sp) const;

    // Toán tử nhân hai số phức
    SoPhuc operator*(const SoPhuc& sp) const;

    // Toán tử chia hai số phức
    SoPhuc operator/(const SoPhuc& sp) const;

    // Toán tử so sánh bằng
    bool operator==(const SoPhuc& sp) const;

    // Toán tử so sánh khác
    bool operator!=(const SoPhuc& sp) const;

    // Toán tử nhập số phức từ luồng
    friend istream& operator>>(istream& in, SoPhuc& sp);

    // Toán tử xuất số phức ra luồng
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};

#endif
