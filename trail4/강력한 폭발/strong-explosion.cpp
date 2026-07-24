#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[21][21]={};
int bombX[401];
int bombY[401];
int bombCnt = 0;

int maxAnswer =0;
int bombType[401];// bomb타입 1,2,3 중에서 골라야 하니까. 

bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void Explode(){
    bool exploded[21][21]={}; 
    // 터진 범위에 대해서 넣을 것. 계산을 해줘야하니까. 
    for(int i=0;i < bombCnt ;i++){
        //i번 폭탄님에 대해서 이야기해봅시다.
           if(bombType[i]==1){
                for(int j=bombX[i] -2; j<=bombX[i] +2;j++){
                    if (InRange(j, bombY[i]))
                        exploded[j][bombY[i]] = 1;
                  
                }
           }
           else if(bombType[i]==2){
            for(int j=bombX[i] -1; j<=bombX[i] +1;j++){
                if (InRange(j, bombY[i]))
                    exploded[j][bombY[i]] = 1;               
                    
                }
            for(int k = bombY[i]-1;k<=bombY[i]+1;k++){
                if (InRange(bombX[i], k))
                    exploded[bombX[i]][k] = 1;
             
            }

           }
           else if(bombType[i]==3){
                exploded[bombX[i]][bombY[i]]= 1;
             for(int j=bombX[i] -1; j<=bombX[i] +1;j+=2){
                for(int k = bombY[i]-1;k<=bombY[i]+1;k+=2){
                    if (InRange(j, k))
                        exploded[j][k] = 1;
                }
                    
                }

           }
    }
            int cnt=0;
           for(int i=0;i < n;i++)
        for(int j=0; j<n; j++){
            if (exploded[i][j]==1) cnt++;
        }

         maxAnswer = max(maxAnswer, cnt);
           

            
    }



void Choose(int x){
    //x의 폭탑타입을 선택해보자
    if(x== bombCnt) {// 이건 터트려야함
        Explode();
        return;
    }

    for(int i=1;i<=3;i++){ 
        bombType[x] = i;
        Choose(x+1);
    }
}

int main() {
    cin >> n;

    for(int i=0;i < n;i++)
        for(int j=0; j<n; j++){
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                bombX[bombCnt] = i;
                bombY[bombCnt] = j;
                bombCnt++;
            }
            // 그리드에 1이 들어왔을떄만 그거에 대해 
            // 좌표 저장하고 폭탄 개수 추가. 
        }

    Choose(0);
    cout << maxAnswer;

    
    return 0;
}