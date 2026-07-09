#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pos[100][2]={};
    for(int i=0;i<n;i++) cin >> pos[i][0] >> pos[i][1]; //( pos[i][0],0)(pos[i][1],1)
    int ans=0; //겹치지 않아야함. 맞지. intact한 친구들 찾기. 
    for(int i = 0; i < n; i++){ 
    bool crossed = false;

    for(int j = 0; j < n; j++){
        if(i == j) continue;

        if(pos[i][0] < pos[j][0] && pos[i][1] > pos[j][1])
            crossed = true;

        if(pos[i][0] > pos[j][0] && pos[i][1] < pos[j][1])
            crossed = true;
    }

    if(!crossed) ans++;
}
    cout << ans;
    return 0;
}