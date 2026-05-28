#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin>> n;
    int pos[2002] = {0};
    int temp=1000;
    for(int i=0;i< n;i++){
        int a;
        char p;
        cin >> a>>p;
        if(p== 'R'){
            for(int j=temp;j<temp+a;j++){
                pos[j]++;

            }
            temp += a;
        }
        else if(p== 'L'){
            for(int j=temp-1;j>=temp-a;j--){
                pos[j]++;
            
            }
            temp -=a;

        }
    }
    int cnt =0;
   for (int x : pos) {
    if (x >= 2) cnt++;
}

    cout << cnt;

    return 0;
}