#include <iostream>
#include <vector>
using namespace std;

int n,m;
int grid[201][201];

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


int main() {
    cin >> n>>m;
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++)    {
        cin >> grid[i][j];
    }

     for(int i=0;i<m;i++)   { 
        int c;
        cin >>c;
        c--;
        int target;
        for(int j=0;j<n;j++){
            if(grid[j][c]!=0) {
                target =j;
                break;
            }
        }

        Bombing(target,c);
     }
    
  

    //print
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)    {
        cout << grid[i][j] << " ";
    }
    cout << '\n';
    }


    return 0;
}