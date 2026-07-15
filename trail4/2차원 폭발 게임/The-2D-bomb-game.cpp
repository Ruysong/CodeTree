#include <iostream>
using namespace std;

int n ,m,k;
int grid[101][101];

int temp[101][101];

void ProcessLine(int arr[]){ //왼쪽으로 몰아드림
    int temp[101]={0};
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0) {
            temp[cnt] = arr[i];
            cnt++;           
    }
    arr[i]=0;
}         
    cnt = 0;
    for(int i=0;i<n;i++){
        if(temp[i]!=0) {
            arr[cnt] = temp[i];
            cnt++;
    }
}  
}

void ColumnDrop(){
        
        for(int j = 0; j < n; j++){
            int arr[101];
            for(int i = 0; i < n; i++){
                arr[i] = grid[n - i-1][j];
            }

            ProcessLine(arr);
            for(int i = 0; i < n; i++){
                grid[n - i-1][j] = arr[i];
            }
        
    }
}

bool Bombing(){
    int exploded =false;
    bool boom[101][101]={};
    // 1. 터질 칸을 표시한다  . boom에 지금 안터지는 애들 뺴고 터진 애들 0으로 넣음.
     for(int i=0;i <n;i++){ // 0열부터 ~
        for(int j=0; j<n;){
            if(grid[j][i] == 0) { 
                j++;
                continue;
}

            int cnt=1;
            while( ((j+cnt) < n )
                && grid[j][i] == grid[j+cnt][i]){
                
                cnt++;
            }

            if( cnt >= m ) {
                for(int s=j;s< j+cnt;s++){
                    exploded = true;
                    boom[s][i] = 1; // 2. 표시된 칸을 1으로 만든다
                    
                            }
             j += cnt;
            }
            else {
                j += cnt;
            }
        }
         }  
        for(int i=0;i <n;i++)
        for(int j=0; j<n;j++){
             if(boom[i][j]) grid[i][j] = 0;
        }
        


    // 3. ColumnDrop() 한다
    ColumnDrop();
    // 4. 하나라도 터졌으면 true, 없으면 false
    return exploded;
}

void RotateToRight(){
    int temp[101][101];
     for(int i=0;i <n;i++)
        for(int j=0; j<n;j++){
            temp[j][i] = grid[n-1-i][j];
        }
    for(int i=0;i <n;i++)
        for(int j=0; j<n;j++){
            grid[j][i] =temp[j][i] ;
        }

        ColumnDrop();
}


int main() {
    cin >> n>>m>>k;
    for(int i=0;i <n;i++)
        for(int j=0; j<n;j++) cin >> grid[i][j];

    for(int i=0;i <k;i++){
        while(Bombing()){} 
        RotateToRight();
        
    }
    while(Bombing()) {}

   

   int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] != 0) ans++;
        }
    } 

    cout << ans;
    return 0;
}