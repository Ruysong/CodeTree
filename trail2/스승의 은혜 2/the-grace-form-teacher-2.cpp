#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,b;
    cin >> n>>b;
    int price[1000]={};
    for(int i=0;i<n;i++) cin >> price[i] ;
    int ans=0;
    sort(price,price+n);
    for(int i=0;i<n;i++){
         int tmp[1000] = {};
        
        for(int j = 0; j < n; j++)
        tmp[j] = price[j];
        tmp[i] /= 2;
         sort(tmp, tmp + n);

         int money =b;
         int ppl=0;
            for(int j=0;j<n;j++){
            if(tmp[j] <= money) {money -= tmp[j];
            ppl++;
            }
            else if(tmp[j] > money) break;

        }
        ans = max(ans, ppl);
        tmp[i] *=2;
    }
    cout << ans;
    return 0;
}