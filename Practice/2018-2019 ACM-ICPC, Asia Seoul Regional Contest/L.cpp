#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int nd[2005];
int wk[2005];
int main() {
    int n, m, w, h;
    cin >> n >> m >> w >> h;
    vector<int> ans[n+5];
    int tot = 0;
    for (int i  = 1 ; i <= n ; i++) {
        cin >> nd[i];
        tot += nd[i];
        if (nd[i] % w) {
            cout << -1 << '\n';
            exit(0);
        }
        nd[i] /= w;
    }
    for (int i = 1 ; i <= m ; i++) {
        cin >> wk[i];
        tot -= wk[i];
    }
    if (tot) {
        cout << -1 << '\n';
        exit(0);
    }
    priority_queue<pair<int, int> >q;
    vector<int>v;
    for (int i = 1 ; i <= n ; i++) {
        v.push_back(i);
    }
    sort(v.begin(), v.end(),[&](int x,int y) {
        return nd[x] > nd[y];
    });
    for (auto i:v) {
        if (nd[i]) {
            q.push({nd[i], i});
        }
    }
    int al[n + 5] = {};
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if(al[j] == i && nd[j]) {
                q.push({nd[j], j});
            }
        }
        //cout << i <<' '<<q.size() <<' '<< wk[i]<<endl;
        if (q.size() < wk[i]) {
 
            cout << -1 << endl;
            exit(0);
        }
        int times = wk[i];
        for (int j = 0 ; j < times ; j++) {
            int now = q.top().S;
            q.pop();
            ans[now].push_back(i);
            nd[now]--;
            for (int k = i ; k < i + w ;k++) {
                wk[k]--;
                if(wk[k]<0){
                    cout << -1 << endl;
                    exit(0);
                }
            }
            al[now]= i + w + h;
        }
    }
    cout << 1 << endl;
    for (int i = 1 ; i <= n ;i++) {
        for(auto j:ans[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
}
