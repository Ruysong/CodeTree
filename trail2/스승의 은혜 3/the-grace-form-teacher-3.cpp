#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,b;
    cin >> n>>b;
    int price[1000][2]={};
    
    for(int i=0;i<n;i++) cin >> price[i][0]>> price[i][1] ; //price랑 shipping가격.
    int ans=0;
       
    #include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,b;
    cin >> n>>b;
    int price[1000][2]={};
    
    for(int i=0;i<n;i++) cin >> price[i][0]>> price[i][1] ; //price랑 shipping가격.
    int ans=0;
       
    for(int i=0;i<n;i++){ //i는 반값
         int tmp[1000][2] = {};
        
        for(int j = 0; j < n; j++){
        tmp[j][0] = price[j][0];
        tmp[j][1] = price[j][1];
        }

        tmp[i][0] /= 2;
        for(int j = 0; j < n; j++){
        tmp[j][0]  += tmp[j][1] ;
        }
        
         sort(tmp[0][0], tmp[n-1][0]);

         int money =b;
         int ppl=0;
            for(int j=0;j<n;j++){
            if(tmp[j][0] <= money) {money -= tmp[j][0];
            ppl++;
            }
            else if(tmp[j][0] > money) break;

        }
        ans = max(ans, ppl);
        
    }
    cout << ans;
    return 0;
}
    