#include <iostream>
using namespace std;

int main() {
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

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

    for (int x = ax1; x < ax2; x++) {
        for (int y = ay1; y < ay2; y++) {
            checked[x][y] = true;
        }
    }

    for (int x = bx1; x < bx2; x++) {
        for (int y = by1; y < by2; y++) {
            checked[x][y] = 0;
        }
    }
    
int minX = 2001, minY = 2001;
int maxX = -1, maxY = -1;
    
      for (int x = ax1; x < ax2; x++) {
       for (int y = ay1; y < ay2; y++) {
           if (checked[x][y]) {
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
}

        }
    }
    if (maxX == -1) {
    cout << 0;
    return 0;
}

cout << (maxX - minX + 1) * (maxY - minY + 1);

    return 0;
}