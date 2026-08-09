#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> graph[1001];
bool visited[1001];

void dfs(int x){
    visited[x]=1;
    
    for(int i=0;i< graph[x].size();i++){
        int next = graph[x][i]; //지금에 연결된 애들 작은거부터

        if(visited[next]==0){
            dfs(next);
        }
    }
}

int main() {
    cin >>n>>m;

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
            }
    dfs(1); //1부터

    int cnt=0;

for (int i = 2; i <= n; i++) {
        if (visited[i] == true) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}