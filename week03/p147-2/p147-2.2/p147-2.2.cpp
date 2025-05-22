/*
    p147-2
    정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 작성하라.
    예를 들어 reverse(12345)는 54321을 반환한다.
    이 함수와 이를 사용하는 프로그램을 그림 3.5와 같이 네 가지 방법으로 구현하고 
    결과가 동일한지 확인하라.
*/

#include <iostream> // 표준 입출력 라이브러리 포함
using namespace std; // std 네임스페이스 사용

// 함수 선언 (프로토타입)
// 이 함수는 정수를 입력받아 그 숫자의 역순을 반환합니다.
int reverse(int num);

int main() {
    int num; // 사용자 입력을 받을 정수 변수 선언

    // 사용자에게 숫자 입력 요청
    cout << "숫자를 입력하세요: "; 
    cin >> num; // 입력된 값을 num 변수에 저장

    // reverse() 함수를 호출하여 숫자를 뒤집은 후 출력
    cout << "역순 변환 결과: " << reverse(num) << endl;

    return 0; // 프로그램 정상 종료
}

// 함수 정의 (숫자를 뒤집는 기능을 수행)
int reverse(int num) {
    int reversed = 0; // 뒤집힌 숫자를 저장할 변수

    // num이 0보다 큰 동안 반복 (모든 자리수를 처리할 때까지)
    while (num > 0) {
        reversed = reversed * 10 + num % 10; // 현재 숫자의 마지막 자리를 추가
        num /= 10; // 마지막 자리 제거
    }

    return reversed; // 최종적으로 뒤집힌 숫자 반환
}
