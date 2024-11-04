#include <iostream>
using namespace std;

class PhanSo {
private:
    int Tu;   // Tử số
    int Mau;  // Mẫu số

    // Hàm rút gọn phân số bằng cách chia cả tử và mẫu cho ước chung lớn nhất
    void RutGon() {
        int a = abs(Tu), b = abs(Mau);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        Tu /= a;
        Mau /= a;
        // Đảm bảo mẫu số luôn dương
        if (Mau < 0) {
            Tu = -Tu;
            Mau = -Mau;
        }
    }

public:
    // Hàm dựng mặc định, tạo phân số 0/1
    PhanSo() : Tu(0), Mau(1) {}

    // Hàm dựng với tử và mẫu, nếu mẫu bằng 0 thì đặt mẫu là 1
    PhanSo(int tu, int mau) : Tu(tu), Mau(mau == 0 ? 1 : mau) {
        RutGon();
    }

    // Toán tử cộng hai phân số
    PhanSo operator+(const PhanSo& ps) const {
        return PhanSo(Tu * ps.Mau + ps.Tu * Mau, Mau * ps.Mau);
    }

    // Toán tử trừ hai phân số
    PhanSo operator-(const PhanSo& ps) const {
        return PhanSo(Tu * ps.Mau - ps.Tu * Mau, Mau * ps.Mau);
    }

    // Toán tử nhân hai phân số
    PhanSo operator*(const PhanSo& ps) const {
        return PhanSo(Tu * ps.Tu, Mau * ps.Mau);
    }

    // Toán tử chia hai phân số
    PhanSo operator/(const PhanSo& ps) const {
        return PhanSo(Tu * ps.Mau, Mau * ps.Tu);
    }

    // Toán tử so sánh bằng
    bool operator==(const PhanSo& ps) const {
        return Tu * ps.Mau == ps.Tu * Mau;
    }

    // Toán tử so sánh khác
    bool operator!=(const PhanSo& ps) const {
        return !(*this == ps);
    }

    // Toán tử so sánh lớn hơn hoặc bằng
    bool operator>=(const PhanSo& ps) const {
        return Tu * ps.Mau >= ps.Tu * Mau;
    }

    // Toán tử so sánh nhỏ hơn hoặc bằng
    bool operator<=(const PhanSo& ps) const {
        return Tu * ps.Mau <= ps.Tu * Mau;
    }

    // Toán tử so sánh lớn hơn
    bool operator>(const PhanSo& ps) const {
        return Tu * ps.Mau > ps.Tu * Mau;
    }

    // Toán tử so sánh nhỏ hơn
    bool operator<(const PhanSo& ps) const {
        return Tu * ps.Mau < ps.Tu * Mau;
    }

    // Hàm nhập phân số từ luồng
    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.Tu;
        cout << "Nhap mau so: ";
        in >> ps.Mau;
        if (ps.Mau == 0) ps.Mau = 1;
        ps.RutGon();
        return in;
    }

    // Hàm xuất phân số ra luồng
    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        out << ps.Tu << "/" << ps.Mau;
        return out;
    }
};

int main() {
    PhanSo a, b;

    // Nhập phân số thứ nhất
    cout << "Nhap phan so thu nhat:" << endl;
    cin >> a;

    // Nhập phân số thứ hai
    cout << "Nhap phan so thu hai:" << endl;
    cin >> b;

    // Hiển thị kết quả của các phép toán
    cout << "Phan so thu nhat: " << a << endl;
    cout << "Phan so thu hai: " << b << endl;
    cout << "Tong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;
    cout << "Thuong: " << a / b << endl;

    // So sánh hai phân số
    cout << "a " << (a == b ? "==" : "!=") << " b" << endl;
    cout << "a " << (a >= b ? ">=" : "<") << " b" << endl;
    cout << "a " << (a <= b ? "<=" : ">") << " b" << endl;

    return 0;
}
