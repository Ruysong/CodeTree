#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    
    int n;
    string s;
    cin >> s;

    int num = 0;

    for (int i = 0; i < s.size(); i++) {
    num = num * 2 + (s[i] - '0'); //왜냐면 왜냐며ㅛㄴ.. s[i]는 문자니까.. 아스키코드상으로 숫자화 해준거임
}

    cout << num;
  


  return 0;
}
