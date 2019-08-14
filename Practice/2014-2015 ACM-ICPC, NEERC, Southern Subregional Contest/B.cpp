#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int m = n / k;
    vector<int> data(n);
    vector<vector<int> > cnt(k);
    for (int i = 0 ; i < n ; i++) {
        cin >> data[i];
        if (data[i] == -1)
            data[i] = 1;
        data[i]--;
        cnt[data[i]].push_back(i);
    }

    set<pii> pool;
    for (int i = 0 ; i < k ; i++) {
        if (cnt[i].size())
            pool.insert({cnt[i].size(), i});
    }
    vector<int> idx(n, -1);
    vector<pii> val;
    while (pool.size()) {
        if (pool.size() == 1) {
            pii target = *pool.begin();
            pool.erase(target);
            target.F -= m;
            for (int i = 0 ; i < m ; i++) {
                idx[cnt[target.S].back()] = val.size();
                cnt[target.S].pop_back();
            }
            val.push_back({target.S, target.S});
            if (target.F != 0)
                pool.insert(target);
        } else {
            pii Min = *pool.begin();
            pii Max = *prev(pool.end());
            pool.erase(Min);
            pool.erase(Max);
            if (Min.F >= m) {
                Min.F -= m;
                for (int i = 0 ; i < m ; i++) {
                    idx[cnt[Min.S].back()] = val.size();
                    cnt[Min.S].pop_back();
                }
                val.push_back({Min.S, Min.S});
                if (Min.F != 0)
                    pool.insert(Min);
                pool.insert(Max);
            } else {
                for (int i = 0 ; i < Min.F ; i++) {
                    idx[cnt[Min.S].back()] = val.size();
                    cnt[Min.S].pop_back();
                }
                Max.F -= m - Min.F;
                for (int i = Min.F ; i < m ; i++) {
                    idx[cnt[Max.S].back()] = val.size();
                    cnt[Max.S].pop_back();
                }
                val.push_back({Max.S, Min.S});
                if (Max.F != 0)
                    pool.insert(Max);
            }
        }
    }
    cout << "Yes\n";
    for (auto &v : idx)
        cout << val[v].F + 1 << ' ' << val[v].S + 1 << '\n';
    cout << '\n';
}
