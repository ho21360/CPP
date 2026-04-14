#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

// 초기화
MyTime::MyTime() : hour(0), min(0), sec(0), msec(0) {}

// 초 -> 시:분:초:밀리초 변환
void MyTime::convert(double duration) {
    long long total_msec = (long long)(duration * 1000);
    msec = total_msec % 1000;
    long long total_sec = total_msec / 1000;
    sec = total_sec % 60;
    min = (total_sec / 60) % 60;
    hour = (int)(total_sec / 3600);
}

// 출력 (setfill, setw 사용)
void MyTime::print() {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << ":"
         << setw(3) << msec << endl;
}

// 두 시간 더하기
MyTime MyTime::add(MyTime t) {
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

void MyTime::reset() { hour = min = sec = msec = 0; }
void MyTime::read() {
    cout << "시간 입력 (시 분 초 밀리초): ";
    cin >> hour >> min >> sec >> msec;
}