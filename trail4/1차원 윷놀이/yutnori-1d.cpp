#include <iostream>
#include <climits>
using namespace std;

int n,m,k; //k마리의 말.. n번의 선택 m에 도착
int movePower[13]; //참 나스러운.. 이게 매 그 횟수에 몇칸 가는지 .  
int pos[5]; //말 위치
int ans = INT_MIN;
void calculate(){
    int cnt=0;
    for(int i=0;i<k;i++){
        if (pos[i]==m) cnt++;
    }
    ans = max(ans, cnt);
}
void choose(int x){
    if(x==n){
        calculate();
        return;
    }

    for(int i=0;i <k;i++){
        int temp= pos[i];
        pos[i] += movePower[x];
        if(pos[i]>=m) pos[i]=m;
        choose(x+1);
        pos[i] =temp;
    }
}

int main() {
    cin >> n>>m>>k;
    for(int i=0;i<n;i++){
        cin >> movePower[i];
    }
    for (int i = 0; i < k; i++) {
    pos[i] = 1;
}
    choose(0);// 0번 인덱스부터 n번까지 선택

    cout << ans;
    return 0;
}







