#include <iostream>
#include <algorithm>
using namespace std;

int n ;

int main() {
    cin >> n;
    int arr[100];
    for(int &x: arr){
        cin >> x;
    }
    int cnt=0;
    int max_sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            int mean_val = 0;
            for(int k = i; k <= j; k++)
                mean_val += arr[k];
            mean_val  /= (j-i+1);
            for(int k = i; k <= j; k++)
            if(mean_val == arr[k]) cnt++;
        }
    
    cout << cnt;
    
    return 0;
}


