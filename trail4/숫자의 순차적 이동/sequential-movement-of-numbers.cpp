#include <iostream>
using namespace std;

int n, m;
int r, c;

int grid[21][21];
int pos[401][2];  // pos[숫자][0] = 행, pos[숫자][1] = 열
int temp;

bool InRange(int x,int y){
    return x>=0 && x< n && y>=0 && y<n;
}

// 8방향
// 위 → 오른위 → 오른쪽 → 오른아래
// 아래 → 왼아래 → 왼쪽 → 왼위
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0,  1, 1, 1, 0,-1,-1, -1};

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];

            int num = grid[i][j];

            pos[num][0] = i;
            pos[num][1] = j;
        }
    }

    for(int k=0;k<m;k++){
    for(int i=1;i <= n*n;i++){
         r = pos[i][0];
         c =pos[i][1]; // 1일떄 좌표
         int max_num=0;
         int next_x=r;
         int next_y=c;
        for(int j=0;j<8;j++){
            int nx= r + dx[j];
            int ny =c + dy[j];
            if(!InRange(nx,ny)) continue;
            
            if(max_num < grid[nx][ny]){
                max_num = grid[nx][ny];
                next_x =nx;
                next_y=ny;

            }

        }
        temp = grid[next_x][next_y];
        grid[next_x][next_y] =grid[r][c];
        grid[r][c] =temp;
         pos[i][0]= next_x;
         pos[i][1]=next_y;

pos[temp][0] = r;
pos[temp][1] = c;

    }
    }


     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] <<" ";
        }
        cout << "\n";
    }


    return 0;
}