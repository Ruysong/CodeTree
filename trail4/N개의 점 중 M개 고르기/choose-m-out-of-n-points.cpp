#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;

long long x[21];
long long y[21];

int selected[21];       // 선택한 점의 번호
long long ans = LLONG_MAX;


// 선택한 점들 사이의 거리를 확인하는 재귀
// a, b = selected 배열에서 비교할 두 위치
// maxDist = 현재 조합에서 지금까지 나온 최대 거리
void CalculateDistance(int a, int b, long long maxDist) {

    // 모든 점 쌍을 확인했음
    if (a == m - 1) {
        ans = min(ans, maxDist);
        return;
    }

    // a번 점과 비교할 점을 전부 확인했다면
    // 다음 기준점으로 넘어감
    if (b == m) {
        CalculateDistance(a + 1, a + 2, maxDist);
        return;
    }

    int point1 = selected[a];
    int point2 = selected[b];

    long long dx = x[point1] - x[point2];
    long long dy = y[point1] - y[point2];

    // 문제에서는 제곱근을 씌우지 않고 거리의 제곱을 사용
    long long dist = dx * dx + dy * dy;

    maxDist = max(maxDist, dist);

    // 같은 기준점 a와 다음 점을 비교
    CalculateDistance(a, b + 1, maxDist);
}


// N개의 점 중 M개를 선택하는 재귀
// start = 다음에 선택할 수 있는 점의 시작 번호
// cnt   = 지금까지 선택한 점 개수
void Choose(int start, int cnt) {

    // M개를 전부 선택했음
    if (cnt == m) {
        CalculateDistance(0, 1, 0);
        return;
    }

    for (int i = start; i < n; i++) {
        selected[cnt] = i;

        // 다음에는 i보다 뒤에 있는 점만 선택
        Choose(i + 1, cnt + 1);
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // 0번 점부터 살펴보고, 아직 선택한 점은 0개
    Choose(0, 0);

    cout << ans;

    return 0;
}