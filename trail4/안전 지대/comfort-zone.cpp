#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[101][101];
int visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int k;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (InRange(nx, ny) &&
            grid[nx][ny] > k &&
            visited[nx][ny] == false) {

            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int max_area = 0;
    int answer_k = 1;

    for (k = 1; k <= 100; k++) {

        // K가 바뀌었으니 방문기록 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        int area_cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] > k &&
                    visited[i][j] == false) {

                    area_cnt++;
                    dfs(i, j);
                }
            }
        }

        if (area_cnt > max_area) {
            max_area = area_cnt;
            answer_k = k;
        }
    }

    cout << answer_k << ' ' << max_area;

    return 0;
}