#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n ;
int segments[101][2] = {};

int main() {
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> segments[i][0]>> segments[i][1];
    }

    int ans =INT_MAX;

    for(int i = 0; i < n; i++) {
        int max_x=0;
        int max_y=0;
        int min_x=40001;
        int min_y=40001;
        int area;
        for(int j = 0; j < n; j++) {
            if(j == i)
                continue;
            
            
            
            int x = segments[j][0], y = segments[j][1];
            max_x = max(x,max_x);
            min_x = min(x,min_x);
            max_y = max(y,max_y);
            min_y = min(y,min_y);           
        } 
        area = (max_x - min_x)*( max_y - min_y);
        ans = min(ans,area);
    
        
    }
    
    cout << ans;
    
    return 0;
}


