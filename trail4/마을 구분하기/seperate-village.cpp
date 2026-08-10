#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[101][101];
int visited[101][101]={0};
int people[100];
int village_cnt = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int cnt; //그냥 해당 빌리지에서 잠깐 몇명인지 세는거.
void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (InRange(nx, ny) &&
            grid[nx][ny] == 1 &&
            visited[nx][ny] == false) {

            dfs(nx, ny);
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1 && visited[i][j] == false) {
                village_cnt++; //새 마을 가보자구.

                cnt = 0;
                dfs(i, j);

                people[village_cnt - 1] = cnt;
            }
        }
    }

    sort(people, people + village_cnt);

cout << village_cnt << '\n';

for (int i = 0; i < village_cnt; i++) {
    cout << people[i] << '\n';
}

    return 0;
}