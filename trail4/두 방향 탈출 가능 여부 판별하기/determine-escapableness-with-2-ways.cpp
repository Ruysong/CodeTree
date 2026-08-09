#include <iostream>
using namespace std;

int n, m;
int grid[101][101];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 2; i++) {
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
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }



    return 0;
}