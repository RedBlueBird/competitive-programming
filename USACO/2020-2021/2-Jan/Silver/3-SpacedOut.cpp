#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    //Each row or column can have only 2 states in order to satisfy the 2 requirements
    //Either C.C.C. or .C.C.C
    //Since each row or column are independent from each other,
    //it is not necessary to compute all the 2^n permutations.
    //Compute the sums for all the horizontal and vertical, output the max
    int horz = 0;
    for (int i = 0; i < n; i++){
        vector<int> states(2,0);
        for (int j = 0; j < n; j++){
            states[j%2] += grid[i][j];
        }
        horz += max(states[0],states[1]);
    }
    int vert = 0;
    for (int i = 0; i < n; i++){
        vector<int> states(2,0);
        for (int j = 0; j < n; j++){
            states[j%2] += grid[j][i];
        }
        vert += max(states[0],states[1]);
    }

    //Output
    cout << max(vert, horz);

    return 0;
}