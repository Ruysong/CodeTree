#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(s[i] == 'C' && s[j] == 'O' && s[k] == 'W') {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}