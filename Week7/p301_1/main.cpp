#include <iostream>
#include <iomanip>

using namespace std;

class MyTime {
private:
    int hour, min, sec, msec;

public:
    MyTime() : hour(0), min(0), sec(0), msec(0) {}

    void convert(double duration) {
        long long total_msec = (long long)(duration * 1000);
        msec = total_msec % 1000;
        long long total_sec = total_msec / 1000;
        sec = total_sec % 60;
        min = (total_sec / 60) % 60;
        hour = (int)(total_sec / 3600);
    }

    void print() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << ":"
             << setw(3) << msec << endl;
    }

    MyTime add(const MyTime& t) {
        MyTime res;
        int carry;
        res.msec = msec + t.msec;
        carry = res.msec / 1000; res.msec %= 1000;
        res.sec = sec + t.sec + carry;
        carry = res.sec / 60; res.sec %= 60;
        res.min = min + t.min + carry;
        carry = res.min / 60; res.min %= 60;
        res.hour = hour + t.hour + carry;
        return res;
    }

    void read() {
        cout << "시간 입력 (시 분 초 밀리초): ";
        cin >> hour >> min >> sec >> msec;
    }
};

int main() {
    MyTime t1, t2, t3;

    // 1. 125.456초 변환 테스트
    t1.convert(125.456);
    cout << "t1 변환 결과 : ";
    t1.print();

    // 2. 사용자 입력 테스트
    t2.read();
    cout << "입력된 t2 : ";
    t2.print();

    // 3. 합계 테스트
    t3 = t1.add(t2);
    cout << "t1 + t2 합계 : ";
    t3.print();

    return 0;
}