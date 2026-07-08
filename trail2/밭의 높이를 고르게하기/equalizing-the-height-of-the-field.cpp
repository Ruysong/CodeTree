#include <iostream>
#include <climits>
using namespace std;

int n,h,t;

int main() {
    cin >> n>> h>>t;
    int height[100];
    for(int i=0;i<n;i++){
        cin >> height[i];
    }
   
    int ans = INT_MAX;
    for(int i = 0; i <= n - t; i++){
    int cost = 0;
    for(int j = i; j < i + t; j++){
        cost += abs(height[j] - h);
    }
    ans = min(ans, cost);
}
    cout << ans;
    

   

    return 0;
}