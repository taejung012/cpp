#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {  // 행 반복
        for (int j = 5; j >= 6 - i; j--) {  // 5부터 감소하면서 출력
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
