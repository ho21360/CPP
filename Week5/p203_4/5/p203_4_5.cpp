#include <iostream>
#include <vector>

using namespace std;

int SIZE = 3;
vector<vector<int>> board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// 숫자 1을 'A'로 변환하는 핵심 로직
char getChar(int val) {
    if (val == 0) return ' '; // 빈칸 처리
    return (char)(val + 64);  // 1 + 64 = 65('A')
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "[" << getChar(board[i][j]) << "] ";
        }
        cout << endl;
    }
}

int main() {
    printBoard();
    return 0;
}