#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Count the files each directory holds
//While also count the total relative path length to the root directory
void initialize(vector<vector<int>>& graph, vector<int>& sizes, vector<int>& length, int node, ll& dist){
    for (int i: graph[node]){
        initialize(graph, sizes, length, i, dist);
        sizes[node] += sizes[i];
    }
    if (graph[node].size() == 0)
        sizes[node] = 1;
    dist += length[node]*sizes[node];
}

//Dfs the tree graph, keep the best answer
void dfs(vector<vector<int>>& graph, vector<int>& sizes, vector<int>& length, int node, ll dist, ll& ans){
    ans = min(ans, dist);
    for (int i: graph[node]){
        if (graph[i].size() == 0) continue;
        ll new_dist = dist + (sizes[1] - sizes[i]) * 3 - sizes[i] * length[i];
        dfs(graph, sizes, length, i, new_dist, ans);
    }
}

int main() {
    ofstream fout("dirtraverse.out");
    ifstream fin("dirtraverse.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct tree graph
    int n;
    fin >> n;
    vector<vector<int>> graph(n+1);
    vector<int> length(n+1);
    for (int i = 1; i <= n; i++){
        string name;
        int len;
        fin >> name >> len;
        length[i] = name.size();
        if (len){
            length[i]++;
            for (int j = 0; j < len; j++){
                int a;
                fin >> a;
                graph[i].push_back(a);
            }
        }
    }

    //Do two dfs
    //Initialize and then dp the answer
    vector<int> sizes(n+1, 0);
    ll dist = 0;
    initialize(graph, sizes, length, 1, dist);
    dist -= sizes[1] * length[1];
    ll ans = LONG_LONG_MAX;
    dfs(graph, sizes, length, 1, dist, ans);

    //Output
    fout << ans;

    return 0;
}