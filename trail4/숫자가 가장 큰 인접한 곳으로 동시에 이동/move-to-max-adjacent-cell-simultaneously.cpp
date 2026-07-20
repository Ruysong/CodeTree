#include <iostream>
using namespace std;

int n, m, t;

int grid[21][21];      // 각 칸에 적힌 숫자
int marble[21][21];    // 현재 구슬이 있으면 1, 없으면 0

// 문제에서 정한 우선순서: 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 모든 구슬을 1초 동안 동시에 이동
void MoveAll() {
    // temp[x][y] = 이번 이동에서 이 칸으로 온 구슬의 개수
    int temp[21][21] = {};

    // 현재 구슬이 있는 모든 칸 확인
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(marble[i][j] == 0)
                continue;

            // (i, j)에 구슬 하나가 있음
            int max_num = -1;
            int next_x = i;
            int next_y = j;

            // 상, 하, 좌, 우 중 가장 큰 숫자의 칸 찾기
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(!InRange(nx, ny))
                    continue;

                if(grid[nx][ny] > max_num) {
                    max_num = grid[nx][ny];
                    next_x = nx;
                    next_y = ny;
                }
            }

            // 구슬이 다음 칸으로 이동
            temp[next_x][next_y]++;
        }
    }

    // 충돌 처리 후 marble 배열 갱신
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(temp[i][j] == 1)
                marble[i][j] = 1;
            else
                marble[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> t;

    // 격자의 숫자 입력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // 처음 M개 구슬의 위치 입력
    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;

        r--;
        c--;

        marble[r][c] = 1;
    }

    // T초 동안 이동
    for(int time = 0; time < t; time++) {
        MoveAll();
    }

    // 남아 있는 구슬 개수 세기
    int answer = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(marble[i][j] == 1)
                answer++;
        }
    }

    cout << answer;

    return 0;
}