#include <iostream>
#include <climits>
using namespace std;
int n;
int ans = INT_MAX;
int power[11]; // 0
int cnt=0;
int ok =false;
void calculate(){
    ans =min(ans,cnt);
}
void jump(int x){
    if (x==n-1 ){
        //도착슨
        calculate();
        ok =true;
        return;
    }
    if(power[x]==0) return;
    for(int i=1;i<=power[x];i++){
        if(x+i <=n) {
            cnt++;
            jump(x+i);
        
        }
        else break;
        cnt--;
    }

}


int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> power[i];
    jump(0);//

    if(ok ==true) cout << ans;
    else cout <<-1;
    return 0;
}