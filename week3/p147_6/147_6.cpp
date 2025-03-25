#include "147_6.h"  // 필요한 헤더 파일을 포함 (헤더 파일은 실제 구현에 따라 달라질 수 있음)

// 구구단 게임 (1~9 사이의 숫자 곱셈)
void playGugu() {
    // 1부터 9 사이의 랜덤 숫자 a와 b를 생성
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int answer;

    // 문제 출력
    cout << a << " x " << b << " = ";

    // 사용자 입력을 기다림
    while (true) {
        cin >> answer;  // 사용자로부터 답을 입력받음

        // 답이 맞으면 종료
        if (answer == a * b) {
            cout << "정답입니다!" << endl;
            break;
        }
        // 답이 틀리면 다시 시도하라고 안내
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 두 자리 곱셈 게임 (10~99 사이의 숫자 곱셈)
void playMul() {
    // 10부터 99 사이의 랜덤 숫자 a와 b를 생성
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    // 문제 출력
    cout << a << " x " << b << " = ";

    // 사용자 입력을 기다림
    while (true) {
        cin >> answer;  // 사용자로부터 답을 입력받음

        // 답이 맞으면 종료
        if (answer == a * b) {
            cout << "정답입니다!" << endl;
            break;
        }
        // 답이 틀리면 다시 시도하라고 안내
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 여러 자리 덧셈 게임 (자리 수에 따라 숫자 생성)
void playAdd(int digits) {
    // 최대 숫자와 최소 숫자 설정 (예: 2자리 숫자의 경우 99와 10)
    int maxNum = pow(10, digits) - 1;
    int minNum = pow(10, digits - 1);

    // 지정된 자리 수에 맞춰 랜덤 숫자 a와 b를 생성
    int a = rand() % (maxNum - minNum + 1) + minNum;
    int b = rand() % (maxNum - minNum + 1) + minNum;
    int answer;

    // 문제 출력
    cout << a << " + " << b << " = ";

    // 사용자 입력을 기다림
    while (true) {
        cin >> answer;  // 사용자로부터 답을 입력받음

        // 답이 맞으면 종료
        if (answer == a + b) {
            cout << "정답입니다!" << endl;
            break;
        }
        // 답이 틀리면 다시 시도하라고 안내
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 메인 함수
int main() {
    srand(time(0)); // 랜덤 시드 설정 (실행할 때마다 다른 난수 생성)

    int choice;
    // 게임 선택을 사용자에게 요청
    cout << "게임을 선택하세요 (1: 구구단, 2: 두 자리 곱셈, 3~9: 덧셈): ";
    cin >> choice;

    // 사용자 입력에 따라 다른 게임을 실행
    if (choice == 1) 
        playGugu();  // 구구단 게임
    else if (choice == 2) 
        playMul();  // 두 자리 곱셈 게임
    else if (choice >= 3 && choice <= 9) 
        playAdd(choice);  // 덧셈 게임 (자리 수에 따라)
    else 
        cout << "잘못된 선택입니다!" << endl;  // 잘못된 선택 처리

    return 0;  // 프로그램 종료
}
