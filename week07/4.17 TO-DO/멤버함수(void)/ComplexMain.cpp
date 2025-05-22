// ComplexMain.cpp
#include "Complex.h"

// 생성자 정의
Complex::Complex(double r, double i) : real(r), imag(i) {}

// 값 설정 함수 정의
void Complex::set(double r, double i) {
    real = r;
    imag = i;
}

// 멤버 함수 정의: 참조로 전달받은 두 복소수를 더해서 this에 저장
void Complex::add(Complex& a, Complex& b) {
    real = a.real + b.real;
    imag = a.imag + b.imag;
}

// 출력 함수 정의
void Complex::print() {
    cout << real << " + " << imag << "i" << endl;
}

// main 함수
int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    // 멤버 함수 방식: c = a + b
    c.add(a, b);

    cout << "a + b = ";
    c.print();

    return 0;
}
