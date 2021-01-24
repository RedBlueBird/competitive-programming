#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//A O(log(b)) method for modular exponentiation
ll fastmod(ll a, ll b){
    if (a == 0) return 0;
    ll track = 1;
    while (b){
        if (b & 1)
            track = (track*a)%(ll)(1e9+7);
        a = (a*a)%(ll)(1e9+7);
        b = b >> 1;
    }
    return track;
}

int main() {
    ofstream fout("poetry.out");
    ifstream fin("poetry.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Keep track how many words with same syllables and how many words in the same rhyme class
    int n, m, k;
    fin >> n >> m >> k;
    vector<ll> count(k+1, 0);
    vector<vector<ll>> type(n+1);
    for (int i = 0; i < n; i++){
        int a,b;
        fin >> a >> b;
        count[a]++;
        type[b].push_back(a);
    }
    vector<int> rhyme(m);
    for (int i = 0; i < m; i++){
        char a;
        fin >> a;
        rhyme[i] = int(a-'A');
    }

    //Check how many words can a line possibly fit
    //Get all the possible ways for each line that ends with a different rhyme class
    //Compress the rhyme lines and sort them in alphabetical order
    //Total ways is all the possible ways for each ending rhyme class to the power of all the rhyme segments
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= i; j++){
            dp[i] = (dp[i] + (dp[i-j]*count[j]))%(ll)(1e9+7);
        }
    }
    vector<ll> total(n+1,0);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < type[i].size(); j++){
            total[i] = (total[i]+dp[k-type[i][j]])%(ll)(1e9+7);
        }
    }
    if (dp[k] == 0){
        fout << 0;
        return 0;
    }
    sort(rhyme.begin(),rhyme.end());
    vector<int> groups;
    rhyme.push_back(-1);
    int back = 0;
    for (int i = 1; i <= m; i++){
        if (rhyme[i] != rhyme[i-1]){
            groups.push_back(i-back);
            back = i;
        }
    }
    ll ans = 1;
    for (int i = 0; i < groups.size(); i++){
        ll curr = 0;
        for (int j = 1; j <= n; j++){
            curr = (curr+fastmod(total[j], groups[i]))%(ll)(1e9+7);
        }
        ans = (ans*curr)%(ll)(1e9+7);
    }

    //Output
    fout << ans;

    return 0;
}