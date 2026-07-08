#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >>n>>m;
    int a[100],b[100];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(b,b+m);
    int ans =0;

    for(int i=0;i<= n-m;i++){
        int temp[100];
        for(int j = i; j < i+m; j++) {
            temp[j] = a[j];
        } //일단 템프에 이번 거 넣어놓고.
        sort(temp+i, temp +i + m);
        bool same =1;//정렬하고, 온오프 정해서 준비

        for(int k=0;k<m;k++){
             if(temp[i+k] != b[k]) {
                same = false;
                break;
            }
       } //냅다 비교. 이번 j위치 신경썻고. 내쪼대로 비교

        if(same) {
            ans++;
        }
    }
    

    cout << ans;


    return 0;
}