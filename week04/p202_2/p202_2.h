#ifndef P202_2_H
#define P202_2_H

#include <stdio.h>   // 표준 입출력 라이브러리
#include <stdlib.h>  // 난수 생성 및 메모리 관리 라이브러리
#include <time.h>    // 시간 기반 난수 생성을 위한 라이브러리

#define SIZE 5       // 체커보드의 크기를 5x5로 정의

// 5x5 크기의 2차원 배열을 무작위로 0과 1로 채우는 함수
void randomMap(int map[SIZE][SIZE]);

// 5x5 크기의 2차원 배열을 화면에 보기 좋게 출력하는 함수
void printMap(int map[SIZE][SIZE]);

// 가로, 세로, 또는 대각선이 모두 0 또는 1인지 확인하는 함수
void checkMap(int map[SIZE][SIZE]);

#endif  // P202_2_H
