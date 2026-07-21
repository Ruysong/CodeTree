#include <iostream>
#include <vector>
using namespace std;

int n, m;

// 아래 → 위 순서로 저장
vector<int> grid[21][21];

// pos[숫자][0] = 행
// pos[숫자][1] = 열
int pos[401][2];

// 움직일 숫자 순서
int move_num[401] = {0};

// 위 → 오른위 → 오른쪽 → 오른아래
// 아래 → 왼아래 → 왼쪽 → 왼위
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0,  1, 1, 1, 0,-1,-1, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void Simulate(int num, int x, int y) {
    int next_x = -1;
    int next_y = -1;
    int max_num = 0;

    // 인접한 8칸 중 가장 큰 숫자가 있는 칸 찾기
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 격자 밖이면 확인하지 않음
        if(!InRange(nx, ny))
            continue;

        // 해당 칸에 쌓인 모든 숫자 확인
        for(int j = 0; j < grid[nx][ny].size(); j++) {
            if(grid[nx][ny][j] > max_num) {
                max_num = grid[nx][ny][j];
                next_x = nx;
                next_y = ny;
            }
        }
    }

    // 주변에 숫자가 없다면 움직이지 않음
    if(max_num == 0)
        return;

    // 현재 칸에서 num이 몇 번째인지 찾기
    int idx = -1;

    for(int i = 0; i < grid[x][y].size(); i++) {
        if(grid[x][y][i] == num) {
            idx = i;
            break;
        }
    }

    // num부터 그 위의 숫자까지 목적지로 이동
    for(int i = idx; i < grid[x][y].size(); i++) {
        int value = grid[x][y][i];

        grid[next_x][next_y].push_back(value);

        pos[value][0] = next_x;
        pos[value][1] = next_y;
    }

    // 기존 칸에서 이동한 부분 제거
    grid[x][y].erase(
        grid[x][y].begin() + idx,
        grid[x][y].end()
    );
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;

            grid[i][j].push_back(num);

            pos[num][0] = i;
            pos[num][1] = j;
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> move_num[i];
    }

    for(int i = 0; i < m; i++) {
        int num = move_num[i];

        int r = pos[num][0];
        int c = pos[num][1];

        Simulate(num, r, c);
    }

    // 출력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(grid[i][j].empty()) {
                cout << "None";
            }
            else {
                // 위 → 아래로 출력해야 하므로 뒤에서부터 출력
                for(int k = grid[i][j].size() - 1; k >= 0; k--) {
                    cout << grid[i][j][k] << " ";
                }
            }

            cout << "\n";
        }
    }

    return 0;
}