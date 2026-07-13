#include <iostream>
using namespace std;

int n,t;
int segments[3][201]={};

int main() {
    cin >> n>>t;

    for(int j=0;j<3; j++){
    for(int i=0;i<n;i++){        
            cin >> segments[j][i];
        }
    }

    for(int i=0;i<t;i++){
        int temp = segments[2][n-1];
        for(int k=2;k >=0;k--){
        for(int j=n-1;j>=1;j--)
        segments[k][j] =segments[k][j-1];

        if(k!= 0) segments[k][0] = segments[k-1][n-1];
     
        

    }segments[0][0] = temp;
    }

    for(int j=0;j< 3; j++){
     for(int i=0;i<n;i++){        
            cout << segments[j][i] << " ";
        }
        cout << '\n';
    }

    



    return 0;
}