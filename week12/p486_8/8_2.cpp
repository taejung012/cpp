#include <iostream>
using namespace std;

// Sample1 클래스: 부모 클래스, play()를 가상 함수로 선언
class Sample1 {
public:
    Sample1() {}
    virtual void play() { // virtual 선언
        cout << "1번 sample" << endl;
    }
};

// Sample2 클래스: Sample1을 상속받고 play()를 오버라이딩
class Sample2 : public Sample1 {
public:
    Sample2() {}
    void play() override {
        cout << "2번 sample" << endl;
    }
};

// Sample3 클래스: Sample1을 상속받고 play()를 오버라이딩
class Sample3 : public Sample1 {
public:
    Sample3() {}
    void play() override {
        cout << "3번 sample" << endl;
    }
};

// Sample4 클래스: Sample1을 상속받고 play()를 오버라이딩
class Sample4 : public Sample1 {
public:
    Sample4() {}
    void play() override {
        cout << "4번 sample" << endl;
    }
};

int main() {
    // Sample1 포인터 배열에 각각 다른 객체 저장
    Sample1* arr[4];

    Sample1* a = new Sample1();
    Sample2* b = new Sample2();
    Sample3* c = new Sample3();
    Sample4* d = new Sample4();

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    // play() 함수 호출 시 동적 바인딩에 의해 자식 함수가 실행됨
    for (int i = 0; i < 4; i++) {
        arr[i]->play();
    }

    // 메모리 해제
    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}
