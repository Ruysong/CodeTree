#include <iostream>
#include <climits>
using namespace std;
int n;
char grid[21][21];
int len=0;

int startR, startC;
int endR, endC;

int coinR[10];
int coinC[10];
bool exists[10];
int ans=INT_MAX;


void choose(int r,int c, int num,int cnt){ //cnt는 몇번째 점픈지(3개넘어야함).
    // num이 방금지난 번호.

    if (cnt == 3) { //일단 3번 넘은 애들은 끝. 최소이동이니까 바로 도달해버려. 
    int total = len + abs(r - endR) + abs(c - endC);
    ans = min(ans, total);
    return;
        }

    for (int i = num+1; i < 10; i++){
        if(exists[i]){
            int nr= coinR[i];
            int nc= coinC[i];
            int temp =len;
            len += abs(nr-r)+abs(nc-c);
            choose(nr,nc,i,cnt+1);     
            len = temp;       
        }
        else continue;

    } 
 

}

int main() {
    cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> grid[i][j];

        if (grid[i][j] == 'S') {
            startR = i;
            startC = j;
        }
        else if (grid[i][j] == 'E') {
            endR = i;
            endC = j;
        }
        else if ('1' <= grid[i][j] && grid[i][j] <= '9') {
            int number = grid[i][j] - '0';

            coinR[number] = i;
            coinC[number] = j;
            exists[number] = true;
        }
    }
}   

    choose(startR,startC,0,0);//행 ,열,다음 찾는 숫자, 지금까지 선택한  동전수.
    if(ans==INT_MAX) cout << -1;
    else cout <<ans;

    return 0;
}