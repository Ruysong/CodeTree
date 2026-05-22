#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    cin >>a>>b>> c>>d;

    int start;
    int end;

    start = a*60+b;
    end = c*60 + d;

    cout << end-start;
    return 0;
}