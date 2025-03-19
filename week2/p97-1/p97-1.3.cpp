#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {  // 행 반복
        for (int j = i; j >= 1; j--) {  // i부터 1까지 감소하며 출력
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
