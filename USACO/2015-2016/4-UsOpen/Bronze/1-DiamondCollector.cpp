#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
//    ifstream fin("../input.txt");
//    ofstream fout("../output.txt");

    //Take inputs
    //Sort the input
    int n, k;
    fin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        fin >> nums[i];
    sort(nums.begin(), nums.end());

    //We can use sliding window to solve the problem
    //A window is valid if the maximum difference is <= k
    //The answer is the maximum window size during the slide
    int ans = 0;
    deque<int> window;
    for (int i = 0; i < n; i++){
        while (window.size() && window.front() < nums[i]-k){
            window.pop_front();
        }
        window.push_back(nums[i]);
        ans = max(ans, int(window.size()));
    }

    //Output
    fout << ans;

    return 0;
}

