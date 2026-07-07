#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt =0;
    for(int i=0; i< s.length()-2; i++){
        for(int j=i+2; j< s.length()-1;j++){
        bool openPair = (s[i] == '(' && s[i + 1] == '(');
        bool closePair = (s[j] == ')' && s[j + 1] == ')');

            if(openPair && closePair) {
                    cnt++;
}
        }
    }
    cout << cnt;
    return 0;
}