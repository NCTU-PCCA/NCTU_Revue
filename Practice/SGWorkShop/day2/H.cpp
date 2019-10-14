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

void print(int tar1, int tar2, string s) {
    for (int i = 0; i < 4; i ++) {
        if ((1 << i) & tar1) cout << '*';
        else cout << '.';
    }
    cout << '|';
    for (int i = 4; i < 8; i ++) {
        if ((1 << i) & tar1) cout << '*';
        else cout << '.';
    }
    cout << " " << s << " ";
    for (int i = 0; i < 4; i ++) {
        if ((1 << i) & tar2) cout << '*';
        else cout << '.';
    }
    cout << '|';
    for (int i = 4; i < 8; i ++) {
        if ((1 << i) & tar2) cout << '*';
        else cout << '.';
    }
    cout << '\n';
    for (int i = 8; i < 12; i ++) {
        if ((1 << i) & tar1) cout << '*';
        else cout << '.';
    }
    cout << '|';
    for (int i = 12; i < 16; i ++) {
        if ((1 << i) & tar1) cout << '*';
        else cout << '.';
    }
    cout << "     ";
    for (int i = 8; i < 12; i ++) {
        if ((1 << i) & tar2) cout << '*';
        else cout << '.';
    }
    cout << '|';
    for (int i = 12; i < 16; i ++) {
        if ((1 << i) & tar2) cout << '*';
        else cout << '.';
    }
    cout << '\n';
    cout << "---\n";
}
int buy(int S) {
    if (S == 0) return (1 << 10) - 1;
    bool ok = false;
    int ptr = 0;
    while (1) {
        if (S & (1 << ptr)) ok = true;
        if (ok && (S & (1 << ptr)) == 0) {
            for (int x = 0 ; x < 10 ; x++)
                S ^= (1 << ((x + ptr) % 16));
            break;
        }
        ptr++; ptr %= 16;
    }
    return S;
}
int eat(int S) {
    bool ok = false;
    int ptr = 0;
    while (1) {
        if ((S & (1 << ptr)) == 0) ok = true;
        if (ok && (S & (1 << ptr))) {
            S ^= (1 << ptr);
            break;
        }
        ptr++; ptr %= 16;
    }
    return S;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> used(1 << 16, 0);
    used[0] = 1;
    queue<int> q; q.push(0);
    while (q.size()) {
        int p = q.front(); q.pop();
        if (__builtin_popcount(p) <= 5) {
            int bp = buy(p);
            print(p, bp, "buy");
            if (!used[bp]) {
                used[bp] = 1;
                q.push(bp);
            }
        }
        if (__builtin_popcount(p) > 0) {
            int ep = eat(p);
            print(p, ep, "eat");
            if (!used[ep]) {
                used[ep] = 1;
                q.push(ep);
            }
        }
    }
}
