#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    vector<int>v[26];
    int n=s.size();
    for(int i=0;i<n;i++){
        v[s[i]-'a'].push_back(i);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int num = s[i]-'a';
        for(int j=0;j<26;j++){
            if(j==num)continue;
            if(lower_bound(v[j].begin(),v[j].end(),i)==v[j].end())continue;
            int ed = *lower_bound(v[j].begin(),v[j].end(),i);
            int idx2 = lower_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
            int idx = lower_bound(v[num].begin(),v[num].end(),i)-v[num].begin();
            if(idx!=v[num].size()-1&&v[num][idx+1]<ed)continue;
            if(idx2!=0&&v[j][idx2-1]>i)continue;
            ans++;
            
        }
    }
    cout << ans << endl;
}
