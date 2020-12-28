#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        tickets.insert(-a);
    }

    //Greedily assign each customer with the most expensive but affordable ticket possible
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        auto it = tickets.lower_bound(-a);
        if (it != tickets.end()){
            cout << *it * -1 << "\n";
            tickets.erase(it);
        }
        else{
            cout << -1 << "\n";
        }
    }


    return 0;
}