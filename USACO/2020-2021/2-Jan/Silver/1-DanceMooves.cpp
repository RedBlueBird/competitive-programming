#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> track(n+1);
    for (int i = 1; i <= n; i++) {
        track[i] = i;
        graph[i].push_back(i);
    }
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        swap(track[a],track[b]);
        graph[track[a]].push_back(a);
        graph[track[b]].push_back(b);
    }

    //Find all the connected components
    //For all the cows in the same connected components their answer will be the same
    //Two cows are connected if the last position of the first cow is same as the second cow or vice versa.
    //Go through the connected components and count all the unique positions.
    vector<int> ans(n+1);
    vector<int> visited(n+1, 0);
    for (int i = 1; i <= n; i++){
        if (visited[i] != 0){
            ans[i] = ans[visited[i]];
            continue;
        }
        vector<bool> seen(n+1, false);
        int total = 0;
        int curr = i;
        do{
            visited[curr] = i;
           for (int j: graph[curr]){
               if (!seen[j]){
                   seen[j] = true;
                   total++;
               }
           }
           curr = graph[curr].back();
        } while (curr != i);
        ans[i] = total;
    }

    //Output
    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}