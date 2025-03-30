#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <vector>
#include <string>

class PuzzleGame {
public:
    PuzzleGame(int size);
    void start();
    void endGame();
    void saveGame(const std::string& filename);   // 게임 저장
    void loadGame(const std::string& filename);   // 게임 불러오기
    void printPuzzle();                           // 퍼즐 출력
    bool move(char direction);                    // 이동 처리
    void replay();                                // 리플레이
    void saveRank(const std::string& filename);   // 랭킹 저장 (간단한 예시)

private:
    int size;                                    // 퍼즐 크기
    std::vector<std::vector<char>> board;        // 퍼즐 보드
    std::vector<std::string> moveHistory;        // 이동 히스토리
    void printBoard();                           // 보드 출력
};

#endif
