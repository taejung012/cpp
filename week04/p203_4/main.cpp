#include <stdio.h>   // 기본 입출력 (printf, scanf)
#include <stdlib.h>  // rand(), srand(), exit()
#include <time.h>    // time() 함수
#include "puzzle.h"  // 헤더 파일 포함

// 조건 1: "게임을 3x3과 5x5로 확장하라" - 생성자에서 퍼즐 크기 설정
PuzzleGame::PuzzleGame(int size) {
    N = size;         // 조건 1: 사용자가 선택한 크기(3, 4, 5)를 저장
    move_count = 0;   // 조건 3: "현재까지 퍼즐 조각을 움직인 횟수도 저장되어야 한다" - 이동 횟수 초기화
    history_size = 0; // 조건 2: "게이머의 움직임들도 모두 저장해야 한다" - 이동 기록 크기 초기화
    start_time = time(0); // 조건 3 & 4: "시각 정보도 저장되어야 한다" - 시작 시간 저장
    init_map();       // 조건 1: 맵 초기화 호출
    shuffle_map();    // 조건 1: 맵 섞기 호출
}

// 조건 1: "게임을 3x3과 5x5로 확장하라" - 맵을 순서대로 초기화
void PuzzleGame::init_map() {
    int num = 1;
    for (int i = 0; i < N; i++) { // 조건 1: N에 따라 3x3, 4x4, 5x5 크기 초기화
        for (int j = 0; j < N; j++) {
            map[i][j] = num;  // 1부터 순서대로 숫자 채움
            num++;
        }
    }
    map[N-1][N-1] = 0; // 마지막 칸을 빈 칸(0)으로 설정
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initial_map[i][j] = map[i][j]; // 조건 2: "최초의 섞인 퍼즐 맵을 저장해두어야 한다" - 초기 맵 복사
        }
    }
}

// 조건 1: "게임을 3x3과 5x5로 확장하라" - 맵을 무작위로 섞기
void PuzzleGame::shuffle_map() {
    srand(time(0)); // 난수 생성 초기화
    for (int i = 0; i < N * N; i++) { // 조건 1: N에 따라 섞기 범위 조정
        int r1 = rand() % N;
        int c1 = rand() % N;
        int r2 = rand() % N;
        int c2 = rand() % N;
        int temp = map[r1][c1];
        map[r1][c1] = map[r2][c2]; // 두 위치 교환
        map[r2][c2] = temp;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            initial_map[i][j] = map[i][j]; // 조건 2: "최초의 섞인 퍼즐 맵을 저장해두어야 한다" - 섞인 맵 저장
        }
    }
}

// 퍼즐이 풀렸는지 확인 (모든 크기 공통)
int PuzzleGame::is_solved() {
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N-1 && j == N-1) {
                if (map[i][j] != 0) return 0; // 마지막 칸이 0이 아니면 실패
            }
            else if (map[i][j] != num) return 0; // 순서가 맞지 않으면 실패
            num++;
        }
    }
    return 1; // 모두 맞으면 성공
}

// 타일 이동 로직 (방향 수정: w=위, s=아래, a=왼쪽, d=오른쪽)
void PuzzleGame::move_tile(char direction) {
    int r = -1, c = -1;
    for (int i = 0; i < N; i++) { // 빈 칸 위치 찾기
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                r = i; c = j; break;
            }
        }
    }
    // 수정된 이동 방향
    if (direction == 'w' && r > 0) { // w: 위로 이동 (빈 칸이 맨 위가 아니어야 함)
        map[r][c] = map[r-1][c];
        map[r-1][c] = 0;
    }
    else if (direction == 's' && r < N-1) { // s: 아래로 이동 (빈 칸이 맨 아래가 아니어야 함)
        map[r][c] = map[r+1][c];
        map[r+1][c] = 0;
    }
    else if (direction == 'a' && c > 0) { // a: 왼쪽으로 이동 (빈 칸이 맨 왼쪽이 아니어야 함)
        map[r][c] = map[r][c-1];
        map[r][c-1] = 0;
    }
    else if (direction == 'd' && c < N-1) { // d: 오른쪽으로 이동 (빈 칸이 맨 오른쪽이 아니어야 함)
        map[r][c] = map[r][c+1];
        map[r][c+1] = 0;
    }
}

// 조건 5: "퍼즐 조각에 숫자가 아니라 문자가 출력되도록 해 보라" - 문자로 퍼즐 출력
void PuzzleGame::display() {
    char pieces[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'}; // 조건 5: 간단한 문자로 아스키 아트 대체
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%c] ", pieces[map[i][j]]); // 조건 5: 숫자를 문자로 매핑하여 출력
        }
        printf("\n");
    }
    printf("Moves: %d\n", move_count); // 조건 3: "현재까지 퍼즐 조각을 움직인 횟수도 저장되어야 한다" - 이동 횟수 출력
}

// 게임 진행 (모든 기능 통합)
void PuzzleGame::play() {
    char input;
    while (!is_solved()) { // 퍼즐이 풀릴 때까지 반복
        display(); // 조건 5: 현재 상태 출력
        printf("Move (w/a/s/d), Save (v), Quit (q): ");
        scanf(" %c", &input); // 사용자 입력 받기
        if (input == 'q') return; // q 입력 시 종료
        if (input == 'v') { save_game(); return; } // 조건 3: "경기를 종료하는 기능" - 저장 후 종료
        move_tile(input); // 타일 이동 (수정된 방향 적용)
        move_count++; // 조건 3: "현재까지 퍼즐 조각을 움직인 횟수" - 횟수 증가
        move_history[history_size] = input; // 조건 2: "게이머의 움직임들도 모두 저장해야 한다" - 이동 기록 저장
        history_size++;
    }
    display(); // 조건 5: 최종 상태 출력
    printf("Solved! Moves: %d\n", move_count);
    char name[20];
    printf("Enter name: ");
    scanf("%s", name); // 플레이어 이름 입력
    update_ranking(name); // 조건 6: "상위 10개의 게임을 랭킹 파일에 저장" - 랭킹 갱신
    replay(); // 조건 2: "움직인 내용들을 다시 순서대로 보여준다" - 리플레이 호출
}

// 조건 2: "경기가 끝나고 나면 게이머가 움직인 내용들을 다시 순서대로 보여준다" - 이동 재현
void PuzzleGame::replay() {
    printf("Replaying...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = initial_map[i][j]; // 조건 2: "최초의 섞인 퍼즐 맵을 저장" - 초기 맵 복원
        }
    }
    display(); // 조건 5: 초기 상태 출력
    for (int i = 0; i < history_size; i++) {
        move_tile(move_history[i]); // 조건 2: "움직임들을 다시 순서대로 보여준다" - 기록 재현
        display(); // 조건 5: 각 이동 후 상태 출력
        for (int t = 0; t < 10000000; t++); // 간단한 지연 (약 0.5초)
    }
}

// 조건 3: "경기 중에 현재 게임 상태를 파일에 저장하고 경기를 종료하는 기능을 구현하라"
void PuzzleGame::save_game() {
    FILE* file = fopen("game.dat", "wb"); // 조건 3: 파일에 저장 (이진 모드)
    fwrite(&N, sizeof(int), 1, file); // 조건 1 & 3: "게임을 3x3과 5x5로 확장" - 퍼즐 크기 저장
    fwrite(map, sizeof(int), N * N, file); // 조건 3: 현재 맵 상태 저장
    fwrite(&move_count, sizeof(int), 1, file); // 조건 3: "움직인 횟수도 저장" - 이동 횟수 저장
    fwrite(&history_size, sizeof(int), 1, file); // 조건 2 & 3: "움직임들도 저장" - 기록 크기 저장
    fwrite(move_history, sizeof(char), history_size, file); // 조건 2 & 3: 이동 기록 저장
    fwrite(&start_time, sizeof(int), 1, file); // 조건 3 & 4: "시각 정보도 저장" - 시작 시간 저장
    int current = time(0); // 현재 시간 계산
    fwrite(&current, sizeof(int), 1, file); // 조건 3 & 4: "시각 정보도 저장" - 현재 시간 저장
    fclose(file); // 파일 닫기
}

// 조건 4: "저장된 경기를 계속 이어서 진행할 수 있는 기능을 구현하라"
void PuzzleGame::load_game() {
    FILE* file = fopen("game.dat", "rb"); // 조건 4: 저장된 파일 열기 (이진 모드)
    if (file == NULL) {
        printf("No saved game.\n");
        return;
    }
    fread(&N, sizeof(int), 1, file); // 조건 1 & 4: "3x3과 5x5로 확장" - 퍼즐 크기 읽기
    fread(map, sizeof(int), N * N, file); // 조건 4: 저장된 맵 읽기
    fread(&move_count, sizeof(int), 1, file); // 조건 4: "움직인 횟수" - 이동 횟수 읽기
    fread(&history_size, sizeof(int), 1, file); // 조건 2 & 4: "움직임들도 저장" - 기록 크기 읽기
    fread(move_history, sizeof(char), history_size, file); // 조건 2 & 4: 이동 기록 읽기
    fread(&start_time, sizeof(int), 1, file); // 조건 4: "시작 시각" - 시작 시간 읽기
    int current;
    fread(&current, sizeof(int), 1, file); // 조건 4: "중간에 종료한 시각" - 저장된 현재 시간 읽기
    fclose(file); // 파일 닫기
}

// 조건 6: "상위 10개의 게임을 랭킹 파일에 저장하라. 단, 파일 저장은 이진 모드로 한다"
void PuzzleGame::update_ranking(char* name) {
    RankingEntry ranking[10]; // 조건 6: 최대 10개 랭킹 저장
    int rank_size = 0;
    FILE* file = fopen("ranking.bin", "rb"); // 조건 6: 이진 모드로 파일 열기
    if (file != NULL) {
        rank_size = fread(ranking, sizeof(RankingEntry), 10, file); // 기존 랭킹 읽기
        fclose(file);
    }
    int time_taken = time(0) - start_time; // 조건 6: 게임 소요 시간 계산
    for (int j = 0; name[j] != '\0' && j < 19; j++) { // 새 기록의 이름 복사
        ranking[rank_size].name[j] = name[j];
    }
    ranking[rank_size].name[19] = '\0'; // 문자열 종료
    ranking[rank_size].moves = move_count; // 이동 횟수 저장
    ranking[rank_size].time = time_taken; // 소요 시간 저장
    rank_size++;
    if (rank_size > 10) rank_size = 10; // 조건 6: "상위 10개" - 초과 시 제한
    for (int i = 0; i < rank_size - 1; i++) { // 조건 6: 이동 횟수 기준 정렬
        for (int j = 0; j < rank_size - i - 1; j++) {
            if (ranking[j].moves > ranking[j+1].moves) {
                RankingEntry temp = ranking[j];
                ranking[j] = ranking[j+1];
                ranking[j+1] = temp;
            }
        }
    }
    file = fopen("ranking.bin", "wb"); // 조건 6: "파일 저장은 이진 모드로 한다"
    fwrite(ranking, sizeof(RankingEntry), rank_size, file); // 정렬된 랭킹 저장
    fclose(file);
}

// 조건 6: "상위 10개의 게임을 랭킹 파일에 저장" - 랭킹 출력
void PuzzleGame::show_ranking() {
    RankingEntry ranking[10];
    FILE* file = fopen("ranking.bin", "rb"); // 조건 6: 이진 모드로 파일 열기
    if (file == NULL) {
        printf("No rankings yet.\n");
        return;
    }
    int rank_size = fread(ranking, sizeof(RankingEntry), 10, file); // 최대 10개 읽기
    fclose(file);
    printf("Top Rankings:\n");
    for (int i = 0; i < rank_size; i++) {
        printf("%d. %s - Moves: %d, Time: %d\n", i+1, ranking[i].name, ranking[i].moves, ranking[i].time);
    }
}

// 조건 1: "게임을 3x3과 5x5로 확장하라" - 메인 함수에서 크기 입력
int main() {
    int size;
    printf("Enter puzzle size (3, 4, 5): ");
    scanf("%d", &size);
    if (size != 3 && size != 4 && size != 5) { // 조건 1: 유효한 크기 확인
        printf("Invalid size.\n");
        return 1;
    }
    PuzzleGame game(size); // 조건 1: 선택된 크기로 게임 생성
    char choice;
    printf("New game (n), Load game (l), Rankings (r): ");
    scanf(" %c", &choice);
    if (choice == 'l') game.load_game(); // 조건 4: "저장된 경기를 이어서 진행" - 로드 호출
    else if (choice == 'r') {
        game.show_ranking(); // 조건 6: 랭킹 출력
        return 0;
    }
    game.play(); // 모든 기능 실행
    return 0;
}
