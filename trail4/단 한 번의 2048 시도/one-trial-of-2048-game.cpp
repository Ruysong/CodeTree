#include <iostream>
using namespace std;

int grid[4][4];
char dir;   

void ProcessLine(int arr[4]){
    int temp[4]={0};
    int cnt=0;
    for(int i=0;i<4;i++){
        if(arr[i]!=0) {
            temp[cnt] = arr[i];
            cnt++;           
    }
    arr[i]=0;
}        // 왼쪽으로 다 몰았음.

    for(int i=0;i<3;i++){
        if(temp[i]==temp[i+1]) {
            temp[i] += temp[i+1];
            temp[i+1]=0;
   }
}   
    //이제 다시 왼쪽 몰기
    cnt = 0;
    for(int i=0;i<4;i++){
        if(temp[i]!=0) {
            arr[cnt] = temp[i];
            cnt++;
    }
}  
}

void MoveTo(char dir){
    if(dir == 'L'){
        for(int i=0;i <4;i++){        
           ProcessLine(grid[i]);    
        }
    }
    else if(dir == 'R'){
        for(int i = 0; i < 4; i++){
            int arr[4];

            for(int j = 0; j < 4; j++){
                arr[j] = grid[i][3 - j];
            }

            ProcessLine(arr);

            for(int j = 0; j < 4; j++){
                grid[i][3 - j] = arr[j];
            }
        }
    }
    else if(dir == 'U'){
        for(int j = 0; j < 4; j++){
            int arr[4];

            for(int i = 0; i < 4; i++){
                arr[i] = grid[i][j];
            }

            ProcessLine(arr);

            for(int i = 0; i < 4; i++){
                grid[i][j] = arr[i];
            }
        }
    }

    else if(dir == 'D'){
        for(int j = 0; j < 4; j++){
            int arr[4];

            for(int i = 0; i < 4; i++){
                arr[i] = grid[3 - i][j];
            }

            ProcessLine(arr);

            for(int i = 0; i < 4; i++){
                grid[3 - i][j] = arr[i];
            }
        }
    }
}




int main() {
    for(int i=0;i <4;i++)
        for(int j=0; j<4;j++) cin >> grid[i][j];

    cin >>dir;

    MoveTo(dir);

    for(int i=0;i <4;i++){
        for(int j=0; j<4;j++) cout << grid[i][j] << " ";
        cout << "\n";
        }
    return 0;
}