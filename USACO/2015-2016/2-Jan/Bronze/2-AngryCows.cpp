#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Brute force left and right
int count(vector<int>& nums, int k){
    int total = 1;
    int r = 1;
    int start = nums[k];
    int c = k+1;
    while (c != nums.size() && start + r >= nums[c]){
        while (c != nums.size() && start + r >= nums[c]){
            c++;
            total++;
        }
        start = nums[c-1];
        r++;
    }
    r = 1;
    start = nums[k];
    c = k-1;
    while (c != -1 && start - r <= nums[c]){
        while (c != -1 && start - r <= nums[c]){
            c--;
            total++;
        }
        start = nums[c+1];
        r++;
    }
    return total;
}

int main() {
    ofstream fout("angry.out");
    ifstream fin("angry.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        fin >> nums[i];
    sort(nums.begin(), nums.end());

    //Brute force all positions and keep the best one
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, count(nums,i));
    }

    //Output
    fout << ans;

    return 0;
}

