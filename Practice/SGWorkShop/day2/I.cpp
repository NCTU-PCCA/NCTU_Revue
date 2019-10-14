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
string s1,s2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    if((n-m)&1){
        cout<<"NO"<<endl;
        exit(0);
    }
    s1 = " "+s1;
    s2 = " "+s2;
    int odd = 0;
    int even = 0;
    for(int i=1;i<s2.size();i+=2){
        if(s2[i]==s1[1]){
            if(i%2==1){
                odd=i;
                break;
            }
        }
    }
    int ans = 0;
    if(odd){
        int p2 = odd;
        int p1 = 1;
        while(p2<s2.size()&&p1<s1.size()){
            if(s1[p1]==s2[p2]){
                p2++;
                p1++;
            }
            else{
                p2+=2;
            }
        }
        if(p1==s1.size()){
            ans = 1;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
