#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    int max_num = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }

    int ans = 0;

    for(int k = 1; k <= max_num; k++) { // k를 등차중항으로 가정
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] + arr[j] == 2 * k) {
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}