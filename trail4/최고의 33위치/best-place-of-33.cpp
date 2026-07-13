#include <iostream>
#include <algorithm>
using namespace std;

int n;
int segments[21][21]={};
int Inrange(int i,int j){
    return (i<n && j <n) ;
}

int main() {
    cin >> n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> segments[i][j];
        }

    int ans =0;
    for(int i=0;i<n-2;i++)
        for(int j=0;j<n-2;j++){
            int sum=0;

            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++){
                    if(Inrange(i+k,j+l)) sum += segments[i+k][j+l];
                    else continue;
                }
            ans = max(sum,ans);     
                          
        }
    cout << ans;
    return 0;
}