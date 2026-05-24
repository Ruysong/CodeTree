#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    
   
    string s;
    cin >> s;

    int num = 0;

    for (int i = 0; i < s.size(); i++) {
    num = num * 2 + (s[i] - '0'); //왜냐면 왜냐며ㅛㄴ.. s[i]는 문자니까.. 아스키코드상으로 숫자화 해준거임
}

    num = num*17;

  vector<int> digits;
    while(true){
        if(num <2) {digits.push_back(num);
        
        break;
        }

        digits.push_back(num%2);
        num /=2;
        
    }
    for(int i= digits.size()-1; i>=0;i--){
      cout << digits[i];

    }


  return 0;
}
