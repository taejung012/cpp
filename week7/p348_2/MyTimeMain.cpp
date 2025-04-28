// MyTimeMain.cpp
#include <iostream>
#include "MyTime.h"
using namespace std;

// (1) 기본 생성자
MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), minute(m), second(s), millisecond(ms) {
}

// (2) 새로 추가된 생성자 (실수형 시간 입력)
MyTime::MyTime(double duration) {
    int totalMilli = static_cast<int>(duration * 1000);
    hour = totalMilli / (3600 * 1000);
    totalMilli %= (3600 * 1000);
    minute = totalMilli / (60 * 1000);
    totalMilli %= (60 * 1000);
    second = totalMilli / 1000;
    millisecond = totalMilli % 1000;
}

// 사용자 입력 함수
void MyTime::input() {
    double seconds;
    cout << "초 단위(double)로 입력: ";
    cin >> seconds;

    // 입력 받은 시간으로 새로운 MyTime 객체를 생성 후 대입
    *this = MyTime(seconds);
}

// 출력 함수
void MyTime::show() const {
    cout << (hour < 10 ? "0" : "") << hour << ":"
         << (minute < 10 ? "0" : "") << minute << ":"
         << (second < 10 ? "0" : "") << second << ":"
         << (millisecond < 100 ? (millisecond < 10 ? "00" : "0") : "") 
         << millisecond << endl;
}

// 시간 합산 함수
MyTime MyTime::addTime(const MyTime& t) const {
    int newMilli = millisecond + t.millisecond;
    int carrySec = newMilli / 1000;
    newMilli %= 1000;

    int newSec = second + t.second + carrySec;
    int carryMin = newSec / 60;
    newSec %= 60;

    int newMin = minute + t.minute + carryMin;
    int carryHour = newMin / 60;
    newMin %= 60;

    int newHour = hour + t.hour + carryHour;

    return MyTime(newHour, newMin, newSec, newMilli);
}

// main 함수
int main() {
    MyTime t1, t2, result;

    cout << "[첫 번째 시간 입력]\n";
    t1.input();

    cout << "[두 번째 시간 입력]\n";
    t2.input();

    cout << "\n[입력된 시간]\n";
    cout << "t1: "; t1.show();
    cout << "t2: "; t2.show();

    result = t1.addTime(t2);

    cout << "\n[합산 결과]\n";
    result.show();

    return 0;
}
