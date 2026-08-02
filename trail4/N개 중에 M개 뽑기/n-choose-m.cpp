#include <iostream>
using namespace std;
int n,m;
int arr[11];

void print(){
    for(int i=0;i<m;i++){
        cout << arr[i] << " " ;
            }
            cout << '\n';
}

void choose(int x){
    if(x==m){
        print();
        return;
    }
   for(int i=1;i<=n;i++){
        arr[x]=i;
        if( x==0 || (x>=1 && arr[x-1]<arr[x]))
        choose(x+1);
        else continue;
  }
}


int main() {
    cin >>n>>m;

    choose(0); // 0부터 m개 골라야지?
    
    
    return 0;

}