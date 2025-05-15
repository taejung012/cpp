// main.cpp
#include "Shape.h"

int main() {
    // ▶ Rectangle 객체 생성
    // ▶ Point 클래스에서 상속받은 생성자도 함께 호출됨
    Rectangle r(2, 3, 100, 200);

    // ▶ 재정의된 draw() 호출
    // ▶ Rectangle의 오버라이딩된 함수가 실행됨
    r.draw();

    return 0;
}
