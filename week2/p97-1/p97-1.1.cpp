#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {  // 행 반복
        for (int j = 1; j <= i; j++) {  // 1부터 i까지 출력
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
