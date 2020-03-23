#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
int n, m;
int a[1030][1030];
int pre[1030][1030];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ms(a);
        ms(pre);
        cin >> n >> m;
        f1(n){
            
            for(int j = 1 ; j <= m; j++){
                char c = getchar();
                while(c != '0' && c != '1'){
                    c = getchar();
                }
                if(c == '1'){
                    a[i][j] = 1;
                }
            }
        }
        f1(n){
            fr(j,1,m+1){
                pre[i][j] = pre[i-1][j] + pre[i][j-1] + a[i][j] - pre[i-1][j-1];
            }
        }
        int l = 1, r = 1005;
        while(r - l > 1){
            int mid = (r + l) >> 1;
            int f = 0;
            //cout << mid << endl;
            for(int i = mid ; i <= n ; i++){
                for(int j = mid ; j <= m; j++){
                    int cnt = pre[i][j] - pre[i - mid][j] - pre[i][j - mid] + pre[i - mid][j - mid];
                    if(cnt <= 1){
                        f = 1;
                        break;
                    }
                }
                if(f){
                    break;
                }
            }
            //cout << f << endl;
            if(f){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        cout << l << '\n';
    }
}
