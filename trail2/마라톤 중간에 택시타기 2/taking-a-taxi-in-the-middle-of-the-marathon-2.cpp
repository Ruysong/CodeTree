#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin>> n;
    int x[101], y[101];

    for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
}   
    int Minrange = INT_MAX;
    
    for(int i=1;i< n-1; i++){
        int range=0;
        for(int j=0;j<n-1; j++){
        range += abs(x[j+1]-x[j])+abs(y[j+1]-y[j]);
        if ((j) == i) {
            range -= abs(x[j+1]-x[j])+abs(y[j+1]-y[j]);
            range -= abs(x[j]-x[j-1])+abs(y[j]-y[j-1]);
            range += abs(x[j+1]-x[j-1])+abs(y[j+1]-y[j-1]);
        }
        }
        Minrange = min(range,Minrange);
    }
    cout << Minrange;
    return 0;
}

/* 답지 풀이
        int prev_idx = 0;
        for(int j = 1; j < n; j++) {
            if(j == i) continue;
            dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
            prev_idx = j;
        }
        */