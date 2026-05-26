#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>> n;
    vector<int> blocks(202,0);

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        // 겹치는 구간이 문제니까. 지점은 왼쪽끝은포함 오른쪽 끝은 제외해서 세면 딱 점세면 맞음 
        for(int j=a; j<b;j++){
            blocks[j+100]++;
        }

    }

    int ans = 0;
    for (int i = 0; i < 202; i++) {
    if (blocks[i] > ans) ans = blocks[i];
}

    cout<< ans;
    return 0;


}