#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    //Scan through the list
    //Keep increasing the window by 1 until encounter a seen number
    //Then remove all the numbers before the seen number
    //Answer is the longest window
    set<int> window;
    int back = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (!window.count(nums[i])){
            window.insert(nums[i]);
        }
        else{
            while (nums[back] != nums[i])
                window.erase(window.find(nums[back++]));
            back++;
        }
        ans = max(ans, i-back+1);
    }

    //Output
    cout << ans;

    return 0;
}