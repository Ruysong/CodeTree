#include <iostream>

using namespace std;

int n,m,r,c;
int grid[101][101]={};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void PutBomb(int t){
    int dist = 1;
    for (int i = 1; i < t; i++) dist *= 2;
    int temp[101][101]={};

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            temp[i][j] = grid[i][j]; 
        }


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                for(int k=0;k<4;k++){
                    int nx= i + dist * dx[k];
                    int ny = j + dist * dy[k];
                    if(!InRange(nx,ny)) continue;
                    temp[nx][ny] =1 ;
                }
            }

        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            grid[i][j]= temp[i][j]; 
        }


}

int main() {
    cin >> n>> m>>r>>c;

    r--;c--;

    grid[r][c] =1;
    for(int i=1;i<=m;i++){
        PutBomb(i);
    }


    int ans=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) ans += grid[i][j];

    cout <<ans;
    return 0;
}