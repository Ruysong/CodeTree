#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt;
vector<int> ans;

bool IsBeautiful() {
    // ans가 아름다운 수인지 검사.n자리수
    int i=0;
     while (i < n) {
        int num = ans[i]; //하나하나 자리 확인할겁니다.

       if( num +i >n ) return false;
       //왜냐면 거의 끝자락이라서.. 자리 부족

       for(int j=i;j<i+num;j++){
        //지금 자리부터 전부 num개인지 확인
                if (ans[j] != num)
                      return false;
       }

        i += num; //이번 묶음은 세이프, 다음묶음으로. 
    }

    return true;

}
void Choose(int x){
    if (x == n) {
        if (IsBeautiful()) cnt++;
        return;
    }

    for(int i=1;i<4; i++){
         ans.push_back(i);
        Choose(x + 1);
        ans.pop_back();
    }


}

int main() {
    cin >>n;

    Choose(0);

    cout << cnt;
    return 0;
}