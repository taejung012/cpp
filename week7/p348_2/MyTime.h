// MyTime.h
#pragma once

class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0); // 기존 생성자
    MyTime(double duration);                            // 새로 추가한 생성자

    void input();            // 사용자 입력 함수
    void show() const;        // 시간 출력 함수
    MyTime addTime(const MyTime& t) const; // 시간 합산 함수
};
