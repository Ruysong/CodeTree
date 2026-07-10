#include <iostream>
#include <climits>
using namespace std;
int t,a,b;

int main() {
    cin >> t>> a>>b;
    char pos[1004]={};
    int ans=0;

    for(int i=0;i<t;i++){
        char c;
        int p;
        cin>> c>>p;
        pos[p] = c;
    }

     for(int i = a; i <= b; i++) {
    int s_dist = INT_MAX;
    int n_dist = INT_MAX;

    for(int j = 0; j < 1000; j++) {
        int dist = abs(i - j);

        if(pos[j] == 'S') {
            s_dist = min(s_dist, dist);
        }
        else if(pos[j] == 'N') {
            n_dist = min(n_dist, dist);
        }
    }

    if(s_dist <= n_dist) ans++;
}
        cout <<ans;

    return 0;
}