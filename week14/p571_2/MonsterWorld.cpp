// MonsterWorld.cpp
#include "MonsterWorld.h"
#include <iostream>
#include <algorithm>
using namespace std;

MonsterWorld::MonsterWorld() {
    // 초기화
    ranking.clear();
}

void MonsterWorld::run() {
    cout << "게임 시작!\n";
    gameLoop();
}

void MonsterWorld::gameLoop() {
    string playerName;
    int playerScore = 0;
    cout << "플레이어 이름을 입력하세요: ";
    cin >> playerName;

    // 게임 진행 코드 (Canvas, Human, Tuman, Matrix 관련 코드 여기에)
    // 예시: 점수 임의 증가
    playerScore = rand() % 100;

    cout << playerName << "님의 점수: " << playerScore << "\n";

    updateRanking(playerName, playerScore);
}

void MonsterWorld::updateRanking(const string& playerName, int score) {
    ranking.push_back({playerName, score});
    // 점수 기준 내림차순 정렬
    sort(ranking.begin(), ranking.end(), [](const RankingEntry& a, const RankingEntry& b) {
        return a.score > b.score;
    });
    // 랭킹 10위까지만 유지
    if (ranking.size() > 10) ranking.resize(10);
}

vector<RankingEntry> MonsterWorld::getRanking() const {
    return ranking;
}
