#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int height[100];
    int max_h = 0;

    for(int i = 0; i < n; i++) {
        cin >> height[i];
        max_h = max(max_h, height[i]);
    }

    int ans = 0;

    for(int h = 0; h <= max_h; h++) { // 해수면 높이
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(height[i] > h) { // 물 위에 있음
                if(i == 0 || height[i - 1] <= h) {
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}