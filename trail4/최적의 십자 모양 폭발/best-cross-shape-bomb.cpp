#include <iostream>
#include <vector>
using namespace std;

int n,m;
int grid[201][201];
int origin[201][201];

void DropColumn(int col) {
    vector <int> v;   
    for(int i=0;i<n;i++) {
        if(grid[i][col] != 0 ) {
            v.push_back(grid[i][col]); 
        }
    }

    for(int i=n-1;i>=0;i--) {
        if(v.empty()) grid[i][col] = 0;
        else {
        grid[i][col] = v.back();
        v.pop_back();
        }
        }
}

void Bombing(int r, int c){
    int boom_size = grid[r][c];
    for(int i=0;i<n;i++){
           if(abs(i-c) < boom_size) grid[r][i] =0;
    } 
    for(int i=0;i<n;i++){
           if(abs(i-r) < boom_size) grid[i][c] =0;
    } 
    
    for(int i=0;i<n;i++) { //i is column number
        DropColumn(i);
    }

}
int CountPairs() {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) continue;

            if(i + 1 < n && grid[i][j] == grid[i + 1][j]) cnt++;
            if(j + 1 < n && grid[i][j] == grid[i][j + 1]) cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++)    {
        cin >> origin[i][j];
    }
    int ans=0;

     for(int i=0;i<n;i++)   { 
        for(int j=0;j<n;j++){
                    for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                grid[a][b] = origin[a][b];
                            }
                        }
        Bombing(i,j);
         int pair_cnt = CountPairs();

        if(pair_cnt > ans) ans = pair_cnt;
        }
     }
    
  

   cout << ans;

    return 0;
}