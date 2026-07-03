#include <iostream>
#include <string>
using namespace std;

int n;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Dir_num(char a){
    if (a == 'R') return 0;
    else if(a =='D') return 1;
    else if(a== 'L') return 2;
    else if(a=='U') return 3;
}
int main(){
    int x=0;
    int y=0;
    int ans =-1;
    int cnt=0;
    string s;
    cin >> s; 
    char dir;
    int dir_num = 3;
    for(int i=0;i<s.length();i++){
        dir =s[i];
        if(dir=='F'){
        x = x + dx[dir_num];
        y = y + dy[dir_num];
        }
        if(dir =='R'){dir_num = (dir_num +1)%4;
        }
        if(dir =='L'){dir_num = (dir_num +3)%4;}
        

        cnt++;
        if(x==0 &&y==0) {
            ans =cnt;
            break;}
        
    }

    cout << ans;
    return 0;
}