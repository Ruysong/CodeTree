#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[100];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int cnt=INT_MIN;
    int ans=INT_MIN;
     for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j++){
            cnt = num[i]+num[j];
            ans = max(cnt,ans);
        }
    }
    cout << ans;
    return 0;
}