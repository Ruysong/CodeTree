#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin >>n >>k;
    int candy[101]={0};
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        candy[b] =a;
    } //candy 좌표랑 개수 입력 받아.
    int max_sum =INT_MIN;
    for(int i=0;i<100-(2*k+1);i++){
        // i is central point
        int sum=0;
        for(int j=0;j < 2*k +1;j++){
            sum += candy[i+j];
        }
        max_sum = max(max_sum,sum);
    } 
    cout << max_sum;

    return 0;
}