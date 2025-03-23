// 1. 표준 입출력 라이브러리 포함
#include <iostream> // cout, cin 등을 사용하기 위해 필요

using namespace std; // std:: 생략하고 cin, cout 바로 사용하기 위해 선언

// 2. 숫자를 역순으로 변환하는 함수 정의
int reverse(int num) { // 매개변수 num: 입력받은 정수
    int reversed = 0; // 역순으로 변환한 결과를 저장할 변수 (초기값 0)

    while (num > 0) { // num이 0보다 클 때까지 반복 (모든 자릿수를 처리할 때까지)
        reversed = reversed * 10 + num % 10; // 기존 reversed에 새로운 숫자를 추가
        num /= 10; // num을 10으로 나누어 마지막 자리 제거 (다음 자릿수로 이동)
    }

    return reversed; // 역순 변환된 결과 반환
}

// 3. 프로그램 실행 시작 (메인 함수)
int main() {
    int num; // 사용자 입력을 저장할 변수 선언

    // 4. 사용자 입력 받기
    cout << "숫자를 입력하세요: "; // 숫자 입력 요청 메시지 출력
    cin >> num; // 사용자가 입력한 숫자를 num 변수에 저장

    // 5. 역순 변환 결과 출력
    cout << "역순 변환 결과: " << reverse(num) << endl;
    // reverse(num) 함수를 호출하여 변환된 숫자를 출력

    return 0; // 프로그램 정상 종료
}