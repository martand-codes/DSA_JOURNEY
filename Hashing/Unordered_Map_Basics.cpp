// For Ordered Map Just use map instead of unordered_map

#include <iostream>
#include <unordered_map>
using namespace std;

// Basic Unordered Map Practice: (STL of Hashing)
int main() {
    unordered_map<string, int> m;

    m["china"] = 150;
    m["India"] = 150;
    m["USA"] = 50;
    m["Nepal"] = 10;

    // For Printing
    for(pair<string, int> country : m) {
        cout<<country.first << "," <<country.second<<endl;
    }

    // For Checking
    if(m.count("Nepal")) {
        cout<<"Nepal Exists";
    } else {
        cout<<"It does Not";
    }
    return 0;
}

