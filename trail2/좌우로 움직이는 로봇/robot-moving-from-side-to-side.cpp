#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>> n>>m;
    vector<int> a,b;
   a.push_back(0);
   b.push_back(0);
    int curA=0,curB=0;

    for(int i=0;i<n;i++){
        int t;
        char d;
        cin >> t>>d;
        for(int j=0;j<t;j++){
            
            if (d=='R'){
                curA++;
            a.push_back(curA);
            }

            if (d=='L'){
                curA--;
                a.push_back(curA);
                           }

        }
       
       
          }

          for(int i=0;i<m;i++){
        int t;
        char d;
        cin >> t>>d;
        for(int j=0;j<t;j++){
            
                if (d=='R'){
                curB++;
            b.push_back(curB);
            }

            if (d=='L'){
                curB--;
                b.push_back(curB);
                           }

        }
       
       
          }
          
      int maxtime = max(a.size(), b.size());

      while (a.size() < b.size()) {
     a.push_back(a.back());
}

        while (b.size() < a.size()) {
        b.push_back(b.back());
}

        int cnt=0;
        for( int j=1;j<maxtime;j++){
            
        if(a[j] == b[j] && a[j-1] != b[j-1]) cnt++;

      }
      
    cout << cnt;




   return 0;
}