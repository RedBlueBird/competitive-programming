#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Take the amount of occurrence of each distinct value as the new list
    //The problem is now reduced to decrease two elements by 1, reduce the new list to size of 1
    //where the value of the element minimized
    //This can be done through greed approach, where you always decrease the 2 highest values by 1 until it is no longer possible
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int n,a;
        cin >> n;
        map<int,int> count;
        for (int i = 0; i < n; i++){
            cin >> a;
            count[a]++;
        }
        priority_queue<int> greed;
        for (auto i: count){
            greed.push(i.ss);
        }
        int ans = 0;
        while (greed.size() > 1){
            int a = greed.top();
            greed.pop();
            int b = greed.top();
            greed.pop();
            a--;b--;
            if (a)
                greed.push(a);
            if (b)
                greed.push(b);
        }
        if (greed.size())
            cout << greed.top() << "\n";
        else
            cout << 0 << "\n";
    }


    return 0;
}