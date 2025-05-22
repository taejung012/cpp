#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <cstring> // strcpy, strlen

class Sample {
private:
    char* name;
    static int count;

public:
    Sample(); // 기본 생성자
    Sample(const char* name); // 문자열 매개변수 생성자
    Sample(const Sample& other); // 복사 생성자
    ~Sample(); // 소멸자

    void printCount(); // count 출력 함수
};

#endif
