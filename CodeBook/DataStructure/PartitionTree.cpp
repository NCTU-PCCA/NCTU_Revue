#include <bits/stdc++.h>
using namespace std;
// LatexBegin
const int MAXN = 50005;
const int lgN = __log(MAXN) + 5;
struct PT{
    int sorted[MAXN];
    int tree[lgN][MAXN];
    int toleft[lgN][MAXN];
    int n;
    void build(int l, int r, int dep){
        if (l == r) return ;
        int mid = (l+r) >> 1;
        int same = mid - l + 1;
        for (int i = l ; i <= r ; i++)
            if (tree[dep][i] < sorted[mid])
                same--;
        int lpos =  l;
        int rpos = mid+1;
        for (int i = l ; i <= r ; i++){
            if (tree[dep][i] < sorted[mid])
                tree[dep+1][lpos++] = tree[dep][i];
            else if (tree[dep][i] == sorted[mid] && same){
                tree[dep+1][lpos++] = tree[dep][i];
                same--;
            }else
                tree[dep+1][rpos++] = tree[dep][i];
            toleft[dep][i] = toleft[dep][l-1] + lpos - l;
        }
        build(l ,mid, dep+1);
        build(mid+1, r, dep+1);
    }
    int query(int L, int R, int l, int r, int dep, int k){
        if (l == r) return tree[dep][l];
        int mid = (L+R) >> 1;
        int cnt = toleft[dep][r] - toleft[dep][l-1];
        if (cnt >= k){
            int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
            int newr = newl + cnt - 1;
            return Query(L, mid, newl, newr, dep+1, k);
        }else{
            int newr = r + toleft[dep][R] - toleft[dep][r];
            int newl = newr - (r - l - cnt);
            return Query(mid + 1, R, newl, newr, dep+1, k-cnt);
        }
    }
    void Insert(int _n){
        n = _n;
        for (int i = 0 ; i < n ; i++){
            cin >> tree[0][i];
            sorted[i] = tree[0][i];
        }
        sort(sorted, sorted + n);
        build(0, n-1, 0);
    }
    int query(int l, int r, int k){
        return query(0, n-1, l, r, 0, k);
    }
}_PT;
int main(){
    int n, q; cin >> n >> q;
    _PT.Insert(n);
    for (int i = 0 ; i < q;  i++){
        int x, y, k; cin >> x >> y >> k;
        cout << _PT.query(x-1, y-1, k) << '\n';
    }
}
// LatexEnd
