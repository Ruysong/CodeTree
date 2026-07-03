#include <iostream>
using namespace std;

int n;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Dir_num(char a){
    if (a == 'E') return 0;
    else if(a =='S') return 1;
    else if(a== 'W') return 2;
    else return 3;
}

int main(){
    cin >>n;
    int x=0;
    int y=0;
    int cnt=0;
    int ans =-1;
    for(int i=0;i<n;i++){
        char dir;
        cin >> dir;
        int t; cin>> t;
        for(int j=0;j<t;j++){
        int dir_num= Dir_num(dir);
        x = x + dx[dir_num];
        y = y + dy[dir_num];

        cnt++;
        if(x==0 &&y==0) {
            ans =cnt;
            break;}
        }
        if(ans!=-1) break;

    }

    cout << ans;
    return 0;
}