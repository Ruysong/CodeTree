#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t;
    cin>> t;
    vector<int> v;

    for(int i=0; i<n ; i++){
        int a;
        cin >> a;
        v.push_back(a);
  }

    int max=0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
    if(  v[i] > t  )
        cnt++;
    if( v[i]<= t) cnt=0;
    if(cnt> max) max =cnt;
    
    
    }
cout << max;

    return 0;
}