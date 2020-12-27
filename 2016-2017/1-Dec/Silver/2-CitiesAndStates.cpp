#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("citystate.out");
    ifstream fin("citystate.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Collect all the keys and their counters
    int n;
    fin >> n;
    int ans = 0;
    unordered_map<string,int> cities;
    for (int i = 0; i < n; i++) {
        string a, b;
        fin >> a >> b;
        a = a.substr(0, 2);
        if (a == b) continue;
        cities[a+b]++;
    }

    //Multiply the pairs for each key if both are present
    //Add that to the answer
    for (auto i: cities){
        string key = i.first.substr(2) + i.first.substr(0,2);
        if (cities.count(key)) ans += i.second * cities[key];
    }

    //Output divide by 2, because it is counted twice
    fout << ans/2;

    return 0;
}