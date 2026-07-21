#include <iostream>
using namespace std;

const int MAX_N = 100;
const int LIMIT = 2000;
const int OFFSET = 2000;
const int MAX_POS = 4001;

int test_case;
int n;

int x[MAX_N + 1];
int y[MAX_N + 1];
int weight[MAX_N + 1];
int dir[MAX_N + 1];

bool alive[MAX_N + 1];

// 해당 좌표에 있는 구슬 번호
int board[MAX_POS][MAX_POS];

// U, R, D, L
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int ChangeDir(char d) {
    if(d == 'U')
        return 0;

    if(d == 'R')
        return 1;

    if(d == 'D')
        return 2;

    return 3;
}

// a번 구슬이 b번 구슬보다 강한지
bool IsStronger(int a, int b) {
    if(weight[a] != weight[b])
        return weight[a] > weight[b];

    return a > b;
}

// 좌표 범위를 벗어났는지 확인
bool OutOfRange(int ball_x, int ball_y) {
    return ball_x < -LIMIT || ball_x > LIMIT ||
           ball_y < -LIMIT || ball_y > LIMIT;
}

// 1초 진행
bool Simulate() {
    bool collision_happened = false;

    // 1. 모든 구슬 이동
    for(int i = 1; i <= n; i++) {
        if(alive[i] == false)
            continue;

        x[i] += dx[dir[i]];
        y[i] += dy[dir[i]];

        // 이 범위를 벗어난 구슬은 앞으로 충돌할 수 없음
        if(OutOfRange(x[i], y[i])) {
            alive[i] = false;
        }
    }

    // 2. 이동한 좌표에 구슬 배치
    for(int i = 1; i <= n; i++) {
        if(alive[i] == false)
            continue;

        int board_x = x[i] + OFFSET;
        int board_y = y[i] + OFFSET;

        // 해당 위치에 아직 구슬이 없음
        if(board[board_x][board_y] == 0) {
            board[board_x][board_y] = i;
        }
        // 해당 위치에 이미 다른 구슬이 있음
        else {
            collision_happened = true;

            int other = board[board_x][board_y];

            // 새로 들어온 i번 구슬이 더 강함
            if(IsStronger(i, other)) {
                alive[other] = false;
                board[board_x][board_y] = i;
            }
            // 기존 구슬이 더 강함
            else {
                alive[i] = false;
            }
        }
    }

    // 3. 다음 시간을 위해 board 초기화
    for(int i = 1; i <= n; i++) {
        if(alive[i] == false)
            continue;

        int board_x = x[i] + OFFSET;
        int board_y = y[i] + OFFSET;

        board[board_x][board_y] = 0;
    }

    return collision_happened;
}

int main() {
    cin >> test_case;

    while(test_case--) {
        cin >> n;

        for(int i = 1; i <= n; i++) {
            char d;

            cin >> x[i] >> y[i] >> weight[i] >> d;

            // 0.5 단위 충돌을 정수 좌표로 처리
            x[i] *= 2;
            y[i] *= 2;

            dir[i] = ChangeDir(d);
            alive[i] = true;
        }

        int last_time = -1;

        for(int time = 1; time <= 4000; time++) {
            if(Simulate()) {
                last_time = time;
            }
        }

        cout << last_time << '\n';
    }

    return 0;
}