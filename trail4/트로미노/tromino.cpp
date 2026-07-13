#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int segments[201][201]={};
int Inrange(int i,int j){
    return (i<n && j <m) ;
}

int main() {
    cin >> n>> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> segments[i][j];
        }

    int ans =0;
   
for(int i = 0; i < n; i++) { // 1*3짜리 먼저 진행 
        int sum =0;
      for(int j = 0; j < m-2; j++) {
        sum = segments[i][j]+ segments[i][j+1]+segments[i][j+2];
        ans = max(ans,sum);
    }
}
for(int i = 0; i < n-2; i++) { // 3*1 짜리 살짜쿵 돌려서
        int sum =0;
      for(int j = 0; j < m; j++) {
        sum = segments[i][j]+ segments[i+1][j]+segments[i+2][j];
        ans = max(ans,sum);
    }
}
for(int i = 0; i < n-1; i++) { // ㄴ모양 진행.
        int sum =0;
      for(int j = 0; j < m-1; j++) {
        for(int k=i;k<i+2;k++)
            for(int l=j;l<j+2;l++){
        sum = segments[i][j]+ segments[i+1][j]+segments[i][j+1]+segments[i+1][j+1];
        sum -= segments[k][l];
        ans = max(ans,sum);
        }
    }
}
    cout << ans;
    return 0;
}