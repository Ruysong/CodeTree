#include <iostream>
#include <string>
#include <climits>
using namespace std;

string s;
int n;

string ShiftRight(string s) {
    char temp =s[n-1];
    
    for(int i=n-1; i>=1;i--){
        s[i]= s[i-1];
    }
    s[0]=temp;

    return s;
}

int GetLength(string s) {
    int len=2;
    
    for(int i = 0; i < n-1; i++){
        if(s[i]!= s[i+1]) { len +=2;
        }

    }
    if (len ==2) len =3;

    return len;
}

int main() {
    cin >> s;
    n = s.length();

    int ans = INT_MAX;


    for(int i = 0; i < n; i++) {
       ans = min(ans, GetLength(s));
        s= ShiftRight(s);
    }

    cout << ans;

    return 0;
}