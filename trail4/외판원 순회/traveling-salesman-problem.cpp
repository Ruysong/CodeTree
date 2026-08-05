#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int grid[11][11];
int visited[11] = {};
int path[11];

int cnt = 0;
int ans = INT_MAX;
int cost = 0;

void choose(int now, int cnt) {
    // 모든 지점을 방문했음
    if (cnt == n) {
        cost += grid[now][1];   // 현재 지점에서 1번으로 복귀
        ans = min(ans, cost);
        cost -= grid[now][1];
        return;
    }

    for (int next = 2; next <= n; next++) {
        if (visited[next]) continue;

        visited[next] = 1;
        cost += grid[now][next];  // now에서 next로 이동

        choose(next, cnt + 1);     // 이제 현재 위치는 next

        cost -= grid[now][next];
        visited[next] = 0;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    path[1] = 1;     // 첫 번째 방문 지점은 항상 1번
    visited[1] = 1;  // 1번 지점은 이미 방문함

    
    choose(1, 1);      // 두 번째 방문 지점부터 선택

    cout << ans;

    return 0;
}