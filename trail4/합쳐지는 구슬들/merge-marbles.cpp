#include <iostream>
using namespace std;

int n, m, t;

int x[10001];
int y[10001];
int dir[10001];
int weight[10001];
int number[10001];

bool alive[10001];

int board[101][101];

// U, R, D, L
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int ChangeDir(char d) {
    if(d == 'U')
        return 0;

    if(d == 'R')
        return 1;

    if(d == 'D')
        return 2;

    return 3;
}

// 모든 구슬을 1초 이동
void Move() {
    for(int i = 1; i <= m; i++) {
        if(alive[i] == false)
            continue;

        int nx = x[i] + dx[dir[i]];
        int ny = y[i] + dy[dir[i]];

        // 벽이면 이동하지 않고 방향만 반대로
        if(!InRange(nx, ny)) {
            dir[i] = (dir[i] + 2) % 4;
        }
        else {
            x[i] = nx;
            y[i] = ny;
        }
    }
}

// 같은 칸에 있는 구슬 합치기
void Merge() {
    // board 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(alive[i] == false)
            continue;

        int now_x = x[i];
        int now_y = y[i];

        // 현재 칸에 아무 구슬도 없음
        if(board[now_x][now_y] == 0) {
            board[now_x][now_y] = i;
        }
        // 현재 칸에 이미 구슬이 있음
        else {
            int other = board[now_x][now_y];

            // 무게 합치기
            weight[other] += weight[i];

            // 번호가 더 큰 구슬의 번호와 방향 사용
            if(number[i] > number[other]) {
                number[other] = number[i];
                dir[other] = dir[i];
            }

            // i번 구슬은 합쳐져서 사라짐
            alive[i] = false;
        }
    }
}

void Simulate() {
    Move();
    Merge();
}

int main() {
    cin >> n >> m >> t;

    for(int i = 1; i <= m; i++) {
        int r, c, w;
        char d;

        cin >> r >> c >> d >> w;

        x[i] = r - 1;
        y[i] = c - 1;
        dir[i] = ChangeDir(d);
        weight[i] = w;
        number[i] = i;
        alive[i] = true;
    }

    for(int time = 0; time < t; time++) {
        Simulate();
    }

    int count = 0;
    int heaviest = 0;

    for(int i = 1; i <= m; i++) {
        if(alive[i] == false)
            continue;

        count++;

        if(weight[i] > heaviest) {
            heaviest = weight[i];
        }
    }

    cout << count << ' ' << heaviest;

    return 0;
}