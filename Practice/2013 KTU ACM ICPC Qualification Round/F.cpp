#include <bits/stdc++.h>
using namespace std;
int atk[2], def[2], heal[2], isHit[2];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        atk[0] = atk[1] = 0;
        heal[0] = heal[1] = 0;
        def[0] = def[1] = 0;
        isHit[0] = isHit[1] = 0;
        for (int x = 0 ; x < 2 ; x++) 
        for (int i = 0 ; i < 10 ; i++) {
            string op; cin >> op;
            if (op == "HIT!")
                isHit[x] = 1;
            else {
                int v; cin >> v;
                if (op[0] == 'A')
                    atk[x] = max(atk[x], v);
                if (op[0] == 'D')
                    def[x] = max(def[x], v);
                if (op[0] == 'H')
                    heal[x] = max(heal[x], v);
            }
        }
        int hp[2]; hp[0] = hp[1] = 10;


        if (isHit[0] && !isHit[1]) { // b gg
bGG:;
            int turn = 2;
            int aA = atk[0], bD = def[1];
            while (1) {
                hp[1] -= aA - bD; turn++;
                if (hp[1] <= 0)
                    break;
                hp[1] += heal[1]; turn++;
                if (turn > 12)
                    goto aGG;
            }
            cout << "win " << turn << '\n';
        } else if (!isHit[0] && isHit[1]) { // a gg
aGG:;
            int turn = 2;
            int aD = def[0], bA = atk[1];
            while (1) {
                hp[0] += heal[0]; hp[0] = min(10, hp[0]); turn++;
                hp[0] -= bA - aD; turn++;
                if (hp[0] <= 0)
                    break;
                if (turn > 12)
                    goto bGG;
            }
            cout << "lose " << turn << '\n';
        } else {
            if (atk[0] <= def[1] || atk[0] - def[1] <= heal[1]) { // A gg
                goto aGG;
            } else if (atk[1] <= def[0] || atk[1] - def[0] <= heal[0]) { // b gg
                goto bGG;
            } else {
                int a = atk[0] - def[1];
                int b = atk[1] - def[0];
                if ((10 - 1) / a + 1 <= (10 - 1) / b + 1)
                    goto bGG;
                else
                    goto aGG;
            }
        }
    }
}
