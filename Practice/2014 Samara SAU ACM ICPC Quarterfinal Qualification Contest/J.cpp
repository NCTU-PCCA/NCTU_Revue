#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double eps = 1e-6;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL k; cin >> k;
    string ans;
    while (k > 0) {
        LL tar = 0;
        for(int i=1<<15;i;i>>=1){
            if((tar+i)*(tar+i+1)/2 + (tar+i) / 2 + 1<=k)
                tar += i;
        }
        for (int i = 0 ; i < tar ; i++) {
            ans += 'a';
        }
        ans += 'b';
        k -= (tar + 1) * tar / 2 + (tar) / 2+1;
        if (k < 20) {
            for (int i = 2 ; i < k + 2 ; i++)
                ans += char('a' + i);
            break;
        } else {
            ans += "yz";
            k -= 2;
        }
    }
    cout << ans << '\n';
}
