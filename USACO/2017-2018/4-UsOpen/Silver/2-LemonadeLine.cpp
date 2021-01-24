#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("lemonade.out");
    ifstream fin("lemonade.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        fin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    for (int i = n-1; i >= 0; i--){
        if (nums[i] < n-i-1){
            fout << n-i-1;
            return 0;
        }
    }
    fout << n;

    return 0;
}