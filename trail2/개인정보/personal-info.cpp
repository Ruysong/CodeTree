#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Person {
public:
    string name;
    int height;
    double weight;

    Person(string name, int height, double weight) {
        this->name = name;
        this->height = height;
        this->weight = weight;
    }
};

int main() {
    vector<Person> v;

    for (int i = 0; i < 5; i++) {
        string name;
        int height;
        double weight;

        cin >> name >> height >> weight;
        v.push_back(Person(name, height, weight));
    }

    sort(v.begin(), v.end(), [](Person a, Person b) {
        return a.name < b.name;
    });

    cout << "name\n";
    for (int i = 0; i < 5; i++) {
        cout << v[i].name << " " << v[i].height << " " << 
        fixed << setprecision(1)<< v[i].weight << '\n';
    }

    sort(v.begin(), v.end(), [](Person a, Person b) {
        return a.height > b.height;
    });

    cout << "\nheight\n";
    for (int i = 0; i < 5; i++) {
        cout << v[i].name << " " << v[i].height << " " <<
        fixed << setprecision(1)<<  v[i].weight << '\n';
    }

    return 0;
}