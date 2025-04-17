// Complex.h
#pragma once
#include <iostream>
using namespace std;

// 복소수 표현용 구조체 정의
struct Complex {
    double real;
    double imag;
};

// 복소수 덧셈 함수 선언 (참조로 전달)
void add(Complex& a, Complex& b, Complex& result);
