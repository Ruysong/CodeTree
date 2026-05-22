#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
class Pos{
    public:

    int bf;
    int af;
        Pos(int a,int b){
            this->bf =a;
            this->af =b;
                    }
};
int main() {
    int n;
    cin >> n;
    vector<Pos> v;

    for (int i=0; i< n; i++){
        int a;

        cin >>a ;
        v.push_back(Pos(i,a));


    }
   sort(v.begin(), v.end(), [](Pos a, Pos b){
    if (a.af == b.af) return a.bf < b.bf;
    return a.af < b.af;
});
    int ans[10001];
    for(int i =0; i< n; i++){
        ans[v[i].bf]= i+1;
       
           }
    for(int i=0;i<n;i++){

     cout << ans[i] << " ";
    }

    return 0;
}