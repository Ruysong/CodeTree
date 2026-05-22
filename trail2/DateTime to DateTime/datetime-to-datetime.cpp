#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >>a>>b>>c;
    int day =11;
    int hour =11;
    int min=11;
   int elasped=0;
  if (a < 11 || (a == 11 && b < 11) || (a == 11 && b == 11 && c < 11)) {
        cout << -1;
        return 0;
    }

    while (true){
        if (day ==a && hour == b && min ==c) break;

        if(min ==60) {
            min =0;
            hour ++;

        }
        else if(hour ==24){
            day++;
            hour =0;

        }



        min++;
        elasped++;
    }

    cout << elasped;

    return 0;
}