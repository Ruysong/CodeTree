#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int grid[20][20];

int GetSum(int r1, int c1, int r2, int c2) {
    
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
                        
            if( grid[i][j] <=0) return -1;
        }
    }
    return (r2-r1+1)*(c2-c1+1);
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = -1;

    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            for(int r2 = r1; r2 < n; r2++) {
                for(int c2 = c1; c2 < m; c2++) {
                    
                    // 사각형: (r1, c1) ~ (r2, c2)
                    int sum = GetSum(r1, c1, r2, c2);
                                   
                               
                    ans = max(ans, sum);   
                   
                }
            }
        }
    }

    cout << ans;

    return 0;
}