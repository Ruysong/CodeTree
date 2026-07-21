#include <iostream>
using namespace std;

int test_case;
int n;

// 각 구슬의 정보
int x[101];
int y[101];
int weight[101];
int dir[101];
bool alive[101];
// U, R, D, L
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 문자 방향을 숫자로 바꾸는 함수
int ChangeDir(char d) {
    if(d == 'U')
        return 0;

    if(d == 'R')
        return 1;

    if(d == 'D')
        return 2;

    return 3; // L
}

// 모든 살아 있는 구슬을 1초 이동
void Move() {
    for(int i = 1; i <= n; i++) {
        if(alive[i] == false)
            continue;

        x[i] += dx[dir[i]];
        y[i] += dy[dir[i]];
    }
}

// a번 구슬이 b번 구슬보다 영향력이 큰지 확인
bool IsStronger(int a, int b) {
    // 무게가 다르면 무거운 구슬이 강함
    if(weight[a] != weight[b])
        return weight[a] > weight[b];

    // 무게가 같으면 번호가 큰 구슬이 강함
    return a > b;
}

// 현재 위치에서 충돌 처리
bool Collision() {
    bool collision_happened = false;

    for(int i = 1; i <= n; i++) {
        if(alive[i] == false)
            continue;

        for(int j = i + 1; j <= n; j++) {
            if(alive[j] == false)
                continue;

            // 두 구슬이 같은 위치라면 충돌
            if(x[i] == x[j] && y[i] == y[j]) {
                collision_happened = true;

                // i가 더 강하면 j 제거
                if(IsStronger(i, j)) {
                    alive[j] = false;
                }
                // j가 더 강하면 i 제거
                else {
                    alive[i] = false;
                    break;
                }
            }
        }
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

            // 이동 중간의 0.5 좌표를 정수로 만들기 위해 2배
            x[i] *= 2;
            y[i] *= 2;

            dir[i] = ChangeDir(d);
            alive[i] = true;
        }

        int last_time = -1;

        // 2배한 좌표의 범위가 -2000 ~ 2000이므로
        // 4000초까지만 확인하면 충분
        for(int time = 1; time <= 4000; time++) {
            Move();

            if(Collision()) {
                last_time = time;
            }
        }

        cout << last_time << '\n';
    }

    return 0;
}