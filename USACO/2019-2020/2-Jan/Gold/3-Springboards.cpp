#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void debug(set<tuple<ll,ll,ll>>& a){
    for (tuple<ll,ll,ll> i: a){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "\n";
    }
    cout << " \n --------------- \n";
}

bool comp(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    if (get<0>(a) <= get<0>(b))
        return get<1>(a) < get<1>(b);
    return false;
}

int main() {
//    ifstream fin("boards.in");
//    ofstream fout("boards.out");
    ifstream fin("../input.txt");
    ofstream fout("../output.txt");

    //Take inputs
    int n,p;
    fin >> n >> p;
    vector<vector<ll>> ranges(p, vector<ll>(4));
    for (int i = 0; i < p; i++)
        fin >> ranges[i][2] >> ranges[i][3] >> ranges[i][0] >> ranges[i][1];

    sort(ranges.begin(), ranges.end());
    set<tuple<ll,ll,ll>> dp;
    dp.insert(make_tuple(0,0,0));
    for (int i = 0; i < p; i++){
        auto it = upper_bound(dp.begin(), dp.end(), make_tuple(-ranges[i][2], -ranges[i][3],0), comp);
        auto best = upper_bound(dp.begin(), dp.end(), make_tuple(-ranges[i][0], -ranges[i][1],0), comp);
        ll dist = get<2>(*it)+abs((ranges[i][0]-ranges[i][2])+(ranges[i][1]-ranges[i][3]));
//        fout << abs((ranges[i][0]-ranges[i][2])+(ranges[i][1]-ranges[i][3])) << "\n";
        if (it != best && dist <= get<2>(*best))
            continue;
//        fout << dist << "\n";
        dp.insert(make_tuple(-ranges[i][0], -ranges[i][1], dist));
        cout << get<2>(*it) << "\n";
        debug(dp);
    }

    //Output
    fout << ll(2*n) - get<2>(*dp.begin());

    return 0;
}
