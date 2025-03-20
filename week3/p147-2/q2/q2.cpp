#include <iostream>
using namespace std;

int reverse(int num); // 함수 선언 (프로토타입)

int main() {
    int num;
    cout << "숫자를 입력하세요: ";
    cin >> num;
    cout << "역순 변환 결과: " << reverse(num) << endl;
    return 0;
}

// 함수 정의
int reverse(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}
