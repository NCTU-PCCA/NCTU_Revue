#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>ans;
int solve(int cur,int rem,int l,int r){
    //cout<<cur<<' '<<rem<<' '<<l<<' '<<r<<endl;
    for(auto i:ans){
        //cout<<i<<' ';
    }
    //cout << endl;
    if(cur==s.size()-1&&l!=r){
        return 0;
    }
    else if(cur==s.size()-1){
        ans.push_back(l);
        return 1;
    }
    int mid = (l+r)>>1;
    int rsz = r-mid;
    int lsz = mid-l;
    if(s[cur]=='>'){
        while(lsz>=rsz){
            mid--;
            lsz--;
            rsz++;
        }
        //cout << "solve >\n";
        if(rsz < rem-1){
            int dif = (rem-1) - rsz;
            int nxt = mid - dif;
            ans.push_back(nxt);
            return solve(cur+1,rem-1,nxt+1,r);
        }
        else{
            ans.push_back(mid);
            return solve(cur+1,rem-1,mid+1,r);
        }
    }
    else{
        while(lsz<rsz){
            mid++;
            lsz++;
            rsz--;
        }
        //cout << lsz << ' ' << rem - 1 << '\n';
        if(lsz<rem-1){
            int dif = (rem-1) - lsz;
            int nxt = mid + dif;
            ans.push_back(nxt);
            //cout << "solve > 1\n";
            return solve(cur+1,rem-1,l,nxt-1);
        }
        else{
            ans.push_back(mid);
            //cout << "solve > 2\n";
            return solve(cur+1,rem-1,l,mid-1);
        }
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    cin >> s;
    if(s.back()!='='){
        if(s.size()>n-1){
            cout<<"-1"<<endl;
        }
        else{
            int l = 1,r = n;
            for(auto i:s){
                if(i=='>'){
                    cout<<l++<<' ';
                }
                else{
                    cout<<r--<<' ';
                }
            }
            cout << endl;
        }
    }
    else{
        if(solve(0,s.size(),1,n)){
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout << endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
