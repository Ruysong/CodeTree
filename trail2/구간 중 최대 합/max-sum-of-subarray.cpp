#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n,k;
int arr[100];

int main() {
    
    cin >> n>> k;
    for(int i = 0; i <= n; i++) cin>> arr[i];
    int max_val = INT_MIN;
    for(int i = 0; i <= n - k; i++) {
        
        int sum=0;
        for(int j = i; j < i + k; j++)
            sum += arr[j];
    
        max_val = max(sum, max_val);
    }
    
    cout << max_val;
    
    return 0;
}


