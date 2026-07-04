#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cin>> n;
    int ppl[100];
    for(int i=0;i<n;i++){
        cin >> ppl[i];
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int cnt =0;
        for(int j=0;j<n;j++){
            cnt += abs((i-j)*ppl[j]);
        }
        ans = min(ans,cnt);
    }

cout << ans;
    return 0;
}