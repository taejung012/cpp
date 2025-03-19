#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "정수 n을 입력하세요: ";
    cin >> n;

    double pi = 0.0;
    for (int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) {
            pi += term;
        } else {
            pi -= term;
        }
    }

    pi *= 4; // 최종적으로 4를 곱하여 π 값 근사 계산
    cout << "근사값의 π: " << pi << endl;

    return 0;
}
