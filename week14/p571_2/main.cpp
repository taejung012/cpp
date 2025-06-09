#include <iostream>
#include <string>
#include "MonsterWorld.h"
#include "FileManager.h"

using namespace std;

bool checkPassword() {
    const string adminPass = "1234";
    string input;
    cout << "관리자 비밀번호를 입력하세요: ";
    cin >> input;
    return input == adminPass;
}

int main() {
    if (!checkPassword()) {
        cout << "비밀번호가 틀렸습니다. 프로그램을 종료합니다.\n";
        return 1;
    }

    MonsterWorld game;
    FileManager fileManager;

    try {
        fileManager.loadRanking();
    } catch (const std::exception& e) {
        cout << "랭킹 파일 로드 실패: " << e.what() << "\n";
    }

    game.run();

    try {
        fileManager.saveRanking(game.getRanking());
    } catch (const std::exception& e) {
        cout << "랭킹 파일 저장 실패: " << e.what() << "\n";
    }

    return 0;
}
