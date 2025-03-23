// SimpleFn.cpp - reverse() 함수 정의

#include "SimpleFn.h"  // 헤더 파일 포함 (함수 선언을 가져옴)

// reverse() 함수: 입력받은 정수를 거꾸로 변환하여 반환
int reverse(int num) {
    int reversed = 0;  // 역순으로 변환한 결과를 저장할 변수

    while (num > 0) {  // 숫자가 0보다 클 때까지 반복
        reversed = reversed * 10 + num % 10;  // 마지막 자리 숫자를 결과 변수에 추가
        num /= 10;  // 원래 숫자의 마지막 자리를 제거
    }

    return reversed;  // 변환된 숫자를 반환
}