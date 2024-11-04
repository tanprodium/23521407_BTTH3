#include "ThoiGian.h"

// Constructor mặc định
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Constructor với tham số
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) {
    iGio = Gio;
    iPhut = Phut;
    iGiay = Giay;
}

// Xuất thời gian
void ThoiGian::ThoiGianXuat() const {
    std::cout << iGio << " Gio " << iPhut << " Phut " << iGiay << " Giay" << std::endl;
}

// Tính tổng giây
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Tính lại giờ từ giây
void ThoiGian::TinhLaiGio(int Giay) {
    iGio += Giay / 3600;
    iPhut += (Giay % 3600) / 60;
    iGiay += Giay % 60;

    // Điều chỉnh lại
    if (iGiay >= 60) {
        iPhut += iGiay / 60;
        iGiay %= 60;
    }
    if (iPhut >= 60) {
        iGio += iPhut / 60;
        iPhut %= 60;
    }
}

// Toán tử +
ThoiGian ThoiGian::operator+(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(Giay);
    return result;
}

// Toán tử -
ThoiGian ThoiGian::operator-(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(-Giay);
    return result;
}

// Toán tử +
ThoiGian ThoiGian::operator+(const ThoiGian &a) {
    return ThoiGian(iGio + a.iGio, iPhut + a.iPhut, iGiay + a.iGiay);
}

// Toán tử -
ThoiGian ThoiGian::operator-(const ThoiGian &a) {
    return ThoiGian(iGio - a.iGio, iPhut - a.iPhut, iGiay - a.iGiay);
}

// Toán tử ==
bool ThoiGian::operator==(const ThoiGian &a) const {
    return iGio == a.iGio && iPhut == a.iPhut && iGiay == a.iGiay;
}

// Toán tử !=
bool ThoiGian::operator!=(const ThoiGian &a) const {
    return !(*this == a);
}

// Toán tử >
bool ThoiGian::operator>(const ThoiGian &a) const {
    return TinhGiay() > a.TinhGiay();
}

// Toán tử <
bool ThoiGian::operator<(const ThoiGian &a) const {
    return TinhGiay() < a.TinhGiay();
}

// Toán tử >=
bool ThoiGian::operator>=(const ThoiGian &a) const {
    return TinhGiay() >= a.TinhGiay();
}

// Toán tử <=
bool ThoiGian::operator<=(const ThoiGian &a) const {
    return TinhGiay() <= a.TinhGiay();
}

// Toán tử ++ (tiền tố)
ThoiGian& ThoiGian::operator++() {
    iGiay++;
    return *this;
}

// Toán tử ++ (hậu tố)
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    iGiay++;
    return temp;
}

// Toán tử -- (tiền tố)
ThoiGian& ThoiGian::operator--() {
    iGiay--;
    return *this;
}

// Toán tử -- (hậu tố)
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    iGiay--;
    return temp;
}

// Toán tử >> (nhập)
std::istream& operator>>(std::istream &in, ThoiGian &tg) {
    in >> tg.iGio >> tg.iPhut >> tg.iGiay;
    return in;
}

// Toán tử << (xuất)
std::ostream& operator<<(std::ostream &out, const ThoiGian &tg) {
    out << tg.iGio << " Gio " << tg.iPhut << " Phut " << tg.iGiay << " Giay";
    return out;
}
