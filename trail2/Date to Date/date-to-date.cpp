#include <iostream>
using namespace std;

int main() {
    int m1,d1,m2,d2;
    cin >> m1>>d1>>m2>>d2;
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int elasped=1;

    while(true){
        if(d1==d2 && m1 ==m2) break;

    if( num_of_days[m1] == d1) {
        m1++;
        d1=0;
        }

    elasped++;
    d1++;
    }

    cout << elasped;




    return 0;
}