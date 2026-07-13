#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int segments[101][101]={};
int Inrange(int i,int j){
    return (i<n && j <n) ;
}

int main() {
    cin >> n>> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> segments[i][j];
        }

    int ans =0;
   

// 행 N개 검사
for(int i = 0; i < n; i++) {
    int cnt = 1;
    bool ok = false;

    for(int j = 1; j < n; j++) {
        if(segments[i][j] == segments[i][j - 1]) cnt++;
        else cnt = 1;

        if(cnt >= m) ok = true;
    }

    if(m == 1) ok = true;
    if(ok) ans++;
}

// 열 N개 검사
for(int j = 0; j < n; j++) {
    int cnt = 1;
    bool ok = false;

    for(int i = 1; i < n; i++) {
        if(segments[i][j] == segments[i - 1][j]) cnt++;
        else cnt = 1;

        if(cnt >= m) ok = true;
    }

    if(m == 1) ok = true;
    if(ok) ans++;
}
    cout << ans;
    return 0;
}