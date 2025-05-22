#ifndef MYTIME_H
#define MYTIME_H

// MYTime 구조체: 시간 데이터를 저장
struct MYTime {
    int hours;   // 시간
    int minutes; // 분
    int seconds; // 초
    int millis;  // 밀리초
};

// 함수 선언
MYTime addTime(MYTime t1, MYTime t2);           // 방법 1: 반환값으로 결과 전달
void addTime(MYTime t1, MYTime t2, MYTime& t3); // 방법 2: 참조로 결과 전달
void addTime(MYTime t1, MYTime t2, MYTime* pt); // 방법 3: 포인터로 결과 전달

#endif