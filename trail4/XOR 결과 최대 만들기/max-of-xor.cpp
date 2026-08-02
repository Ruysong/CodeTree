#include <iostream>
using namespace std;
int n,m;
int arr[21];
int nums[21];
int ans =0;
void fine() {
    int result = 0;

    for (int j = 0; j < m; j++) {
        result ^= arr[j];
    }

    ans = max(ans, result);
}

void choose(int x, int start) {
    if (x == m) {
        fine();
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[x] = nums[i];         // 실제 숫자를 저장
        choose(x + 1, i + 1);
    }
}
int main() {
    cin >>n>>m;
    for (int i = 1; i <= n; i++)
    cin >> nums[i];
    choose(0); // 0부터 m개 골라야지?
  
    return 0;

}