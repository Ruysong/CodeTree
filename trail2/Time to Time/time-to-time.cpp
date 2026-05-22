#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
int elapsed = 0;

cin >> a >> b >> c >> d;

while (!(a == c && b == d)) {
    b++;
    elapsed++;

    if (b == 60) {
        a++;
        b = 0;
    }
}

cout << elapsed;
    return 0;
}