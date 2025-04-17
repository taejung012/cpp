// Complex.h
#pragma once
#include <iostream>
using namespace std;

// 복소수 표현용 구조체 정의
struct Complex {
    double real;
    double imag;
};

// 복소수 덧셈 함수 선언 (값 전달, 반환형 사용)
Complex add(Complex a, Complex b);
