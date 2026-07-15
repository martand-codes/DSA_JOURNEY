// For Ordered Set Use <Set>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(7);
    s.insert(8);
    s.insert(3);

    cout<<s.size()<<endl; // It Does Not COUNT the duplicate size

    // FOr Finiding
    if(s.find(7) != s.end()) {
        cout<<"Exists"<<endl;
    } else {
        cout<<"Doesn't"<<endl;
    }
    
    // Printing Every Element
    for(auto el : s) {
        cout<<el<< " ";
    }
    return 0;
}