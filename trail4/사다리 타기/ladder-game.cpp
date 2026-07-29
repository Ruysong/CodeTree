#include <iostream>
#include <algorithm>
using namespace std;

int n,m; //세로줄 n 가로줄 m
int lineA[16];  // 왼쪽부 세로줄 번호
int lineB[16];  // 높이
int target[12]; // 그 세로줄에서의 지금 내려오는 숫자
int answer = 16;
bool selected[16]; //choose할때 무슨 m개중에서 어떤거 선택할지


void Check(int cnt) {
    int result[12];

    for (int i = 1; i <= n; i++) {
        result[i] = i;
    }

    for (int h = 1; h <= 15; h++) {
        for (int i = 0; i < m; i++) {
            if (selected[i] && lineB[i] == h) {
                int a = lineA[i];
                swap(result[a], result[a + 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (result[i] != target[i])
            return;
    }

    answer = min(answer, cnt); // 타겟 (주어진 가로줄 쭉 내려온거)랑
    //  리절트 (지금 해낸거). 같으면 아하 이거구나. 숫자 최소화 찾자 .
}


void MakeTarget() {
    // 처음에는 각 번호가 자기 세로줄에 있음
    for (int i = 1; i <= n; i++) {
        target[i] = i;
    }

    // 위에서 아래로 가로줄 처리
    for (int h = 1; h <= 15; h++) {
        for (int i = 0; i < m; i++) {
            if (lineB[i] == h) {
                int a = lineA[i];

                swap(target[a], target[a + 1]);
            }
        }
    }
}



void Choose(int x, int cnt) {
    if (x == m) {
        // 선택된 가로줄로 사다리 실행
        Check(cnt); //몇개 선택한 상태로, 문제 결과랑 동일한지 실험
        return;
    }

    selected[x] = true;
    Choose(x + 1, cnt + 1);

    selected[x] = false;
    Choose(x + 1, cnt);
}





int main() {
  

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
    cin >> lineA[i] >> lineB[i];
    }
    
    MakeTarget();

    Choose(0, 0);

    cout << answer;

    return 0;
}