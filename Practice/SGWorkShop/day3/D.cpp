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
struct S {
    int idx;
    vector<int> data;
    bool operator < (const S &rhs) const {
        return data == rhs.data ? idx < rhs.idx : data < rhs.data;
    }
};
int get_int() {
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    int ret = 0;
    while (isdigit(ch)) {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}
int main() {
    int n = get_int();
    vector<S> all(n);
    for (int i = 0 ; i < n ; i++) {
        int t = get_int();
        while (t--)
            all[i].data.push_back(get_int());
        all[i].idx = i;
    }
    sort(all.begin(), all.end());
    for (int i = 0 ; i < n ; i++)
        cout << all[i].idx + 1 << '\n';
}
