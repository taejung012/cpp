// ComplexMain.cpp
#include "Complex.h"

// 복소수 덧셈 함수 정의
void add(Complex& a, Complex& b, Complex& result) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

int main() {
    // a = 1 + 2i, b = 3 + 4i
    Complex a = {1, 2};
    Complex b = {3, 4};
    Complex c;

    // add(a, b, c) 방식으로 덧셈
    add(a, b, c);

    // 결과 출력
    cout << "a + b = " << c.real << " + " << c.imag << "i" << endl;

    return 0;
}
