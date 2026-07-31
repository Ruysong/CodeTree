#include <iostream>
using namespace std;

int grid[5][5];
int vector[5][5];
int n;
int r,c;
int ans = 0;
int dr[9]={0,-1,-1,0,1,1,1,0,-1};
int dc[9]={0,0,1,1,1,0,-1,-1,-1}; //입력이 1부터 북쪽이라. 인덱스맞춤
int InRange(int x,int y){
    return x>=0 && x<n && y>=0 && y<n;
}
void move(int x,int posr,int posc){
    int v = vector[posr][posc]; //이번 이동 방향
    int nr = posr +dr[v];
    int nc = posc + dc[v];
    while(InRange(nr,nc)){
        if(grid[nr][nc] > grid[posr][posc]){
            move(x+1,nr,nc);
        }
        nr += dr[v];
        nc += dc[v];
    }
     ans = max(ans,x);
    return;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin >> grid[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin >> vector[i][j];
    cin >> r>>c;
    r--;c--;
    move(0,r,c); //뭐뭐 들어가면 좋을지 고민

    cout << ans;
    return 0;
}