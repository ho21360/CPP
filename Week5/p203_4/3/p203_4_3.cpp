
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int SIZE = 3; 
vector<vector<int>> board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

void saveGame() {
    ofstream out("save.txt");
    out << SIZE << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << board[i][j] << " ";
        }
        out << endl;
    }
    out.close();
    cout << "저장되었습니다! (save.txt 확인)" << endl;
}

int main() {
    char input;
    cout << "현재 3x3 판을 저장하려면 's'를 누르세요: ";
    cin >> input;

    if (input == 's') {
        saveGame();
    }

    return 0;
}