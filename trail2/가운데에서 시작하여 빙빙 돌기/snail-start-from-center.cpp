#include <iostream>
using namespace std;
int n;
bool InRange(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1,0};
int x = 0, y = 0;           
int dir_num = 0;            

int main() {
    cin >> n;
    int answer[100][100] = {};
    answer[(n-1)][(n-1)] = n*n;
    x=(n-1);
    y=(n-1);
    for(int i = n*n-1; i >= 1; i--) {
        // 현재 방향 dir를 기준으로 그 다음 위치 값을 계산합니다.
        int nx = x + dx[dir_num], ny = y + dy[dir_num];

        // 더 이상 나아갈 수 없다면
        // 시계방향으로 90'를 회전합니다.
        
        if(!InRange(nx, ny) || answer[nx][ny]!=0)
            dir_num = (dir_num + 1) % 4;

        // 그 다음 위치로 이동한 다음 배열에 올바른 값을 채워넣습니다.
        x = x + dx[dir_num]; y = y + dy[dir_num];
        answer[x][y] = i;
    }
    
    // 출력:
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
