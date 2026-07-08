#include <iostream>
using namespace std;


int main() {
    int n;
    int question[11];
    int cnt1[11];
    int cnt2[11];
    cin >> n;
    for(int i = 0; i < n; i++) {
    cin >> question[i] >> cnt1[i] >> cnt2[i];
}      
    int ans=0;
    for(int a = 1; a <= 9; a++) {
    for(int b = 1; b <= 9; b++) {
        for(int c = 1; c <= 9; c++) {
            
            if(a == b || b == c || a == c) continue;
            int ct = 0;
            for(int i=0;i<n;i++){
                int p,q,r;
                p= question[i] /100; 
               q = question[i] / 10 % 10;
                r= question[i] %10;
                int one = 0;

                if(p == a) one++;
                if(q == b) one++;
                if(r == c) one++;

                int two = 0;

                if(p != a && (p == b || p == c)) two++;
                if(q != b && (q == a || q == c)) two++;
                if(r != c && (r == a || r == b)) two++;
                if(one == cnt1[i] && two == cnt2[i]) {
                ct++;
                
    }          


            } if(ct ==n) ans++;


        }
    }
}
    cout << ans;
    return 0;
}
