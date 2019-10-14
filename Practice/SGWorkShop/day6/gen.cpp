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
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q = 1e6; cout << q << '\n';
    for (int i = 0 ; i < 1e5 ; i++)
        cout << "I " << rand() % 20 - 10 << '\n', q--;
    while (q--) {
        cout << "Q " << rand() % 100000 + 1 << '\n';
    }

}
