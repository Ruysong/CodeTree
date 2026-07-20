#include <iostream>
using namespace std;

int n;
int r, c;
char grid[101][101];

bool visited[101][101][4];

// 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool WallExist(int x, int y) {
    return InRange(x, y) && grid[x][y] == '#';
}

int main() {
    cin >> n;
    cin >> r >> c;

    r--;
    c--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int dir_num = 1;  // 처음에는 오른쪽을 바라봄
    int t = 0;

    while (InRange(r, c)) {
        // 같은 위치에서 같은 방향을 다시 바라보면 무한 반복
        if (visited[r][c][dir_num]) {
            cout << -1 << '\n';
            return 0;
        }

        visited[r][c][dir_num] = true;

        // 현재 바라보는 방향의 앞칸
        int nx = r + dx[dir_num];
        int ny = c + dy[dir_num];

        // 앞에 벽이 있으면 반시계 방향으로 회전
        if (WallExist(nx, ny)) {
            dir_num = (dir_num + 3) % 4;
        }

        // 앞칸이 격자 밖이면 한 칸 이동하여 탈출
        else if (!InRange(nx, ny)) {
            r = nx;
            c = ny;
            t++;
        }

        // 앞칸이 격자 안의 빈칸인 경우
        else {
            // 앞으로 이동했다고 가정한 위치의 오른쪽 칸
            int right_dir = (dir_num + 1) % 4;

            int rx = nx + dx[right_dir];
            int ry = ny + dy[right_dir];

            // 오른쪽에 벽이 있으면 앞으로 한 칸 이동
            if (WallExist(rx, ry)) {
                r = nx;
                c = ny;
                t++;
            }

            // 오른쪽에 벽이 없으면 앞으로 한 칸,
            // 오른쪽으로 한 칸 이동하고 방향도 오른쪽으로 변경
            else {
                r = rx;
                c = ry;
                dir_num = right_dir;
                t += 2;
            }
        }
    }

    cout << t << '\n';

    return 0;
}