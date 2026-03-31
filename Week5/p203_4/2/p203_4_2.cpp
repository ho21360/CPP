#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int SIZE = 5;
vector<vector<int>> board;
vector<char> moveHistory; // (2) 리플레이를 위해 이동 경로를 기록할 벡터
int emptyX, emptyY;       // 빈 공간(0)의 위치 저장

// 맵 초기화 함수
void initBoard(int s) {
    SIZE = s;
    board.assign(SIZE, vector<int>(SIZE));
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (num < SIZE * SIZE) board[i][j] = num++;
            else {
                board[i][j] = 0;
                emptyX = i; emptyY = j; // 빈 공간 위치 저장
            }
        }
    }
    // 간단하게 몇 번 섞기 (원래는 더 복잡하게 섞어야 함)
    srand(time(NULL));
    for(int i=0; i<100; i++) {
        int r = rand() % 4;
        // 섞는 로직은 생략 (일단 정렬된 상태에서 테스트)
    }
}

// 맵 출력 함수
void printBoard() {
    cout << "\n--- Puzzle Game (" << SIZE << "x" << SIZE << ") ---\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) cout << "   ";
            else printf("%2d ", board[i][j]);
        }
        cout << endl;
    }
}

// (2) 조각 이동 함수
bool moveTile(char direction) {
    int targetX = emptyX;
    int targetY = emptyY;

    if (direction == 'w') targetX++; // 아래에 있는걸 위로 올림
    else if (direction == 's') targetX--; 
    else if (direction == 'a') targetY++;
    else if (direction == 'd') targetY--;
    else return false;

    if (targetX >= 0 && targetX < SIZE && targetY >= 0 && targetY < SIZE) {
        swap(board[emptyX][emptyY], board[targetX][targetY]);
        emptyX = targetX;
        emptyY = targetY;
        moveHistory.push_back(direction); // (2) 이동 경로 기록
        return true;
    }
    return false;
}

int main() {
    int choice;
    cout << "퍼즐 크기 선택 (3 or 5): ";
    cin >> choice;
    initBoard(choice);

    char input;
    while (true) {
        printBoard();
        cout << "이동 (w,a,s,d) / 리플레이(r) / 종료(q): ";
        cin >> input;

        if (input == 'q') break;
        if (input == 'r') {
            cout << "\n--- [REPLAY START] ---\n";
            for (char m : moveHistory) cout << m << " ";
            cout << "\n--- [REPLAY END] ---\n";
            continue;
        }
        
        if (!moveTile(input)) {
            cout << "이동할 수 없습니다!\n";
        }
    }

    return 0;
}