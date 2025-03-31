#ifndef PUZZLE_H
#define PUZZLE_H

// 조건 6: 랭킹 보드 - 랭킹 항목을 저장하기 위한 구조체
struct RankingEntry {
    char name[20];  // 플레이어 이름 (최대 20자)
    int moves;      // 이동 횟수
    int time;       // 소요 시간(초)
};

// 퍼즐 게임 클래스
class PuzzleGame {
private:
    int N;              // 조건 1: 퍼즐 맵 크기 확장 - 3x3, 4x4, 5x5 지원
    int map[5][5];      // 조건 1: 최대 5x5 크기의 퍼즐 맵
    int initial_map[5][5]; // 조건 2: 리플레이 기능 - 초기 맵 저장
    char move_history[100]; // 조건 2: 리플레이 기능 - 이동 기록 저장 (최대 100개)
    int move_count;     // 조건 3: 게임 저장 기능 - 이동 횟수 저장
    int start_time;     // 조건 3 & 4: 게임 저장/이어가기 - 시작 시간 저장
    int history_size;   // 조건 2: 리플레이 기능 - 이동 기록 크기 추적

    void init_map();    // 조건 1: 퍼즐 맵 초기화 (크기 확장 지원)
    void shuffle_map(); // 조건 1: 맵을 무작위로 섞기 (크기 확장 적용)
    int is_solved();    // 퍼즐 완성 여부 확인 (모든 크기 공통)
    void move_tile(char direction); // 타일 이동 로직 (모든 크기 공통)

public:
    PuzzleGame(int size); // 조건 1: 생성자에서 크기 설정
    void display();       // 조건 5: 그림 퍼즐 기능 - 문자로 출력
    void play();          // 게임 진행 (모든 기능 통합)
    void replay();        // 조건 2: 리플레이 기능 - 이동 재현
    void save_game();     // 조건 3: 게임 저장 기능
    void load_game();     // 조건 4: 저장된 게임 이어가기
    void update_ranking(char* name); // 조건 6: 랭킹 보드 - 랭킹 갱신
    void show_ranking();  // 조건 6: 랭킹 보드 - 랭킹 출력
};

#endif