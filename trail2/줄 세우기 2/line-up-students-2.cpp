#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class User{
    public:
    int number;
    int height;
    int weight;
        User(int n,int h,int w){
            this->number =n;
            this->height =h;
            this->weight = w;

            }

};

int main() {

    int n;
    cin>> n;
    vector<User> u;
    for(int i=0;i<n;i++){
        int na = i+1; int h; int w;

        cin>> h>> w;

        u.push_back(User(na,h,w));


    } // input until here

    sort(u.begin(),u.end(),[](User a, User b){
        if( a.height != b.height ) 
        return a.height < b.height        ;
        else if(a.weight != b.weight) 
        return a.weight > b.weight;
        else
            return a.number < b.number;
        



    });

    for(int i=0;i<n;i++){
       cout << u[i].height << " " << u[i].weight << " " << u[i].number << '\n';
    }


    
    return 0;
}