#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int map[5][5];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == map[i][0]) count++;
        }
        if (count == 5) cout << "가로 " << i + 1 << "행 성공" << endl;
    }

    for (int j = 0; j < 5; j++) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (map[i][j] == map[0][j]) count++;
        }
        if (count == 5) cout << "세로 " << j + 1 << "열 성공" << endl;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < 5; i++) {
        if (map[i][i] == map[0][0]) d1++;
        if (map[i][4 - i] == map[0][4]) d2++;
    }

    if (d1 == 5) cout << "왼쪽 대각선 성공" << endl;
    if (d2 == 5) cout << "오른쪽 대각선 성공" << endl;

    return 0;
}