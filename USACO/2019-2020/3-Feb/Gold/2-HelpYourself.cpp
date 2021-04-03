#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("help.out");
    ifstream fin("help.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Compress the input
    int n;
    fin >> n;
    vector<pii> ranges(n);
    vector<ll> compress;
    map<ll,int> convert;
    for (int i = 0; i < n; i++){
        fin >> ranges[i].ff >> ranges[i].ss;
        compress.push_back(ranges[i].ff);
        compress.push_back(ranges[i].ss);
    }
    sort(compress.begin(), compress.end());
    for (int i = 0; i < compress.size(); i++){
        if (!convert.count(compress[i]))
            convert[compress[i]] = i+1;
    }

    //Precompute the power of 2 beforehand
    //Add up all the ranges using difference sum
    //The amount of complexity a single range contribute is
    //equal to 2^(n-1-(the amount of ranges that intersects it))
    vector<ll> power(n);
    power[0] = 1;
    for (int i = 1; i <= n; i++){
        power[i] = (power[i-1]*2)%mod;
    }
    vector<int> psum(2*n);
    for (int i = 0; i < n; i++){
        psum[convert[ranges[i].ff]]++;
        psum[convert[ranges[i].ss]]--;
    }

    for (int i = 1; i < 2*n; i++){
        psum[i] += psum[i-1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = (ans+power[n-1-psum[convert[ranges[i].ff]-1]])%mod;
    }

    //Output
    fout << ans;

    return 0;
}

