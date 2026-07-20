#include <iostream>
using namespace std;

int n, m, r, c;
int grid[101][101] = {};
char dir[100001];

int top = 1;
int bottom = 6;
int left_side = 4;
int right_side = 3;
int front = 2;
int back = 5;

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void Move(char direction) {
    int nr = r;
    int nc = c;

    if (direction == 'L') nc--;
    else if (direction == 'R') nc++;
    else if (direction == 'U') nr--;
    else if (direction == 'D') nr++;

    if (!InRange(nr, nc)) return;

    r = nr;
    c = nc;

    int temp = bottom;

    if (direction == 'L') {
        bottom = left_side;
        left_side = top;
        top = right_side;
        right_side = temp;
    }
    else if (direction == 'R') {
        bottom = right_side;
        right_side = top;
        top = left_side;
        left_side = temp;
    }
    else if (direction == 'U') {
        bottom = back;
        back = top;
        top = front;
        front = temp;
    }
    else if (direction == 'D') {
        bottom = front;
        front = top;
        top = back;
        back = temp;
    }

    grid[r][c] = bottom;
}

int main() {
    cin >> n >> m >> r >> c;

    r--;
    c--;

    for (int i = 0; i < m; i++) {
        cin >> dir[i];
    }

    grid[r][c] = bottom;

    for (int i = 0; i < m; i++) {
        Move(dir[i]);
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer += grid[i][j];
        }
    }

    cout << answer << '\n';

    return 0;
}