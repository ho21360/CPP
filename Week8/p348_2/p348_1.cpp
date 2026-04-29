#include <iostream>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    // 1번 문제 생성자
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), msec(ms) { }

    // 2번 문제 생성자 (함수 중복)
    MyTime(double duration) {
        int total = (int)duration; 
        
        hour = total / 3600;
        min = (total % 3600) / 60;
        sec = total % 60;
        msec = (int)((duration - total) * 1000);
    }

    void print() {
        cout << hour << ":" << min << ":" << sec << "." << msec << endl;
    }
};

int main() {
    // 실수(double)를 넣으면 2번 생성자가 실행됨
    MyTime t1(3661.5); 
    t1.print();

    return 0;
}