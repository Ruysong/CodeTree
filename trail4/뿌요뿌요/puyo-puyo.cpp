#include <iostream>

using namespace std;

int n;
int grid[100][100];
int visitied[100][100]={0};
int bomb; //크기가 4개이상인 블럭 개수
int max_block; //같은 블럭일떄.
int cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y, int num) {

    // [1] 현재 칸 처리
    visited[x][y] =1;
    cnt++;

    // [2] 4방향 확인

    for (int d = 0; d < 4; d++) {
    

        // [3] 다음 칸 생성
        int nx = x + dx[d];
        int ny = y + dy[d];

        // [4] 갈 수 없는 후보 제거

        if (!InRange(nx, ny))
            continue;

        if (visited[nx][ny])
            continue;

        if (grid[nx][ny] != num)
            continue;


        // [5] 갈 수 있으면 들어가기
        dfs(nx, ny, num);
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
    if (visited[i][j])
    continue;
    cnt = 0;
    dfs(i, j, grid[i][j]);

    if (cnt >= 4)
            bomb++;

    max_block = max(max_block, cnt);

    }}
    cout << bomb << ' ' << max_block;
    return 0;
}
