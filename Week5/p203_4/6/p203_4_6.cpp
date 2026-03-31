#include <iostream>
#include <algorithm>

using namespace std;

int rankings[5] = {10, 20, 30, 40, 50}; // 현재 1~5위 기록 (작을수록 고수)

void updateRanking(int newScore) {
    // 1. 새로운 점수가 5위(마지막 칸)보다 낮을 때만 진입
    if (newScore < rankings[4]) {
        rankings[4] = newScore; // 5위를 내 기록으로 교체
        sort(rankings, rankings + 5); // 다시 1~5위 순서대로 정렬
    }
}

void printRanking() {
    cout << "--- 랭킹 TOP 5 ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "위: " << rankings[i] << "회" << endl;
    }
}

int main() {
    int myScore = 15; 
    
    updateRanking(myScore);
    printRanking();

    return 0;
}