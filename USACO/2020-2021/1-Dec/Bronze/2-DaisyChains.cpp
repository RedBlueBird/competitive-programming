#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    //Take inputs
    int n;
    cin >> n;
    vector<int> flowers(n);
    vector<int> sums(n+1);
    for (int i = 0; i < n; i++){
        cin >> flowers[i];
        sums[i+1] = sums[i] + flowers[i];
    }

    //Find all the pair intervals that have average flower in them
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int average = (sums[j+1] - sums[i])%(j-i+1) ? 0 : (sums[j+1] - sums[i])/(j-i+1);
            for (int h = i; h <= j; h++){
                if (flowers[h] == average){
                    ans++;
                    break;
                }
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}