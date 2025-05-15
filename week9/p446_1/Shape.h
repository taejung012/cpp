// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

//  기반 클래스(Base class) 또는 부모 클래스(Parent class)
class Point {
protected:  // ▶ protected: 자식 클래스에서 접근 가능 (PPT '상속과 접근 지정자' 참고)
    int x, y;  // ▶ 점의 위치 (좌표)

public:
    // ▶ 생성자: 객체 생성 시 좌표를 초기화함
    // ▶ 초기화 리스트 사용 
    Point(int xx, int yy);

    // ▶ 점을 그리는 함수
    void draw();
};

//  파생 클래스(Derived class) 또는 자식 클래스(Child class)
// ▶ Rectangle is-a Point → 상속의 "is-a" 관계 (PPT 참고)
class Rectangle : public Point {
    // ▶ 사각형의 가로, 세로 길이
    int width, height;

public:
    // ▶ 생성자: 부모 클래스인 Point의 생성자를 호출하고,
    //    사각형의 고유 멤버도 초기화함
    Rectangle(int xx, int yy, int w, int h);

    // ▶ draw() 함수 오버라이딩 (PPT의 함수 재정의, overriding)
    //    - 부모 클래스의 draw()를 같은 이름으로 다시 정의함
    void draw();
};

#endif
