#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n = 100;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int c = 0;
            bool valid = true;
            while (pow(3,c) <= i || pow(3,c) <= j){
                int a = (i/int(pow(3,c)))%3;
                int b = (j/int(pow(3,c)))%3;
                c++;
                if (a == b || a + b == 2)
                    continue;
                valid = false;
                break;
            }
            if (valid)
                cout << 1;
            else
                cout << " ";
        }
        cout << "\n";
    }


    return 0;
}