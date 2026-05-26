#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> blocks(201, 0); // -100 ~ 100 -> 0 ~ 200

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = a; j <= b; j++) { // 끝점 포함
            blocks[j + 100]++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 200; i++) {
        if (blocks[i] > ans) ans = blocks[i];
    }

    cout << ans;

    return 0;
}