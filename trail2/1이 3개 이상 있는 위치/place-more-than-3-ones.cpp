#include <iostream>
using namespace std;
 int n;
 int arr[100][100]; 
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
  
   cin>> n;
    int cnt=0;
   



    for(int i=0;i< n;i++){
        for(int j=0; j< n;j++){
        cin >> arr[i][j];
        }
    }

    int answer = 0;

    for (int x = 0; x < n; x++) {// 자이제 돌면서 함 보까
    for (int y = 0; y < n; y++) {
        int cnt = 0;

        for (int dir = 0; dir < 4; dir++) {//위아우왼 함 돌자꾸나
            int nx = x + dr[dir]; 
            int ny = y + dc[dir];

            if (InRange(nx, ny) && arr[nx][ny] == 1) {
                cnt++;
            }
        }

        if (cnt >= 3) {
            answer++;
        }
    }
}

cout << answer;



    return 0;
}