#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int x, y;
int grid[101][101];

int head_x = 0, head_y = 0;
int elapsed_time = 0;

queue<int> snakeX;
queue<int> snakeY;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int SnakeMove(char dir, int p) {
    int dir_num;

    if (dir == 'U') dir_num = 0;
    else if (dir == 'R') dir_num = 1;
    else if (dir == 'D') dir_num = 2;
    else dir_num = 3;

    for (int i = 0; i < p; i++) {
        int nx = head_x + dx[dir_num];
        int ny = head_y + dy[dir_num];

        elapsed_time++;

        if (!InRange(nx, ny)) {
            return 0;
        }

        if (grid[nx][ny] != 1) {
            int tail_x = snakeX.front();
            int tail_y = snakeY.front();

            snakeX.pop();
            snakeY.pop();

            grid[tail_x][tail_y] = 0;
        }

        if (grid[nx][ny] == 2) {
            return 0;
        }

        head_x = nx;
        head_y = ny;

        snakeX.push(head_x);
        snakeY.push(head_y);

        grid[head_x][head_y] = 2;
    }

    return 1;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        grid[a][b] = 1;
    }

    snakeX.push(0);
    snakeY.push(0);
    grid[0][0] = 2;

    for (int i = 0; i < k; i++) {
        char dir;
        int p;

        cin >> dir >> p;

        if (SnakeMove(dir, p) == 0) {
            break;
        }
    }

    cout << elapsed_time;

    return 0;
}