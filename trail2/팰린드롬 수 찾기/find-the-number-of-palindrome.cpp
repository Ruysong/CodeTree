#include <iostream>
using namespace std;

bool IsPalindrome(int num) {
    int arr[10];
    int len = 0;

    while(num > 0) {
        arr[len] = num % 10;
        num /= 10;
        len++;
    }

    bool ok = true;

    for(int i = 0; i < len / 2; i++) {
        if(arr[i] != arr[len - 1 - i]) {
            ok = false;
            break;
        }
    }

    return ok;
}

int main() {
    int x, y;
    cin >> x >> y;

    int cnt = 0;

    for(int i = x; i <= y; i++) {
        if(IsPalindrome(i)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}