#include <iostream>
#include <algorithm>
using namespace std;

int n;
int segments[11][2] = {};

int GetOverlappedCnt(int i1, int i2, int i3) { // 안겹치면 오케이 1 
    int counting[1000] = {}; // initialize
    for(int i = 0; i < n; i++) {
        if(i == i1 || i == i2 || i == i3)
            continue; // 얘네 3개일 떄의 선분들은 뺴겠다.
        
        int x1 = segments[i][0], x2 = segments[i][1];
        for(int j = x1; j <= x2; j++)
            counting[j]++;
    }

    bool ok =1;
    for(int i=0; i<1000;i++){
        if(counting[i]>=2) ok =0;
    }

    return ok;
}

int main() {
    cin >>n;
    for(int i = 0; i < n; i++) cin >> segments[i][0] >> segments[i][1];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++) {
                if(( GetOverlappedCnt(i, j, k)) )ans++; 
                
            }
    
    cout << ans;
    
    return 0;
}
