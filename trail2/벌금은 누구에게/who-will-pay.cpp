#include <iostream>
#include<vector>
using namespace std;

int main() {
   
        int n,m,k;
        cin >> n>>m >>k;
        int ans = -1;
        vector<int> cnt(n + 1, k);
        for(int i=0; i< m; i++){
            int penalty;
            cin >> penalty;
            cnt[penalty]--;
            
            if (cnt[penalty] ==0) {
                ans = penalty;
                break;
            }
          


        }
        cout<< ans;
    
   


    return 0;
}