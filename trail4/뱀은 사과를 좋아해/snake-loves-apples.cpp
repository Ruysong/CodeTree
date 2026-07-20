#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int grid[101][101];

int head_x = 0;
int head_y = 0;
int elapsed_time = 0;

queue<int> snakeX;
queue<int> snakeY;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool SnakeMove(char dir, int p) {
    int dir_num;

    if (dir == 'U') dir_num = 0;
    else if (dir == 'R') dir_num = 1;
    else if (dir == 'D') dir_num = 2;
    else dir_num = 3;

    for (int i = 0; i < p; i++) {
        int nx = head_x + dx[dir_num];
        int ny = head_y + dy[dir_num];

        elapsed_time++;

        // 격자 밖이면 게임 종료
        if (!InRange(nx, ny)) {
            return false;
        }

        bool hasApple = (grid[nx][ny] == 1);

        // 사과가 없으면 꼬리 제거
        if (!hasApple) {
            int tail_x = snakeX.front();
            int tail_y = snakeY.front();

            snakeX.pop();
            snakeY.pop();

            grid[tail_x][tail_y] = 0;
        }

        // 이미 뱀의 몸이 있는 곳이면 게임 종료
        if (grid[nx][ny] == 2) {
            return false;
        }

        // 새 머리 추가
        head_x = nx;
        head_y = ny;

        snakeX.push(head_x);
        snakeY.push(head_y);

        grid[head_x][head_y] = 2;
    }

    return true;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        grid[a][b] = 1;  // 사과
    }

    snakeX.push(0);
    snakeY.push(0);
    grid[0][0] = 2;  // 처음 뱀 위치

    bool game_over = false;

    for (int i = 0; i < k; i++) {
        char dir;
        int p;

        cin >> dir >> p;

        if (!game_over && !SnakeMove(dir, p)) {
            game_over = true;
        }
    }

    cout << elapsed_time << '\n';

    return 0;
}