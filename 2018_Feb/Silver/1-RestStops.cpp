#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("reststops.out");
    ifstream fin("reststops.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int l, n;
    ll s1, s2;
    fin >> l >> n >> s1 >> s2;
    vector<pair<int,int>> stops(n);
    for (int i = 0; i < n; i++){
        fin >> stops[i].first >> stops[i].second;
    }

    //Find the stop with maximum value from the back in order to receive the maximum happiness
    vector<pair<int,int>> bestStops;
    int maxs = 0;
    ll ans = 0;
    for (int i = n-1; i >= 0; i--){
        if (stops[i].second > maxs){
            bestStops.push_back(stops[i]);
            maxs = stops[i].second;
        }
    }
    bestStops.push_back(make_pair(0,0));
    for (int i = bestStops.size()-2; i >= 0; i--){
        ans += (bestStops[i].first - bestStops[i+1].first) * (s1 - s2) * bestStops[i].second;
    }

    //Output
    fout << ans;

    return 0;
}