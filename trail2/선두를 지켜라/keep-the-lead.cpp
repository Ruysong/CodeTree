#include <iostream>
 #include<vector>
using namespace std;


int main() {
    vector<int> posA(1000000,0) ;

    vector<int> posB(1000000,0) ;
    
    int n,m;
    cin >> n >>m;
    int timeA=0;
    int curA=0;
    for(int i=0;i<n;i++){
        int v,t;
        cin >> v>> t;
        for(int j = 0; j < t; j++){
        curA += v;
        timeA++;
    posA[timeA] = curA;
               }
    
    
    }
    int timeB=0;
    int curB=0;
    for(int i=0;i<m;i++){
        int v,t;
        cin >> v>> t;
        for(int j = 0; j < t; j++){
        curB += v;
        timeB++;
posB[timeB] = curB;

        }
        

    }
int prevLeader = 0;
int cnt = 0;
  int curLeader = 0;
int totalTime = min(timeA, timeB);

for (int i = 1; i <= totalTime; i++) {
    int curLeader = 0;

    if (posA[i] > posB[i]) curLeader = 1;
    else if (posB[i] > posA[i]) curLeader = 2;

    if (curLeader == 0) continue;

    if (prevLeader != 0 && prevLeader != curLeader) cnt++;

    prevLeader = curLeader;
}
cout << cnt;
    return 0;
}