#include <iostream>
#include <climits>
using namespace std;

int n;
int grid[101][101];
int elasped_time =0;
 int r;
 int c;
 int dir_num ;
/* 0 means empty 1 means / 2 means \
*/
int dx[4] = {-1, 0, 1, 0};  //상 우 하 좌
int dy[4] = {0, 1, 0, -1};
int slash_dir[4] = {1, 0, 3, 2};       // /
int backslash_dir[4] = {3, 2, 1, 0};  // \|
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}


void Simulate(){
    // 1초일떄의 상황을 케어.
     if(grid[r][c] == 1)
        dir_num = slash_dir[dir_num];
    else if(grid[r][c] == 2)
        dir_num = backslash_dir[dir_num];


    while(true){
    elasped_time++;
    int nx= r + dx[dir_num];
    int ny = c +dy[dir_num];

    if(!InRange(nx,ny)) return;
    
    if(grid[nx][ny]==0) {
        r=nx;
        c=ny;
    }
    else if(grid[nx][ny]==1){ 
        dir_num  = slash_dir[dir_num];
        r=nx;
        c=ny;

    }
    else if(grid[nx][ny]==2){
     dir_num = backslash_dir[dir_num];
     r=nx;
        c=ny;
    }

    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
        cin >> grid[i][j];
    }

    int max_time = INT_MIN;
    //천장시작
   
    for(int i=0;i<n;i++){
         r=0;
    dir_num =2;
        elasped_time =1;
        c=i;
        Simulate();
        max_time = max(max_time,elasped_time);
    }

  
    for(int i=0;i<n;i++){
          c=n-1;
    dir_num =3;
        elasped_time =1;
        r=i;
        Simulate();
        max_time = max(max_time,elasped_time);
    }
    
   
    for(int i=0;i<n;i++){
         r=n-1;
    dir_num =0;
        elasped_time =1;
        c=i;
        Simulate();
        max_time = max(max_time,elasped_time);
    }
  
    for(int i=0;i<n;i++){
          c=0;
        dir_num =1;
        elasped_time =1;
        r=i;
        Simulate();
        max_time = max(max_time,elasped_time);
    }



    cout << max_time;


    return 0;
}