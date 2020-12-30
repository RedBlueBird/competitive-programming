#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Get all the digits in an integer in decimal form
vector<int> get(int a){
    vector<int> digits;
    while (a){
        digits.push_back(a%10);
        a /= 10;
    }
    return digits;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Calculate all the minimum steps needed to transform i to 0
    //for i from 1 to n
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        vector<int> digits = get(i);
        for (int j = 0; j < digits.size(); j++){
            if (digits[j] == 0) continue;
            dp[i] = min(dp[i], dp[i-digits[j]]+1);
        }
    }

    //Output
    cout << dp[n];

    return 0;
}