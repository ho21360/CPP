#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 최대 80x40 정적 배열 및 변수 선언
static int MineMapMask[40][80];  
static int MineMapLabel[40][80];
static int nx, ny, nBomb;

// 지뢰 개수 입력 및 무작위 매설
void init() {
    printf("Map Size (Width Height) & Mines: ");
    scanf("%d %d %d", &nx, &ny, &nBomb);

    if (nx > 80) nx = 80; if (ny > 40) ny = 40;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < nBomb; ) {
        int rx = rand() % nx, ry = rand() % ny;
        if (MineMapLabel[ry][rx] == 0) {
            MineMapLabel[ry][rx] = 9; i++;
        }
    }

    // 주변 지뢰 개수 계산 로직
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (MineMapLabel[y][x] == 9) continue;
            int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int ny_i = y + dy, nx_i = x + dx;
                    if (ny_i >= 0 && ny_i < ny && nx_i >= 0 && nx_i < nx)
                        if (MineMapLabel[ny_i][nx_i] == 9) count++;
                }
            }
            MineMapLabel[y][x] = count;
        }
    }
}

// 가로/세로 숫자 좌표 출력
void print() {
    system("clear"); 
    printf("   ");
    for (int x = 0; x < nx; x++) printf("%2d", x % 100);
    printf("\n");

    for (int y = 0; y < ny; y++) {
        printf("%2d ", y % 100);
        for (int x = 0; x < nx; x++) {
            if (MineMapMask[y][x] == 0) printf(" ㅁ");
            else if (MineMapMask[y][x] == 2) printf("  P");
            else {
                if (MineMapLabel[y][x] == 9) printf(" ※");
                else printf("%2d", MineMapLabel[y][x]);
            }
        }
        printf("\n");
    }
}

// 명령어 처리 입력 함수
int getPos(int *px, int *py) {
    char ch;
    printf("\n입력 (예: 5 10 또는 p 5 10): ");
    scanf(" %c", &ch);

    if (ch == 'p' || ch == 'P') {
        scanf("%d %d", py, px);
        return 2; // 깃발 모드
    } else {
        ungetc(ch, stdin);
        scanf("%d %d", py, px);
        return 1; // 오픈 모드
    }
}

int main() {
    init();
    while (1) {
        print();
        int x, y;
        int mode = getPos(&x, &y);

        if (x < 0 || x >= nx || y < 0 || y >= ny) continue;

        if (mode == 2) MineMapMask[y][x] = 2; // 깃발 꽂기
        else {
            MineMapMask[y][x] = 1; // 땅 파기
            if (MineMapLabel[y][x] == 9) { // 지뢰 밟음
                print();
                printf("\nGAME OVER!\n");
                break;
            }
        }
    }
    return 0;
}
