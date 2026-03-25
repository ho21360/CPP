#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n, bullet, people;

    cout << "탄창 크기(n): ";
    cin >> n;

    cout << "총알 개수: ";
    cin >> bullet;

    cout << "참가자 수: ";
    cin >> people;

    // 탄창 생성
    vector<int> gun(n, 0);

    // 랜덤 초기화
    srand(time(0));

    // 총알 배치
    int count = 0;
    while (count < bullet) {
        int pos = rand() % n;
        if (gun[pos] == 0) {
            gun[pos] = 1;
            count++;
        }
    }

    int idx = 0;       // 탄창 위치
    int person = 0;    // 사람 순서
    int dead = 0;      // 맞은 사람 수

    cout << "\n게임 시작!\n";

    while (dead < bullet) {
        cout << person + 1 << "번 사람 차례: ";

        if (gun[idx] == 1) {
            cout << "탕! 맞았습니다!\n";
            gun[idx] = 0;
            dead++;
        } else {
            cout << "살았습니다.\n";
        }

        // 다음으로 이동
        idx = (idx + 1) % n;
        person = (person + 1) % people;
    }

    cout << "\n게임 종료!\n";

    return 0;
}
