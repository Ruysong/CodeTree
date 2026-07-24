#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> answer;

void Choose(int cnt){

   if (cnt == n) { // 이제 자릿수가 다찼다면.
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return;
}

    //원래는
    for(int i=1;i<=k;i++)
    {
        answer.push_back(i);

        Choose(cnt+1);

        answer.pop_back();
    }


}
int main() {
    cin >> k>>n;

    Choose(0);

    return 0;
}