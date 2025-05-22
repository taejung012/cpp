#include <stdio.h>      // printf 사용을 위한 헤더
#include <stdlib.h>     // rand, srand 사용을 위한 헤더
#include <time.h>       // time 사용을 위한 헤더
#include "minesweeper.h" // Minesweeper 헤더 파일 포함

// 전역 변수: 정적 배열로 선언 // 조건 (1)
int MineMapMask[MAX_ROWS][MAX_COLS];  // 마스크 맵 (0: 닫힘, 1: 열림, 2: 깃발) // 조건 (1)
int MineMapLabel[MAX_ROWS][MAX_COLS]; // 지뢰 맵 (0~8: 주변 지뢰 수, 9: 지뢰) // 조건 (1)

// 맵 크기와 지뢰 개수 전역 변수 // 조건 (1), (2)
int rows, cols, mineCount;

// 맵 초기화 함수 // 조건 (2)
void 맵초기화() {
    int i, j;
    // 모든 칸을 초기화 // 조건 (2)
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            MineMapMask[i][j] = 0;   // 닫힌 상태 // 조건 (2)
            MineMapLabel[i][j] = 0;  // 지뢰 없음 // 조건 (2)
        }
    }

    // 지뢰 무작위 배치 // 조건 (2)
    int minesPlaced = 0;
    while (minesPlaced < mineCount) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (MineMapLabel[r][c] != 9) { // 이미 지뢰가 없는 경우에만 // 조건 (2)
            MineMapLabel[r][c] = 9;    // 지뢰 배치 // 조건 (2)
            minesPlaced++;
        }
    }

    // 주변 지뢰 수 계산 // 조건 (2)
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (MineMapLabel[i][j] != 9) {
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && MineMapLabel[ni][nj] == 9) {
                            count++;
                        }
                    }
                }
                MineMapLabel[i][j] = count;
            }
        }
    }
}

// 맵 출력 함수 (행/열 번호 표시 추가) // 조건 (3)
void 맵출력() {
    int i, j;
    // 상단 열 번호 출력 // 조건 (3)
    printf("    "); // 행 번호 공간 // 조건 (3)
    for (j = 0; j < cols; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // 맵 출력 // 조건 (3)
    for (i = 0; i < rows; i++) {
        printf("%2d |", i); // 행 번호 // 조건 (3)
        for (j = 0; j < cols; j++) {
            if (MineMapMask[i][j] == 0) printf(" ■ ");       // 닫힌 칸 // 조건 (3)
            else if (MineMapMask[i][j] == 2) printf(" P ");  // 깃발 // 조건 (3)
            else if (MineMapLabel[i][j] == 9) printf(" * "); // 지뢰 // 조건 (3)
            else printf("%2d ", MineMapLabel[i][j]);         // 주변 지뢰 수 // 조건 (3)
        }
        printf("\n");
    }
    fflush(stdout); // 출력 버퍼를 즉시 비움
}

// 칸 열기 함수 (재귀적으로 주변 열림) // 기존 동작 유지
void 칸열기(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || MineMapMask[r][c] != 0) {
        return; // 범위 밖이거나 이미 열린 경우 // 기존 동작 유지
    }
    MineMapMask[r][c] = 1; // 열기 // 기존 동작 유지
    if (MineMapLabel[r][c] == 0) { // 주변 지뢰가 0이면 주변 칸도 열기 // 기존 동작 유지
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                칸열기(r + di, c + dj);
            }
        }
    }
}

// 게임 상태 확인 함수 // 기존 동작 유지
int 게임상태확인() {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (MineMapLabel[i][j] == 9 && MineMapMask[i][j] == 1) {
                return -1; // 지뢰를 열었음 (패배) // 기존 동작 유지
            }
            if (MineMapLabel[i][j] != 9 && MineMapMask[i][j] == 0) {
                return 0; // 아직 열리지 않은 안전한 칸이 있음 (진행 중) // 기존 동작 유지
            }
        }
    }
    return 1; // 모든 안전한 칸이 열렸음 (승리) // 기존 동작 유지
}

// 메인 함수 // 조건 (1), (2), (4)
int main() {
    srand(time(NULL)); // 난수 초기화 // 조건 (2)

    // 맵 크기 입력 // 조건 (1)
    printf("맵의 가로 크기를 입력하세요 (최대 %d): ", MAX_COLS);
    scanf("%d", &cols);
    if (cols <= 0 || cols > MAX_COLS) cols = MAX_COLS; // 최대값 제한 // 조건 (1)
    while (getchar() != '\n'); // 입력 버퍼 정리

    printf("맵의 세로 크기를 입력하세요 (최대 %d): ", MAX_ROWS);
    scanf("%d", &rows);
    if (rows <= 0 || rows > MAX_ROWS) rows = MAX_ROWS; // 조건 (1)
    while (getchar() != '\n'); // 입력 버퍼 정리

    // 지뢰 개수 입력 // 조건 (2)
    printf("지뢰 개수를 입력하세요 (최대 %d): ", rows * cols);
    scanf("%d", &mineCount);
    if (mineCount <= 0 || mineCount >= rows * cols) mineCount = rows * cols / 4; // 기본값 // 조건 (2)
    while (getchar() != '\n'); // 입력 버퍼 정리

    맵초기화();
    맵출력();

    while (1) {
        char 명령[2] = {0}; // 명령 초기화
        int 열, 행;

        printf("명령 입력 (열 행) 또는 (P 열 행): "); // 조건 (4)
        fflush(stdout); // 입력 프롬프트 즉시 출력

        // 입력 처리 개선
        if (scanf("%1s", 명령) != 1) { // 먼저 명령어 1글자 읽기
            while (getchar() != '\n'); // 버퍼 정리
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            fflush(stdout);
            continue;
        }

        if (명령[0] == 'P' || 명령[0] == 'p') {
            if (scanf("%d %d", &열, &행) != 2) {
                while (getchar() != '\n');
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                fflush(stdout);
                continue;
            }
        } else {
            // 열과 행만 입력된 경우, 명령을 숫자로 간주하고 다시 읽기
            ungetc(명령[0], stdin); // 입력을 되돌림
            if (scanf("%d %d", &열, &행) != 2) {
                while (getchar() != '\n');
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
                fflush(stdout);
                continue;
            }
            명령[0] = ' '; // 일반 열기 명령으로 처리
        }
        while (getchar() != '\n'); // 남은 버퍼 정리

        if (열 < 0 || 열 >= cols || 행 < 0 || 행 >= rows) {
            printf("잘못된 위치입니다. 다시 입력하세요.\n"); // 조건 (4)
            fflush(stdout);
            continue;
        }

        if (명령[0] == 'P' || 명령[0] == 'p') {
            if (MineMapMask[행][열] == 0) { // 닫힌 칸에만 깃발 설치
                MineMapMask[행][열] = 2; // 깃발 표시 // 조건 (4)
                printf("깃발을 설치했습니다: (%d, %d)\n", 열, 행);
            } else {
                printf("이미 열린 칸이거나 깃발이 있습니다: (%d, %d)\n", 열, 행);
            }
        } else {
            if (MineMapMask[행][열] == 0) { // 닫힌 칸만 열기
                칸열기(행, 열);
                printf("칸을 열었습니다: (%d, %d)\n", 열, 행);
            } else {
                printf("이미 열린 칸입니다: (%d, %d)\n", 열, 행);
            }
        }

        맵출력();
        int 상태 = 게임상태확인();
        if (상태 == -1) {
            printf("지뢰를 밟았습니다! 게임 오버.\n");
            fflush(stdout);
            break;
        } else if (상태 == 1) {
            printf("모든 지뢰를 피했습니다! 승리!\n");
            fflush(stdout);
            break;
        }
    }

    return 0;
}