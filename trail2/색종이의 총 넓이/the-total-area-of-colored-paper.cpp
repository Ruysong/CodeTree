#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;
    
    bool checked[2001][2001] = {};
    int OFFSET = 1000;

    for(int i=0;i<n;i++){
    int ax1, ay1;
    cin >> ax1 >> ay1;
    ax1 += OFFSET;
    ay1 += OFFSET;
   for (int x = ax1; x < ax1+8; x++) {
        for (int y = ay1; y < ay1 + 8; y++) {
            checked[x][y] = true;
        }
    }


    }

    int answer = 0;

    // 남아있는 A, B의 넓이 세기
    for (int x = 0; x <= 2000; x++) {
        for (int y = 0; y <= 2000; y++) {
            if (checked[x][y]) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}