#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m, a, b;
    cin >> n >> m;
    ll total = 0;
    vector<ll> nums(n+1, -1);
    vector<ll> index(n+1, -1);
    vector<ll> pointer(n+1, -1);
    for (int i = 1; i <= n; i++){
        cin >> a;
        index[a] = i;
        nums[i] = a;
        if (index[a-1] != -1){
            pointer[a-1] = i;
        }else{
            total++;
        }
    }

    //Output each query
    //The code is pretty self-explanatory, imagine the nums list as a linked list
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (a>b) swap(a,b);
        ll x = nums[a];
        ll y = nums[b];
        swap(nums[a],nums[b]);
        swap(index[x], index[y]);

        if (pointer[y-1] != -1 && index[y-1] > a){
            pointer[y-1] = -1;
            total++;
        }else if (pointer[y-1] != -1){
            pointer[y-1] = a;
        }
        if (y+1 <= n && pointer[y] == -1 && index[y+1] > a){
            pointer[y] = index[y+1];
            total--;
        }

        if (pointer[x] != -1 && index[x+1] < b){
            pointer[x] = -1;
            total++;
        }
        if (pointer[x-1] != -1){
            pointer[x-1] = b;
        }else if (x-1 != 0 && index[x-1] < b){
            pointer[x-1] = b;
            total--;
        }
        cout << total << "\n";
    }

    return 0;
}