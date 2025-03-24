// p147_2번 방법 5
#include <iostream>
#include "reverse.h"

using namespace std;

// 숫자의 자릿수를 뒤집는 함수
int reverse(int num) {
    int rev = 0;
    while (num) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main() {
    int num;
    cout << "숫자 입력: ";
    cin >> num;
    cout << "역순 변환: " << reverse(num) << endl;
    return 0;
}
