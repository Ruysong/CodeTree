#include <iostream>
using namespace std;

int n,t;
int segments[2][200]={};

int main() {
    cin >> n>>t;

    for(int j=0;j< 2; j++){
    for(int i=0;i<n;i++){        
            cin >> segments[j][i];
        }
    }

    for(int i=0;i<t;i++){
        int temp = segments[1][n-1];
        for(int j=n-1;j>=1;j--)
        segments[1][j] =segments[1][j-1];

        segments[1][0] = segments[0][n-1];

        for(int j=n-1;j>=1;j--)
        segments[0][j] =segments[0][j-1];

        segments[0][0] = temp;

    }
    for(int j=0;j< 2; j++){
     for(int i=0;i<n;i++){        
            cout << segments[j][i] << " ";
        }
        cout << '\n';
    }

    



    return 0;
}