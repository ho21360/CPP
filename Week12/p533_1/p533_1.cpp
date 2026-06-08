#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;
public:
    TimeHMS(int h=0, int m=0, int s=0) : hour(h), min(m), sec(s) {}

    // (1) + 연산자: 시간 합산 및 올림 처리
    TimeHMS operator+(const TimeHMS& t) {
        int s = sec + t.sec;
        int m = min + t.min + (s / 60);
        int h = hour + t.hour + (m / 60);
        return TimeHMS(h, m % 60, s % 60);
    }

    // (2) - 연산자: 시간 차이 및 내림 처리
    TimeHMS operator-(const TimeHMS& t) {
        int s = sec - t.sec;
        int m = min - t.min;
        int h = hour - t.hour;
        if (s < 0) { s += 60; m--; }
        if (m < 0) { m += 60; h--; }
        return TimeHMS(h, m, s);
    }

    // (3) ==, != 연산자
    bool operator==(const TimeHMS& t) { return (hour == t.hour && min == t.min && sec == t.sec); }
    bool operator!=(const TimeHMS& t) { return !(*this == t); }

    // (4) 전위 증감 (증가/감소 시 전체 시간 조정)
    TimeHMS& operator++() { min++; if (min >= 60) { hour++; min = 0; } return *this; }
    TimeHMS& operator--() { min--; if (min < 0) { hour--; min = 59; } return *this; }

    // (5) 후위 증감 (1초씩 증가/감소)
    TimeHMS operator++(int) { TimeHMS temp = *this; sec++; if (sec >= 60) { min++; sec = 0; } return temp; }
    TimeHMS operator--(int) { TimeHMS temp = *this; sec--; if (sec < 0) { min--; sec = 59; } return temp; }

    // (6) 인덱스 연산자
    int operator[](int i) { if (i == 0) return hour; if (i == 1) return min; return sec; }

    // (7) int 변환 (초 단위)
    operator int() { return hour * 3600 + min * 60 + sec; }

    // (8) double 변환 (시간 단위)
    operator double() { return hour + min / 60.0 + sec / 3600.0; }
};

// (9) 정수와 TimeHMS 객체 곱하기 (전역 함수로 구현)
TimeHMS operator*(int n, TimeHMS t) {
    int totalSec = (t.operator int()) * n;
    int h = totalSec / 3600;
    int m = (totalSec % 3600) / 60;
    int s = totalSec % 60;
    return TimeHMS(h, m, s);
}

int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;
    
    t3 = t1 + t2;
    cout << "t1+t2: " << t3[0] << "시 " << t3[1] << "분 " << t3[2] << "초" << endl;
    
    t3 = 2 * t1;
    cout << "2 * t1: " << t3[0] << "시 " << t3[1] << "분 " << t3[2] << "초" << endl;
    
    return 0;
}