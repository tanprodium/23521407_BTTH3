#include "SoPhuc.h"
#include <stdexcept>

// Hàm dựng mặc định, tạo số phức 0 + 0i
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

// Hàm dựng với tham số phần thực và phần ảo
SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

// Toán tử cộng hai số phức
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

// Toán tử trừ hai số phức
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

// Toán tử nhân hai số phức
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

// Toán tử chia hai số phức
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double mau = sp.dThuc * sp.dThuc + sp.dAo * sp.dAo;
    if (mau == 0) throw runtime_error("Loi: Mau so bang 0.");
    return SoPhuc((dThuc * sp.dThuc + dAo * sp.dAo) / mau, (dAo * sp.dThuc - dThuc * sp.dAo) / mau);
}

// Toán tử so sánh bằng
bool SoPhuc::operator==(const SoPhuc& sp) const {
    return dThuc == sp.dThuc && dAo == sp.dAo;
}

// Toán tử so sánh khác
bool SoPhuc::operator!=(const SoPhuc& sp) const {
    return !(*this == sp);
}

// Toán tử nhập số phức từ luồng
istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.dThuc;
    cout << "Nhap phan ao: ";
    in >> sp.dAo;
    return in;
}

// Toán tử xuất số phức ra luồng
ostream& operator<<(ostream& out, const SoPhuc& sp) {
    out << sp.dThuc << (sp.dAo >= 0 ? " + " : " - ") << abs(sp.dAo) << "i";
    return out;
}
