// 5*5 크기의 체커 보드와 관련된 다음 프로그램을 작성해라
#include "p202_2.h"  // 헤더 파일 포함

// 5x5 배열을 0과 1로 무작위로 채우는 함수
void randomMap(int map[SIZE][SIZE]) {
    srand(time(NULL));  // 현재 시간을 기반으로 난수 생성
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = rand() % 2;  // 0 또는 1을 랜덤하게 설정
        }
    }
}

// 5x5 배열을 체커보드 형태로 출력하는 함수
void printMap(int map[SIZE][SIZE]) {
    printf("체커 보드 상태:\n");
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", map[i][j]);  // 배열의 값을 출력
        }
        printf("\n");
    }
}

// 가로, 세로, 또는 대각선이 모두 0 또는 1인지 확인하고 출력하는 함수
void checkMap(int map[SIZE][SIZE]) {
    int i, j, flag;
    int found = 0; // 특정 패턴을 찾았는지 확인하는 변수

    printf("\n[검사 결과]\n");

    // 1. 가로(행) 확인
    for (i = 0; i < SIZE; i++) {
        flag = 1;
        for (j = 1; j < SIZE; j++) {
            if (map[i][j] != map[i][0]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("가로 %d번째 줄이 모두 %d입니다.\n", i + 1, map[i][0]);
            found = 1;
        }
    }

    // 2. 세로(열) 확인
    for (j = 0; j < SIZE; j++) {
        flag = 1;
        for (i = 1; i < SIZE; i++) {
            if (map[i][j] != map[0][j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("세로 %d번째 줄이 모두 %d입니다.\n", j + 1, map[0][j]);
            found = 1;
        }
    }

    // 3. 좌상 -> 우하 대각선 확인 (↘ 방향)
    flag = 1;
    for (i = 1; i < SIZE; i++) {
        if (map[i][i] != map[0][0]) {  
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("좌상에서 우하 대각선이 모두 %d입니다.\n", map[0][0]);
        found = 1;
    }

    // 4. 우상 -> 좌하 대각선 확인 (↙ 방향)
    flag = 1;
    for (i = 1; i < SIZE; i++) {
        if (map[i][SIZE - i - 1] != map[0][SIZE - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("우상에서 좌하 대각선이 모두 %d입니다.\n", map[0][SIZE - 1]);
        found = 1;
    }

    // 일치하는 줄이 없으면 메시지 출력
    if (!found) {
        printf("가로나 세로 또는 대각선이 모두 0이거나 1인 경우가 없습니다.\n");
    }
}

// 메인 함수: 프로그램 실행 시작점
int main() {
    int map[SIZE][SIZE];  // 5x5 크기의 배열 선언

    randomMap(map);  // 랜덤한 0과 1을 채움
    printMap(map);   // 배열을 출력
    checkMap(map);   // 패턴 검사 후 출력

    return 0;  // 프로그램 종료
}
