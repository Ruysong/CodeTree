#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> bombs;  


bool Bombing(){ 
    vector<int> temps; /*원본 bombs는 읽기만 한다
        살아남는 애들만 temps에 담는다
        마지막에 bombs = temps*/
    bool exploded = false;

    for(int i = 0; i < bombs.size(); ) { //독특함. 왜냐면 이게 덩어리째로 보는거라서.
        int cnt = 1;

        while(i + cnt < bombs.size() && bombs[i] == bombs[i + cnt]) {
            cnt++;
        }

        if(cnt >= m) {
            exploded = true;
        }
        else { // 살아났았으니까 너네는 temps에 들어가
            for(int j = 0; j < cnt; j++) {
                temps.push_back(bombs[i]);
            }
        }

        i += cnt;  //i는 여기서 컨트롤 해줄거임
    }

    bombs = temps;  // 벡터 최고 장점. 걍 새로운 템스를 샥 덮어주면 이쁘게 다 덮임

    return exploded;
}


int main() {
    cin >> n >> m;
     for(int i = 0; i < n; i++) { int x; cin >> x;
        bombs.push_back(x);
    }


    while( Bombing()) {}


    //print
   cout << bombs.size() << '\n';

    for(int i = 0; i < bombs.size(); i++) {
        cout << bombs[i] << '\n';
    }


    return 0;
}