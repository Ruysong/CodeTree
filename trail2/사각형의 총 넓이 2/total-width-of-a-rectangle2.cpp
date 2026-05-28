#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool checked[201][201] = {};

    int OFFSET = 100;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                checked[x][y] = true;
            }
        }
    }

    int answer = 0;

    for (int x = 0; x <= 200; x++) {
        for (int y = 0; y <= 200; y++) {
            if (checked[x][y]) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}