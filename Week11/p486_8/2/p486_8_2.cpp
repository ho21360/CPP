#include <iostream>

using namespace std;

class Sample1 {
public:
    Sample1() {}
    // 1. virtual 키워드 추가 (가상 함수로 변경)
    virtual void play() { cout << "1번 sample" << endl; }
};

class Sample2 : public Sample1 {
public:
    Sample2() {}
    void play() { cout << "2번 sample" << endl; }
};

class Sample3 : public Sample1 {
public:
    Sample3() {}
    void play() { cout << "3번 sample" << endl; }
};

class Sample4 : public Sample1 { 
public:
    Sample4() {}
    void play() { cout << "4번 sample" << endl; }
};

int main() {
    Sample1* arr[4];

    Sample1* a = new Sample1();
    Sample2* b = new Sample2();
    Sample3* c = new Sample3();
    Sample4* d = new Sample4();

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    // 2. 가상 함수 효과로 인해 1번, 2번, 3번, 4번이 순서대로 출력됨
    for (int i = 0; i < 4; i++) {
        arr[i]->play();
    }

    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}