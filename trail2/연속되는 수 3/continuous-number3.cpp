#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;

    for(int i=0; i<n ; i++){
        int a;
        cin >> a;
        v.push_back(a);

        
    }
    int max=0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
    if(i == 0 || v[i] * v[i - 1] >0)
        cnt++;
    if(v[i] * v[i - 1] <0 ) cnt=1;
    if(cnt> max) max =cnt;
    
    
    }
cout << max;

    return 0;
}