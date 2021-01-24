#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Bisearch function that give true/false base on if the given distance can allow at least n cows or not
bool bisearch(ll n, vector<pair<ll,ll>>& grass, ll dist){
    ll total = 0;
    ll c = -dist;
    for (pair<ll,ll> i: grass){
        if (max(c+dist, i.first) > i.second) continue;
        c = max(c+dist, i.first);
        ll steps = (i.second - c)/dist + 1;
        total += steps;
        c += (steps-1)*dist;
    }
    return total >= n;
}


int main() {
    ofstream fout("socdist.out");
    ifstream fin("socdist.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    ll n, m;
    fin >> n >> m;
    vector<pair<ll,ll>> grass(m);
    for (int i = 0; i < m; i++){
        fin >> grass[i].first >> grass[i].second;
    }

    //Sort the input, binary search on answer
    sort(grass.begin(), grass.end());
    ll a = 0, b = 1e18;
    while (b-a>1){
        if (bisearch(n, grass, (a+b)/2)){
            a += (b-a)/2;
        }else{
            b -= (b-a)/2;
        }
    }
    if (!bisearch(n, grass, a)) a = b;

    //Output
    fout << a;

    return 0;
}