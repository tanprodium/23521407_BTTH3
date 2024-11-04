#include "SoPhuc.h"

int main() {
    SoPhuc a, b;

    // Nhập số phức thứ nhất
    cout << "Nhap so phuc thu nhat:" << endl;
    cin >> a;

    // Nhập số phức thứ hai
    cout << "Nhap so phuc thu hai:" << endl;
    cin >> b;

    // Hiển thị kết quả của các phép toán
    cout << "So phuc thu nhat: " << a << endl;
    cout << "So phuc thu hai: " << b << endl;
    cout << "Tong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;

    try {
        cout << "Thuong: " << a / b << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // So sánh hai số phức
    cout << "a " << (a == b ? "==" : "!=") << " b" << endl;

    return 0;
}
