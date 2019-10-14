#include <bits/stdc++.h>
using namespace std;
struct B : vector<int> { int id; };
bool legal;
void rotate(B &b) {
    B ret; ret.resize(4);
    ret[0] = b[1];
    ret[1] = b[2];
    ret[2] = b[3];
    ret[3] = b[0];
    ret.id = b.id;
    b = ret;
}
bool corner(B &b) {
    for (int i = 0 ; i < 4 ; i++) {
        if (b[0] == 0 && b[1] == 0)
            return true;
        rotate(b);
    }
    return false;
}
map<int, vector<int> > pos;
//      0
//  1       3
//      2
void right(vector<int> &target, vector<int> &prev, vector<B> &bs) {
    if (!legal) return ;
    while (bs[target.back()][3] != 0) {
        vector<int> res = pos[bs[target.back()][3]];
        if (res[0] == target.back())
            swap(res[0], res[1]);
        while (bs[res[0]][1] != bs[target.back()][3])
            rotate(bs[res[0]]);
        if (prev.size() == 0) {
            if (bs[res[0]][0] != 0)
                legal = false;
        } else {
            if (target.size() + 1 > prev.size() || bs[res[0]][0] != bs[prev[target.size()]][2])
                legal = false;
        }
        if (!legal) return ;
        target.push_back(res[0]);
    }
}
void go(vector<vector<int> > &ans, vector<B> &bs) {
    vector<int> fake;
    right(ans[0], fake, bs);
    int cnt = ans[0].size();
    while (legal && cnt < bs.size() && bs[ans.back()[0]][2] != 0) {
        vector<int> res = pos[bs[ans.back()[0]][2]];
        if (res[0] == ans.back()[0])
            swap(res[0], res[1]);
        while (bs[res[0]][0] != bs[res[1]][2])
            rotate(bs[res[0]]);
        ans.push_back({res[0]});
        right(ans.back(), ans[ans.size() - 2], bs);
        if (ans.back().size() != ans[0].size()) {
            legal = false;
            return ;
        }
        cnt += ans.back().size();
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, cnt = 0; cin >> n;
    vector<B> bs(n);
    pos.clear();
    for (auto &b : bs) {
        b.resize(4);
        for (auto &v : b) {
            cin >> v;
            pos[v].push_back(cnt);
        }
        b.id = cnt;
        cnt++;
    }
    for (int i = 0 ; i < n ; i++) {
        B b = bs[i];
        if (corner(b)) {
            legal = true;
            vector<vector<int> > ans(1);
            ans[0].push_back(b.id);
            go(ans, bs);
            if ((int)ans.size() * ans[0].size() != n)
                legal = false;
            for (auto &v : ans.back())
                if (bs[v][2] != 0)
                    legal = false;
            if (legal) {
                cout << ans.size() << ' ' << ans[0].size() << '\n';
                for (auto &vv : ans) {
                    for (int i = 0 ; i < vv.size() ; i++)
                        cout << vv[i] + 1 << ' ';
                    cout << endl;
                }
                exit(0);
            }
        }
    }
    if (!legal)
        cout << "impossible\n";
}
