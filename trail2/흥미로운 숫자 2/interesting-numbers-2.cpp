#include <iostream>
using namespace std;
int x,y;
int Interest(int a){
    int num[10]={0}; //0부터 9까지
    int digit=0;
    while(a>0){
        num[a%10] += 1;
        a /=10;
        digit++;
    }
   for(int i=0;i<10;i++){
        if(num[i]==(digit-1)) return 1;

   }
    return 0;
}
int main() {
    cin >> x >>y;
    int cnt=0;
    for(int i=x;i<=y;i++){
        cnt += Interest(i);

    }    
    cout <<cnt;
    return 0;
}