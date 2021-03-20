#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Increase the k-th element of a BIT by x
void add(vector<int>& bit, int k, int x){
    int n = bit.size();
    while (k <= n){
        bit[k]+= x;
        k += k&-k;
    }
}

//Sum the elements up to k in a BIT
int sum(vector<int>& bit, int k){
    int result = 0;
    while (k >= 1){
        result+= bit[k];
        k -= k&-k;
    }
    return result;
}

int main() {
    ofstream fout("sort.out");
    ifstream fin("sort.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pii> nums;
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        nums.push_back(make_pair(a,i));
    }
    sort(nums.begin(), nums.end());

    //Check how many elements needed to transition from left to right
    //Answer is the maximum of it
    vector<int> bit(n+2);
    int ans = 1;
    for (int i = 0; i < n; i++){
        add(bit, nums[i].ss+1, 1);
        ans = max(ans, i - sum(bit, i+1) + 1);
    }

    //Output
    fout << ans;

    return 0;
}

