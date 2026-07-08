#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;

int main() {
    cin >> n;
    char placed[101]={};
    for(int i = 0; i < n; i++){
       int a; //position
       char b; 
       cin >> a>>b;
      placed[a] =b;     
    }     //일단 나래비
    int ans = 0;

    for(int i = 0; i <= 100; i++) {
        if(!placed[i]) continue;
        for(int j = i; j <= 100; j++){ //i가 스타팅.j가 끝.
           if(!placed[j]) continue;
           int G_count=0;
           int H_count=0;
           int size = j-i;

           for(int k=i;k<=j;k++){ //이치요 카운트
           if(placed[k] == 'G') G_count++;
           else if(placed[k] == 'H') H_count++;
           }

           if( (G_count ==0 && H_count !=0)
           ||  (G_count !=0 && H_count ==0)
            || (G_count == H_count )
           ) ans = max (ans ,size);

        }
    }
    
    cout << ans;
    
    return 0;
}


