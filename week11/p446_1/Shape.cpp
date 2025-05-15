// Shape.cpp
#include "Shape.h"

// ▶ Point 생성자 정의
// 초기화 리스트로 x, y 값 초기화
Point::Point(int xx, int yy) : x(xx), y(yy) {}

// ▶ Point의 기본 draw 함수
// PPT 예제처럼 좌표만 출력 (단순 점)
void Point::draw() {
    cout << x << " , " << y << " 에 점을 그려라.\n";
}

// ▶ Rectangle 생성자 정의
// ▶ 기반 클래스 Point의 생성자 호출 + 자체 멤버 초기화
Rectangle::Rectangle(int xx, int yy, int w, int h)
    : Point(xx, yy), width(w), height(h) {}

// ▶ Rectangle의 draw 함수
// ▶ 함수 오버라이딩(overriding) → 부모의 draw 대신 자신만의 방식 정의
void Rectangle::draw() {
    // 부모 클래스의 protected 멤버 x, y에 직접 접근 가능
 cout << x << " , " << y << " 에 가로 " << width << " 세로 " << height << "인 사각형을 그려라.\n";
}
