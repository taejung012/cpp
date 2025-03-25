#include "147_6.h"

// 구구단 게임 (1~9 사이의 숫자 곱셈)
void playGugu() {
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    int answer;

    cout << a << " x " << b << " = ";
    while (true) {
        cin >> answer;
        if (answer == a * b) {
            cout << "정답입니다!" << endl;
            break;
        }
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 두 자리 곱셈 게임 (10~99 사이의 숫자 곱셈)
void playMul() {
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    cout << a << " x " << b << " = ";
    while (true) {
        cin >> answer;
        if (answer == a * b) {
            cout << "정답입니다!" << endl;
            break;
        }
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 여러 자리 덧셈 게임 (자리 수에 따라 숫자 생성)
void playAdd(int digits) {
    int maxNum = pow(10, digits) - 1;
    int minNum = pow(10, digits - 1);

    int a = rand() % (maxNum - minNum + 1) + minNum;
    int b = rand() % (maxNum - minNum + 1) + minNum;
    int answer;

    cout << a << " + " << b << " = ";
    while (true) {
        cin >> answer;
        if (answer == a + b) {
            cout << "정답입니다!" << endl;
            break;
        }
        cout << "틀렸습니다! 다시 입력하세요: ";
    }
}

// 메인 함수
int main() {
    srand(time(0)); // 랜덤 시드 설정

    int choice;
    cout << "게임을 선택하세요 (1: 구구단, 2: 두 자리 곱셈, 3~9: 덧셈): ";
    cin >> choice;

    if (choice == 1) playGugu();
    else if (choice == 2) playMul();
    else if (choice >= 3 && choice <= 9) playAdd(choice);
    else cout << "잘못된 선택입니다!" << endl;

    return 0;
}
