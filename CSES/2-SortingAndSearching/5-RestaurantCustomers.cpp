#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<pair<int,int>> customers(n);
    for (int i = 0; i < n; i++)
        cin >> customers[i].first >> customers[i].second;

    //Keep track of all the present customers in a priority queue
    //If the customer leave time lower than the next customer's arrival time
    //Remove it from the queue
    sort(customers.begin(), customers.end());
    priority_queue<int, vector<int>, greater<int>> curr;
    int ans = 0;
    for (int i = 0; i < n; i++){
        curr.push(customers[i].second);
        if (curr.top() <= customers[i].first) curr.pop();
        int a = curr.size();
        ans = max(ans, a);
    }

    //Output
    cout << ans;

    return 0;
}