// ComplexMain.cpp
#include "Complex.h"

// 생성자 정의
Complex::Complex(double r, double i) : real(r), imag(i) {}

// 값 설정 함수 정의
void Complex::set(double r, double i) {
    real = r;
    imag = i;
}

// 멤버 함수 정의 (참조로 받은 복소수를 더해서 새 객체 반환)
Complex Complex::add(Complex& other) {
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

    // c = a.add(b); 형태
    Complex c = a.add(b);

    cout << "a + b = ";
    c.print();

    return 0;
}
