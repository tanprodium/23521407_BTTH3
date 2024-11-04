#include "PhanSo.h"

int main() {
    PhanSo a, b;

    // Nhập hai phân số
    cout << "Nhap phan so thu nhat:" << endl;
    cin >> a;
    cout << "Nhap phan so thu hai:" << endl;
    cin >> b;

    // Hiển thị kết quả của các phép toán
    cout << "Phan so thu nhat: " << a << endl;
    cout << "Phan so thu hai: " << b << endl;
    cout << "Tong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;

    try {
        cout << "Thuong: " << a / b << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // So sánh hai phân số
    cout << "a " << (a == b ? "==" : "!=") << " b" << endl;
    cout << "a " << (a > b ? ">" : "<=") << " b" << endl;
    cout << "a " << (a < b ? "<" : ">=") << " b" << endl;

    return 0;
}
