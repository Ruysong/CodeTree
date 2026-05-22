#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class User{
    public:
    string name;
    int height;
    int weight;
        User(string n,int h,int w){
            this->name =n;
            this->height =h;
            this->weight = w;

            }

};

int main() {

    int n;
    cin>> n;
    vector<User> u;
    for(int i=0;i<n;i++){
        string na; int h; int w;

        cin>> na >> h>> w;

        u.push_back(User(na,h,w));


    }

    sort(u.begin(),u.end(),[](User a, User b){
        return a.height < b.height ;
    });

    for(int i=0;i<n;i++){
       cout << u[i].name << " " << u[i].height << " " << u[i].weight << '\n';
    }


    
    return 0;
}