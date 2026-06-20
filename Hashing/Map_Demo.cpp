// Demo for mapping

#include<iostream>
#include<string>
#include<map>

using namespace std;

int  main() {
    // making a map
    map<int, string> m;

    //Inserting values inside a map
    m[101] = "asdadas";
    m[1023] = "saffdffaf";
    m[1] = "fdfgc";

    // Printing the map
    for(auto it : m) {
        cout<<"key= "<<it.first<<" | "<<"Value= "<<it.second<<endl;
    }
    return 0;
}