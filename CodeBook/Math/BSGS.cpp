#include <bits/stdc++.h>
#include "Extgcd.cpp"
#include "ModInv.cpp"
using namespace std;
// LatexBegin
LL BSGS(LL B, LL N, LL P) { //  B^L = N mod 
    unordered_map<LL, int> R;
    LL sq = (LL)(sqrt(P) + 1e-6), t = 1;
    for (int i = 0 ; i < sq ; i++) {
        if (t == N) return i;
        if (!R.count(t)) R[t] = i;
        t = (t * B) % P;
    }
    
    LL f = modInv(t, P);
    for (int i = 0 ; i <= sq + 1 ; i++) {
        if (R.count(N)) return i * sq + R[N];
        N = (N * f) % P;
    }
    return -1;
}
int main() {
    int a, b, n; while (cin >> a >> b >> n) {
        LL L = BSGS(a, b, n);
        if (L == -1) cout << "NOT FOUND\n";
        else cout << L << '\n';
    }
}
// LatexEnd
