#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, p, T;
    cin >> n >> k >> p >> T;

    vector<int> infected(n + 1, 0); // 감염 여부
    vector<int> spread(n + 1, k);   // 각 사람이 남은 전염 가능 횟수

    infected[p] = 1; // 처음 감염자

    vector<vector<int>> handshakes; //악수해보자구

    for (int i = 0; i < T; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        handshakes.push_back({t, x, y}); 
    }

    // 시간순 정렬
    sort(handshakes.begin(), handshakes.end());

    for (int i = 0; i < T; i++) {
        int t = handshakes[i][0];
        int x = handshakes[i][1];
        int y = handshakes[i][2];
       
      if((infected[x] == 1 && infected[y]==1 ) &&(spread[x]>0 ||spread[y]>0) ){
          infected[x] = 1 ;
          infected[y]=1;
          if (spread[x]>0) spread[x]--;
          if (spread[y]>0) spread[y]--;
      }

      else if((infected[x] == 1 && spread[x]>0 ) && infected[y]!=1 ){
         
          infected[y]=1;
          spread[x]--;
        
        }  
      else if((infected[y] == 1 && spread[y]>0 ) && infected[x]!=1 ){
          infected[x] = 1 ;
          
          spread[y]--;
        
        }
    }
     

    // 최종 감염 여부 출력
    for (int i = 1; i <= n; i++) {
        cout << infected[i];
    }

    return 0;
}