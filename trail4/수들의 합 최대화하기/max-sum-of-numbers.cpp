#include <iostream>

using namespace std;

int n;
int grid[10][10];
int colored[10]={0};//행은 재귀로 바줄거고, 열은 이거 컬러드로 visited효과
int ans=0;
int cnt=0;

void choose(int row) {
    if(row ==n){
        ans =max(ans,cnt);
        return;
    }

    for (int col = 0; col < n; col++) {
        // row행의 col열을 선택
        if(colored[col]) continue;
        else {
        colored[col]=1;
        cnt += grid[row][col];
        choose(row + 1);
        cnt -= grid[row][col];
        colored[col] =0;}
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    choose(0); //0행부터 시작.
    cout << ans;
    return 0;
}
