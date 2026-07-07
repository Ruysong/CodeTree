#include <iostream>
#include <string>
using namespace std;

int n,m;
bool InRange(int x, int y){
    return (x>=0 && x<n)
    && (y>=0 && y <m);
}
int main() {
    cin >> n>>m;
    string name[50];
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i=0; i<n;i++){
        cin >> name[i];
    }

    int ans=0;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(name[i][j] =='L'){
                for(int k=0;k<8;k++){
                     int cnt =0;
                    for(int l=1;l<=2;l++){
                   int nx = i + dx[k]*l;
                    int ny = j + dy[k]*l;
                    if(InRange(nx,ny) && name[nx][ny] =='E') 
                    {
                    cnt++;}
                 
                }
                    if (cnt ==2) ans++;
                }


            }
        }
    }
    cout << ans;
    return 0;
}