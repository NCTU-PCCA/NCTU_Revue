#include <bits/stdc++.h>
#define fr(i, a, b) for (int i = a ; i < b ; i++)
#define f(n) fr(i, 0, n)
#define f1(n) fr(i, 1, n + 1)
#define ll long long
#define pb push_back
    using namespace std;
vector<int>g[200005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt[n+5] = {};
    int v[n+5] = {};
    f(n-1){
        int add1, add2;
        cin >> add1 >> add2;
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    queue<int>q;
    f(m){
        int add;
        cin >> add;
        v[add] = 1;
        cnt[add] = 1;
        q.push(add);
    }
    while(!q.empty()){
        set<int>st;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(cnt[now]==m){
                cout << "YES" << endl;
                cout << now << endl;
                exit(0);
            }
            for(auto i:g[now]){
                if(!v[i]){
                    cnt[i] += cnt[now];
                    st.insert(i);
                }
            }
        }
        for(auto i:st){
            v[i] = 1;
            q.push(i);
        }
    }
    cout << "NO" << endl;
}
