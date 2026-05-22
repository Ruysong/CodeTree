#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Pos{
    public:
    int index;
    int x;
    int y;
    
    Pos(int index,int x,int y){
        this->index=index;
        this->x =x;
        this->y=y;
    }
};

bool cmp (Pos a, Pos b){
    if( abs(a.x)+abs(a.y) ==abs(b.x)+abs(b.y)) 
    return a.index < b.index;
    else return abs(a.x)+abs(a.y) <abs(b.x)+abs(b.y);
}

int main() {
    vector<Pos> u;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int a,b;
        cin >> a>> b;
        u.push_back(Pos(i+1,a,b));

    }

    sort(u.begin(),u.end(),cmp);

    for(int i=0;i<n;i++){

        cout << u[i].index <<endl;
    }



    return 0;
}