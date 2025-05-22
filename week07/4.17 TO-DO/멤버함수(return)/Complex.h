// Complex.h
#pragma once
#include <iostream>
using namespace std;

// 복소수 클래스 정의
class Complex {
private:
    double real;
    double imag;

public:
    // 생성자
    Complex(double r = 0, double i = 0);

    // 값 설정 함수
    void set(double r, double i);

    // 멤버 함수: 다른 복소수를 더한 결과를 반환 (참조 전달)
    Complex add(Complex& other);

    // 출력 함수
    void print();
};
