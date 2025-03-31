#ifndef PUZZLE_H
#define PUZZLE_H

// 조건 6: "4.7절의 랭킹 보드 프로그램을 참고하여 상위 10개의 게임을 랭킹 파일에 저장하라. 단, 파일 저장은 이진 모드로 한다"
// - 랭킹 항목을 저장하기 위한 구조체 정의
struct RankingEntry {
    char name[20];  // 플레이어 이름 (최대 20자)
    int moves;      // 이동 횟수
    int time;       // 소요 시간(초)
};

// 퍼즐 게임 클래스 선언
class PuzzleGame {
private:
    int N;              // 조건 1: "게임을 3x3과 5x5로 확장하라" - 퍼즐 크기를 동적으로 설정 (3, 4, 5)
    int map[5][5];      // 조건 1: 최대 5x5 크기의 퍼즐 맵 배열
    int initial_map[5][5]; // 조건 2: "최초의 섞인 퍼즐 맵을 저장해두어야 한다" - 초기 맵 저장
    char move_history[100]; // 조건 2: "게이머의 움직임들도 모두 저장해야 한다" - 이동 기록 저장 (최대 100개)
    int move_count;     // 조건 3: "현재까지 퍼즐 조각을 움직인 횟수도 저장되어야 한다" - 이동 횟수 카운트
    int start_time;     // 조건 3 & 4: "시각 정보도 저장되어야 한다" - 게임 시작 시간
    int history_size;   // 조건 2: 이동 기록의 크기를 추적

    // 내부 함수 선언
    void init_map();    // 조건 1: 퍼즐 맵을 순서대로 초기화 (3x3, 4x4, 5x5 지원)
    void shuffle_map(); // 조건 1: 맵을 무작위로 섞음 (크기에 맞게 조정)
    int is_solved();    // 퍼즐이 풀렸는지 확인 (크기 공통)
    void move_tile(char direction); // 타일 이동 (방향 수정 포함)

public:
    PuzzleGame(int size); // 조건 1: 생성자에서 퍼즐 크기 설정
    void display();       // 조건 5: "퍼즐 조각에 숫자가 아니라 문자가 출력되도록 해 보라" - 문자 출력
    void play();          // 게임 진행 (모든 기능 통합)
    void replay();        // 조건 2: "게이머가 움직인 내용들을 다시 순서대로 보여준다" - 이동 재현
    void save_game();     // 조건 3: "현재 게임 상태를 파일에 저장하고 경기를 종료" - 저장 기능
    void load_game();     // 조건 4: "저장된 경기를 계속 이어서 진행" - 로드 기능
    void update_ranking(char* name); // 조건 6: "상위 10개의 게임을 랭킹 파일에 저장" - 랭킹 갱신
    void show_ranking();  // 조건 6: 랭킹 출력
};

#endif
