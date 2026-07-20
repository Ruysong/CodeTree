#include <iostream>
using namespace std;

int n, m, r, c;
int grid[101][101] = {};
char dir[1000001];

int top = 1;
int bottom = 6;
int left_side = 4;
int right_side = 3;
int front = 2;
int back = 5;

void Move(char direction) {
    int temp = bottom;

    if (direction == 'L') {
        c--;

        bottom = left_side;
        left_side = top;
        top = right_side;
        right_side = temp;
    }
    else if (direction == 'R') {
        c++;

        bottom = right_side;
        right_side = top;
        top = left_side;
        left_side = temp;
    }
    else if (direction == 'U') {
        r--;

        bottom = back;
        back = top;
        top = front;
        front = temp;
    }
    else if (direction == 'D') {
        r++;

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