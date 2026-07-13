#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int grid[6][6];

int GetSum(int r1, int c1, int r2, int c2) {
    int sum = 0;

    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            sum += grid[i][j];
        }
    }

    return sum;
}

bool Overlap(int r1, int c1, int r2, int c2,
             int r3, int c3, int r4, int c4) {
    
    // 두 직사각형이 완전히 위아래로 떨어진 경우
    if(r2 < r3 || r4 < r1) return false;

    // 두 직사각형이 완전히 좌우로 떨어진 경우
    if(c2 < c3 || c4 < c1) return false;

    // 위 두 경우가 아니면 겹침
    return true;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = INT_MIN;

    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            for(int r2 = r1; r2 < n; r2++) {
                for(int c2 = c1; c2 < m; c2++) {

                    // 첫 번째 직사각형: (r1, c1) ~ (r2, c2)
                    int sum1 = GetSum(r1, c1, r2, c2);

                    for(int r3 = 0; r3 < n; r3++) {
                        for(int c3 = 0; c3 < m; c3++) {
                            for(int r4 = r3; r4 < n; r4++) {
                                for(int c4 = c3; c4 < m; c4++) {

                                    // 두 번째 직사각형: (r3, c3) ~ (r4, c4)
                                    if(Overlap(r1, c1, r2, c2, r3, c3, r4, c4)) {
                                        continue;
                                    }

                                    int sum2 = GetSum(r3, c3, r4, c4);

                                    ans = max(ans, sum1 + sum2);
                                }
                            }
                        }
                    }

                }
            }
        }
    }

    cout << ans;

    return 0;
}