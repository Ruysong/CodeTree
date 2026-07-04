#include <iostream>
#include <string>
using namespace std;
   int n;
int InRange(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y< n);
}
int main() {
    string s;
    int t;
 
    cin >> n>>t;
    cin >>s ;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
    int mat[100][100] ={0};
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> mat[i][j];
        }
    }    // until here is input
    int x=n/2,y=n/2;
    int cnt=mat[n/2][n/2];
    int dir_num =2;
    for(int i=0;i<s.length();i++){
        int nx,ny;
        nx = x + dx[dir_num];
        ny = y + dy[dir_num];
        if(s[i]=='L'){ // rotate direction
    dir_num = (dir_num +3) % 4;
        }
        else if(s[i]=='R'){
             // rotate direction
    dir_num = (dir_num + 1) % 4;

        }
        else if(s[i]=='F' && InRange(nx,ny)){            
    // move
    x = x + dx[dir_num];
    y = y + dy[dir_num];
    cnt += mat[x][y];
    }


    }
   
    cout<< cnt;



    return 0;
}