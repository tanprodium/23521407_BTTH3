#include "NgayThangNam.h"

// Khởi tạo mặc định
NgayThangNam::NgayThangNam() : iNam(2023), iThang(1), iNgay(1) {}

// Khởi tạo với tham số
NgayThangNam::NgayThangNam(int nam, int thang, int ngay) : iNam(nam), iThang(thang), iNgay(ngay) {}

// Xuất ngày
void NgayThangNam::NgayThangNamXuat() const {
    std::cout << std::setw(2) << std::setfill('0') << iNgay << "/"
              << std::setw(2) << std::setfill('0') << iThang << "/"
              << iNam;
}

// Tính số ngày đã qua trong năm
int NgayThangNam::TinhNgay() const {
    int soNgay[] = {0, 31, 28 + (iNam % 4 == 0 && (iNam % 100 != 0 || iNam % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int tong = 0;
    for (int i = 1; i < iThang; ++i) {
        tong += soNgay[i];
    }
    return tong + iNgay;
}

// Cộng ngày
NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam temp(*this);
    temp.iNgay += ngay;
    while (temp.iNgay > (31 - (temp.iThang % 2 == 0 && temp.iThang != 2 ? 1 : 0))) {
        temp.iNgay -= (31 - (temp.iThang % 2 == 0 && temp.iThang != 2 ? 1 : 0));
        temp.iThang++;
        if (temp.iThang > 12) {
            temp.iThang = 1;
            temp.iNam++;
        }
    }
    return temp;
}

// Giảm ngày
NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam temp(*this);
    temp.iNgay -= ngay;
    while (temp.iNgay <= 0) {
        temp.iThang--;
        if (temp.iThang <= 0) {
            temp.iThang = 12;
            temp.iNam--;
        }
        temp.iNgay += (31 - (temp.iThang % 2 == 0 && temp.iThang != 2 ? 1 : 0));
    }
    return temp;
}

// Trừ hai ngày để tính số ngày
int NgayThangNam::operator-(const NgayThangNam& a) const {
    int ngay1 = TinhNgay();
    int ngay2 = a.TinhNgay();
    return ngay1 - ngay2;
}

// Tiền tăng
NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

// Hậu tăng
NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp(*this);
    ++(*this);
    return temp;
}

// Tiền giảm
NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

// Hậu giảm
NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp(*this);
    --(*this);
    return temp;
}

// So sánh bằng
bool NgayThangNam::operator==(const NgayThangNam& a) const {
    return (iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam);
}

// So sánh khác
bool NgayThangNam::operator!=(const NgayThangNam& a) const {
    return !(*this == a);
}

// So sánh lớn hơn
bool NgayThangNam::operator>(const NgayThangNam& a) const {
    if (iNam != a.iNam) return iNam > a.iNam;
    if (iThang != a.iThang) return iThang > a.iThang;
    return iNgay > a.iNgay;
}

// So sánh nhỏ hơn
bool NgayThangNam::operator<(const NgayThangNam& a) const {
    return !(*this >= a);
}

// So sánh lớn hơn hoặc bằng
bool NgayThangNam::operator>=(const NgayThangNam& a) const {
    return (*this > a || *this == a);
}

// So sánh nhỏ hơn hoặc bằng
bool NgayThangNam::operator<=(const NgayThangNam& a) const {
    return (*this < a || *this == a);
}

// Nhập từ bàn phím
std::istream& operator>>(std::istream& is, NgayThangNam& a) {
    char sep; // ký tự phân cách
    is >> a.iNam >> sep >> a.iThang >> sep >> a.iNgay;
    return is;
}

// Xuất ra màn hình
std::ostream& operator<<(std::ostream& os, const NgayThangNam& a) {
    os << std::setw(2) << std::setfill('0') << a.iNgay << "/"
       << std::setw(2) << std::setfill('0') << a.iThang << "/"
       << a.iNam;
    return os;
}
