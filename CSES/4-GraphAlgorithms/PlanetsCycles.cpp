#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    //Find all the cycles
    //If the starting node is a tail, set the tail nodes size in decreasing order
    //Then scan for the size of the cycle it is pointing to
    //If the next is already calculated in a previous cycle,
    //add the result computed previously instead doing another cycle.
    vector<bool> visited(n+1);
    vector<int> sizes(n+1);
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        int size = 0;
        int node = i;
        while (true){
            size++;
            visited[node] = true;
            node = nums[node];
            if (visited[node]){
                size += sizes[node];
                break;
            }
        }
        int dest = node;
        node = i;
        do {
            sizes[node] = size;
            node = nums[node];
            if (i != dest) size--;
        } while (node != dest);
        if (sizes[dest]) continue;
        size = 0;
        do {
            size++;
            node = nums[node];
        } while (node != dest);
        do {
            sizes[node] = max(sizes[node],size);
            node = nums[node];
        } while (node != dest);
    }

    //Output
    for (int i = 1; i <= n; i++){
        cout << sizes[i] << " ";
    }

    return 0;
}