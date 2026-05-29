#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;
    
    int checked[2001][2001] = {}; // 글고 0을 빈색. 1은 빨강 2는 파랑 이런식으로.
    int OFFSET = 1000;

    for(int i=0;i<n;i++){
    int ax1, ay1,ax2,ay2;
    cin >> ax1 >> ay1 >>  ax2 >> ay2;
    ax1 += OFFSET;
    ay1 += OFFSET;
    ax2 += OFFSET;
    ay2 += OFFSET;
   for (int x = ax1; x < ax2; x++) {
        for (int y = ay1; y < ay2; y++) {
            if(i%2 ==0)         
            checked[x][y] = 1;
            else if(i%2 ==1)
            checked[x][y] = 2;
        }
    }


    }

    int answer = 0;

    // 파랑출력
    for (int x = 0; x <= 2000; x++) {
        for (int y = 0; y <= 2000; y++) {
            if (checked[x][y]==2) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}