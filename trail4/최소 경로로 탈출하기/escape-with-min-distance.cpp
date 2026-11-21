#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int a[100][100];
int min_move=INT_MAX;
int step[100][100];
int visited[100][100]={0};
int dx[4]= {0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<pair<int,int>> q;

void push(int x, int y, int s){
    step[x][y]= s;
    visited[x][y]=true;
    q.push({x,y});
}
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
    
    for(int i=0;i<4;i++){
        int nx = x +dx[i];
        int ny = y +dy[i];

        
        if(!(nx >=0 && ny>=0 && nx<n && ny <m)) continue;
        if(visited[nx][ny]) continue;
        if(!a[nx][ny]) continue;
        if(nx == n-1 && ny == m-1) {
            min_move = step[x][y]+1;
            return; 
        }        
        push(nx,ny,step[x][y]+1);
        }

    }
    min_move = -1;

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    push(0,0,0); // 시작위치 방문했읍니다랑, 이제 첫스텝 0입니다.
    bfs();
    cout << min_move;

    return 0;
}
