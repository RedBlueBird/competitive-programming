#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("helpcross.out");
    ifstream fin("helpcross.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    multiset<int> chickens;
    vector<pair<int,int>> cows(m);
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        chickens.insert(a);
    }
    for (int i = 0; i < m; i++){
        fin >> cows[i].second >> cows[i].first;
    }

    //Greedily find all the possible matching for cows sorted with lowest end time
    //Once the chicken-cow pair is formed, erase chicken from the multiset
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < m; i++){
        auto chicken_pos = chickens.lower_bound(cows[i].second);
        if (chicken_pos != chickens.end() && *chicken_pos <= cows[i].first){
            ans++;
            chickens.erase(chicken_pos);
        }
    }

    //Output
    fout << ans;

    return 0;
}
