#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int a[100][100];
int visited[100][100];
int order =0;
queue<pair<int,int>> q;

void push(int x, int y){
    
    visited[x][y]=true;
    q.push(make_pair(x,y));
}
int Inrange(int x, int y){
    if(x<n && y<m && x>=0 && y>=0) return 1;

    return 0;
}

int ok(int x,int y){
    if(!Inrange(x,y)) return 0;
      
    if(visited[x][y]) return 0;
    if(!a[x][y]) return 0;
    return 1;

}

void bfs(){
    int dx[4]= {1,0,-1,0};
    int dy[4]= {0,1,0,-1};

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int n_x=x+dx[i];
            int n_y=y+dy[i];
            if(ok(n_x,n_y))
            push(n_x,n_y);        }

    }



}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    push(0,0);
    bfs();
    
    cout << visited[n-1][m-1];

    return 0;
}
