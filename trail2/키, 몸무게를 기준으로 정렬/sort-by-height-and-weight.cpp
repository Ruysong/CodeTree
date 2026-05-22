#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int height;
    int weight;

    Person(string name, int height, int weight) {
        this->name = name;
        this->height = height;
        this->weight = weight;
    }
};

int main() {
    vector<Person> v;
    int n;
    cin >>n;

    for (int i = 0; i < n; i++) {
        string name;
        int height;
        int weight;

        cin >> name >> height >> weight;
        v.push_back(Person(name, height, weight));
    }

  sort(v.begin(), v.end(), [](Person a, Person b) {
        if(a.height != b.height) return a.height < b.height;
        else return a.weight > b.weight;


    });


    for (int i = 0; i < n; i++) {
        cout << v[i].name << " " << v[i].height << " " << 
         v[i].weight << '\n';
    }

  
 

    return 0;
}