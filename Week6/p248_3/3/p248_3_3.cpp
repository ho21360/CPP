#include <iostream>
using namespace std;

struct MyTime {
    int hour, min, sec;
};

void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    int total = (t1.hour + t2.hour) * 3600 + (t1.min + t2.min) * 60 + (t1.sec + t2.sec);
    pt->hour = total / 3600;
    pt->min = (total % 3600) / 60;
    pt->sec = total % 60;
}

int main() {
    MyTime t1 = {1, 50, 40}, t2 = {2, 20, 30}, r;

    addTime(t1, t2, &r); // &r을 써서 변수의 주소를 전달함
    cout << "방법3 결과: " << r.hour << ":" << r.min << ":" << r.sec << endl;

    return 0;
}