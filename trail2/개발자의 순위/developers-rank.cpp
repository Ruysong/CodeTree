#include <iostream>
using namespace std;

int k, n;
int pos[11][21]; 
// pos[경기번호][개발자번호] = 그 경기에서의 순위

int main() {
    cin >> k >> n;
    for(int game = 0; game < k; game++) {
        for(int rank = 1; rank <= n; rank++) {
            int dev;
            cin >> dev;

            pos[game][dev] = rank;
        }
    }
    int ans = 0;
   for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++){
            int cnt =0;
            if (i==j) continue;
            for(int game = 0; game < k; game++){
                if( pos[game][i] <  pos[game][j]) cnt++;
            }
            if(cnt ==k) ans++;

        }

    cout << ans;

    return 0;
}