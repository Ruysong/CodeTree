#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int pos[1001]; 
int boom[1001];


int main() {
    cin >> n>>k;
    for(int i = 0; i < n; i++) cin>> pos[i];
        
    int ans = 0;

   for(int i = 0; i < n; i++) 
        for(int j = i-k; j <= i+k; j++){
           if( i-k < 0)  continue;
           if( i==j)  continue;

           if(pos[j]==pos[i]) ans = max(j,ans);
           
        }

    cout << ans;

    return 0;
}