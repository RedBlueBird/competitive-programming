#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Find all the prime numbers within a range
void sieve(int n){
    int k = 1e7;
    vector<bool> primes(k+1);

    for (int i = 2; i*i <= k; i++){
        if (!primes[i]){
            for (int j = i*i; j <= k; j += i){
                primes[j] = true;
            }
        }
    }

    int c = 0;
    for (int i = 2; i <= k; i++){
        if (!primes[i]){
            cout << i << " ";
            c++;
        }
        if (c == n) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    //Finding a hungry sequence of length N is same as finding the first N primes
    int n;
    cin >> n;

    //Output
    sieve(n);

    return 0;
}