#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[81];
bool found = false;
int determine(int x){

    //subsequence의 길이를 1부터 n/2까지 잡을 수 있겟고..
    int ok=true;
    for(int len=1;len<=n/2;len++){
        for (int i = 0; i + 2 * len <= x; i++){
            int cnt=0;
           for(int j=0;j<len;j++){ 
            if(i+len+j > n) continue;
            if( arr[i+j] ==arr[i+len+j]) cnt++;
           }
           if(cnt==len) {ok =false; break;}
    }
    }
    if (ok ==true&& x==n){
        for(int i=0;i<n;i++)
        cout << arr[i];
        found = true;
        return 0;
    }
    return ok;
}

void makeS(int x){ //일단 뭐.. 수열 만듭시다. 

    if (found) return;
    if(x==n){ //길이 n짜리 수열 
        determine(x);
        return;
    }
    for(int i=4;i<=6;i++){
        arr[x]=i;
        if(determine(x+1))
        makeS(x+1);
        if(found) return;

    }

}

int main() {
    cin >> n;

    makeS(0);
    return 0;
}