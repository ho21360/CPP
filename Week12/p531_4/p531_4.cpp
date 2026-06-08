#include <iostream>
#include <cstdlib>

class SampleList {
    int list[100];
public:
    SampleList() {
        for(int x = 0; x < 100; x++) {
            list[x] = rand() % 1000;
        }
    }

    // (1) 인덱스 연산자 중복
    int& operator[](int index) {
        return list[index];
    }

    // (2) & (3) 함수 호출 연산자 중복 (두 수의 곱을 인덱스로 활용)
    int& operator()(int a, int b) {
        return list[a * b];
    }
};

int main() {
    SampleList s;
    int a, b;

    std::cout << "두 개의 숫자를 입력하세요 (0~9 사이): ";
    std::cin >> a >> b;

    // 입력받은 a, b의 곱(a*b)이 인덱스로 사용됨을 확인
    std::cout << "s(" << a << ", " << b << ")의 값 (list[" << a * b << "]): " << s(a, b) << std::endl;

    return 0;
}