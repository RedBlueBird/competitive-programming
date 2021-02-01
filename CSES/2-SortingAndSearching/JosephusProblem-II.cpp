#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int Josephus(int n,int k){
    if (n == 1) return 1;
    return (Josephus(n-1,k)+k-1)%n + 1;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;



    return 0;
}