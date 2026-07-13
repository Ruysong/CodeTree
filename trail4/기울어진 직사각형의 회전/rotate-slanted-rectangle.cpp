#include <iostream>
using namespace std;

int n;
int grid[21][21];
int px[100];
int py[100]; // 직사각형 저장할 선형 배

int x, y;
int move_num[4];
int dir;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int InRange(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

void Shift(int x, int y, int dir) {
        
    int cnt = 0;

    int cx = x;
    int cy = y;

    px[cnt] = cx;
    py[cnt] = cy;
    cnt++;

    for(int d = 0; d < 4; d++) {
        for(int k = 0; k < move_num[d]; k++) {
            cx += dx[d];
            cy += dy[d];

            px[cnt] = cx;
            py[cnt] = cy;
            cnt++;
        }
    }

    // 마지막 좌표는 다시 시작점으로 돌아온 중복 좌표라 제거
    cnt--;

    if(dir == 1) {
        // 시계 방향으로 한 칸 shift
        int temp = grid[px[0]][py[0]];

        for(int i = 0; i < cnt - 1; i++) {
            grid[px[i]][py[i]] = grid[px[i + 1]][py[i + 1]];
        }

        grid[px[cnt - 1]][py[cnt - 1]] = temp;
    }
    else {
        // 반시계 방향으로 한 칸 shift
        int temp = grid[px[cnt - 1]][py[cnt - 1]];

        for(int i = cnt - 1; i >= 1; i--) {
            grid[px[i]][py[i]] = grid[px[i - 1]][py[i - 1]];
        }

        grid[px[0]][py[0]] = temp;
    }
}


int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >>x >> y;
    x--;
    y--;

    for(int i = 0; i < 4; i++) {
        cin >> move_num[i];
    }

    cin >> dir;

    Shift(x,y,dir);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}