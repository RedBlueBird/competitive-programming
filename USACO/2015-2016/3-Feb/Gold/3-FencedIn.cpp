#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

//Find the ancestor node of the current node
pii find(pii target, vector<vector<pii>>& top){
    return target == top[target.ff][target.ss] ? target : target = find(top[target.ff][target.ss], top);
}

//Merge two trees together with union-find data-structure
//Two trees are merged if their root are different
bool merge(pii a, pii b, vector<vector<pii>>& top, vector<vector<int>>& size){
    a = find(a, top);
    b = find(b, top);
    if (a == b) return false;
    if (size[a.ff][a.ss] < size[b.ff][b.ss])
        swap(a,b);
    top[b.ff][b.ss] = a;
    size[a.ff][a.ss] += size[b.ff][b.ss];
    return true;
}

int main() {
    ofstream fout("fencedin.out");
    ifstream fin("fencedin.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Sort the positions of the horizontal and vertical fences
    //Extract the difference between two consecutive fences
    //Sort those distances
    int xlimit, ylimit, n, m;
    fin >> xlimit >> ylimit >> n >> m;
    vector<int> vert(n+1);
    vector<int> horz(m+1);
    for (int i = 1; i <= n; i++){
        fin >> vert[i];
    }
    for (int i = 1; i <= m; i++){
        fin >> horz[i];
    }
    sort(vert.begin(), vert.end());
    sort(horz.begin(), horz.end());
    for (int i = 0; i < n; i++){
        vert[i] = vert[i+1]-vert[i];
    }
    for (int i = 0; i < m; i++){
        horz[i] = horz[i+1]-horz[i];
    }
    vert[n] = xlimit - vert[n];
    horz[m] = ylimit - horz[m];
    sort(vert.begin(), vert.end());
    sort(horz.begin(), horz.end());

    //Set up 2D Union-Find data-structure for minimum spanning tree
    //Start merging grids from the shortest fence to the longest fence
    vector<vector<int>> size(n+1, vector<int>(m+1,1));
    vector<vector<pii>> top(n+1, vector<pii>(m+1, make_pair(0,0)));
    ll ans = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            top[i][j] = make_pair(i,j);
        }
    }
    for (int vi = 0, hi = 0; vi <= n || hi <= m;){
        if (vi <= n && vert[vi] < horz[hi] || hi > m){
            for (int j = 0; j < m; j++){
                if (merge(make_pair(vi,j), make_pair(vi,j+1), top, size)){
                    ans += vert[vi];
                }
            }
            vi++;
        }else{
            for (int j = 0; j < n; j++){
                if (merge(make_pair(j,hi), make_pair(j+1,hi), top, size)){
                    ans += horz[hi];
                }
            }
            hi++;
        }
    }

    //Output
    fout << ans;

    return 0;
}