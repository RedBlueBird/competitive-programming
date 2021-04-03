#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");
//    ifstream fin("../input.txt");
//    ofstream fout("../output.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> first(n+1);
    for (int i = 1; i <= n; i++){
        fin >> first[i];
    }
    vector<int> second(n+1);
    for (int i = 1; i <= n; i++){
        int a;
        fin >> a;
        second[a] = i;
    }

    //Assume a can only connect to b if |a-b| == 0
    //Then this problem reduced to finding the longest increasing subsequence
    //where the index of a number is used to find the increasing sequence
    //The problem for |a-b| <= 4 is no different
    //We can use find the normal increasing subsequence with dynamic programming
    //We can use dynamic programming to find this as well
    //(There is actually a O(n*log(N)) method to find the longest increasing subsequence that can be applied to here as well)
    vector<vector<int>> connections(n+1);
    for (int i = 1; i <= n; i++){
        for (int j = first[i]-4; j <= first[i]+4; j++){
            if (j < 1 || j > n) continue;
            connections[i].push_back(second[j]);
        }
        sort(connections[i].begin(),connections[i].end());
    }
    vector<vector<int>> dp(n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int self = 0; self < connections[i].size(); self++) {
            dp[i].push_back(1);
            for (int j = i - 1; j > 0; j--) {
                for (int k = 0; k < dp[j].size(); k++) {
                    if (connections[j][k] < connections[i][self]){
                        dp[i][self] = max(dp[i][self], dp[j][k]+1);
                        ans = max(ans, dp[i][self]);
                    }else{
                        break;
                    }
                }
            }
        }
    }

    //Output
    fout << ans;

    return 0;
}

