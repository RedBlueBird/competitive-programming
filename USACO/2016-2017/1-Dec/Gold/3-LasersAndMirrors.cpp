#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

int main() {
    ofstream fout("lasers.out");
    ifstream fin("lasers.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Append each coordinate to a horz and vert map
    //This later helps us to search through the graph
    int n;
    pii start;
    pii end;
    fin >> n >> start.ff >> start.ss >> end.ff >> end.ss;
    map<int,vector<int>> horz;
    map<int,vector<int>> vert;
    map<pii, bool> visited;
    map<pii, int> dists;
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        horz[a].push_back(b);
        vert[b].push_back(a);
        visited[make_pair(a,b)] = false;
        dists[make_pair(a,b)] = INT_MAX;
    }
    horz[end.ff].push_back(end.ss);
    vert[end.ss].push_back(end.ff);

    //Each possible mirror position can be seen as a node
    //Two nodes are connected if they share the same x or y value
    //The shortest way to reach the destination is bfs the graph
    queue<pair<pii,bool>> bfs;
    visited[start] = false;
    dists[start] = 0;
    dists[end] = INT_MAX;
    bfs.push(make_pair(start,true));
    bfs.push(make_pair(start,false));
    int ans = 0;
    int count = 2;
    while (bfs.size()){
        bool type;
        pii coords;
        tie(coords, type) = bfs.front();
        bfs.pop();
        if (coords == end){
            ans = dists[coords];
            break;
        }
        if ((visited[coords] && coords != start) || (coords == start && count-- <= 0)) continue;
        visited[coords] = true;
        if (type){
            for (int i: horz[coords.ff]){
                if (dists[make_pair(coords.ff, i)] > dists[coords]+1){
                    dists[make_pair(coords.ff, i)] = dists[coords]+1;
                    bfs.push(make_pair(make_pair(coords.ff,i),false));
                }
            }
        }else{
            for (int i: vert[coords.ss]){
                if (dists[make_pair(i,coords.ss)] > dists[coords]+1){
                    dists[make_pair(i,coords.ss)] = dists[coords]+1;
                    bfs.push(make_pair(make_pair(i,coords.ss),true));
                }
            }
        }
    }

    //Since we over counted 1 mirror at the end position
    //Output answer - 1
    fout << ans-1;

    return 0;
}