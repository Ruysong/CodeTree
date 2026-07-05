#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;
    int tall[100];
    for(int i=0;i<n;i++){
        cin >> tall[i];
    }
    int cnt=0;
    for(int i=0;i< n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1; k<n;k++){
                if(tall[i] <= tall[j] && tall[j] <= tall[k]) cnt++;
            }

        }
    }
    cout << cnt;
    return 0;
}