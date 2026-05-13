#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define DIM 20

// [도구] 화면을 그리는 클래스
class Canvas {
    char screen[DIM][DIM];
public:
    void clear() {
        for (int i = 0; i < DIM; i++)
            for (int j = 0; j < DIM; j++) screen[i][j] = '.'; 
    }
    void draw(int x, int y, string icon) {
        if (x >= 0 && x < DIM && y >= 0 && y < DIM) screen[y][x] = icon[0];
    }
    void print() {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) cout << screen[i][j] << " ";
            cout << endl;
        }
    }
};

// [클래스] 몬스터 속성 및 동작
class Monster {
    string name, icon;
    int x, y, nEnergy;
    static int nMon; // (4) 정적 멤버 변수: 전체 몬스터 수

public:
    Monster(string n, string i, int px, int py) : name(n), icon(i), x(px), y(py), nEnergy(100) {
        nMon++; // 생성 시 수 증가
    }
    ~Monster() { nMon--; } // 소멸 시 수 감소

    int getEnergy() { return nEnergy; }
    static int getCount() { return nMon; }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[DIM][DIM], int& totalItems) {
        int dir = rand() % 8;
        switch (dir) {
            case 0: y--; break; case 1: x++; y--; break;
            case 2: x++; break; case 3: x++; y++; break;
            case 4: y++; break; case 5: x--; y++; break;
            case 6: x--; break; case 7: x--; y--; break;
        }

        // 경계 처리
        if (x < 0) x = 0; if (x >= DIM) x = DIM - 1;
        if (y < 0) y = 0; if (y >= DIM) y = DIM - 1;

        // 아이템 체크
        if (map[y][x] == 1) { 
            map[y][x] = 0; 
            nEnergy += 8; 
            totalItems--; // (핵심) 전체 아이템 수 감소
        } else { 
            nEnergy -= 1; 
            if (nEnergy < 0) nEnergy = 0; 
        }
    }

    void print() {
        cout << "\t" << name << icon << " : " << nEnergy << endl;
    }
};

int Monster::nMon = 0; // 정적 변수 초기화

// [함수] 굶어 죽은 몬스터를 배열에서 제거하는 로직 (3)
void checkStarvation(Monster* pMon[], int& nMon) {
    for (int i = 0; i < nMon; ) {
        if (pMon[i]->getEnergy() <= 0) {
            cout << "Monster 하나가 굶어 죽습니다" << endl;
            delete pMon[i]; // 메모리 해제
            pMon[i] = pMon[nMon - 1]; // 마지막 요소를 빈칸으로 이동
            nMon--; // 마릿수 감소 (정적 변수와는 별도로 배열 관리용)
        } else {
            i++;
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));
    Canvas canvas;
    int map[DIM][DIM] = {0};
    int totalItems = 20; 
    int nMove = 0;      // 전체 이동 횟수
    int nMon = 4;       // 배열 관리용 마릿수

    // 맵에 아이템 배치
    for(int i=0; i<totalItems; i++) map[rand()%DIM][rand()%DIM] = 1;

    // 몬스터 동적 생성 (포인터 배열 사용)
    Monster* pMon[10];
    pMon[0] = new Monster("몬스터", "※", 5, 5);
    pMon[1] = new Monster("도깨비", "§", 15, 15);
    pMon[2] = new Monster("별그대", "★", 10, 5);
    pMon[3] = new Monster("고스트", "♥", 5, 15);

    while (nMon > 0) { // 살아있는 몬스터가 있을 때까지
        system("clear");
        
        // 1. 상단 정보 출력
        cout << "[ Monster World (Dynamic World) ]" << endl;
        cout << " 전체 이동 횟수 = " << nMove << endl;
        cout << " 남은 아이템 수 = " << totalItems << endl;

        canvas.clear();
        for (int i = 0; i < nMon; i++) {
            pMon[i]->move(map, totalItems);
            pMon[i]->draw(canvas);
        }

        // 2. 맵 출력
        canvas.print();

        // 3. 하단 상태 출력
        for (int i = 0; i < nMon; i++) pMon[i]->print();
        cout << "전체 몬스터의 수 : [" << Monster::getCount() << "]" << endl;

        // 4. 아사 체크
        checkStarvation(pMon, nMon);

        nMove++;
        cout << "엔터를 누르세요...";
        cin.get();
        
        if (totalItems <= 0) break; // 아이템 다 먹어도 종료
    }

    cout << "\n게임이 종료되었습니다." << endl;
    
    // 남은 메모리 정리
    for (int i = 0; i < nMon; i++) delete pMon[i];

    return 0;
}