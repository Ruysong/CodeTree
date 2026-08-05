#include <iostream>
#include <algorithm>
using namespace std;

int n;
int visited[9]={0};
int s[9];
int ans[9];
void print(){   
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
            }
    cout<< '\n';
}

void choose(int x){
    if(x==n+1){
        print();

        return;
    }
    for(int i=n;i>=1;i--){
        if(visited[i]) continue;
        else {
            ans[x]=s[i];
            visited[i]=1;
            choose(x+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i=1;i<=n;i++) s[i]=i;
    
    choose(1);//0번째 자리부터. 
    
    return 0;
}
