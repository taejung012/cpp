#include <iostream>
using namespace std;

// Sample1 클래스 정의
class Sample1 {
public:
    virtual void play() { cout << "1번 sample" << endl; }
};

// Sample2 클래스 정의 (Sample1 상속)
class Sample2 : public Sample1 {
public:
    void play() override { cout << "2번 sample" << endl; }
};

// Sample3 → Sample2 상속 (가능하게 만들기 위해 변경)
class Sample3 : public Sample2 {
public:
    void play() override { cout << "3번 sample" << endl; }
};

// Sample4 → Sample2 상속 (가능하게 만들기 위해 변경)
class Sample4 : public Sample2 {
public:
    void play() override { cout << "4번 sample" << endl; }
};

int main() {
    Sample2* arr[4]; // 배열 타입을 Sample2* 로 제한

    // 모두 Sample2이거나 Sample2에서 파생된 객체
    Sample2* a = new Sample2();
    Sample3* b = new Sample3();
    Sample4* c = new Sample4();
    Sample2* d = new Sample2(); // 하나 더

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    for (int i = 0; i < 4; i++)
        arr[i]->play(); // virtual 이므로 동적 바인딩됨

    return 0;
}
