#include <stdio.h>   // printf 사용을 위한 헤더
#include "mytime.h"  // MYTime 헤더 파일 포함

// 방법 1: 두 MYTime 객체를 더하고 결과를 반환값으로 제공
MYTime addTime(MYTime t1, MYTime t2) {
    MYTime 결과;
    int 총밀리초 = t1.millis + t2.millis;
    결과.millis = 총밀리초 % 1000;         // 밀리초 계산 (1000 초과 시 초로 넘김)
    int 초넘김 = 총밀리초 / 1000;           // 밀리초에서 초로 넘기는 값

    int 총초 = t1.seconds + t2.seconds + 초넘김;
    결과.seconds = 총초 % 60;              // 초 계산 (60 초과 시 분으로 넘김)
    int 분넘김 = 총초 / 60;                // 초에서 분으로 넘기는 값

    int 총분 = t1.minutes + t2.minutes + 분넘김;
    결과.minutes = 총분 % 60;              // 분 계산 (60 초과 시 시간으로 넘김)
    결과.hours = t1.hours + t2.hours + 총분 / 60; // 시간 계산

    return 결과;
}

// 방법 2: 두 MYTime 객체를 더하고 결과를 참조로 저장
void addTime(MYTime t1, MYTime t2, MYTime& t3) {
    int 총밀리초 = t1.millis + t2.millis;
    t3.millis = 총밀리초 % 1000;           // 밀리초 계산
    int 초넘김 = 총밀리초 / 1000;           // 밀리초에서 초로 넘기는 값

    int 총초 = t1.seconds + t2.seconds + 초넘김;
    t3.seconds = 총초 % 60;                // 초 계산
    int 분넘김 = 총초 / 60;                // 초에서 분으로 넘기는 값

    int 총분 = t1.minutes + t2.minutes + 분넘김;
    t3.minutes = 총분 % 60;                // 분 계산
    t3.hours = t1.hours + t2.hours + 총분 / 60; // 시간 계산
}

// 방법 3: 두 MYTime 객체를 더하고 결과를 포인터로 저장
void addTime(MYTime t1, MYTime t2, MYTime* pt) {
    int 총밀리초 = t1.millis + t2.millis;
    pt->millis = 총밀리초 % 1000;          // 밀리초 계산
    int 초넘김 = 총밀리초 / 1000;           // 밀리초에서 초로 넘기는 값

    int 총초 = t1.seconds + t2.seconds + 초넘김;
    pt->seconds = 총초 % 60;               // 초 계산
    int 분넘김 = 총초 / 60;                // 초에서 분으로 넘기는 값

    int 총분 = t1.minutes + t2.minutes + 분넘김;
    pt->minutes = 총분 % 60;               // 분 계산
    pt->hours = t1.hours + t2.hours + 총분 / 60; // 시간 계산
}

// 시간 출력 함수
void 시간출력(MYTime 시간) {
    printf("%02d:%02d:%02d:%03d\n", 시간.hours, 시간.minutes, 시간.seconds, 시간.millis);
    // 형식: 01:02:03:567 (시간:분:초:밀리초)
}

// 메인 함수: 세 방법 테스트
int main() {
    MYTime 시간1 = {1, 30, 45, 500}; // 1시간 30분 45초 500밀리초
    MYTime 시간2 = {2, 15, 20, 700}; // 2시간 15분 20초 700밀리초

    // 방법 1 테스트: 반환값
    MYTime 결과1 = addTime(시간1, 시간2);
    printf("방법 1 (반환값): ");
    시간출력(결과1);

    // 방법 2 테스트: 참조
    MYTime 결과2;
    addTime(시간1, 시간2, 결과2); // 누락된 부분 수정
    printf("방법 2 (참조): ");
    시간출력(결과2);

    // 방법 3 테스트: 포인터
    MYTime 결과3;
    addTime(시간1, 시간2, &결과3);
    printf("방법 3 (포인터): ");
    시간출력(결과3);

    return 0;
}