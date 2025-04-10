// MyTime.cpp
#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

// 기본 생성자: 모든 시간 0으로 초기화
MyTime::MyTime() : hour(0), minute(0), second(0), millisec(0) {}

// 초 단위 시간(duration)을 시:분:초:밀리초로 변환
void MyTime::convert(double duration) {
    int totalMilli = static_cast<int>(duration * 1000);
    hour = totalMilli / (60 * 60 * 1000);
    totalMilli %= (60 * 60 * 1000);
    minute = totalMilli / (60 * 1000);
    totalMilli %= (60 * 1000);
    second = totalMilli / 1000;
    millisec = totalMilli % 1000;
}

// 시간 출력 함수: 01:02:03:456 형식
void MyTime::print() {
    cout << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << ":"
         << setw(3) << millisec << endl;
}

// 두 시간 객체를 더한 결과를 반환
MyTime MyTime::add(MyTime t) {
    MyTime result;
    result.millisec = millisec + t.millisec;
    result.second = second + t.second;
    result.minute = minute + t.minute;
    result.hour = hour + t.hour;

    // 단위 보정
    if (result.millisec >= 1000) {
        result.second += result.millisec / 1000;
        result.millisec %= 1000;
    }
    if (result.second >= 60) {
        result.minute += result.second / 60;
        result.second %= 60;
    }
    if (result.minute >= 60) {
        result.hour += result.minute / 60;
        result.minute %= 60;
    }
    return result;
}

// 모든 시간 값을 0으로 리셋
void MyTime::reset() {
    hour = minute = second = millisec = 0;
}

// 사용자로부터 시간 정보 입력 받기
void MyTime::read() {
    cout << "시간 입력 (시 분 초 밀리초): ";
    cin >> hour >> minute >> second >> millisec;
}

// === 메인 함수 ===
int main() {
    MyTime t1, t2, t3;
    
    cout << "첫 번째 시간 입력:\n";
    t1.read();

    cout << "두 번째 시간 입력:\n";
    t2.read();

    t3 = t1.add(t2);

    cout << "더한 결과: ";
    t3.print();

    cout << "\n초 단위 실수 입력 (예: 3661.789): ";
    double seconds;
    cin >> seconds;

    MyTime t4;
    t4.convert(seconds);
    cout << "변환된 시간: ";
    t4.print();

    return 0;
}