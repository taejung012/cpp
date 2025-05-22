#include "Monster.h"

int Monster::total = 0; // 정적 멤버 초기화

// 생성자
Monster::Monster(string n, string s, int px, int py)
    : name(n), symbol(s), x(px), y(py), energy(100), itemCount(0) {
    ++total; // 전체 몬스터 수 증가
}

// 소멸자
Monster::~Monster() {
    cout << name << " 몬스터가 사라졌습니다.\n";
    --total; // 몬스터 수 감소
}

// 몬스터 이동
void Monster::move(int map[8][16]) {
    // 방향 배열: 대각선 포함 8방향
    int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
    int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
    int dir = rand() % 8;  // 랜덤 방향 선택
    x += dx[dir];
    y += dy[dir];

    // 맵 범위 벗어나지 않도록 조정
    if (x < 0) x = 0; if (x >= 16) x = 15;
    if (y < 0) y = 0; if (y >= 8) y = 7;

    // 해당 위치에 아이템이 있으면 먹고 에너지 회복
    if (map[y][x] > 0) {
        map[y][x]--;
        itemCount++;
        energy += 8;
    } else {
        energy -= 1; // 아이템 없으면 에너지 감소
    }

    if (energy < 0) energy = 0; // 최소 에너지 0
}

// 몬스터 정보 출력
void Monster::draw() const {
    cout << name << "(" << symbol << ") - 에너지: " << energy
         << ", 아이템: " << itemCount << endl;
}

// 죽었는지 확인 (에너지 0이면 죽음)
bool Monster::isDead() const {
    return energy <= 0;
}

// 전체 살아있는 몬스터 수 출력
void Monster::showCount() {
    cout << "현재 몬스터 수: " << total << endl;
}
