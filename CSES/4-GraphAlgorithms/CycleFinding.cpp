#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Convert input to edge list for Bellford
    int n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges(m);
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        edges.push_back(make_tuple(a,b,c));
    }

    //Bellford the graph to detect if a cycle exists
    //Track all the nodes' ancestors while Bellford-ing
    //If cycle exists, find the origin of the negative cycle and then output it
    //Otherwise output no
    vector<ll> path(n+1);
    vector<ll> dist(n+1);
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++){
        for (auto j: edges){
            ll a,b,c;
            tie(a,b,c) = j;
            if (dist[a] + c < dist[b]){
                path[b] = a;
                if (i == n){
                    int start = b;
                    while (!visited[start]){
                        visited[start] = true;
                        start = path[start];
                    }
                    stack<int> ans;
                    ans.push(start);
                    int node = path[start];
                    while (node != start){
                        ans.push(node);
                        node = path[node];
                    }
                    cout << "YES\n" << start;
                    while (!ans.empty()){
                        cout << " ";
                        cout << ans.top();
                        ans.pop();
                    }
                    return 0;
                }else{
                    dist[b] = dist[a] + c;
                }
            }
        }
    }

    //Output no
    cout << "NO";

    return 0;
}