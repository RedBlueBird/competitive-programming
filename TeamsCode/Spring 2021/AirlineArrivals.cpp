#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    string time;
    cin >> time;
    string first = time.substr(0,2);
    string second = time.substr(3,4);
    int hour = stoi(first);
    int minute = stoi(second);
    double speed, distance;
    cin >> speed >> distance;

    //Compute
    int hourGain = floor(distance/speed);
    int minuteGain = ((distance/speed) - double(hourGain))*60;
//    cout << hour << " " << minute << "\n";
//    cout << hourGain << " " << minuteGain << "\n";
    minute += minuteGain;
    hour += hourGain + minute/60;
    minute = minute%60;
    hour = hour%24;

    //Output
    cout << hour << ":" << minute;

    return 0;
}