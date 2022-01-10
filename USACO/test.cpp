#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

void recurse(int& n, vector<bool> visited, vector<int> curr, vector<int>& order, map<int,vector<int>>& head, vector<int>& puts){
    if (curr.size() == n){
        for (int j = 0; j < n; j++){
            cout << puts[curr[j]] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if (visited[i]) continue;
        if (order[i] != 1 && !visited[head[puts[i]][order[i]-2]]) return;
        visited[i] = true;
        curr.push_back(i);
        recurse(n, visited, curr, order, head, puts);
        visited[i] = false;
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n = 5;
    vector<int> puts = {12,13,14,15,16};

    //Code
    map<int,int> index;
    map<int,vector<int>> head;
    vector<int> order(n);
    for (int i = 0; i < n; i++){
        index[puts[i]]++;
        order[i] = index[puts[i]];
        head[puts[i]].push_back(i);
    }
    vector<bool> visited(n);
    vector<int> nums;
    recurse(n, visited, nums, order, head, puts);


    return 0;
}