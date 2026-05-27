#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
#define DIM 20

class Canvas {
    string screen[DIM][DIM];
public:
    void clear() { for(int i=0; i<DIM; i++) for(int j=0; j<DIM; j++) screen[i][j] = ". "; }
    void draw(int x, int y, string icon) { if(x>=0 && x<DIM && y>=0 && y<DIM) screen[y][x] = icon; }
    void print() { for(int i=0; i<DIM; i++) { for(int j=0; j<DIM; j++) cout << screen[i][j]; cout << endl; } }
};

class Monster {
protected:
    string name, icon;
    int x, y, nItem;
public:
    Monster(string n, string i, int px, int py) : name(n), icon(i), x(px), y(py), nItem(0) {}
    virtual ~Monster() {}
    void draw(Canvas &c) { c.draw(x, y, icon); }
    void print() { cout << left << setw(12) << name << " " << icon << " : " << nItem << endl; }
    virtual void move(int map[DIM][DIM], int& totalItems) {
        int dir = rand() % 8;
        int dx[]={0,1,1,1,0,-1,-1,-1}, dy[]={-1,-1,0,1,1,1,0,-1};
        x += dx[dir]; y += dy[dir];
        if(x<0) x=0; if(x>=DIM) x=DIM-1; if(y<0) y=0; if(y>=DIM) y=DIM-1;
        if(map[y][x] == 1) { map[y][x] = 0; nItem++; totalItems--; }
    }
};

// [문제 3] Monster를 상속받은 Tuman 클래스 구현
class Tuman : public Monster {
public:
    Tuman(string n, string i, int px, int py) : Monster(n, i, px, py) {}
    
    // [문제 1] 조작키를 처리하는 moveHuman 함수 구현 (입력된 키에 따라 이동)
    void moveHuman(int map[DIM][DIM], int& totalItems, char ch) {
        if (ch == 'w') y--; else if (ch == 's') y++;
        else if (ch == 'a') x--; else if (ch == 'd') x++;
        if(x<0) x=0; if(x>=DIM) x=DIM-1; if(y<0) y=0; if(y>=DIM) y=DIM-1;
        if(map[y][x] == 1) { map[y][x] = 0; nItem++; totalItems--; }
    }
};

int main() {
    srand((unsigned int)time(NULL));
    Canvas canvas;
    int map[DIM][DIM] = {0}, totalItems = 60, totalMoves = 0;
    for(int i=0; i<totalItems; i++) map[rand()%DIM][rand()%DIM] = 1;

    // [문제 2] 각 몬스터 및 플레이어의 아이콘 문자열 지정
    // [문제 4] 몬스터 5개와 Tuman 객체 2개(좌, 우)를 생성하여 배열에 배치
    Monster* pMon[7] = {
        new Monster("허접좀비", "S ", 5, 5), new Monster("뱀파이어", "* ", 15, 15),
        new Monster("어쩌다귀신", "♥ ", 8, 8), new Monster("못먹어세로", "↔ ", 3, 12),
        new Monster("슬라임", "M ", 2, 2),
        new Tuman("미래의좌", "좌", 0, 0), new Tuman("미래의우", "우", 19, 19)
    };

    // [문제 5] 턴제 게임 로직 (사용자 입력 시 플레이어와 몬스터가 동시 이동)
    while (totalItems > 0) {
        system("clear");
        cout << "[ Monster World (신인류 탄생) ]" << endl;
        canvas.clear();
        for(int y=0; y<DIM; y++) for(int x=0; x<DIM; x++) if(map[y][x]) canvas.draw(x, y, "■");
        for(int i=0; i<7; i++) pMon[i]->draw(canvas);
        canvas.print();
        
        cout << "전체 이동 횟수 = " << totalMoves++ << endl;
        cout << "남은 아이템 수 = " << totalItems << endl;
        for(int i=0; i<7; i++) pMon[i]->print();

        cout << "이동할 키 입력(w,a,s,d): ";
        char ch;
        cin >> ch;
        
        ((Tuman*)pMon[5])->moveHuman(map, totalItems, ch);
        ((Tuman*)pMon[6])->moveHuman(map, totalItems, ch); 
        for(int i=0; i<5; i++) pMon[i]->move(map, totalItems);
    }
    cout << "게임 종료" << endl;
    for(int i=0; i<7; i++) delete pMon[i];
    return 0;
}