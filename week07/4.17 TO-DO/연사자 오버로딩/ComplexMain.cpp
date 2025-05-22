// ComplexMain.cpp
#include "Complex.h"

// 생성자 정의
Complex::Complex(double r, double i) : real(r), imag(i) {}

// 값 설정 함수 정의
void Complex::set(double r, double i) {
    real = r;
    imag = i;
}

// 연산자 오버로딩 정의 (a + b)
Complex Complex::operator+(Complex& other) {
    Complex result;
    result.real = this->real + other.real;
    result.imag = this->imag + other.imag;
    return result;
}

// 출력 함수 정의
void Complex::print() {
    cout << real << " + " << imag << "i" << endl;
}

// main 함수
int main() {
    Complex a(1, 2);
    Complex b(3, 4);

    // 연산자 오버로딩 사용
    Complex c = a + b;

    cout << "a + b = ";
    c.print();

    return 0;
}
