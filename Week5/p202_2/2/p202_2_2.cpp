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
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}