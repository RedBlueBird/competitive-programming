#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

pii find(pii grid, vector<vector<pii>>& link){
    if (link[grid.ff][grid.ss] == grid) return grid;
    return link[grid.ff][grid.ss] = find(link[grid.ff][grid.ss], link);
}

void unions(pii grid1, pii grid2, vector<vector<pii>>& link, vector<vector<int>>& size){
    grid1 = find(grid1, link);
    grid2 = find(grid2, link);
    if (grid1 == grid2) return;
    if (size[grid1.ff][grid1.ss] < size[grid2.ff][grid2.ss]) swap(grid1,grid2);
    link[grid2.ff][grid2.ss] = grid1;
    size[grid1.ff][grid1.ss] += size[grid2.ff][grid2.ss];
}

int main() {
//    ofstream fout("fencedin.out");
//    ifstream fin("fencedin.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
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
    vert.push_back(xlimit);
    horz.push_back(ylimit);
    sort(vert.begin(), vert.end());
    sort(horz.begin(), horz.end());

    ll ans = 0;
    vector<tuple<int, pii, pii>> edges;
    vector<vector<pii>> link(n+1,vector<pii>(m+1));
    vector<vector<int>> size(n+1, vector<int>(m+1, 1));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            link[i][j] = make_pair(i,j);
            int ylen = vert[i+1] - vert[i];
            int xlen = horz[j+1] - horz[j];
            if (j != 0)
                edges.push_back(make_tuple(ylen, make_pair(i,j), make_pair(i,j-1)));
            if (j != m)
                edges.push_back(make_tuple(ylen, make_pair(i,j), make_pair(i,j+1)));
            if (i != 0)
                edges.push_back(make_tuple(xlen, make_pair(i,j), make_pair(i-1,j)));
            if (i != n)
                edges.push_back(make_tuple(xlen, make_pair(i,j), make_pair(i+1,j)));
        }
    }
    sort(edges.begin(), edges.end());
    for (tuple<int, pii, pii> i: edges){
        pii grid1 = get<1>(i);
        pii grid2 = get<2>(i);
        ll weight = get<0>(i);
//        cout << weight << " (" << grid1.ff << " " << grid1.ss << ") (" << grid2.ff << " " << grid2.ss << ") ";
        if (!(find(grid1, link) == find(grid2, link))){
            ans += weight;
            unions(grid1, grid2, link, size);
//            cout << "-";
        }
//        cout << "\n";
    }

    //Output
    fout << ans;

    return 0;
}