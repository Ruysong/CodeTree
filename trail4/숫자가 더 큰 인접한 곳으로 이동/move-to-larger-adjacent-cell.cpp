#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[101][101]={};
int r,c;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int InRange(int x,int y){
    return x>=0 && x< n && y>=0 && y <n;
}

int main() {
    cin >> n>> r>>c;
    int x,y;
    x = r-1;
    y = c-1;
    vector<int> v;

    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++)
        cin >> grid[i][j];
    }


    v.push_back(grid[x][y]);
    int ok =true;

    while(ok){
        int close=grid[x][y];
        int max_i=-1;
        
        for(int i=0;i<4;i++){
            int nx =x + dx[i];
            int ny =y + dy[i];
            if (InRange(nx, ny) && grid[nx][ny] > close) {
    max_i = i;
    break;
}
           
    }
         if(max_i != -1) {
            x += dx[max_i];
            y += dy[max_i];
            v.push_back(grid[x][y]);
        }   
        else{ ok =false;}
    }

    for(int i=0;i<v.size();i++){ 
        cout << v[i] << " ";
    }

    return 0;
}