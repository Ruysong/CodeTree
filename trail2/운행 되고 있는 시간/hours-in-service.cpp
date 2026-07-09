#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int time[100][2]={};
    for(int i=0;i<n;i++) cin >> time[i][0] >> time[i][1];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i ==j) continue;
            int fill[1001]= {0};
            for(int k=time[j][0];k<time[j][1];k++ ){
                fill[k]=1;
            }
            int op_time=0;
            for(int k=0;k<1000;k++) op_time += fill[k];
            ans = max(ans,op_time);
        }
       
    }
    cout << ans;
    return 0;
}