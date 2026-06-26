#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s;
    cin >>s;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
    int x=0,y=0;
    int dir_num =3;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='L'){ // rotate direction
    dir_num = (dir_num -1 +4) % 4;
        }
        else if(s[i]=='R'){
             // rotate direction
    dir_num = (dir_num + 1) % 4;



        }
        else if(s[i]=='F'){
            
    // move
    x = x + dx[dir_num];
    y = y + dy[dir_num];

        }


    }

     cout << x <<" " << y;




    return 0;
}