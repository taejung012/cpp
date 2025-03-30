#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "puzzle_game.h"

PuzzleGame::PuzzleGame(int size) : size(size) {
    board.resize(size, std::vector<char>(size));
    moveHistory.clear();
    // 초기 보드 설정 (그림 퍼즐 기능)
    char letter = 'A';
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = letter++;
        }
    }
    board[size - 1][size - 1] = ' ';  // 빈 칸 설정
}

// 게임 보드 출력
void PuzzleGame::printBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// 퍼즐 출력 (문자 사용)
void PuzzleGame::printPuzzle() {
    printBoard();
}

// 사용자의 이동 처리
bool PuzzleGame::move(char direction) {
    int empty_x = -1, empty_y = -1;
    // 빈 칸 찾기
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                empty_x = i;
                empty_y = j;
            }
        }
    }

    // 이동 처리
    switch (direction) {
        case 'w':  // 위로 이동
            if (empty_x > 0) {
                std::swap(board[empty_x][empty_y], board[empty_x - 1][empty_y]);
                moveHistory.push_back("위로");
                return true;
            }
            break;
        case 's':  // 아래로 이동
            if (empty_x < size - 1) {
                std::swap(board[empty_x][empty_y], board[empty_x + 1][empty_y]);
                moveHistory.push_back("아래로");
                return true;
            }
            break;
        case 'a':  // 왼쪽으로 이동
            if (empty_y > 0) {
                std::swap(board[empty_x][empty_y], board[empty_x][empty_y - 1]);
                moveHistory.push_back("왼쪽으로");
                return true;
            }
            break;
        case 'd':  // 오른쪽으로 이동
            if (empty_y < size - 1) {
                std::swap(board[empty_x][empty_y], board[empty_x][empty_y + 1]);
                moveHistory.push_back("오른쪽으로");
                return true;
            }
            break;
        default:
            std::cout << "잘못된 이동입니다!" << std::endl;
            return false;
    }
    return false;
}

// 게임 종료 후 리플레이
void PuzzleGame::replay() {
    std::cout << "당신의 이동 기록:" << std::endl;
    for (const auto& move : moveHistory) {
        std::cout << move << std::endl;
    }
}

// 게임 종료
void PuzzleGame::endGame() {
    std::cout << "게임 종료!" << std::endl;
    replay();
}

// 게임 저장
void PuzzleGame::saveGame(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    // 보드 저장
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            outFile << board[i][j] << " ";
        }
        outFile << std::endl;
    }

    outFile.close();
    std::cout << "게임이 저장되었습니다!" << std::endl;
}

// 게임 불러오기
void PuzzleGame::loadGame(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    // 보드 불러오기
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inFile >> board[i][j];
        }
    }

    inFile.close();
    std::cout << "게임이 불러와졌습니다!" << std::endl;
}

// 랭킹 저장
void PuzzleGame::saveRank(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);
    outFile << "Player1: " << "Score" << std::endl;
    outFile.close();
}

// 게임 시작 함수
void PuzzleGame::start() {
    while (true) {
        printPuzzle();
        char moveDirection;
        std::cout << "이동을 입력하세요 (w/a/s/d), 저장하려면 s, 종료하려면 q: ";
        std::cin >> moveDirection;

        if (moveDirection == 'q') {
            endGame();
            break;
        } else if (moveDirection == 's') {
            std::cout << "저장할 파일 이름을 입력하세요: ";
            std::string filename;
            std::cin >> filename;
            saveGame(filename);
        } else {
            if (!move(moveDirection)) {
                std::cout << "이동 실패, 다시 시도하세요!" << std::endl;
            }
        }
    }
}

int main() {
    int choice;
    int size;
    PuzzleGame* game = nullptr;

    while (true) {
        std::cout << "메뉴:\n";
        std::cout << "1. 게임 저장\n";
        std::cout << "2. 게임 불러오기\n";
        std::cout << "3. 리플레이\n";
        std::cout << "4. 새 게임 시작\n";
        std::cout << "원하는 번호를 입력하세요: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "저장할 파일 이름을 입력하세요: ";
                std::string filename;
                std::cin >> filename;
                if (game) game->saveGame(filename);  // 게임 저장
                break;
            }
            case 2: {
                std::cout << "불러올 파일 이름을 입력하세요: ";
                std::string filename;
                std::cin >> filename;
                game = new PuzzleGame(4);  // 기본 4x4 퍼즐 게임 설정
                game->loadGame(filename);  // 게임 불러오기
                game->start();
                break;
            }
            case 3:
                if (game) game->replay();  // 리플레이
                break;
            case 4:
                std::cout << "퍼즐 크기를 입력하세요 (3, 4, 5 중 하나): ";
                std::cin >> size;
                game = new PuzzleGame(size);  // 선택된 크기로 퍼즐 생성
                game->start();
                break;
            default:
                std::cout << "잘못된 선택입니다!" << std::endl;
        }
    }

    return 0;
}

