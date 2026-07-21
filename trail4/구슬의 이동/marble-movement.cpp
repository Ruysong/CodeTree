#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, k;

// ball[i][0] = 행
// ball[i][1] = 열
// ball[i][2] = 방향
// ball[i][3] = 속도
int ball[2501][4];

// U R D L
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 문자 방향을 숫자로 변경
int ChangeDirNum(char dir) {
    if(dir == 'U')
        return 0;

    if(dir == 'R')
        return 1;

    if(dir == 'D')
        return 2;

    return 3; // L
}

// 반대 방향으로 변경
int ChangeDir(int dir) {
    return (dir + 2) % 4;
}

// i번 구슬을 1초 동안 이동
void MoveBall(int i) {
    int x = ball[i][0];
    int y = ball[i][1];
    int dir = ball[i][2];
    int speed = ball[i][3];

    // 1초 동안 speed칸 이동
    for(int move = 0; move < speed; move++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 벽을 만나면 즉시 반대 방향으로 변경
        if(!InRange(nx, ny)) {
            dir = ChangeDir(dir);

            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    // 이동 결과 저장
    ball[i][0] = x;
    ball[i][1] = y;
    ball[i][2] = dir;
}

// 우선순위 비교
bool cmp(int a, int b) {
    // 속도가 다르면 속도가 큰 구슬 우선
    if(ball[a][3] != ball[b][3])
        return ball[a][3] > ball[b][3];

    // 속도가 같으면 번호가 큰 구슬 우선
    return a > b;
}

// 같은 칸에 있는 구슬 충돌 처리
void Collision() {
    vector<int> temp[51][51];

    // 현재 살아 있는 구슬을 각 칸에 모음
    for(int i = 1; i <= m; i++) {
        // 사라진 구슬
        if(ball[i][0] == -1)
            continue;

        int x = ball[i][0];
        int y = ball[i][1];

        temp[x][y].push_back(i);
    }

    // 각 칸 확인
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // K개 이하라면 아무 일도 없음
            if(temp[i][j].size() <= k)
                continue;

            // 우선순위가 높은 순서로 정렬
            sort(temp[i][j].begin(), temp[i][j].end(), cmp);

            // K번째 뒤의 구슬들은 제거
            for(int p = k; p < temp[i][j].size(); p++) {
                int num = temp[i][j][p];

                ball[num][0] = -1;
                ball[num][1] = -1;
            }
        }
    }
}

// 1초 진행
void Simulate() {
    // 모든 구슬을 먼저 이동
    for(int i = 1; i <= m; i++) {
        if(ball[i][0] == -1)
            continue;

        MoveBall(i);
    }

    // 모든 구슬의 이동이 끝난 뒤 충돌 처리
    Collision();
}

int main() {
    cin >> n >> m >> t >> k;

    for(int i = 1; i <= m; i++) {
        int r, c, v;
        char d;

        cin >> r >> c >> d >> v;

        ball[i][0] = r - 1;
        ball[i][1] = c - 1;
        ball[i][2] = ChangeDirNum(d);
        ball[i][3] = v;
    }

    // T초 동안 진행
    for(int time = 0; time < t; time++) {
        Simulate();
    }

    // 살아남은 구슬 개수
    int answer = 0;

    for(int i = 1; i <= m; i++) {
        if(ball[i][0] != -1)
            answer++;
    }

    cout << answer;

    return 0;
}