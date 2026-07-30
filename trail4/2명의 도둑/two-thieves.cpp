#include <iostream>
#include <algorithm>
using namespace std;

int n,m,c;
int grid[11][11]={};
int ans=0;

void Calculate();

int InRagne(int x, int y){
    return x>=0 && x<n &&y >=0 && y<n;
}

//도둑정보 저장할건 지금 어디서 시작인지
int thief_X[2];
int thief_Y[2];

void Choose(int x){
    if(x==2){
        //둘다 선택되면 이제 계산하는거잖아? 
        if(thief_X[0]==thief_X[1] 
        && abs(thief_Y[0] - thief_Y[1]) <m
         ) return;
        
        Calculate();
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-m;j++){

           thief_X[x] =i;
           thief_Y[x] = j;
            Choose(x+1);
        }
    }
}

// thief번 도둑이 고른 M칸 안에서
// idx번째 물건을 지금 고를지 말지 결정하는 함수
int SelectItem(int thief, int idx, int weightSum, int valueSum) {
    // 이미 무게 제한 C를 넘었으면 이 선택은 실패
    // 뒤에 뭘 더 골라도 무게가 줄어들진 않으니까 바로 끝
    if (weightSum > c)
        return 0;

    // M개 물건을 전부 확인했음
    // 지금까지 만든 가치 합을 결과로 돌려줌(완뇨)
    if (idx == m)
        return valueSum;

    // 현재 보고 있는 물건의 무게
    // 도둑의 시작 열에서 idx만큼 오른쪽에 있는 물건
    int w = grid[thief_X[thief]][thief_Y[thief] + idx];

    // 현재 물건을 가져가는 경우
    // 무게에는 w를 더하고
    // 가치에는 w의 제곱을 더함
    int take = SelectItem(
        thief,
        idx + 1,
        weightSum + w,
        valueSum + w * w
    );

    // 현재 물건을 안 가져가는 경우
    // 무게와 가치는 그대로 두고 다음 물건으로 감
    int skip = SelectItem(
        thief,
        idx + 1,
        weightSum,
        valueSum
    );

    // 가져간 경우와 안 가져간 경우 중
    // 더 큰 가치를 선택
    return max(take, skip);
}

void Calculate() {

    // 0번 도둑이 자기 M칸 안에서 만들 수 있는 최대 가치
    int value1 = SelectItem(0, 0, 0, 0);

    // 1번 도둑이 자기 M칸 안에서 만들 수 있는 최대 가치
    int value2 = SelectItem(1, 0, 0, 0);

    // 이번 두 구간에서 얻은 가치 합과
    // 지금까지의 전체 최고값을 비교
    ans = max(ans, value1 + value2);
}

int main() {
    cin >> n>> m>>c;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin >> grid[i][j];

    Choose(0); //0이라는건 아무도 지금 도둑선택안됨.
    cout << ans;
    return 0;
}