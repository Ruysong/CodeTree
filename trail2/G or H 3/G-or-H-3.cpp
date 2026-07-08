#include <iostream>
#include <algorithm>
using namespace std;

int n,k;

int main() {
    cin >> n >>k;
    int placed[10001]={0};
    for(int i = 0; i < n; i++){
       int a; //position
       char b; 
       cin >> a>>b;
       if(b =='G') placed[a] = 1;
       else if(b=='H') placed[a] = 2;
    }
    
    int max_cnt = 0;
    for(int i = 0; i <= 10000 -(k) ; i++) {
        int candy_num = 0;
        for(int j = i; j < i + k+1; j++)
            candy_num += placed[j];
    
        max_cnt = max(max_cnt, candy_num);
    }
    
    cout << max_cnt;
    
    return 0;
}


