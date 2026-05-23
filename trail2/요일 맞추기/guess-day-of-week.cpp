#include <iostream>
using namespace std;


int getday(int a, int b);
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int m1,d1,m2,d2;
    cin >> m1>>d1>>m2>>d2;
    
    int diff =  getday(m2,d2) - getday(m1, d1);



    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    
    int idx = (diff%7 +7) %7;

    cout << days[idx];



    return 0;
}

int getday(int a,int b){
    int sum=b;
    for(int i=1; i<a;i++){
        sum += num_of_days[i];

    }
    return   sum;


}