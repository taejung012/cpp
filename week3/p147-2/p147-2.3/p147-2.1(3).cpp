// q3.cpp - main() 함수가 포함된 메인 프로그램

#include <iostream>   // 입출력 라이브러리 포함
#include "SimpleFn.h" // reverse() 함수 선언 포함

using namespace std;  // std:: 생략 가능

int main() {
    int num;  // 사용자 입력을 저장할 변수

    // 사용자에게 숫자 입력 요청
    cout << "숫자를 입력하세요: ";
    cin >> num;  // 입력받은 숫자를 변수 num에 저장

    // reverse() 함수 호출하여 결과 출력
    cout << "역순 변환 결과: " << reverse(num) << endl;

    return 0;  // 프로그램 정상 종료
}