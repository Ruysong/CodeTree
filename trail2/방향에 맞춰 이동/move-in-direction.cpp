#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
    }
    int x=0,y=0;
    int dir_num ;
     int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
    int nx, ny;

    


    for (int i = 0; i < n; i++) {
    if (dir[i] == 'E') dir_num = 0;
    else if (dir[i] == 'S') dir_num = 1;
    else if (dir[i] == 'W') dir_num = 2;
    else dir_num = 3; // N
        
        x += dx[dir_num]*dist[i];
        y += dy[dir_num]*dist[i];
        
    }
    cout << x<< " " << y;
   

    return 0;
}