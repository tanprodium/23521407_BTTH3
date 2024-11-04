#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <bits/stdc++.h>

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    // Constructor mặc định
    ThoiGian();

    // Constructor với tham số
    ThoiGian(int Gio, int Phut, int Giay);

    // Xuất thời gian
    void ThoiGianXuat() const;

    // Tính tổng giây
    int TinhGiay() const;

    // Tính lại giờ từ giây
    void TinhLaiGio(int Giay);

    // Toán tử +
    ThoiGian operator+(int Giay);

    // Toán tử -
    ThoiGian operator-(int Giay);

    // Toán tử +
    ThoiGian operator+(const ThoiGian &a);

    // Toán tử -
    ThoiGian operator-(const ThoiGian &a);

    // Toán tử ==
    bool operator==(const ThoiGian &a) const;

    // Toán tử !=
    bool operator!=(const ThoiGian &a) const;

    // Toán tử >
    bool operator>(const ThoiGian &a) const;

    // Toán tử <
    bool operator<(const ThoiGian &a) const;

    // Toán tử >=
    bool operator>=(const ThoiGian &a) const;

    // Toán tử <=
    bool operator<=(const ThoiGian &a) const;

    // Toán tử ++ (tiền tố)
    ThoiGian& operator++();

    // Toán tử ++ (hậu tố)
    ThoiGian operator++(int);

    // Toán tử -- (tiền tố)
    ThoiGian& operator--();

    // Toán tử -- (hậu tố)
    ThoiGian operator--(int);

    // Bạn thân cho xuất nhập
    friend std::istream& operator>>(std::istream &in, ThoiGian &tg);
    friend std::ostream& operator<<(std::ostream &out, const ThoiGian &tg);
};

#endif // THOIGIAN_H
