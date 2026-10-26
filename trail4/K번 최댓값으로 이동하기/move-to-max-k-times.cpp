#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int grid[100][100];
int visited[100][100];
int r, c;
int best=-1;
int  best_x;
int  best_y;
int start_value;

queue<pair<int,int>> q;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void push(int x, int y){
    if(grid[x][y] > best){
        best =grid[x][y];
        best_x =x; 
        best_y=y;
    }
    else if (grid[x][y] == best) {
    if (x < best_x) {
        best_x = x;
        best_y = y;
    }
    else if (x == best_x && y < best_y) {
        best_y = y;
    }
}

    visited[x][y]=true;
    q.push(make_pair(x,y));
}
int Inrange(int x, int y){
    if(x<n && y<n && x>=0 && y>=0) return 1;
    return 0;
}
int ok(int x,int y){
    if(!Inrange(x,y)) return 0;
    if(visited[x][y]) return 0;
    return 1;

}

void bfs(){        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int n_x=x+dx[i];
                int n_y=y+dy[i];
                if(ok(n_x,n_y) 
                && grid[n_x][n_y] < start_value){
                    push(n_x,n_y);
                }
            }
        }


}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    q.push({r-1,c-1});
    best_x =r-1;
    best_y=c-1;
    
    for(int i=0;i<k;i++){
        best = -1;
        visited[best_x][best_y] =1;
        start_value = grid[best_x][best_y];
        bfs();
        q.push({best_x,best_y});
        if(best==-1) break;
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j]=0;
        }
    }
    }
    cout << best_x+1 << " " << best_y+1 ;

    return 0;
}
