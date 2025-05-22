#include "Sample.h"

int Sample::count = 0;

// 기본 생성자
Sample::Sample() {
    name = nullptr;
    count++;
}

// 문자열 생성자
Sample::Sample(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    count++;
}

// 복사 생성자
Sample::Sample(const Sample& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    count++;
}

// 소멸자
Sample::~Sample() {
    delete[] name;
    count--;
}

// count 출력
void Sample::printCount() {
    std::cout << "현재 Sample 객체 수: " << count << std::endl;
}
