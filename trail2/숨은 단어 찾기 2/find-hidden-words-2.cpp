#include <iostream>
using namespace std;

bool InRange(int x, int y){
    return (x>=0 && x<n)
    && (y>=0 && y <n);
}
int main() {
    
    cin >> n>>m;
    int name[50][50];
    int dx[5]={-1,-1,0,1,1};
    int dy[5]={0,1,1,1,0};
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin >> name[i][j];
        }
    }

    int ans=0;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(name[i][j] =='L'){
                for(int k=0;k<5;k++){
                    for(int l=1;l<=2;l++){
                    int  cnt =0;
                    int nx = i + dx[k]*l;
                    int ny = j + dy[k]*l;
                    if(Inrange(nx,ny && name[nx][ny] =='E') 
                    &&){cnt++;}
                    if (cnt ==2) ans++;
                   
                }
                }


            }
        }
    }
    cout << ans;
    return 0;
}