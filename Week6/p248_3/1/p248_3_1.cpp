#include <iostream>
using namespace std;

struct MyTime {
    int hour, min, sec;
};

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime t;
    int total = (t1.hour + t2.hour) * 3600 + (t1.min + t2.min) * 60 + (t1.sec + t2.sec);
    t.hour = total / 3600;
    t.min = (total % 3600) / 60;
    t.sec = total % 60;
    return t;
}

int main() {
    MyTime t1 = {1, 50, 40}, t2 = {2, 20, 30};
    MyTime r;

    r = addTime(t1, t2);
    cout << "방법1 결과: " << r.hour << ":" << r.min << ":" << r.sec << endl;

    return 0;
}
