#include "PhanSo.h"
#include <stdexcept>

// Hàm tìm ước chung lớn nhất (UCLN)
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm rút gọn phân số
void PhanSo::RutGon() {
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
    if (iMau < 0) { // Đảm bảo mẫu dương
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Hàm dựng mặc định, tạo phân số 0/1
PhanSo::PhanSo() : iTu(0), iMau(1) {}

// Hàm dựng với tham số tử và mẫu
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau) {
    if (iMau == 0) throw runtime_error("Loi: Mau so bang 0.");
    RutGon();
}

// Toán tử cộng hai phân số
PhanSo PhanSo::operator+(const PhanSo& ps) const {
    return PhanSo(iTu * ps.iMau + ps.iTu * iMau, iMau * ps.iMau);
}

// Toán tử trừ hai phân số
PhanSo PhanSo::operator-(const PhanSo& ps) const {
    return PhanSo(iTu * ps.iMau - ps.iTu * iMau, iMau * ps.iMau);
}

// Toán tử nhân hai phân số
PhanSo PhanSo::operator*(const PhanSo& ps) const {
    return PhanSo(iTu * ps.iTu, iMau * ps.iMau);
}

// Toán tử chia hai phân số
PhanSo PhanSo::operator/(const PhanSo& ps) const {
    if (ps.iTu == 0) throw runtime_error("Loi: Chia cho 0.");
    return PhanSo(iTu * ps.iMau, iMau * ps.iTu);
}

// Các toán tử so sánh
bool PhanSo::operator==(const PhanSo& ps) const {
    return iTu * ps.iMau == iMau * ps.iTu;
}

bool PhanSo::operator!=(const PhanSo& ps) const {
    return !(*this == ps);
}

bool PhanSo::operator>(const PhanSo& ps) const {
    return iTu * ps.iMau > iMau * ps.iTu;
}

bool PhanSo::operator<(const PhanSo& ps) const {
    return iTu * ps.iMau < iMau * ps.iTu;
}

bool PhanSo::operator>=(const PhanSo& ps) const {
    return !(*this < ps);
}

bool PhanSo::operator<=(const PhanSo& ps) const {
    return !(*this > ps);
}

// Toán tử nhập phân số
istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau;
    if (ps.iMau == 0) throw runtime_error("Loi: Mau so bang 0.");
    ps.RutGon();
    return in;
}

// Toán tử xuất phân số
ostream& operator<<(ostream& out, const PhanSo& ps) {
    out << ps.iTu;
    if (ps.iMau != 1) out << "/" << ps.iMau;
    return out;
}
