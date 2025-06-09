// MonsterWorld.h
#ifndef MONSTERWORLD_H
#define MONSTERWORLD_H

#include <vector>
#include <string>

struct RankingEntry {
    std::string name;
    int score;
};

class MonsterWorld {
public:
    MonsterWorld();
    void run();
    std::vector<RankingEntry> getRanking() const;

private:
    std::vector<RankingEntry> ranking;
    // Canvas, Human, Tuman, Matrix 객체 및 관련 멤버 함수 선언
    void gameLoop();
    void updateRanking(const std::string& playerName, int score);
};

#endif
