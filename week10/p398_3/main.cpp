#include "Monster.h"   // 몬스터 클래스 정의
#include "Game.h"      // 게임 클래스 정의
#include <ctime>       // 시간 관련 함수 사용 (srand용)

// Game 클래스의 생성자
Game::Game() : monCount(0), step(0) {
    // 맵 전체를 아이템으로 채움 (1이 아이템 존재를 의미)
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            map[y][x] = 1;
}

// Game 클래스의 소멸자
Game::~Game() {
    // 생성된 몬스터들 모두 삭제
    for (int i = 0; i < monCount; ++i)
        delete monsters[i];
}

// 몬스터 추가 함수
void Game::add(Monster* m) {
    if (monCount < MAX_MONSTER)
        monsters[monCount++] = m;  // 배열에 추가 후 개수 증가
}

// 게임 상태를 출력 (몬스터 정보 표시)
void Game::draw() const {
    cout << "\n=== 스텝 " << step << " ===\n";
    for (int i = 0; i < monCount; ++i)
        monsters[i]->draw();       // 각각의 몬스터 상태 출력
    Monster::showCount();          // 전체 몬스터 수 출력 (정적 멤버 함수)
}

// 한 스텝마다 몬스터 이동 및 사망 처리
void Game::update() {
    for (int i = 0; i < monCount; ++i)
        monsters[i]->move(map);    // 맵에서 몬스터 이동
    removeDead();                  // 에너지가 0 이하인 몬스터 삭제
    step++;                        // 스텝 증가
}

// 게임 루프: 조건을 만족하는 동안 반복 실행
void Game::run(int maxSteps, int delay) {
    while (step < maxSteps && countItems() > 0 && monCount > 0) {
        draw();            // 현재 게임 상태 출력
        update();          // 게임 상태 갱신
        usleep(delay * 1000); // 지연 시간(ms)
    }

    // 게임 종료 메시지 출력
    cout << "\n게임 종료! 남은 아이템: " << countItems()
         << ", 남은 몬스터 수: " << monCount << endl;
}

// 맵에 남아있는 아이템 수 계산
int Game::countItems() const {
    int sum = 0;
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            sum += map[y][x];
    return sum;
}

// 에너지가 0 이하인 몬스터를 배열에서 제거
void Game::removeDead() {
    for (int i = 0; i < monCount; ) {
        if (monsters[i]->isDead()) {
            delete monsters[i];               // 동적 메모리 해제
            monsters[i] = monsters[--monCount]; // 뒤에서 하나 땡겨옴
        } else {
            ++i;
        }
    }
}

// 메인 함수
int main() {
    srand((unsigned)time(NULL));  // 랜덤 시드 초기화

    Game game;  // 게임 객체 생성

    // 몬스터 3마리 생성 후 게임에 추가 (랜덤 위치)
    game.add(new Monster("고블린", "G", rand() % 16, rand() % 8));
    game.add(new Monster("유령", "Y", rand() % 16, rand() % 8));
    game.add(new Monster("악당", "A", rand() % 16, rand() % 8));

    // 게임 실행 (최대 500스텝, 지연 300ms)
    game.run(500, 300);

    return 0;
}
