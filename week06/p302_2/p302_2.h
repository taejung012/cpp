#ifndef MYDIC_H
#define MYDIC_H

#include <string>
using namespace std;

const int MAXWORDS = 100;

// (1) WordPair 구조체 정의 - 조건 (1): 영어 단어와 한글 설명을 위한 구조체, public 멤버
struct WordPair {
    string eng; // 영어 단어
    string kor; // 한글 설명
};

// (2) MyDic 클래스 선언 - 조건 (2): 단어장 클래스, 모든 멤버 함수 public
class MyDic {
    WordPair words[MAXWORDS];
    int nwords;
public:
    MyDic(); // 생성자
    void add(string eng, string kor); // 단어 추가 - 조건 (2): add 함수 선언
    void load(string filename); // 파일 로드 - 조건 (2): load 함수 선언
    void store(string filename); // 파일 저장 - 조건 (2): store 함수 선언
    void print(); // 단어장 출력 - 조건 (2): print 함수 선언
    int size(); // 현재 단어 수 반환 - 조건 (2): 추가 기능
};

#endif