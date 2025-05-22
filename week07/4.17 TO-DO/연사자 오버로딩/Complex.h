// Complex.h
#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 생성자
    Complex(double r = 0, double i = 0);

    // 값 설정 함수
    void set(double r, double i);

    // 연산자 오버로딩: + 연산자 정의
    Complex operator+(Complex& other);

    // 출력 함수
    void print();
};
