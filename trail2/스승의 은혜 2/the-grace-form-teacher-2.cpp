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
         price[i] /=2; // 반값을 쓸.
         
         int money =b;
         int ppl=0;
            for(int j=0;j<n;j++){
            if(price[j] <= money) {money -= price[j];
            ppl++;
            }
            else if(price[j] > money) break;

        }
        ans = max(ans, ppl);
        price[i] *=2;
    }
    cout << ans;
    return 0;
}