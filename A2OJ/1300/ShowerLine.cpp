#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

const int n = 5;

//Permutate through all the possible permutations of 5
//Keep the highest score as the final answer
void permutate(vector<vector<int>>& values, vector<bool> used, vector<int> curr, int& ans){
    if (curr.size() != n){
        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(i);
            permutate(values, used, curr, ans);
            used[i] = false;
            curr.pop_back();
        }
    }else{
        ans = max(ans, values[curr[0]][curr[1]] + values[curr[1]][curr[0]] +
                        values[curr[2]][curr[3]] + values[curr[3]][curr[2]] +
                        values[curr[1]][curr[2]] + values[curr[2]][curr[1]] +
                        values[curr[3]][curr[4]] + values[curr[4]][curr[3]] +
                        values[curr[2]][curr[3]] + values[curr[3]][curr[2]] +
                        values[curr[3]][curr[4]] + values[curr[4]][curr[3]]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    vector<vector<int>> values(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> values[i][j];
        }
    }

    //Initiate bruteforce
    int ans = 0;
    vector<bool> used(n);
    vector<int> curr;
    permutate(values, used, curr, ans);

    //Output
    cout << ans;

    return 0;
}