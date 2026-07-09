#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,b;
    cin >> n>>b;
    int price[1000][2]={};
    
    for(int i=0;i<n;i++) cin >> price[i][0]>> price[i][1] ; //price랑 shipping가격.
    int ans=0;
       
  for(int i = 0; i < n; i++) { // i번 학생 선물에 쿠폰 사용
    int cost[1000];

    for(int j = 0; j < n; j++) {
        cost[j] = price[j][0] + price[j][1];
    }

    cost[i] = price[i][0] / 2 + price[i][1];

    sort(cost, cost + n);

    int money = b;
    int ppl = 0;

    for(int j = 0; j < n; j++) {
        if(cost[j] <= money) {
            money -= cost[j];
            ppl++;
        }
        else {
            break;
        }
    }

    ans = max(ans, ppl);
}

    cout << ans;
    return 0;
}
    