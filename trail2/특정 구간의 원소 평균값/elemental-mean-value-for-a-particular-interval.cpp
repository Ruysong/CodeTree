#include <iostream>
#include <algorithm>
using namespace std;

int n ;

int main() {
    cin >> n;
    int arr[100];
   for(int i =0;i<n;i++){
    cin >> arr[i];
   }
    int cnt=0;
    int max_sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++)
                sum += arr[k];
            
            for(int k = i; k <= j; k++){
            if(sum == (j-i+1) *arr[k] ) {cnt++;
            break;}
            }
        }
    
    cout << cnt;
    
    return 0;
}


