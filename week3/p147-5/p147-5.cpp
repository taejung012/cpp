#include <iostream>   // 입출력 라이브러리
#include <vector>     // 벡터 사용 (탄창)
#include <cstdlib>    // rand() 함수 사용
#include <ctime>      // srand() 시간 설정

using namespace std;

int main() {
    int n, m;  // 탄창 크기(n), 총알 개수(m)

    // 사용자 입력 받기
    cout << "탄창 크기(n)를 입력하세요: ";
    cin >> n;
    
    cout << "총알 개수(m)를 입력하세요 (0 ≤ m ≤ " << n << "): ";
    cin >> m;

    // 입력값 검증
    if (m > n || m < 0) {
        cout << "잘못된 총알 개수입니다! 프로그램 종료.\n";
        return 1;
    }

    // 탄창 생성 (0 = 빈 칸, 1 = 총알)
    vector<int> chamber(n, 0);

    // 랜덤하게 총알 삽입
    srand(time(0));  // 랜덤 시드 설정
    for (int i = 0; i < m; i++) {
        int pos;
        do {
            pos = rand() % n;  // 0~n-1 사이 랜덤 위치
        } while (chamber[pos] == 1);  // 중복 방지
        chamber[pos] = 1;  // 총알 삽입
    }

    // 게임 시작
    cout << "\n게임 시작! 방아쇠를 당깁니다...\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "번째 탄창: ";
        if (chamber[i] == 1) {
            cout << "총알 발사! 게임 종료!\n";
            break;
        } else {
            cout << "살아남음\n";
        }
    }

    return 0;
}
