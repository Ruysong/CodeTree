#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int segments[21][21]={};
int InRange(int i,int j){
    return ((i>=0 && i<n) && (j <n && j>=0)) ;
}

int main() {
    cin >> n>> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> segments[i][j];
        }

    int ans =0;
    for(int i = 0; i < n; i++) { 
       for(int j = 0; j < n; j++) {

        for(int k=0;k <2* n;k++){
            int sum =0;
        for(int x=0;x<n;x++){
        for(int y=0;y<n;y++)
            {
            if( (abs(i - x) + abs(j - y) <= k) ){
                sum += segments[x][y];
            }          
    }
    }
        if( 2*k*k+ 2*k+1 <= sum*m ) ans = max(ans,sum);
        }
      }
}

    cout << ans;
    return 0;
}