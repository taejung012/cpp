#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>
using namespace std;

class Monster {
    string name, symbol; // 몬스터 이름, 출력용 심볼
    int x, y;            // 위치 좌표
    int energy;          // 에너지 수치
    int itemCount;       // 먹은 아이템 개수

public:
    static int total;    // 전체 살아있는 몬스터 수 (정적 멤버)

    Monster(string n, string s, int px, int py); // 생성자
    ~Monster();                                  // 소멸자

    void move(int map[8][16]);                   // 이동 함수
    void draw() const;                           // 정보 출력
    bool isDead() const;                         // 죽었는지 확인
    static void showCount();                     // 전체 몬스터 수 출력
};

#endif
