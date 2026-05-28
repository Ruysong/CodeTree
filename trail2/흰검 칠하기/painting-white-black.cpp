#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin>> n;
    int pos[200002] = {0};
    int color[200002] ={0} ;  // 최종 색: 0, 1백 2검 3회
    int whiteCnt[200002] = {0}; // 흰색으로 칠해진 횟수
    int blackCnt[200002] ={0};// 검은색으로 칠해진 횟수


    int temp=100000;
    for(int i=0;i< n;i++){
        int a;
        char p;
        cin >> a>>p;
        if(p== 'R'){
            
            for(int j=temp;j<temp+a;j++){
                blackCnt[j]++;
               if (whiteCnt[j] >= 2 && blackCnt[j] >= 2 ) {color[j] =3;  
               
               continue;                        
            }   else {color[j]=2;
            }
            }
            temp += (a-1);
        
        }
        else if(p== 'L'){
            for(int j=temp;j >temp-a;j--){
                whiteCnt[j]++; 
             if (whiteCnt[j] >= 2 && blackCnt[j] >= 2 ) {color[j] =3;
               
               continue;                        
            }   else {color[j]=1;
            
            }
             }
            temp -= (a-1) ;

        }
    }
   int cntG=0;
   int cntW=0;
   int cntB=0;
   for(int x:color){
        if(x==3) cntG++;
        if(x==2)  cntB++;
        if(x==1) cntW++;
 

   }
   cout << cntW << " " << cntB << " " << cntG;
    return 0;
}