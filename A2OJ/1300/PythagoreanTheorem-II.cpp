#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;

    //Generating all pythagorean triples using Euclid's formula
    //Where m > n, m and n are integers,
    //(a,b,c) => (m^2 - n^2, 2mn, m^2 + n^2)
    vector<int> nums;
    for (int i = 1; i*i <= n; i++){
        nums.push_back(i*i);
    }
    int ans = 0;
    int k = nums.size();
    for (int i = 0; i < k; i++){
        for (int j = i+1; j < k; j++){
            if (nums[i] + nums[j] <= n){
                if (gcd(pow(nums[j],2)-pow(nums[i],2),2*nums[j]*nums[i]) != 1) continue;
                ans+= n/(nums[i] + nums[j]);
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}