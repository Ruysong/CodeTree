#include <iostream>
using namespace std;

// 결국 핵심은 이걸 1초마다의 위치를 체크하느 ㄴ것.
int main() {
    int n,m;
    cin>> n>>m;
    int posA[1000005] ={};
    int posB[1000005] = {};  
    
    int cur = 0; // 현재 위치
    int t = 0;   // 현재 시간

for (int i = 0; i < n; i++) {
    char dir;
    int time;
    cin >> dir >> time;

    for (int j = 0; j < time; j++) {
        if (dir == 'R') {
            cur++;
        }
        else if (dir == 'L') {
            cur--;
        }

        t++;
        posA[t] = cur;
    }
}
int totalA =t;
int lastA = cur;
cur = 0;
t = 0;

for (int i = 0; i < m; i++) {
    char dir;
    int time;
    cin >> dir >> time;

    for (int j = 0; j < time; j++) {
        if (dir == 'R') {
            cur++;
        }
        else if (dir == 'L') {
            cur--;
        }

        t++;
        posB[t] = cur;
    }
}
int totalB =t;
int lastB = cur;
int total = max(totalA, totalB);
for (int i = totalA + 1; i <= total; i++) {
    posA[i] = lastA;
}

for (int i = totalB + 1; i <= total; i++) {
    posB[i] = lastB;
}
int ans = -1;
for (int i = 1; i <= total; i++) {
    if (posA[i] == posB[i]) {
        ans = i;
        break;
    }
}

cout << ans;


    return 0;
}