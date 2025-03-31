#include <stdio.h>   // 기본 입출력 (printf, scanf)
#include <stdlib.h>  // rand(), srand(), exit()
#include <time.h>    // time() 함수
#include "puzzle.h"  // 헤더 파일 포함

// 조건 1: 퍼즐 맵 크기 확장 - 생성자에서 크기 설정
PuzzleGame::PuzzleGame(int size) {
    N = size;         // 조건 1: 사용자가 선택한 크기(3, 4, 5) 저장
    move_count = 0;   // 조건 3: 이동 횟수 초기화
    history_size = 0; // 조건 2: 이동 기록 크기 초기화
    start_time = time(0); // 조건 3 & 4: 시작 시간 저장
    init_map();       // 조건 1: 맵 초기화 호출
    shuffle_map();    // 조건 1: 맵 섞기 호출
}

// 조건 1: 퍼즐 맵 크기 확장 - 맵을 순서대로 초기화
void PuzzleGame::init_map() {
    int num = 1;
    for (int i = 0; i < N; i++) { // 조건 1: N에 따라 3x3, 4x4, 5x5 초기화
        for (int j = 0; j < N; j++) {
            map[i][j] = num;  // 순서대로 숫자 채움
            num++;
        }
    }
    map[N-1][N-1] = 0; // 마지막 칸을 빈 칸(0)으로 설정
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initial_map[i][j] = map[i][j]; // 조건 2: 초기 맵 저장
        }
    }
}

// 조건 1: 퍼즐 맵 크기 확장 - 맵을 무작위로 섞기
void PuzzleGame::shuffle_map() {
    srand(time(0)); // 난수 초기화
    for (int i = 0; i < N * N; i++) { // 조건 1: N에 따라 섞기 범위 조정
        int r1 = rand() % N;
        int c1 = rand() % N;
        int r2 = rand() % N;
        int c2 = rand() % N;
        int temp = map[r1][c1];
        map[r1][c1] = map[r2][c2];
        map[r2][c2] = temp;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initial_map[i][j] = map[i][j]; // 조건 2: 섞인 초기 맵 저장
        }
    }
}

// 퍼즐 완성 여부 확인 (모든 크기 공통)
int PuzzleGame::is_solved() {
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N-1 && j == N-1) {
                if (map[i][j] != 0) return 0;
            }
            else if (map[i][j] != num) return 0;
            num++;
        }
    }
    return 1;
}

// 타일 이동 로직 (모든 크기 공통)
void PuzzleGame::move_tile(char direction) {
    int r = -1, c = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                r = i; c = j; break;
            }
        }
    }
    if (direction == 'w' && r < N-1) {
        map[r][c] = map[r+1][c];
        map[r+1][c] = 0;
    }
    else if (direction == 's' && r > 0) {
        map[r][c] = map[r-1][c];
        map[r-1][c] = 0;
    }
    else if (direction == 'a' && c < N-1) {
        map[r][c] = map[r][c+1];
        map[r][c+1] = 0;
    }
    else if (direction == 'd' && c > 0) {
        map[r][c] = map[r][c-1];
        map[r][c-1] = 0;
    }
}

// 조건 5: 그림 퍼즐 기능 - 숫자 대신 문자 출력
void PuzzleGame::display() {
    char pieces[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'}; // 간단한 문자로 아스키 아트 대체
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%c] ", pieces[map[i][j]]); // 조건 5: 숫자를 문자로 매핑
        }
        printf("\n");
    }
    printf("Moves: %d\n", move_count); // 조건 3: 이동 횟수 출력
}

// 게임 진행 (모든 기능 통합)
void PuzzleGame::play() {
    char input;
    while (!is_solved()) {
        display();
        printf("Move (w/a/s/d), Save (v), Quit (q): ");
        scanf(" %c", &input);
        if (input == 'q') return;
        if (input == 'v') { save_game(); return; } // 조건 3: 저장 호출
        move_tile(input);
        move_count++; // 조건 3: 이동 횟수 증가
        move_history[history_size] = input; // 조건 2: 이동 기록 저장
        history_size++;
    }
    display();
    printf("Solved! Moves: %d\n", move_count);
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    update_ranking(name); // 조건 6: 랭킹 갱신
    replay(); // 조건 2: 리플레이 호출
}

// 조건 2: 리플레이 기능 - 이동 재현
void PuzzleGame::replay() {
    printf("Replaying...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = initial_map[i][j]; // 조건 2: 초기 맵 복원
        }
    }
    display();
    for (int i = 0; i < history_size; i++) {
        move_tile(move_history[i]); // 조건 2: 기록된 이동 재현
        display();
        for (int t = 0; t < 10000000; t++); // 간단한 지연
    }
}

// 조건 3: 게임 저장 기능
void PuzzleGame::save_game() {
    FILE* file = fopen("game.dat", "wb");
    fwrite(&N, sizeof(int), 1, file); // 조건 1 & 3: 퍼즐 크기 저장
    fwrite(map, sizeof(int), N * N, file); // 조건 3: 맵 데이터 저장
    fwrite(&move_count, sizeof(int), 1, file); // 조건 3: 이동 횟수 저장
    fwrite(&history_size, sizeof(int), 1, file); // 조건 2 & 3: 기록 크기 저장
    fwrite(move_history, sizeof(char), history_size, file); // 조건 2 & 3: 이동 기록 저장
    fwrite(&start_time, sizeof(int), 1, file); // 조건 3 & 4: 시작 시간 저장
    int current = time(0);
    fwrite(&current, sizeof(int), 1, file); // 조건 3 & 4: 현재 시간 저장 (수정됨)
    fclose(file);
}

// 조건 4: 저장된 게임 이어가기
void PuzzleGame::load_game() {
    FILE* file = fopen("game.dat", "rb");
    if (file == NULL) {
        printf("No saved game.\n");
        return;
    }
    fread(&N, sizeof(int), 1, file); // 조건 1 & 4: 퍼즐 크기 읽기
    fread(map, sizeof(int), N * N, file); // 조건 4: 맵 데이터 읽기
    fread(&move_count, sizeof(int), 1, file); // 조건 4: 이동 횟수 읽기
    fread(&history_size, sizeof(int), 1, file); // 조건 2 & 4: 기록 크기 읽기
    fread(move_history, sizeof(char), history_size, file); // 조건 2 & 4: 이동 기록 읽기
    fread(&start_time, sizeof(int), 1, file); // 조건 4: 시작 시간 읽기
    int current;
    fread(&current, sizeof(int), 1, file); // 조건 4: 저장된 현재 시간 읽기 (수정됨)
    fclose(file);
}

// 조건 6: 랭킹 보드 - 랭킹 갱신
void PuzzleGame::update_ranking(char* name) {
    RankingEntry ranking[10];
    int rank_size = 0;
    FILE* file = fopen("ranking.bin", "rb");
    if (file != NULL) {
        rank_size = fread(ranking, sizeof(RankingEntry), 10, file);
        fclose(file);
    }
    int time_taken = time(0) - start_time; // 조건 6: 소요 시간 계산
    for (int j = 0; name[j] != '\0' && j < 19; j++) { // 이름 복사 수정
        ranking[rank_size].name[j] = name[j];
    }
    ranking[rank_size].name[19] = '\0'; // 문자열 종료
    ranking[rank_size].moves = move_count;
    ranking[rank_size].time = time_taken;
    rank_size++;
    if (rank_size > 10) rank_size = 10; // 조건 6: 상위 10개 제한
    for (int i = 0; i < rank_size - 1; i++) { // 조건 6: 이동 횟수로 정렬
        for (int j = 0; j < rank_size - i - 1; j++) {
            if (ranking[j].moves > ranking[j+1].moves) {
                RankingEntry temp = ranking[j];
                ranking[j] = ranking[j+1];
                ranking[j+1] = temp;
            }
        }
    }
    file = fopen("ranking.bin", "wb");
    fwrite(ranking, sizeof(RankingEntry), rank_size, file); // 조건 6: 이진 파일 저장
    fclose(file);
}

// 조건 6: 랭킹 보드 - 랭킹 출력
void PuzzleGame::show_ranking() {
    RankingEntry ranking[10];
    FILE* file = fopen("ranking.bin", "rb");
    if (file == NULL) {
        printf("No rankings yet.\n");
        return;
    }
    int rank_size = fread(ranking, sizeof(RankingEntry), 10, file);
    fclose(file);
    printf("Top Rankings:\n");
    for (int i = 0; i < rank_size; i++) {
        printf("%d. %s - Moves: %d, Time: %d\n", i+1, ranking[i].name, ranking[i].moves, ranking[i].time);
    }
}

// 조건 1: 퍼즐 맵 크기 확장 - 메인 함수에서 크기 입력
int main() {
    int size;
    printf("Enter puzzle size (3, 4, 5): ");
    scanf("%d", &size);
    if (size != 3 && size != 4 && size != 5) {
        printf("Invalid size.\n");
        return 1;
    }
    PuzzleGame game(size); // 조건 1: 선택된 크기로 게임 생성
    char choice;
    printf("New game (n), Load game (l), Rankings (r): ");
    scanf(" %c", &choice);
    if (choice == 'l') game.load_game(); // 조건 4: 저장된 게임 로드
    else if (choice == 'r') {
        game.show_ranking(); // 조건 6: 랭킹 출력
        return 0;
    }
    game.play(); // 모든 기능 실행
    return 0;
}