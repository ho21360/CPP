#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    // 멤버 초기화 리스트 사용 (매개변수 없으면 0으로 초기화)
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), msec(ms) { }

    void print() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << "."
             << setw(3) << msec << endl;
    }
};

int main() {
    MyTime t1;          // 0으로 초기화됨
    MyTime t2(1, 2, 3, 4); 
    
    t1.print();
    t2.print();
    return 0;
}