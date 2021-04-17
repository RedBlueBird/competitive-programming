#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Check if a number is prime
bool prime(int n){
    if (n%2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i+=2){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n,m;
    cin >> n >> m;

    //Iterate through all the numbers for primality testing
    bool valid = true;
    for (int i = n+1; i < m; i++){
        if (prime(i)) valid = false;
    }
    if (valid && !prime(m)) valid = false;

    //Output
    if (valid)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}