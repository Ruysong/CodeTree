#include <iostream>
#include <algorithm>
using namespace std;

int n;
int max_cnt = 0;

int main() {
    cin >>n;
    
    int max_cnt =0;
    int ans=-1;
    for(int i = 0; i <= 2; i++) {
        int cup[3]={0};
        cup[i];
        int cnt;
        for(int j=0;j<n; j++){
            int a,b,c;
            cin >> a>> b>> c;
            a--;b--;c--;
            int temp = cup[a];
            cup[a]=cup[b];
            
            if(cup[c]==1) cnt++;
        }
        if(cnt > max_cnt){
            max_cnt= cnt;
            ans =i++;

        }
        
    }
   
    cout << ans ;
    
    return 0;
}

