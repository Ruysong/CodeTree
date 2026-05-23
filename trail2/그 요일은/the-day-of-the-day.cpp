#include <iostream>
#include <string>
using namespace std;

int main() {
    int m1,d1,m2,d2;
    cin >> m1>>d1>>m2>>d2;
    int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string whatday[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    int i=0,cnt=0;
    string a;
    cin >> a;
    while(true){

        if(whatday[i]== a) cnt++;
        if(d1==d2 && m1 ==m2) break;

    if( num_of_days[m1] == d1) {
        m1++;
        d1=0;
        }
    i %= 7;
    i++;
    d1++;
    }

    cout << cnt;




    return 0;
}