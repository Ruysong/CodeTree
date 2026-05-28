#include <iostream>
using namespace std;

int main() {
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int mx1, my1, mx2, my2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> mx1 >> my1 >> mx2 >> my2;

    bool checked[2001][2001] = {};

    int OFFSET = 1000;

    ax1 += OFFSET;
    ay1 += OFFSET;
    ax2 += OFFSET;
    ay2 += OFFSET;

    bx1 += OFFSET;
    by1 += OFFSET;
    bx2 += OFFSET;
    by2 += OFFSET;

    mx1 += OFFSET;
    my1 += OFFSET;
    mx2 += OFFSET;
    my2 += OFFSET;

    // 직사각형 A 칠하기
    for (int x = ax1; x < ax2; x++) {
        for (int y = ay1; y < ay2; y++) {
            checked[x][y] = true;
        }
    }

    // 직사각형 B 칠하기
    for (int x = bx1; x < bx2; x++) {
        for (int y = by1; y < by2; y++) {
            checked[x][y] = true;
        }
    }

    // 직사각형 M이 덮는 부분 지우기
    for (int x = mx1; x < mx2; x++) {
        for (int y = my1; y < my2; y++) {
            checked[x][y] = false;
        }
    }

    int answer = 0;

    // 남아있는 A, B의 넓이 세기
    for (int x = 0; x <= 2000; x++) {
        for (int y = 0; y <= 2000; y++) {
            if (checked[x][y]) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}