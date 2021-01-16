#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n;
    cin >> n;

    //If the total sum is not even, automatically ruled out
    if ((n*(n+1)/2)%2){
        cout << "NO";
        return 0;
    }
    //Otherwise greedily output the first set that sum up to half
    //Then output the other half
    cout << "YES\n";
    vector<ll> first;
    vector<ll> second;
    ll sums = 0;
    for (ll i = n; i > 0; i--){
        if (sums + i <= n*(n+1)/4){
            sums += i;
            first.push_back(i);
        }
        else{
            second.push_back(i);
        }
    }
    cout << first.size() << "\n";
    for (ll i: first)
        cout << i << " ";
    cout << "\n" << second.size() << "\n";
    for (ll i: second)
        cout << i << " ";

    return 0;
}