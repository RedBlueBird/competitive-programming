#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//The transitive cow blaming is a tree graph
//Dfs to search all the blamed cows
void dfs(vector<vector<int>>& graph, int node, vector<int>& cache){
    if (cache[node] != -1) return;
    cache[node] = 0;
    if (graph[node].size() == 0) return;

    for (int i = 0; i < graph[node].size(); i++){
        dfs(graph, graph[node][i], cache);
        cache[node] += cache[graph[node][i]];
    }
    cache[node] += graph[node].size();
}

int main() {
    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> upcow;
    vector<vector<int>> leftcow;
    for (int i = 0; i < n; i++){
        char a;
        cin >> a;
        int b,c;
        cin >> b >> c;
        if (a == 'E'){
            leftcow.push_back(vector<int>{c,b,i});
        }
        else{
            upcow.push_back(vector<int>{b,c,i});
        }
    }

    //Find all intersections between the north cow and the east cow.
    //If the cow has already been blocked by others, they can no longer block cows even if they could
    //If the cow blocked all other cows, its grass will be infinity
    //No two cows in the same direction shares the same lane.
    sort(leftcow.begin(),leftcow.end());
    sort(upcow.begin(),upcow.end());
    vector<int> upstop(n, INT_MAX);
    vector<int> leftstop(n, INT_MAX);
    vector<vector<int>> graph(n);
    for (int i = 0; i < upcow.size(); i++){
        for (int j = 0; j < leftcow.size(); j++){
            if (upcow[i][0] >= leftcow[j][1] && upcow[i][1] <= leftcow[j][0] && leftstop[leftcow[j][2]] >= upcow[i][0]){
                if (upcow[i][0] - leftcow[j][1] < leftcow[j][0] - upcow[i][1]){
                    upstop[upcow[i][2]] = leftcow[j][0];
                    graph[leftcow[j][2]].push_back(upcow[i][2]);
                    break;
                }
                else if (upcow[i][0] - leftcow[j][1] > leftcow[j][0] - upcow[i][1]){
                    leftstop[leftcow[j][2]] = upcow[i][0];
                    graph[upcow[i][2]].push_back(leftcow[j][2]);
                }
            }
        }
    }

    //Output
    vector<int> cache(n,-1);
    for (int i = 0; i < n; i++){
        dfs(graph, i, cache);
        cout << cache[i] << "\n";
    }

    return 0;
}