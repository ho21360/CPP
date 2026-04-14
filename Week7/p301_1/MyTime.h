#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour, min, sec, msec; // 모든 멤버 변수는 private

public:
    MyTime(); 
    void convert(double duration);
    void print();
    MyTime add(MyTime t); // 객체를 매개변수로 받는 함수
    void reset();
    void read(); // 사용자 입력을 받는 함수
};

#endif