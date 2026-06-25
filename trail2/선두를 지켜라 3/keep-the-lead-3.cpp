#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin >> n>>m;
    vector<int> a,b;
        a.push_back(0);
        b.push_back(0);

 
    for(int i=0;i< n;i++){
        int v,t;
        cin>> v>>t;

        for(int j=0;j<t;j++){
            a.push_back(a.back() + v);


        }

    }
    
    for(int i=0;i< m;i++){
        int v,t;
        cin>> v>>t;

        for(int j=0;j<t;j++){
            b.push_back(b.back() + v);


        }

    }

    while(a.size() < b.size()){
            a.push_back(a.back());
    }
    while(a.size() > b.size()){
            b.push_back(b.back());
    }
    int cnt =0;
    vector<int> winner(a.size());// a win  0, b win 1, boti 2
    winner[0] = 2;
    for(int i=1;i< a.size(); i++){
        if(a[i] > b[i]) winner[i]=0;
        else if(a[i]<b[i]) winner[i]=1;
        else if(a[i]==b[i]) winner[i]=2;

        if(winner[i-1] != winner[i]) cnt++;




    }

    cout << cnt;


    return 0;
}