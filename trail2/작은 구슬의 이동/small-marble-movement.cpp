#include <iostream>
using namespace std;
 int n,t;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};


int GetDir(char a) {
    if(a == 'R')
        return 0;
    else if(a == 'D')
        return 1;
    else if(a == 'U')
        return 2;
    else
        return 3;
}
bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}
int main() {

   
    cin>> n>> t;
    char c_dir ;
      
    int x ,y;
    cin >> x>> y>>c_dir;
    int move_dir = GetDir(c_dir);
    int opposite[4] = {3, 2, 1, 0};
      for (int i = 0; i < t; i++) {
        int nx = x + dx[move_dir]; // so nx means next x position
        int ny = y + dy[move_dir];

        if (InRange(nx, ny)) {
            x = nx;
            y = ny;
        }
        else {
            move_dir = opposite[move_dir];
        }
    }


//when t sec later
    cout<< x << ' ' << y;
    return 0;
}
