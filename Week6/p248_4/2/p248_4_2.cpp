#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 최대 80x40 크기의 정적 배열 선언
static int MineMapMask[40][80];  
static int MineMapLabel[40][80]; 
static int nx, ny, nBomb;        

void init() {
    //  맵 크기와 지뢰 개수 입력받기
    printf("Map Size (Width Height) & Mines: ");
    if (scanf("%d %d %d", &nx, &ny, &nBomb) != 3) return;

    // 배열 범위(80x40)를 초과하지 않도록 제한
    if (nx > 80) nx = 80;
    if (ny > 40) ny = 40;

    // 맵 초기화 (모든 칸을 0으로)
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            MineMapMask[y][x] = 0;
            MineMapLabel[y][x] = 0;
        }
    }


    //  지뢰 무작위 매설
    srand((unsigned int)time(NULL)); 
    for (int i = 0; i < nBomb; ) {
        int rx = rand() % nx;
        int ry = rand() % ny;

        if (MineMapLabel[ry][rx] == 0) { // 빈칸일 때만 매설
            MineMapLabel[ry][rx] = 9;    
            i++; 
        }
    }

    //  주변 8방향 지뢰 개수 계산
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (MineMapLabel[y][x] == 9) continue; // 지뢰는 계산 제외

            int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int ny_idx = y + dy;
                    int nx_idx = x + dx;

                    // 맵 범위 안쪽인지 확인 후 지뢰(9) 개수 카운트
                    if (ny_idx >= 0 && ny_idx < ny && nx_idx >= 0 && nx_idx < nx) {
                        if (MineMapLabel[ny_idx][nx_idx] == 9) count++;
                    }
                }
            }
            MineMapLabel[y][x] = count; 
        }
    }
    printf("Initialization Complete: %d x %d map, %d mines.\n", nx, ny, nBomb);
}

int main() {
    init();

    return 0;
}
