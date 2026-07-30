#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

string expression;              // 입력받은 식
int ans = INT_MIN;              // 지금까지 나온 계산 결과 중 최댓값
int alphabetValue[6];           // a~f에 넣은 숫자
void calculate();

void choose(int x) {
    if (x == 6) {               // a~f의 값을 전부 정했음
        calculate();
        return;
    }

    for (int i = 1; i <= 4; i++) {
        alphabetValue[x] = i;   // 현재 알파벳에 1~4 중 하나 넣기
        choose(x + 1);          // 다음 알파벳 정하러 가기
    }
}

void calculate() {
    // 식의 첫 알파벳 값으로 계산 시작
    int result = alphabetValue[expression[0] - 'a'];

    // 연산자는 1, 3, 5... 위치에 있음
    for (int i = 1; i < expression.size(); i += 2) {
        char op = expression[i];

        // 연산자 바로 다음 알파벳의 값
        int nextValue = alphabetValue[expression[i + 1] - 'a'];

        // 모든 연산은 왼쪽부터 바로 계산
        if (op == '+')
            result += nextValue;
        else if (op == '-')
            result -= nextValue;
        else if (op == '*')
            result *= nextValue;
    }

    // 이번 알파벳 조합으로 나온 결과와 최댓값 비교
    ans = max(ans, result);
}

int main() {
    cin >> expression;

    // a부터 f까지 각각 어떤 숫자를 넣을지 전부 정함
    choose(0);

    cout << ans;

    return 0;
}