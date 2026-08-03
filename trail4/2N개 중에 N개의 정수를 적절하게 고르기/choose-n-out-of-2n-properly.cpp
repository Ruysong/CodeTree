#include <iostream>
#include <climits>
using namespace std;
int n;
int s[1001];
int n1[501];
int n2[502];
int ans=INT_MAX;
int sum1,sum2;

void diff() {
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < n; i++) {
        sum1 += n1[i];
        sum2 += n2[i];
    }

    ans = min(ans, abs(sum1 - sum2));
}

void choose(int x,int l1,int l2){
    if(x==2*n){
        diff();
        return;
    }
    if(l1<n){n1[l1]=s[x];
    
    choose(x+1,l1+1,l2);
    n1[l1]=0;}

    if(l2<n){n2[l2]=s[x];
    choose(x+1,l1,l2+1);
    n2[l2]=0;}
}

int main() {
    cin >>n;
    for(int i=0;i<2*n;i++) cin >> s[i];
    choose(0,0,0);//뭐 0번 인덱스부터 예를어디 넣을까나 이런거 아닌가.
    cout <<ans;
    return 0;
}