#include <iostream>
using namespace std;

int n, m, d, s;

// 먹은 기록 D개
int eat_person[1001];
int eat_cheese[1001];
int eat_time[1001];

// 아픈 기록 S개
int sick_person[51];
int sick_time[51];

int main() {
    cin >> n >> m >> d >> s;
    for(int i = 0; i < d; i++) {
        cin >> eat_person[i] >> eat_cheese[i] >> eat_time[i];
    }
    for(int i = 0; i < s; i++) {
        cin >> sick_person[i] >> sick_time[i];
    }
    for(int cheese = 1; cheese <= m; cheese++) {
    // cheese번 치즈가 상했다고 가정

    /*치즈 1번이 상했다고 가정
→ 아픈 사람들이 아프기 전에 1번 치즈를 먹었는지 확인
→ 가능하면 1번 치즈 먹은 사람 수 세기

치즈 2번이 상했다고 가정
→ 똑같이 확인

...*/
}
   
   

    return 0;
}