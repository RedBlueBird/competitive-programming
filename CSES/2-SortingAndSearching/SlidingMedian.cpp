#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class MedianSet{
public:
    MedianSet(){

    }
private:

};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    set<int> window;
    for (int i = 0; i < n; i++){
        window.insert(nums[i]);
        if (i < k) continue;
        cout << *(window.begin()+1) << " ";
    }

    return 0;
}