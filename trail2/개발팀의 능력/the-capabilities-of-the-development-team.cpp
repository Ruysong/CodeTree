#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int numbers[6];

int main() {
    for(int  i=0; i<5; i++) cin >> numbers[i];
    int sumA=0;
    for(int l = 0; l < 5; l++)   sumA += numbers[l];
    int min_diff=INT_MAX;
    for(int i = 0; i < 5; i++)
        for(int j = i + 1; j < 5; j++)
            for(int k=0; k<5; k++)
            for(int l=k+1; l<5; l++){
                 if(k == i || k == j || l == i || l == j) continue;
                int sum1 = numbers[i] + numbers[j];
                int sum2 = numbers[k] + numbers[l];
                int sum3 = sumA - sum1 -sum2;
                if(sum1 ==sum2 || sum2 == sum3 || sum3 == sum1) continue;
                int arr[3]= {sum1,sum2,sum3};
                sort(arr,arr+3);
                min_diff = min(min_diff, arr[2]-arr[0]);
            }


            
    if(min_diff==INT_MAX ) return -1;
    else cout << min_diff;
    
    return 0;
}
