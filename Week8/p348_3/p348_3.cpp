#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#define DIM 40

// 화면을 그려주는 클래스
class Canvas {
    char screen[DIM][DIM];
public:
    Canvas() { clear(); }
    void clear() {
        for (int i = 0; i < DIM; i++)
            for (int j = 0; j < DIM; j++) screen[i][j] = '.'; 
    }
    void draw(int x, int y, string icon) {
        if (x >= 0 && x < DIM && y >= 0 && y < DIM) screen[y][x] = icon[0];
    }
    void print() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) cout << screen[i][j] << " ";
            cout << endl;
        }
    }
};

class Monster {
    string name, icon;
    int x, y, nItem;
    int nEnergy; // 1. 에너지 속성 추가

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0; if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0; if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) { 
            map[y][x] = 0;
            nItem++;
            nEnergy += 8; // 3.1 아이템 획득 시 에너지 +8
        } else {
            nEnergy -= 1; // 3.2 이동 시 에너지 -1
            if (nEnergy < 0) nEnergy = 0;
        }
    }

public:
    // 2. 초기화 리스트로 에너지 100 설정
    Monster(string n, string i, int px, int py)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[DIM][DIM], int maxx, int maxy) {
        int dir = rand() % 8;
        switch (dir) {
            case 0: y--; break; case 1: x++; y--; break;
            case 2: x++; break; case 3: x++; y++; break;
            case 4: y++; break; case 5: x--; y++; break;
            case 6: x--; break; case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    void print() { // 4. 에너지 출력 포함
        cout << "\t" << name << icon << " : " << nItem << "  E:" << nEnergy << endl;
    }
};

int main() {
    srand((unsigned int)time(NULL));
    Canvas canvas;
    int map[DIM][DIM] = {0};

    for(int i=0; i<30; i++) map[rand()%20][rand()%20] = 1;

    Monster m1("몬스터", "※", 5, 5);
    Monster m2("도깨비", "§", 10, 10);
    Monster m3("별그대", "★", 15, 5);

    for (int i = 0; i < 20; i++) {
        system("clear"); 
        canvas.clear();
        
        m1.move(map, 20, 20); m1.draw(canvas);
        m2.move(map, 20, 20); m2.draw(canvas);
        m3.move(map, 20, 20); m3.draw(canvas);

        cout << "[ Monster World ]" << endl;
        canvas.print();
        m1.print();
        m2.print();
        m3.print();
        
        cout << "엔터를 누르면 다음 단계로 이동합니다...";
        cin.get(); 
    }

    return 0;
}
