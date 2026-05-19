#include <iostream>

class Point {
protected:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) {}
    void draw() { std::cout << x << ", " << y << "에 점을 그리라.\n"; }
};

class Rectangle1 : public Point { // (1) 상속
private:
    int width, height;            // (1) 멤버 변수 추가

public:
    // (2) 초기화 리스트로 멤버 초기화
    Rectangle1(int xx, int yy, int w, int h) : Point(xx, yy), width(w), height(h) {}

    // (3) 함수 재정의
    void draw() {
        std::cout << "\"" << x << ", " << y << "에 가로 " << width 
                  << " 세로 " << height << "인 사각형을 그리라\"\n";
    }
};

int main() {
    Rectangle1 rect(2, 3, 100, 200);
    rect.draw(); // (3)번 예시 출력용
    return 0;
}