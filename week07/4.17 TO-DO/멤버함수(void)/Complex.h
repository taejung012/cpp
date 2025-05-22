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

    // 멤버 함수: 두 개의 복소수를 더해서 this에 저장
    void add(Complex& a, Complex& b);

    // 출력 함수
    void print();
};
