#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  최대 80x40 정적 배열 선언
static int MineMapMask[40][80];  
static int MineMapLabel[40][80]; 
static int nx, ny, nBomb;

void init() {
    // 크기와 지뢰 개수 입력 및 무작위 매설
    printf("Map Size(W H) & Mines: ");
    scanf("%d %d %d", &nx, &ny, &nBomb);

    // 맵 초기화 및 지뢰 매설
    srand((unsigned int)time(NULL));
    for (int i = 0; i < nBomb; ) {
        int rx = rand() % nx, ry = rand() % ny;
        if (MineMapLabel[ry][rx] == 0) {
            MineMapLabel[ry][rx] = 9; // 지뢰 설치
            i++;
        }
    }
    
    // 주변 지뢰 개수 계산 
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (MineMapLabel[y][x] == 9) continue;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int ny_idx = y + dy, nx_idx = x + dx;
                    if (ny_idx >= 0 && ny_idx < ny && nx_idx >= 0 && nx_idx < nx)
                        if (MineMapLabel[ny_idx][nx_idx] == 9) MineMapLabel[y][x]++;
                }
            }
        }
    }
}

void print() {
    // 가로/세로 숫자 좌표 출력
    printf("\n    "); // 첫 줄 열 번호
    for (int x = 0; x < nx; x++) printf("%2d", x);
    printf("\n");

    for (int y = 0; y < ny; y++) {
        printf("%2d ", y); // 행 번호
        for (int x = 0; x < nx; x++) {
            if (MineMapLabel[y][x] == 9) printf(" *"); 
            else printf("%2d", MineMapLabel[y][x]);
        }
        printf("\n");
    }
}

int main() {
    init();
    print();
    return 0;
}
