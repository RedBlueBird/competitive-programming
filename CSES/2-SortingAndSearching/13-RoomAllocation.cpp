#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> customers(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }

    //Sort the inputs first
    //Use a priority queue to keep track of the present customers
    //Use a queue to keep track of free rooms currently available
    //If the room queue is empty, append a new room
    sort(customers.begin(), customers.end());
    priority_queue<pair<int,int>> leave;
    queue<int> room;
    vector<int> ans(n);
    int rooms = 1;
    for (int i = 0; i < n; i++){
        while (!leave.empty() && leave.top().first*-1 < customers[i][0]){
            room.push(leave.top().second);
            leave.pop();
        }
        if (room.empty())
            room.push(rooms++);
        leave.push(make_pair(-customers[i][1], room.front()));
        ans[customers[i][2]] = room.front();
        room.pop();
    }

    cout << rooms-1 << "\n";
    for (int i: ans)
        cout << i << " ";

    return 0;
}