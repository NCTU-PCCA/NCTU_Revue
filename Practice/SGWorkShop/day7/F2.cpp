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
struct ST {
    vector<vector<LL> > data;
    vector<vector<LL> > idx;
    ST (vector<LL> &arr) {
        int n = (int)arr.size(), lgN = __lg(n) + 1;
        data.clear(); data.resize(lgN);
        for (int i = 0 ; i < n ; i++)
            data[0].push_back(arr[i]),
            idx[0].push_back(i);
        for (int h = 1 ; h < lgN ; h++) {
            int len = (1 << (h - 1)), i = 0;
            for (; i + len < n ; i++) {
                data[h].push_back(max(data[h - 1][i], data[h - 1][i + len]));
            if (!i) break;
            for (; i < n ; i++)
                data[h].push_back(data[h - 1][i]);
        }
    }
    LL query(int l, int r) {
        int h = __lg(r - l), len = (1 << h);
        return max(data[h][l], data[h][r - len]);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<LL> data(n), preS{0};
    for (auto &v : data)
        cin >> v, preS.push_back(preS.back() + v);
    ST *st = new ST(data);
    bool isA = true;
    for (int i = 0 ; i < n ; i++) {
        cout << i << endl;
        if (isA) {
            if (preS[n] - preS[i] <= a) {
                cout << "ALICE\n";
                exit(0);
            } else if (data[i] > a) {
                cout << "BOB\n";
                exit(0);
            }
            int L = i, R = n;
            while (R - L > 1) {
                int M = (R + L) >> 1;
                if (preS[M] - preS[i] <= a)
                    L = M;
                else
                    R = M;
            }
            // [i, R)
            st->query(i, R)
        } else {
            if (preS[n] - preS[i] <= b) {
                cout << "BOB\n";
                exit(0);
            } else if (data[i] > b) {
                cout << "ALICE\n";
                exit(0);
            }
            if (st->query(i, n) <= a) {
                b -= data[i];
            } else {
                int L = i + 1, R = n;
                while (R - L > 1) {
                    int M = (R + L) >> 1;
                    if (st->query(L, M) > a && preS[M] - preS[i] <= b) {
                        R = M;
                    } else 
                        L = M;
                }
                cout << L << ' ' << R << '\n';
            }
        }
        isA = !isA;
    }
    if (isA) {
        cout << "BOB\n";
    } else 
        cout << "ALICE\n";
    delete st;
}
