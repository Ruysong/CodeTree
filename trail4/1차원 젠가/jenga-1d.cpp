#include <iostream>
#include <vector>
using namespace std;

int n;
int block[101]={};

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> block[i];
    }
    int s1,e1,s2,e2;// 첫번째 제거할 블럭번호,두번째 제버할 블럭번호.s부터 e까지
    cin >> s1>> e1;
    cin >> s2>> e2;
    s1--;
    s2--;
    e1--;
    e2--;
    int cnt =n;
    vector<int> arr1;
    vector<int> arr2;

    for(int i=0;i<cnt;i++){
        if( i >=s1 &&i <=e1) continue;
        arr1.push_back(block[i]);
       }
    cnt -= (e1-s1+1);

    for(int i=0;i<cnt;i++){
        if( i >=s2 &&i <=e2) continue;
        arr2.push_back(arr1[i]);
       }
    cnt -= (e2-s2+1);

cout << arr2.size() << '\n';
   for(int i = 0; i < arr2.size(); i++) {
    cout << arr2[i] << '\n';
}   



    return 0;
}