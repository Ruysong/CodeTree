#include <iostream>
using namespace std;

int n, m;

int ball[2501][3];
// ball[i][0] = 행
// ball[i][1] = 열
// ball[i][2] = 방향
// 사라지면 행, 열을 -1로 둠

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int ChangeDir(char dir) {
    if(dir == 'U') return 0;
    if(dir == 'R') return 1;
    if(dir == 'D') return 2;
    return 3;
}

void Simulate() {
    int temp[51][51] = {};

    // 모든 구슬을 1초 움직임
    for(int i = 0; i < m; i++) {
        if(ball[i][0] == -1)
            continue;

        int x = ball[i][0];
        int y = ball[i][1];
        int dir = ball[i][2];

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(!InRange(nx, ny)) {
            ball[i][2] = (dir + 2) % 4;
        }
        else {
            ball[i][0] = nx;
            ball[i][1] = ny;
        }

        temp[ball[i][0]][ball[i][1]]++;
    }

    // 같은 칸에 2개 이상 있으면 제거
    for(int i = 0; i < m; i++) {
        if(ball[i][0] == -1)
            continue;

        int x = ball[i][0];
        int y = ball[i][1];

        if(temp[x][y] >= 2) {
            ball[i][0] = -1;
            ball[i][1] = -1;
        }
    }
}

int main() {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        cin >> n >> m;

        for(int i = 0; i < m; i++) {
            int r, c;
            char dir;

            cin >> r >> c >> dir;

            ball[i][0] = r - 1;
            ball[i][1] = c - 1;
            ball[i][2] = ChangeDir(dir);
        }

        // 반복 횟수는 제한 확인 후 결정
        for(int time = 0; time < n * 10; time++) {
            Simulate();
        }

        int answer = 0;

        for(int i = 0; i < m; i++) {
            if(ball[i][0] != -1)
                answer++;
        }

        cout << answer << '\n';
    }

    return 0;
}