#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {  // 행 반복
        for (int j = 5; j > i; j--) {  // 공백 출력
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {  // 왼쪽 숫자 출력
            cout << j << " ";
        }
        for (int j = 2; j <= i; j++) {  // 오른쪽 숫자 출력
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
