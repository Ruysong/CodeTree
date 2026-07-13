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
        for(int j=0;j<m;j++){
            cin >> segments[i][j];
        }

    int ans =0;
    for(int i = 0; i < n; i++) { 
        int sum=0;

      for(int j = 0; j < n; j++) {
        sum = segments[i][j];
        for(int k=1;k<n;k++) {
        sum += segments[i+k][j] * InRange(i+k,j)
        +segments[i][j+k] *InRange(i,j+k)
        +segments[i-k][j] *InRange(i-k,j)
        +segments[i][j-k] * InRange(i,j-k);

        if( 2*k*k+ 2*k+1 < sum*m ) ans = max(ans,sum);
    }

      }
}

    cout << ans;
    return 0;
}