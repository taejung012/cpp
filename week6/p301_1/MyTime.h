// MyTime.h
#ifndef MYTIME_H
#define MYTIME_H

// MyTime 클래스 선언부
class MyTime {
private:
    int hour;
    int minute;
    int second;
    int millisec;

public:
    MyTime();                      // 기본 생성자 선언
    void convert(double duration); // 초 단위 시간 -> 시:분:초:밀리초 변환
    void print();                  // 시간 출력
    MyTime add(MyTime t);          // 시간 더하기
    void reset();                  // 시간 초기화
    void read();                   // 사용자 입력
};

#endif
