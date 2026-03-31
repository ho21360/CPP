#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// (1) 실제로 0과 1을 채우는 기능
void randomMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 각 칸에 0 또는 1을 랜덤하게 넣음
        }
    }
}

int main() {
    // 5행 5열 바둑판 만들기 (딱 붙여서 쓰기!)
    int map[5][5]; 

    // 랜덤 숫자 섞기
    srand((unsigned int)time(NULL));

    // 바둑판에 숫자 채우기 실행
    randomMap(map);

    cout << "(1)번 문제 완료: 5x5 배열에 랜덤 값이 채워졌습니다!" << endl;

    return 0;
}