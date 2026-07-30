#include <iostream>
using namespace std;

int k,n;
int idx[10];


void choose(int x){
    if(x==n){
        for (int i = 0; i < n; i++) {
            cout << idx[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=k;i++){
          // 앞의 두 숫자가 현재 넣으려는 숫자와 같다면
        // 같은 숫자가 연속 3번 나오므로 선택하지 않음
        if (x >= 2 && idx[x - 1] == i && idx[x - 2] == i) {
            continue;
        }
         idx[x]=i;
        choose(x+1);
    }
}

int main() {
    cin >> k>>n;
    choose(0);//0번 인덱스 가보자구.


    return 0;
}