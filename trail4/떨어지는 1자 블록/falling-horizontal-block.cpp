#include <iostream>
using namespace std;

int n, m, k;
int grid[101][101];

int main() {
    cin >> n >> m >> k;
    k--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 여기부터 블록을 떨어뜨리는 로직 작성
    int nxt = false; //다음행에 뭐 있으면 멈춰야지
    for (int i = 0; i < n-1; i++) { // 각각 0행부터 얘가 존재할 수 있는지
            

            for(int l=k;l<m+k;l++){
                if(grid[i+1][l]!=0) nxt= true;
            }
            if(nxt ==true) {
                for(int l=k;l<m+k;l++){
                grid[i][l]=1; /// 채워줍시다.
            }
            break;
            }

        
    }



    // 최종 격자 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}