#include <iostream>
#include <algorithm>
using namespace std;

int n ;
int segments[100][2] = {};

int main() {
    cin >> n;
    int ans = 100000;

    for(int i = 0; i < n; i++)
         cin >> segments[i][0]>> segments[i][1];


    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
                        
                int x1 = segments[i][0], y1 = segments[i][1];
                int x2 = segments[j][0], y2 = segments[j][1];
                int range = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                            ans = min(ans, range);
        }
    
    cout << ans;
    
    return 0;
}

