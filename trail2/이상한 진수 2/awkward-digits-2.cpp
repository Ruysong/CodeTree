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
/*
답지: #include <iostream>
#include <climits>

using namespace std;

int main() {
    // 변수 선언 및 입력
    string binary;
    cin >> binary;
    
    // 각 i번째 자릿수를 바꾸었을 때의 십진수 값을 구해줍니다.
    int ans = INT_MIN;
    for(int i = 0; i < (int) binary.size(); i++) {
        // i번째 자릿수를 바꿉니다.
        binary[i] = '0' + '1' - binary[i];
        // 십진수로 변환합니다.
        int num = 0;
        for(int j = 0; j < (int) binary.size(); j++)
            num = num * 2 + (binary[j] - '0');
        
        // 가능한 십진수 값 중 최댓값을 구해줍니다.
        ans = max(ans, num);
        
        // i번째 자릿수를 원래대로 돌려놓습니다.
        binary[i] = '0' + '1' - binary[i];
    }
    
    // 출력
    cout << ans;
    
    return 0;
}

*/