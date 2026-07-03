#include <iostream>
#include <vector>
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
       cin >> n;
       vector<vector<char>> mrr(n + 1, vector<char>(n + 1));
        int x,y;
        int dir_num;
        int cnt =0;
        int ans =-1;
    for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
        mrr[i][j] = s[j - 1];
    }
}
    int t;
    cin>> t;
    int k;
    if(t/n==0 || (t/n==1 && t%n==0)) {  
    k = t;  
    x =1;
    y =k;// 위에서 시작. 
     dir_num =1;
    }
    else if(t/n==1 || (t/n==2 && t%n==0)){
        k = t - n;    
        y=n; x= k;
         dir_num =2;
    }
    else if(t/n==2 || (t/n==3 && t%n==0)){
        k = t - 2*n;
         x=n; y = n+1-(k);
     dir_num =3;
   }
    else if(t/n==3 || (t/n==4 && t%n==0)){ 
        k = t - 3*n; y=1; x = n+1-(k);
    dir_num =0;}

    while(InRange(x,y)){
        int nx,ny;
        if(mrr[x][y]=='/'){  cnt++;
    if(dir_num == 0) dir_num = 3;
    else if(dir_num == 3) dir_num = 0;
    else if(dir_num == 1) dir_num = 2;
    else if(dir_num == 2) dir_num = 1;
}
     if(mrr[x][y]=='\\'){  cnt++;
    if(dir_num == 0) dir_num = 1;
    else if(dir_num == 1) dir_num = 0;
    else if(dir_num == 2) dir_num = 3;
    else if(dir_num == 3) dir_num = 2;
}
        nx = x + dx[dir_num];
       ny = y + dy[dir_num];
        if(InRange(nx, ny)) {
        
        x += dx[dir_num];
        y += dy[dir_num];
       
        }
        else{
            
            ans = cnt;
            break;
        }

    }   
    cout<< ans;
    return 0;
}