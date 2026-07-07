#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>> n;
    int room[1010];
    for(int i=0;i<n;i++){
        cin >> room[i];
    }
    int total =0;
    for(int i=0;i<n;i++){
        total += room[i];
    }
    int range_min = INT_MAX;
    for(int i=0;i<n;i++){ //gotta decide first room
        int range=0;
        int a =total;
        for(int j=0;j<n;j++){
            a= a-room[(i+j+n)%n];
            
            if(a=0) {
                break;}
            range += a;
        }
        range_min = min(range_min,range);
        
    }
    cout << range_min;
    return 0;
}