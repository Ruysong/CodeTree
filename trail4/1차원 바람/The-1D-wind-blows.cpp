#include <iostream>
using namespace std;

int n, m, q;
int grid[101][101];

bool CanSpread(int row1, int row2){ // row1 as now, row2 as future
    for(int i = 0; i < m; i++){
        if(grid[row1][i] == grid[row2][i]) return 1;
    }
    return 0;
}

// 실제로 왼쪽으로 한 칸 shift
void ShiftLeft(int x){
    int temp = grid[x][0];

    for(int i = 0; i < m - 1; i++)
        grid[x][i] = grid[x][i + 1];

    grid[x][m - 1] = temp;
}

// 실제로 오른쪽으로 한 칸 shift
void ShiftRight(int x){
    int temp = grid[x][m - 1];

    for(int i = m - 1; i >= 1; i--)
        grid[x][i] = grid[x][i - 1];

    grid[x][0] = temp;
}

void SpreadUp(int row, char dir){
    char cur_dir = dir;

    while(row >= 1){
        if(CanSpread(row, row - 1)) {
            if(cur_dir == 'R') {
                ShiftLeft(row - 1);
                cur_dir = 'L';
            }
            else if(cur_dir == 'L') {
                ShiftRight(row - 1);
                cur_dir = 'R';
            }
        }
        else break;

        row--;
    }
}

void SpreadDown(int row, char dir){
    char cur_dir = dir;

    while(row < n - 1){
        if(CanSpread(row, row + 1)) {
            if(cur_dir == 'R') {
                ShiftLeft(row + 1);
                cur_dir = 'L';
            }
            else if(cur_dir == 'L') {
                ShiftRight(row + 1);
                cur_dir = 'R';
            }
        }
        else break;

        row++;
    }
}

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int qi = 0; qi < q; qi++) {
        int row;
        char dir;

        cin >> row >> dir;
        row--;

        // dir은 바람 방향 기준
        // L 바람이면 실제 shift는 오른쪽
        // R 바람이면 실제 shift는 왼쪽
        if(dir == 'R') ShiftLeft(row);
        else if(dir == 'L') ShiftRight(row);

        SpreadUp(row, dir);
        SpreadDown(row, dir);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}