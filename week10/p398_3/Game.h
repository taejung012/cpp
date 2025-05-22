#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <unistd.h>  // usleep() 함수 사용을 위한 헤더
#include <cstdlib>   // rand(), srand() 함수 사용
using namespace std;

const int MAX_MONSTER = 10; // 최대 몬스터 수
const int WIDTH = 16;       // 맵의 너비
const int HEIGHT = 8;       // 맵의 높이

class Monster;  // Monster 클래스 전방 선언

class Game {
    int map[HEIGHT][WIDTH];       // 맵: 0이면 빈칸, 1이면 아이템
    Monster* monsters[MAX_MONSTER]; // 몬스터 배열 (포인터로 저장)
    int monCount, step;           // 현재 몬스터 수, 게임 스텝 수

public:
    Game();                       // 생성자
    ~Game();                      // 소멸자

    void add(Monster* m);         // 몬스터 추가
    void draw() const;            // 화면 출력
    void update();                // 게임 상태 업데이트
    void run(int maxSteps, int delay); // 게임 루프 실행
    int countItems() const;       // 남은 아이템 개수
    void removeDead();            // 죽은 몬스터 제거
};

#endif
