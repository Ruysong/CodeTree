#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    string a; 
    cin >> a; // 이건 2진수. 맨앞 0아님.
    int cnt =1;
    int a_num=0;
    for(int i=a.length() -1 ;i >=0;i--){
        a_num += (a[i] - '0')*cnt;
        cnt *=2;
    }
    int m = a_num;
    int now_num=0;
    for (int i=0;i<a.length();i++){
        if(a[i] =='0'){
            a[i]='1';
            int cnt =1;
        for(int j=a.length() -1 ;j >=0;j--){
        now_num += (a[j] - '0')*cnt;
        cnt *=2;
        }   
    a_num =now_num; 
    break;
        }
            
    }
    if(a_num == m ) a_num -=1;

    cout << a_num;
    return 0;
}