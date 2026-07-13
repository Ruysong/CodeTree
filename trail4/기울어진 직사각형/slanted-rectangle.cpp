#include <iostream>
#include <algorithm>
using namespace std;

int n;
int segments[21][21]={};
int InRange(int i,int j){
    return ((i>=0 && i<n) && (j <n && j>=0)) ;
}
int dx[4] ={-1,-1,1,1};
int dy[4] ={1,-1,-1,1};

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> segments[i][j];
        }

    int ans =0;
  
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
       
        // 두변의 길이를 정해야함. 우상.좌상이라고 하겠음.
        // 정하고 가다가 벽을 만나면 바로 폐기해야함. 맞지. 
        // 즉 길이 1로 시작해서 n까지 쭉 보내는데. 벽만나면 폐기. 
        for(int a=1;a<n;a++)
        for(int b=1;b<n;b++){
        int x =i;
        int y =j; //start point
        int sum =0;
        bool ok = true;

        for(int k =0; k<a ;k++){
        int nx = x + dx[0];
        int ny = y + dy[0];
        if(!InRange(nx, ny)) {
    ok = false;
    break;
}
        sum += segments[nx][ny];
        x =nx;
        y =ny;
        }
         for(int k =0; k<b ;k++){
        int nx = x + dx[1];
        int ny = y + dy[1];
        if(!InRange(nx, ny)) {
    ok = false;
    break;
}
        sum += segments[nx][ny];
        x =nx;
        y =ny;
        }
        for(int k =0; k<a ;k++){
        int nx = x + dx[2];
        int ny = y + dy[2];
        if(!InRange(nx, ny)) {
    ok = false;
    break;
}
        sum += segments[nx][ny];
        x =nx;
        y =ny;
        }
        for(int k =0; k<b ;k++){
        int nx = x + dx[3];
        int ny = y + dy[3];
        if(!InRange(nx, ny)) {
    ok = false;
    break;
}
        sum += segments[nx][ny];
        x =nx;
        y =ny;
        }
        if( ok ==true) ans = max(sum,ans);

    }
    }


    cout << ans;
    return 0;
}