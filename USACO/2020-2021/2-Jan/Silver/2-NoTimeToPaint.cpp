#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<int> paint(n);
    for (int i = 0; i < n; i++){
        char a;
        cin >> a;
        paint[i] = int(a-'A');
    }

    //Calculate the total paint required from the left side and from the right side
    //Answer to each query will be found in O(1) time
    vector<int> left(n+1);
    vector<int> right(n+1);
    stack<int> backup;
    stack<int> curr;
    for (int i = 1; i <= n; i++){
        while (curr.size() && curr.top() > paint[i-1]){
            curr.pop();
        }
        if (curr.empty()){
            left[i] = left[i-1] + 1;
            curr.push(paint[i-1]);
        }else if (paint[i-1] == curr.top()){
            left[i] = left[i-1];
        }else if (paint[i-1] > curr.top()){
            left[i] = left[i-1] + 1;
            curr.push(paint[i-1]);
        }
    }
    swap(curr, backup);
    for (int i = n-1; i >= 0; i--){
        while (curr.size() && curr.top() > paint[i]){
            curr.pop();
        }
        if (curr.empty()){
            right[i] = right[i+1] + 1;
            curr.push(paint[i]);
        }else if (paint[i] == curr.top()){
            right[i] = right[i+1];
        }else if (paint[i] > curr.top()){
            right[i] = right[i+1] + 1;
            curr.push(paint[i]);
        }
    }

    //Output answer for each offline query
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        cout << left[a-1] + right[b] << "\n";
    }

    return 0;
}