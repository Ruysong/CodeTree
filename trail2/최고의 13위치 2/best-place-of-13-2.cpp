#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    int mat[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> mat[i][j];
        }
    }
    int ans=0;
    int cnt =0;
    int sum[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
            sum[i][j]= mat[i][j]+mat[i][j+1]+mat[i][j+2];
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n-2;j++){
             for(int k=0; k<n;k++){
                for(int l=0;l<n-2;l++){
                   if(!(i<=k && k<=i+2)) cnt = sum[i][j]+ sum[k][l];
                    ans = max(cnt,ans);
                    cnt =0;
                }
             }
            
        }
    }
    cout << ans;

    return 0;
}