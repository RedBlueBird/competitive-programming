#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Sort a vector from largest to smallest
bool cmp(const int& a, const int& b){
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        nums.push_back(k);
    }
    nums.push_back(-1);
    sort(nums.begin(), nums.end(), cmp);

    //Count the frequency of each number
    vector<int> total;
    for (int i = nums.size()-2; i >= 0; i--){
        if (nums[i] == nums[i+1]){
            total[total.size()-1]++;
        }else{
            total.push_back(1);
        }
    }
    sort(total.begin(), total.end(), cmp);

    //If the highest frequency surpasses all others by more than 1,
    //output NO, else YES
    if ((total.size() == 1 && total[0] > 1) || (total.size() > 1 && total[0] - (n - total[0]) > 1)){
        cout << "NO";
    }else{
        cout << "YES";
    }

    return 0;
}