#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int grid[10][10];

int colored[10] = {};  // 이미 선택한 열인지
int selected[10];      // 각 행에서 어떤 열을 골랐는지

int ans = INT_MIN;

// 이번에 선택한 N개 값 중 최솟값 구하기
int FindMin() {
    int minValue = INT_MAX;

    for (int row = 0; row < n; row++) {
        int col = selected[row];
        minValue = min(minValue, grid[row][col]);
    }

    return minValue;
}

void choose(int row) {
    // 모든 행에서 하나씩 선택 완료
    if (row == n) {
        int minValue = FindMin();
        ans = max(ans, minValue);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (colored[col]) continue;

        colored[col] = 1;
        selected[row] = col;  // row행에서는 col열을 골랐다고 기록

        choose(row + 1);

        colored[col] = 0;
    }
}

int main() {
    cin >> n;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cin >> grid[row][col];
        }
    }

    choose(0);

    cout << ans;

    return 0;
}