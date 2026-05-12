#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char *name;
    static int count; // (1) 정적 변수: 개수 관리

public:
    // (2) 생성자: this와 new를 이용한 초기화
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // (3) 소멸자: 메모리 해제 및 개수 감소
    ~Sample() {
        if (name != NULL) delete[] name;
        count--;
    }

    // (4) 복사 생성자: 다른 객체(rhs)의 내용을 깊은 복사
    Sample(const Sample& rhs) {
        this->name = new char[strlen(rhs.name) + 1];
        strcpy(this->name, rhs.name);
        count++;
    }

    // (1) 정적 함수: 개수 출력
    static void printCount() {
        cout << "현재 개수: " << count << endl;
    }
};

// 정적 변수 초기화
int Sample::count = 0;

int main() {
    Sample a("sample1"); 
    Sample::printCount(); 

    Sample b(a);          
    Sample::printCount(); 

    return 0;
}