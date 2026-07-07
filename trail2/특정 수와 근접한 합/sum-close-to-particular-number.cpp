#include <iostream>
#include <climits>
using namespace std;

int s,n;

int main() {
    cin >> n>>s;
    int num[100];
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int sum;
    int dif=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum=0;
            for(int k=0;k<n;k++){
            if( k==j || k==i) continue;
            sum += num[k];
        }
        dif = min(dif, abs(s-sum));
        
    }
    }
    cout << dif;
    return 0;
}