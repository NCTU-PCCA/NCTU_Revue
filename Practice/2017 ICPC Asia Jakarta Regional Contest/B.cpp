#include <bits/stdc++.h>
#define data _data
using namespace std;
typedef long long ll;
vector<int> d;
vector<int> data;
multiset<pair<int,int> >st;
multiset<int>can;
bool check(vector<vector<int> > &G, vector<int> &d) {
    d[0] = 1;  queue<int> q; q.push(0); 
    while (q.size()) {
        int p = q.front(); q.pop();
        for (auto &v : G[p]) {
            if (!d[v]) {
                d[v] = d[p] * -1;
                q.push(v);
            } else if (d[v] == d[p])
                return false;
        }
    }
    return true;
}
void update(int idx,int val){
    auto it = st.find({data[idx], d[idx]}); 

    if (it != st.begin() && prev(it)->second != it->second) {
        can.erase(can.lower_bound(it->first - prev(it)->first));
    }
    if (next(it) != st.end() && next(it)->second != it->second) {
        int target = next(it)->first - it->first;
        if (can.count(target))
            can.erase(can.lower_bound(next(it)->first - it->first));
    }
    if (it != st.begin() && next(it) != st.end() && prev(it)->second != next(it)->second) {
        can.insert(next(it)->first-prev(it)->first);
    }

    st.erase(it);
    data[idx] = val;
    st.insert({data[idx], d[idx]});
    it = st.find({data[idx], d[idx]});
    if(it != st.begin() && prev(it)->second != it->second) {
        can.insert(it->first-prev(it)->first);
    }
    if(next(it)!=st.end()&&next(it)->second!=it->second){
        can.insert(next(it)->first-it->first);
    }
    if(it!=st.begin()&&next(it)!=st.end()&&prev(it)->second!=next(it)->second){
        can.erase(can.lower_bound(next(it)->first-prev(it)->first));
    }

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    data.clear(); data.resize(n);
    for (auto &v : data)
        cin >> v;
    vector<vector<int> > G(n);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    d.clear(); d.resize(n, 0);
    if (check(G, d)) {
        for(int i=0;i<n;i++){
            st.insert({data[i],d[i]});
        }
        for (auto _i = st.begin() ; _i != st.end() ; _i++) {
            auto i = *_i;
            if(next(_i)==st.end()){
                break;
            }
            if(i.second!=next(_i)->second){
                can.insert(next(_i)->first-i.first);
            }
        }
        int q; cin >> q; while (q--) {
            int op, u, v; cin >> op >> u >> v;
            u--;
            if (op == 1) {
                v--;
                if (d[u] == d[v])
                    cout << 0 << endl;
                else {
                    cout<<*can.begin()<<endl;
                }
            } else {
                update(u,v);
            }
        }

    } else {
        int q; cin >> q; while (q--) {
            int op, u, v; cin >> op >> u >> v;
            if (op == 1)
                cout << 0 << endl;
        }
    }

}
