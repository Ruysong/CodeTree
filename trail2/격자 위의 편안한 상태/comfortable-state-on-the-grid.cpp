#include <iostream>
#include <string>
using namespace std;
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool InRange(int x, int y) {
     return (1 <= x && x <= n && 1 <= y && y <= n);
    }
int Dir_num(char a){
    if (a == 'R') return 0;
    else if(a =='D') return 1;
    else if(a== 'L') return 2;
    else if(a=='U') return 3;
}
int main(){
    int color[101][101]= {0};
    cin >> n>>m;
   
    for(int i=0;i<m;i++){
       int r,c;
        cin>> r>> c;
        color[r][c]=1;
        int cnt =0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];

            if (InRange(nx, ny) && color[nx][ny] == 1) {
                cnt++;
                    }

            }
        if(cnt ==3) cout<< 1 << endl;
        else cout << 0 << endl;
        
    }

    return 0;
}