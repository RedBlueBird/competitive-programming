#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
//    ofstream fout("teleport.out");
//    ifstream fin("teleport.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> dist(n);
    set<int> points;
    int total = 0;
    for (int i = 0; i < n; i++){
        fin >> dist[i].first >> dist[i].second;
        total += dist[i].second - dist[i].first;
        points.insert(dist[i].first);
        points.insert(dist[i].second);
    }

    sort(dist.begin(), dist.end());


    return 0;
}