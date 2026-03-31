
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int SIZE = 3;
vector<vector<int>> board = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// (3) 저장하기
void saveGame() {
    ofstream out("save.txt");
    out << SIZE << endl; // 1. 크기 저장
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) out << board[i][j] << " "; // 2. 숫자 저장
        out << endl;
    }
    out.close();
    cout << "저장 완료!" << endl;
}

// (4) 불러오기
void loadGame() {
    ifstream in("save.txt");
    if (!in.is_open()) {
        cout << "파일이 없습니다!" << endl;
        return;
    }
    in >> SIZE; // 1. 크기 읽기
    board.assign(SIZE, vector<int>(SIZE)); // 2. 판 맞추기
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) in >> board[i][j]; // 3. 숫자 채우기
    }
    in.close();
    cout << "불러오기 완료!" << endl;
}

int main() {
    char input;
    cout << "저장(s), 불러오기(l), 종료(q): ";
    
    while (cin >> input && input != 'q') {
        if (input == 's') saveGame();
        else if (input == 'l') {
            loadGame();
            // 불러온 결과 출력
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) cout << board[i][j] << " ";
                cout << endl;
            }
        }
        cout << "\n다음 명령: ";
    }
    return 0;
}