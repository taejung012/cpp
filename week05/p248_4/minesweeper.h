#ifndef MINESWEEPER_H
#define MINESWEEPER_H

// 최대 맵 크기 정의 // 조건 (1)
#define MAX_ROWS 40
#define MAX_COLS 80

// 전역 변수: 정적 배열로 선언 // 조건 (1)
extern int MineMapMask[MAX_ROWS][MAX_COLS];  // 마스크 맵 (0: 닫힘, 1: 열림, 2: 깃발) // 조건 (1)
extern int MineMapLabel[MAX_ROWS][MAX_COLS]; // 지뢰 맵 (0~8: 주변 지뢰 수, 9: 지뢰) // 조건 (1)

// 맵 크기와 지뢰 개수 전역 변수 // 조건 (1), (2)
extern int rows, cols, mineCount;

// 함수 선언
void 맵초기화(void);         // 조건 (2)
void 맵출력(void);           // 조건 (3)
void 칸열기(int r, int c);   // 기존 동작 유지
int 게임상태확인(void);      // 기존 동작 유지

#endif