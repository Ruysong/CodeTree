#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin>> n;
    int pos[200002] = {0};
    int color[200002] ={0} ;  // 최종 색: 0회색 1검으색 2흰색


    int temp=100000;
    for(int i=0;i< n;i++){
        int a;
        char p;
        cin >> a>>p;
        if(p== 'R'){
            
            for(int j=temp;j<temp+a;j++){
                color[j]=1;
            }
            temp += (a-1);
        
        }
        else if(p== 'L'){
            for(int j=temp;j >temp-a;j--){
               color[j]=2;
             }
            temp -= (a-1) ;

        }
    }
   int cntG=0;
   int cntW=0;
   int cntB=0;
   for(int x:color){
        if(x==0) cntG++;
        if(x==1)  cntB++;
        if(x==2) cntW++;
 

   }
   cout << cntW << " " << cntB ;
    return 0;
}