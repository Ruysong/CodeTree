#include <iostream>
using namespace std;
int board[19][19];
bool InRange(int x, int y) {
    return 0 <= x && x < 19 && 0 <= y && y < 19;
}
int main() {
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    // →, ↓, ↘, ↗
    int dx[4] = {0, 1, 1, -1};
    int dy[4] = {1, 0, 1, 1};
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(board[i][j] == 0) continue;
            int color = board[i][j];
            for(int dir = 0; dir < 4; dir++) {
                bool ok = true;
                for(int k = 0; k < 5; k++) {
                    int nx = i + dx[dir] * k;
                    int ny = j + dy[dir] * k;
                    if(!InRange(nx, ny) || board[nx][ny] != color) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    cout << color << '\n';

                    int midX = i + dx[dir] * 2;
                    int midY = j + dy[dir] * 2;

                    cout << midX + 1 << " " << midY + 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}