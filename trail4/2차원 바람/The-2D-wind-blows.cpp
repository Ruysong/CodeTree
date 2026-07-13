#include <iostream>
using namespace std;

int n, m, q;
int grid[101][101];

int InRange(int x,int y){
    return (x >=0 && x<n) && (y >=0 && y<m);
}

void Shift(int r1,int c1,int r2,int  c2){
    int temp1 = grid[r1][c2];
    int temp2 = grid[r2][c2];
    int temp3 = grid[r2][c1];
    for(int i=c2; i> c1; i--){
        grid[r1][i] =grid[r1][i-1];
    } //upper bound shift

    
    for(int i=r2; i> r1+1; i--){
        grid[i][c2] =grid[i-1][c2];
    }
    grid[r1+1][c2] =temp1;

    
    for(int i=c1; i < c2 ; i++){
        grid[r2][i] =grid[r2][i+1];
    }
    grid[r2][c2-1] =temp2;

    
    for(int i=r1; i < r2-1 ; i++){
        grid[i][c1] =grid[i+1][c1];
    }
    grid[r2-1][c1] =temp3;
}

void Mean_Cell(int r1,int c1,int r2,int  c2){
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            int a=0,b=0,c=0,d=0;
            if(InRange(i-1,j)) a=grid[i-1][j];
            if(InRange(i-1,j)) a=grid[i-1][j];
            grid[i][j] = 
        }
    }
    

}

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int qi = 0; qi < q; qi++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        r1--;
        c1--;
        r2--;
        c2--;       // 행이 우리는 0부터 시작이니까..
        Shift(r1, c1, r2, c2);
        Mean_Cell(r1, c1, r2, c2);

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}