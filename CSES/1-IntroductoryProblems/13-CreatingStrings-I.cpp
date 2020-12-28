#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Generate all the permutation of the raw string
void permutation(deque<char> prev, vector<bool> visited, string& raw, set<string>& ans){
    unsigned int n = visited.size();
    if (prev.size() == n){
        string result;
        while (!prev.empty()){
            result += prev.front();
            prev.pop_front();
        }
        ans.insert(result);
    }
    else{
        for (unsigned int i = 0; i < n; i++){
            if (visited[i]) continue;
            visited[i] = true;
            prev.push_back(raw[i]);
            permutation(prev, visited, raw, ans);
            visited[i] = false;
            prev.pop_back();
        }
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    string raw;
    cin >> raw;
    sort(raw.begin(), raw.end());

    //Initiate the permutation recursion function
    deque<char> prev;
    vector<bool> visited(raw.size());
    set<string> ans;
    permutation(prev, visited, raw, ans);

    //Output
    cout << ans.size() << "\n";
    for (auto i: ans){
        cout << i << "\n";
    }

    return 0;
}