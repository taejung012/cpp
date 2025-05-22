#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cout << "10000 미만의 정수를 입력하세요: ";
    cin >> num;
    
    if (num < 0 || num >= 100000) {
        cout << "잘못된 입력입니다. 10000 미만의 정수를 입력하세요." << endl;
        return 0;
    }
    
    vector<string> units = {"", "십", "백", "천", "만", "십", "백", "천"};
    vector<string> numbers = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    string result = "";
    int place = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit > 0) {
            result = numbers[digit] + units[place] + " " + result;
        }
        num /= 10;
        place++;
    }
    
    cout << "출력: " << result << endl;
    return 0;
}

