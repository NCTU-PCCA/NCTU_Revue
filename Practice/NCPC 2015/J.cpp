#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
map<string, int> mp;
vector<string> idx2str;
int getId(string s) {
    if (!mp.count(s)) {
        int m = mp.size();
        mp[s] = m;
        idx2str.push_back(s);
    }
    return mp[s];
}
const int MAXN = 2e5 + 5;
struct Node : map<int, int> {
    int idx, dep, inS, ouS, C, sz;
    Node () { idx = 0; dep = sz = 0; inS = ouS = -1; }
} N[MAXN];
int r, ptr;
int newNode() { return ptr++; }
void addTrie(vector<int> arr) {
    int ans = arr.back(); arr.pop_back();
    int u = r, dep = 0;
    for (auto &v : arr) {
        if (!(N[u].count(v)))
            N[u][v] = newNode();
        u = N[u][v];
        N[u].dep = ++dep;
    }
    N[u].idx = ans + 1;
    N[u].sz = 1;
}
void dfs(int u, int &stamp, auto &res, auto &querys) {
    N[u].inS = stamp++;
    res.push_back(N[u].idx);
    for (auto &p : N[u]) {
        dfs(p.S, stamp, res, querys);
        N[u].sz += N[p.S].sz;
    }
    N[u].ouS = stamp;
    if (N[u].dep <= 105)
        querys.push_back({N[u].inS, N[u].ouS, 0, u});
}
struct Q {
    int l, r, b, idx;
    bool operator < (const Q &q) const {
        return b == q.b ? r < q.r : l < q.l;
    }
};

int maxC;
vector<int> cnt, cntcnt;
void update(int x, int op) {
    if (x == 0) return ;
    if (op == 1) {
        cntcnt[cnt[x]]--;
        cnt[x]++;
        cntcnt[cnt[x]]++;
        maxC = max(maxC, cnt[x]);
    } else {
        cntcnt[cnt[x]]--;
        if (cntcnt[cnt[x]] == 0 && maxC == cnt[x])
            maxC--;
        cnt[x]--;
        cntcnt[cnt[x]]++;
    }
}
void print(int u) {
    cout << "Node: " << u << endl;
    cout << "dep: " << N[u].dep << endl;
    cout << "maxC: " << N[u].C << endl;
    for (auto &p : N[u]) {
        cout << idx2str[p.F] << ' ';
    }
    cout << "\n\n";
    for (auto &p : N[u])
        print (p.S);
}
double dp[MAXN][105];
double solve(int u, int t) {
    if (dp[u][t] != -1) return dp[u][t];
    if (t == 0) return 0;
    double maxV = solve(0, t - 1) + (double)N[u].C / N[u].sz, sum = 0;
    for (auto &p : N[u]) {
        sum += (double)N[p.S].sz / N[u].sz * solve(p.S, t - 1);
    }
    return dp[u][t] = max(maxV, sum);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; getline(cin, s);
    vector<vector<int>> arr(m);
    ptr = 0; r = newNode();
    for (int i = 0 ; i < m ; i++) {
        getline(cin, s);
        stringstream ss; ss << s;
        string tmp;
        while (ss >> tmp)
            arr[i].push_back(getId(tmp));
        addTrie(arr[i]);
    }


    cnt.resize(2e5, 0);
    cntcnt.resize(2e5, 0);
    maxC = 0;

    vector<Q> querys;
    vector<int> res;
    int stamp = 0; dfs(0, stamp, res, querys);
    int sq = sqrt(querys.size());
    for (auto &q : querys)
        q.b = q.l / sq;
    sort(querys.begin(), querys.end());
    int l = 0, r = 0;
    for (auto &q : querys) {
        while (r < q.r) update(res[r++], 1);
        while (l > q.l) update(res[--l], 1);
        while (r > q.r) update(res[--r], -1);
        while (l < q.l) update(res[l++], -1);
        N[q.idx].C = maxC;
        // cout << "query: " << q.idx  << ' ' << maxC << endl;
    }

//    print (0);
    for (int i = 0 ; i < MAXN ; i++)
        for (int j = 0 ; j <= n ; j++)
            dp[i][j] = -1;
    cout << fixed << setprecision(20) << solve(0, n) << '\n';
}

// Cappppppppppppppppoo
