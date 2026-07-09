#include <iostream>
using namespace std;

int main() {
    int x,y;
    cin >> x>>y;
    int ans=0;
    for(int i=x;i<=y;i++){
        int a,b,c,d,e;
        a =i/1000; // 1000의자리 근데 만까지 커버.
        b= (i%1000)/100; // 100의자리
        c =(i%100)/10; //10의자리.
        d = i %10; //1의자리
        ans = max(ans, a+b+c+d);
    }
    cout << ans;
    return 0;
}

/*
답지는 이렇게 
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
*/