#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin >>n >>k;
    int candy[101]={0};
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        candy[b] +=a;
    } //candy 좌표랑 개수 입력 받아.
   int ans = 0;

    for(int c = 0; c <= 100; c++) {
        int sum = 0;

        for(int x = c - k; x <= c + k; x++) {
            if(0 <= x && x <= 100) {
                sum += candy[x];
            }
        }

        ans = max(ans, sum);
    }


    cout << ans;

    return 0;
}