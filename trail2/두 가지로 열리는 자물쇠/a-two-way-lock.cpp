#include <iostream>
using namespace std;

int n; 

bool Close(int x, int target) { // 타겟이 주어지는 조합.
    for(int d = -2; d <= 2; d++) {
        int num = target + d;

        if(num < 1) num += n;
        if(num > n) num -= n;

        if(x == num) return true;
    }

    return false;
}

int main() {

    cin  >> n;
    int a1,b1,c1;
    cin >> a1>>b1>>c1;
    int a2,b2,c2;
    cin >> a2>>b2>>c2;

    int cnt=0;
    for(int i=1;i <=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n ; k++){ // i j k의 조합.
               if(
                (Close(i, a1) && Close(j, b1) && Close(k, c1))
                ||
                (Close(i, a2) && Close(j, b2) && Close(k, c2)))
                  { cnt++;}

            }
        }
    }
    cout << cnt;
    return 0;
}