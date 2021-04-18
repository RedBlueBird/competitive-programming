#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    if (n < 3){
        cout << n << " " << 0 << " " << 0;
        return 0;
    }

    //For a Fibonacci number, it can be break down in to three separate Fibonacci numbers
    //where if the the current is n_k, then the three numbers will be n_(k-2), n_(k-2), n_(k-3)
    vector<int> fib = {0,1};
    while (fib.back() != n){
        fib.push_back(fib.back()+fib[fib.size()-2]);
        if (fib.back() == n){
            cout << fib[fib.size()-3] << " " << fib[fib.size()-3] << " " << fib[fib.size()-4];
            break;
        }
    }

    return 0;
}