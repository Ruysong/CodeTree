#include <iostream>
#include <algorithm>
using namespace std;

int n;
int max_cnt = 0;
int pick[100][3]={};

int main() {
    cin >>n;
    
    for(int j=0;j<n; j++) {cin>> pick[j][0]>>pick[j][1]>>pick[j][2];
    pick[j][0]--;
    pick[j][1]--;
    pick[j][2]--;
    }
    for(int i = 0; i <= 2; i++) {
        int cup[3]={0};
        cup[i]=1;
        int cnt=0;
        for(int j=0;j<n; j++){
            int temp = cup[pick[j][0]];
            cup[pick[j][0]]=cup[pick[j][1]];
            cup[pick[j][1]]=temp;
            
            if(cup[pick[j][2]]==1) cnt++;
        }
        if(cnt > max_cnt){
            max_cnt= cnt;          

        }
        
    }
   
    cout << max_cnt ;
    
    return 0;
}

