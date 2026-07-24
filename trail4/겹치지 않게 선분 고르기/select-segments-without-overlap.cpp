#include <iostream>
#include <algorithm>
using namespace std;

int n;
int leftL[20];
int rightL[20];
bool selected[20]={};
int ans=0;

void Calculate(){
    int line[1001]={0};
    int cnt=0; //몇개 선분 선택한건지 이번에
    for(int i=0;i < n;i++){
      if (!selected[i]) continue;

        cnt++;

        for (int j = leftL[i]; j <= rightL[i]; j++) {
             if (line[j] == 1) return;
                line[j] = 1;
            }

    }

    ans = max( ans,cnt);
}

void Choose(int x){
    //선분 x개 선택합시다. 
    if (x == n) {
    Calculate();
    return;
}   // n개에 대해서 모든 상태를 다 정해낸 상태

    
        
            selected[x] = true;   // x번 선분 선택
            Choose(x + 1);

            selected[x] = false;  // x번 선분 선택 안 함
            Choose(x + 1);
               
       

}

int main() {
    cin >> n;
    for(int i=0; i< n; i++){
        int a,b;
        cin >> a>>b;
        leftL[i]=a;
        rightL[i]=b;
    }

    Choose(0);

    cout <<ans;

    return 0;
}