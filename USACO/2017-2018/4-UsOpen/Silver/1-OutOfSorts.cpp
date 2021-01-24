#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("sort.out");
    ifstream fin("sort.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, a;
    fin >> n;
    vector<pair<int,int>> nums(n);
    for (int i = 0; i < n; i++){
        fin >> a;
        nums[i] = make_pair(a,i);
    }

    //Answer is the largest difference between the result index - beginning index
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++){
        ans = max(ans, nums[i].second - i);
    }

    //Output
    fout << ans+1;

    return 0;
}