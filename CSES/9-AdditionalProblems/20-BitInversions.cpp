#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    string raw;
    int m, n, x;
    cin >> raw >> m;
    n = raw.size();

    //A inversion set keep track of all the indices that have bit shifted
    //A multiset keep track of all the string lengths
    //For each new bit shift, process the following function 2 times
    //on the target index and the target+1 index to combine substring with same bits if missed
    set<int> inv;
    multiset<int> diffs;
    inv.insert(0); inv.insert(n);
    for (int i = 0; i < n-1; i++)
        if (raw[i] != raw[i+1])
            inv.insert(i+1);
    for (auto i = inv.begin(); next(i) != inv.end(); i++)
        diffs.insert(*next(i)-*i);
    while (m--){
        cin >> x;
        for (int a = x-1; a <= x; a++) {
            if (a == 0 || a == n) continue;
            auto target = inv.find(a);
            if (target != inv.end()) {
                int left = *prev(target), right = *next(target);
                diffs.erase(diffs.find(right - a));
                diffs.erase(diffs.find(a - left));
                diffs.insert(right - left);
                inv.erase(target);
            } else {
                target = inv.insert(a).first;
                int left = *prev(target), right = *next(target);
                diffs.erase(diffs.find(right - left));
                diffs.insert(right - a);
                diffs.insert(a - left);
            }
        }
        cout << *diffs.rbegin() << " ";
    }

    return 0;
}