/*
P.147-5 러시안 룰렛

3.8절의 러시안 룰렛 게임을 다음과 같이 확장하라.
1. 6연발 권총이 아니라 n-연발 권총이다. n은 사용자로부터 입력받는다.
2. 모든 총알이 발사될 때까지 게임을 진행한다.
   예를 들어, 5명이 2발의 총알을 넣어 게임을 한다면 두 명이 총알을 맞는다..
*/

#include <iostream> // 표준 입출력을 위한 헤더 (cin, cout 사용)
#include <cstdlib>  // 난수를 생성하기 위한 rand(), srand() 포함
#include <ctime>    // 현재 시간을 기준으로 난수를 초기화하기 위한 time() 포함

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
    int* chamber = new int[n]();  // 동적 배열 생성 및 초기화

    // 랜덤하게 총알 삽입
    srand(time(0));  // 현재 시간을 기준으로 난수 생성기를 초기화
    for (int i = 0; i < m; i++) {
        int pos;
        do {
            pos = rand() % n;  // 0~n-1 사이의 난수를 생성하여 총알 위치 설정
        } while (chamber[pos] == 1);  // 이미 총알이 있는 위치라면 다시 랜덤 생성
        chamber[pos] = 1;  // 총알 삽입
    }

    // 게임 시작
    cout << "\n게임 시작! 방아쇠를 당깁니다...\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "번째 탄창: ";
        if (chamber[i] == 1) {
            cout << "총알 발사! 탈락!\n";
        } else {
            cout << "살아남음\n";
        }
    }

    cout << "모든 총알이 발사되었습니다. 게임 종료!\n";

    delete[] chamber; // 동적 배열 해제
    return 0;
}
