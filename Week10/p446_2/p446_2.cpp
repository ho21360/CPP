#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip> // 출력 정렬을 위해 추가

using namespace std;
#define DIM 20

class Canvas {
    string screen[DIM][DIM]; 
public:
    void clear() {
        for (int i = 0; i < DIM; i++)
            for (int j = 0; j < DIM; j++) screen[i][j] = ". "; 
    }
    void draw(int x, int y, string icon) {
        if (x >= 0 && x < DIM && y >= 0 && y < DIM) screen[y][x] = icon + " ";
    }
    void print() {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) cout << screen[i][j]; 
            cout << endl;
        }
    }
};

class Monster {
protected: 
    string name, icon;
    int x, y, nItem; 
public:
    Monster(string n, string i, int px, int py) : name(n), icon(i), x(px), y(py), nItem(0) {}
    virtual ~Monster() {}
    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
    
    void print() { 
        cout << left << setw(12) << name << " " << icon << " : " << nItem << endl; 
    }

    virtual void move(int map[DIM][DIM], int& totalItems) {
        int dir = rand() % 8;
        switch (dir) { case 0: y--; break; case 1: x++; y--; break; case 2: x++; break; case 3: x++; y++; break;
                       case 4: y++; break; case 5: x--; y++; break; case 6: x--; break; case 7: x--; y--; break; }
        if (x < 0) x = 0; if (x >= DIM) x = DIM - 1; if (y < 0) y = 0; if (y >= DIM) y = DIM - 1;
        if (map[y][x] == 1) { map[y][x] = 0; nItem++; totalItems--; }
    }
};

// 1. 스몹비
class Smombi : public Monster {
public:
    Smombi(string n, string i, int px, int py) : Monster(n, i, px, py) {}
    void move(int map[DIM][DIM], int& totalItems) override {
        x += (rand() % 2 == 0) ? 1 : -1;
        y += (rand() % 2 == 0) ? 1 : -1;
        if (x < 0) x = 0; if (x >= DIM) x = DIM - 1; if (y < 0) y = 0; if (y >= DIM) y = DIM - 1;
        if (map[y][x] == 1) { map[y][x] = 0; nItem++; totalItems--; }
    }
};

// 2. 슈퍼강시
class Siangshi : public Monster {
    int cnt = 0; bool hori = true;
public:
    Siangshi(string n, string i, int px, int py) : Monster(n, i, px, py) {}
    void move(int map[DIM][DIM], int& totalItems) override {
        if (++cnt % 4 == 0) hori = !hori;
        if (hori) x += (rand() % 2 == 0 ? 1 : -1);
        else y += (rand() % 2 == 0 ? 1 : -1);
        if (x < 0) x = 0; if (x >= DIM) x = DIM - 1; if (y < 0) y = 0; if (y >= DIM) y = DIM - 1;
        if (map[y][x] == 1) { map[y][x] = 0; nItem++; totalItems--; }
    }
};

// 3. 슬라임
class Slime : public Monster {
public:
    Slime(string n, string i, int px, int py) : Monster(n, i, px, py) {}
    void move(int map[DIM][DIM], int& totalItems) override {
        if (rand() % 5 != 0) Monster::move(map, totalItems);
    }
};

int main() {
    srand((unsigned int)time(NULL));
    Canvas canvas;
    int map[DIM][DIM] = {0}, totalItems = 128, nMove = 0; 
    for(int i = 0; i < totalItems; i++) {
        int rx = rand() % DIM, ry = rand() % DIM;
        if (map[ry][rx] == 0) map[ry][rx] = 1; else i--; 
    }

    // 4. 다형성 배열
    Monster* pMon[7] = {
        new Monster("허접좀비", "S", 5, 5), new Monster("뱀파이어", "*", 15, 15),
        new Monster("기본강시", "I", 10, 5), new Monster("처녀귀신", "H", 3, 12),
        new Smombi("스몹비", "§", 12, 12), new Siangshi("슈퍼강시", "↕", 8, 8),
        new Slime("슬라임", "M", 2, 2)
    };

    while (totalItems > 0) { 
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        // 상단 정보 출력
        cout << "[ Monster World (Inheritance) ]" << endl;
        cout << "전체 이동 횟수 = " << nMove << endl;
        cout << "남은 아이템 수 = " << totalItems << endl << endl;

        canvas.clear(); 
        for (int y = 0; y < DIM; y++)
            for (int x = 0; x < DIM; x++) if (map[y][x] == 1) canvas.draw(x, y, "■"); 

        for (int i = 0; i < 7; i++) { pMon[i]->move(map, totalItems); pMon[i]->draw(canvas); }
        canvas.print();

        // 하단 리스트 출력
        cout << endl;
        for (int i = 0; i < 7; i++) pMon[i]->print();
        
        cout << "\n엔터를 누르세요...";
        nMove++; cin.get();
    }
    
    cout << endl << "안녕히 가세요!!! 몬스터 월드 !!!" << endl;
    for (int i = 0; i < 7; i++) delete pMon[i];
    return 0;
}