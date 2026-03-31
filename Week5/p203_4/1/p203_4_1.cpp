#include <iostream>
#include <vector>

using namespace std;

int SIZE;
vector<vector<int>> board;

void initBoard(int s) {
    SIZE = s;
    board.assign(SIZE, vector<int>(SIZE));
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (num < SIZE * SIZE) board[i][j] = num++;
            else board[i][j] = 0;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) printf("   ");
            else printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("3 or 5? ");
    scanf("%d", &choice);

    initBoard(choice);
    printBoard();

    return 0;
}