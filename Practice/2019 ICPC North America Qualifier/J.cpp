#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<double> data;
    for(int i=0;i<n;i++){
        double add;
        cin >> add;
        data.push_back(add);
    }
    double sum = 0;
    double ans = 0;
    for(int i=0;i<n;i++){
        sum += data[i];
        ans = max(ans,sum/(i+1));
    }
    reverse(data.begin(),data.end());
    sum = 0;
    for(int i=0;i<n;i++){
        sum += data[i];
        ans = max(ans,sum/(i+1));
    }
    cout <<fixed<<setprecision(10)<< ans << endl;
}
