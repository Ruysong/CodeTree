#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n,k;
    cin >> n>> k;


    vector<int> blocks(n + 1, 0);

    for(int i=1;i<=k;i++){
        int a,b;
        cin >> a>> b;
        for(int j=a;j<=b;j++){
            blocks[j]++; 
        }

    }

    int max = blocks[1];
    for(int i=1;i<=n;i++){
        if (blocks[i]> max) max = blocks[i];

    }
    cout << max;



    return 0;
}