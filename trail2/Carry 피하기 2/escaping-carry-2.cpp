#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[50];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int cnt=0;
    int ans =-1;
    for(int i=0;i< n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                bool ok =
    ((num[i] / 1000) % 10 + (num[j] / 1000) % 10 + (num[k] / 1000) % 10 < 10) &&
    ((num[i] / 100) % 10 + (num[j] / 100) % 10 + (num[k] / 100) % 10 < 10) &&
    ((num[i] / 10) % 10 + (num[j] / 10) % 10 + (num[k] / 10) % 10 < 10) &&
    ((num[i] / 1) % 10 + (num[j] / 1) % 10 + (num[k] / 1) % 10 < 10);
                if(ok ) {cnt = num[i]+num[j]+num[k];
                ans =max(ans,cnt);
                }
            }
        }
    }
    cout <<ans;
    return 0;
}