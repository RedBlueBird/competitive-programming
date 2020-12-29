#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int k, n, a;
    cin >> k >> n;

    //One set track the light positions, one set track the total distances between lights
    //When getting new light position, find the existing light positions left and right to it
    //Remove the distance between those lights and add 2 more smaller distances
    //The answer is the longest distance in the set
    set<int> lights;
    multiset<int> diffs;
    lights.insert(0);
    lights.insert(k);
    diffs.insert(k);
    for (int i = 0; i < n; i++){
        cin >> a;
        auto it1 = lights.upper_bound(a);
        auto it2 = it1;
        it2--;
        int diff = *it1 - *it2;
        diffs.erase(diffs.find(diff));
        diffs.insert(*it1-a);
        diffs.insert(a-*it2);
        lights.insert(a);
        cout << *diffs.rbegin() << " ";
    }

    return 0;
}