#include <iostream>
#include <algorithm>
using namespace std;

int n;
int segments[100][2] = {};


int main() {
    cin >>n;
    for (int i=0;i < n; i++){
        cin >> segments[i][0] >> segments[i][1];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++) {
                int x1 = segments[i][0], y1 = segments[i][1];
                int x2 = segments[j][0], y2 = segments[j][1];
                int x3 = segments[k][0], y3 = segments[k][1];
                int area=0;
                if( y1 == y2 &&y2 != y3) area = abs(x2-x1)*abs(y2-y3);
                else if( y2 == y3 &&y2 != y1) area = abs(x2-x3)*abs(y2-y1);
                else if( y3 == y1 &&y2 != y3) area = abs(x3-x1)*abs(y2-y3);

                ans = max(ans,area);
            }
    
    cout << ans;
    
    return 0;
}

