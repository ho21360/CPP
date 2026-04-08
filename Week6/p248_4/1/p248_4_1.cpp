#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  최대 80x40 정적 배열 선언
static int MineMapMask[40][80];  
static int MineMapLabel[40][80]; 
static int nx, ny, nBomb;

void init() {
    printf("Map Size (Width Height) & Mines: ");
    scanf("%d %d %d", &nx, &ny, &nBomb);

    // 배열 범위 초과 방지
    if (nx > 80) nx = 80; 
    if (ny > 40) ny = 40;

    // 입력받은 크기만큼 0으로 초기화
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            MineMapMask[y][x] = 0;
            MineMapLabel[y][x] = 0;
        }
    }
    printf("Initialization Complete: %d x %d map\n", nx, ny);
}

int main() {
    init();
    return 0;
}