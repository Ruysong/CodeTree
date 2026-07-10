#include <iostream>
#include <algorithm>
using namespace std;

int max_score = 0;
int n,c,g,h;
int temp[1000][2]={};

int Workload(int num, int a,int b) {
    if(num ==0) return c;
    else if(num < a)
        return c;
    else if(num <= b)
        return g;
    else 
        return h;
}

int main() {
    cin >> n>> c>>g>>h;
    for(int i = 0; i < n; i++) cin >> temp[i][0]>> temp[i][1];

    int ans=0;
    for(int t=0; t<=1001;t++){
        int work=0;
    for(int i = 0; i < n; i++) {
        work += Workload(t,temp[i][0],temp[i][1]);       
    }
    ans = max(work, ans);
    }
    cout << ans;
    
    return 0;
}
