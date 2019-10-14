#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long LL;
LL query(int x) {
    cout << "ask " << x << endl;
    LL ret; cin >> ret;
    return ret;
}
const LL MOD = 1e9 + 7;
bool check(vector<int> data) {
    while (data.size() > 2) {
        vector<int> ret;
        for (int i = 1 ; i < data.size() ; i++)
            ret.push_back((data[i] - data[i - 1] + MOD) % MOD);
        bool allSame = true;
        for (int i = 1 ; i < ret.size() ; i++)
            if (ret[i] != ret[i - 1])
                allSame = false;
        if (allSame) return true;
        data = ret;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data;
    data.push_back(query(1));
    data.push_back(query(2));
    for (int i = 3 ;; i++) {
        data.push_back(query(i));
        if (check(data)) {
            cout << "degree " << i - 2 << endl;
            exit(0);
        }
    }
}
