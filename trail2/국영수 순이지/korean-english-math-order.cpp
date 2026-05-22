#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class User{
    public:
    string name;
    int korean;
    int english;
    int math;
        User(string na, int n,int h,int w){
            this-> name = na;
            this->korean =n;
            this->english =h;
            this->math = w;

            }

};

int main() {

    int n;
    cin>> n;
    vector<User> u;
    for(int i=0;i<n;i++){
        string name ;int na; int h; int w;

        cin>>name >> na >> h>> w;

        u.push_back(User(name, na,h,w));


    }

 sort(u.begin(), u.end(), [](User a, User b){
    if (a.korean != b.korean) {
        return a.korean > b.korean;
    }
    else if (a.english != b.english) {
        return a.english > b.english;
    }
    return a.math > b.math;
});
    for(int i=0;i<n;i++){
       cout << u[i].name << " "<<u[i].korean << " "
       << u[i].english <<" " <<u[i].math << endl;
    }


    
    return 0;
}
