#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    // 생성자 (기본값 지원)
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {
        normalize();
    }

    // (1) + 연산자 중복 정의: 두 TimeHMS 객체를 더함
    TimeHMS operator+(const TimeHMS& t) const {
        int totalSec = sec + t.sec;
        int totalMin = min + t.min + totalSec / 60;
        int totalHour = hour + t.hour + totalMin / 60;
        return TimeHMS(totalHour, totalMin % 60, totalSec % 60);
    }

    // (2) - 연산자 중복 정의: 두 TimeHMS 객체 간 시간 차이 계산
    TimeHMS operator-(const TimeHMS& t) const {
        int total1 = hour * 3600 + min * 60 + sec;
        int total2 = t.hour * 3600 + t.min * 60 + t.sec;
        int diff = total1 - total2;
        if (diff < 0) diff = 0;
        return TimeHMS(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // (3) ==, != 연산자 중복 정의: 시간 비교
    bool operator==(const TimeHMS& t) const {
        return hour == t.hour && min == t.min && sec == t.sec;
    }
    bool operator!=(const TimeHMS& t) const {
        return !(*this == t);
    }

    // (4) 전위 증감 연산자 ++, -- : 시(hour)를 증가/감소
    TimeHMS& operator++() {
        ++hour;
        return *this;
    }
    TimeHMS& operator--() {
        if (hour > 0) --hour;
        return *this;
    }

    // (5) 후위 증감 연산자 ++, -- : 초(sec)를 증가/감소 후 정규화
    TimeHMS operator++(int) {
        TimeHMS temp = *this;
        ++sec;
        normalize();
        return temp;
    }
    TimeHMS operator--(int) {
        TimeHMS temp = *this;
        int total = hour * 3600 + min * 60 + sec;
        if (total > 0) --total;
        hour = total / 3600;
        min = (total % 3600) / 60;
        sec = total % 60;
        return temp;
    }

    // (6) 인덱스 연산자 중복: 0=hour, 1=min, 2=sec
    int operator[](int index) const {
        switch (index) {
            case 0: return hour;
            case 1: return min;
            case 2: return sec;
            default:
                cout << "잘못된 인덱스\n";
                return -1;
        }
    }

    // (7) int 형 변환: 전체 시간을 초 단위로 반환
    operator int() const {
        return hour * 3600 + min * 60 + sec;
    }

    // (8) double 형 변환: 시간을 실수형 시간 단위로 반환
    operator double() const {
        return hour + min / 60.0 + sec / 3600.0;
    }

    // (9) friend * 연산자 중복: 정수 * 시간
    friend TimeHMS operator*(int n, const TimeHMS& t) {
        int total = n * (int)t;
        return TimeHMS(total / 3600, (total % 3600) / 60, total % 60);
    }

    // (10) 입력/출력 연산자 중복 정의
    friend istream& operator>>(istream& is, TimeHMS& t) {
        is >> t.hour >> t.min >> t.sec;
        t.normalize();
        return is;
    }
    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << t.hour << "시간 " << t.min << "분 " << t.sec << "초";
        return os;
    }

private:
    // 시간 정규화 함수 (초과된 초/분 정리)
    void normalize() {
        int total = hour * 3600 + min * 60 + sec;
        hour = total / 3600;
        min = (total % 3600) / 60;
        sec = total % 60;
    }
};

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    // (1) + 연산자 테스트
    t3 = t1 + t2;
    cout << "t1 + t2 = " << t3 << endl;

    // (2) - 연산자 테스트
    t3 = t1 - t2;
    cout << "t1 - t2 = " << t3 << endl;

    // (3) ==, != 연산자 테스트
    cout << "t1 == t2: " << (t1 == t2) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;

    // (4) 전위 ++, -- 연산자 테스트
    cout << "++t1: " << ++t1 << endl;
    cout << "--t1: " << --t1 << endl;

    // (5) 후위 ++, -- 연산자 테스트
    cout << "t1++: " << t1++ << endl;
    cout << "t1--: " << t1-- << endl;

    // (6) 인덱스 연산자 테스트
    cout << "t1[0]: " << t1[0] << ", t1[1]: " << t1[1] << ", t1[2]: " << t1[2] << endl;

    // (7) int 형 변환 테스트
    cout << "(int)t1: " << (int)t1 << "초" << endl;

    // (8) double 형 변환 테스트
    cout << "(double)t1: " << (double)t1 << "시간" << endl;

    // (9) * 연산자 테스트
    TimeHMS t4 = 2 * t1;
    cout << "2 * t1 = " << t4 << endl;

    // (10) 입력 연산자 테스트
    TimeHMS t5;
    cout << "시간 입력(h m s): ";
    cin >> t5;
    cout << "입력된 시간: " << t5 << endl;

    return 0;
}
