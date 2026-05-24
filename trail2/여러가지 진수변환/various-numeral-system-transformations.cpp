#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n ;
    cin >>n;
    int b;
    cin >> b;

    vector<int> digits;
    int cnt = 0;
    
    while (true) {
        if(n < b) {
            digits.push_back( n);
            break;
        }
    
        digits.push_back(n % b);
        cnt++;
        n /= b;
    }
    
    // print binary number
    for(int i = cnt ; i >= 0; i--)
        cout << digits[i];

        return 0;
}
