#include <iostream>
using namespace std;

class Complex {
public:
    double r, i; // real, imag를 r, i로 줄임

    Complex(double real = 0, double imag = 0) : r(real), i(imag) {}

    // 결과 출력용
    void out() const {
        cout << r << " + " << i << "i" << endl;
    }

    // [3] 멤버 함수 (void)
    void add3(const Complex& a, const Complex& b) {
        r = a.r + b.r;
        i = a.i + b.i;
    }

    // [4] 멤버 함수 (return)
    Complex add4(const Complex& b) const {
        return Complex(r + b.r, i + b.i);
    }

    // [5] 연산자 오버로딩
    Complex operator+(const Complex& b) const {
        return Complex(r + b.r, i + b.i);
    }
};

// [1] 일반 함수 (void)
void add1(const Complex& a, const Complex& b, Complex& res) {
    res.r = a.r + b.r;
    res.i = a.i + b.i;
}

// [2] 일반 함수 (return)
Complex add2(Complex a, Complex b) {
    return Complex(a.r + b.r, a.i + b.i);
}

int main() {
    Complex a(1, 2), b(3, 4), c;

    cout << "1번 결과: "; add1(a, b, c); c.out();
    cout << "2번 결과: "; c = add2(a, b); c.out();
    cout << "3번 결과: "; c.add3(a, b); c.out();
    cout << "4번 결과: "; c = a.add4(b); c.out();
    cout << "5번 결과: "; c = a + b; c.out();

    return 0;
}