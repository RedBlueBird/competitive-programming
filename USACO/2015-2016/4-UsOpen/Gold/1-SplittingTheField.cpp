#include <bits/stdc++.h>
#define ff first
#define ss second
typedef long long ll;
using namespace std;

//A custom comparator for sorting with vector<pair<ll,ll>> by the 2nd ll
bool cmp(pair<ll,ll> a, pair<int,int> b){
    return a.ss < b.ss;
}

int main() {
    ofstream fout("split.out");
    ifstream fin("split.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<ll,ll>> cows(n);
    pair<ll,ll> top;
    pair<ll,ll> bottom;
    for (int i = 0; i < n; i++){
        fin >> cows[i].ff >> cows[i].ss;
    }

    //Sort the coordinates by x, then by y
    //The minimum area is equal to the area required for 1 to ith cow + area for i+1th to nth cow
    //Answer is the total area - the minimum area
    ll ans = LONG_LONG_MAX;
    ll total = 0;
    sort(cows.begin(), cows.end());
    vector<ll> area(n+1,0);
    top = make_pair(LONG_LONG_MIN,LONG_LONG_MIN);
    bottom = make_pair(LONG_LONG_MAX,LONG_LONG_MAX);
    for (int i = n-1; i >= 0; i--){
        top.ff = max(top.ff, cows[i].ff);
        top.ss = max(top.ss, cows[i].ss);
        bottom.ff = min(bottom.ff, cows[i].ff);
        bottom.ss = min(bottom.ss, cows[i].ss);
        area[i] = (top.ff - bottom.ff)*(top.ss - bottom.ss);
    }
    total = area[0];
    top = make_pair(LONG_LONG_MIN,LONG_LONG_MIN);
    bottom = make_pair(LONG_LONG_MAX,LONG_LONG_MAX);
    for (int i = 0; i < n; i++){
        top.ff = max(top.ff, cows[i].ff);
        top.ss = max(top.ss, cows[i].ss);
        bottom.ff = min(bottom.ff, cows[i].ff);
        bottom.ss = min(bottom.ss, cows[i].ss);
        if (i != n-1 && cows[i].ff == cows[i+1].ff) continue;
        ans = min(ans, (top.ff - bottom.ff)*(top.ss - bottom.ss)+area[i+1]);
    }
    sort(cows.begin(), cows.end(), cmp);
    fill(area.begin(), area.end(),0);
    top = make_pair(LONG_LONG_MIN,LONG_LONG_MIN);
    bottom = make_pair(LONG_LONG_MAX,LONG_LONG_MAX);
    for (int i = n-1; i >= 0; i--){
        top.ff = max(top.ff, cows[i].ff);
        top.ss = max(top.ss, cows[i].ss);
        bottom.ff = min(bottom.ff, cows[i].ff);
        bottom.ss = min(bottom.ss, cows[i].ss);
        area[i] = (top.ff - bottom.ff)*(top.ss - bottom.ss);
    }
    top = make_pair(LONG_LONG_MIN,LONG_LONG_MIN);
    bottom = make_pair(LONG_LONG_MAX,LONG_LONG_MAX);
    for (int i = 0; i < n; i++){
        top.ff = max(top.ff, cows[i].ff);
        top.ss = max(top.ss, cows[i].ss);
        bottom.ff = min(bottom.ff, cows[i].ff);
        bottom.ss = min(bottom.ss, cows[i].ss);
        if (i != n-1 && cows[i].ss == cows[i+1].ss) continue;
        ans = min(ans, (top.ff - bottom.ff)*(top.ss - bottom.ss)+area[i+1]);
    }

    //Output
    fout << total - ans;

    return 0;
}