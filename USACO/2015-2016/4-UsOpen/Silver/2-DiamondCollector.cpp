#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("diamond.out");
    ifstream fin("diamond.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        fin >> nums[i];
    }

    //Sort the input
    //Find the maximum diamonds that can belong to each diamond
    //Answer is the pair of diamonds that have the maximum diamonds sum
    sort(nums.begin(), nums.end());
    vector<int> steps(n);
    int ans = 0;
    int a = n-1;
    for (int i = n-1; i >= 0; i--){
        while (a >= 0 && nums[i] - nums[a] <= k){
            steps[a] = i-a+1;
            a--;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i+steps[i]; j < n; j++){
            ans = max(ans, steps[i] + steps[j]);
        }
    }

    //Output
    fout << ans;

    return 0;
}