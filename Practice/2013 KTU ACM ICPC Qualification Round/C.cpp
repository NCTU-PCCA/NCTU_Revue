#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
const int mod = 1e9+7;
string s;
int sum[26];
struct seg
{
	int v[26];	
}tree[maxn<<2];
 
void pushup(int idx){
	f(26){
		tree[idx].v[i] = tree[idx<<1].v[i] + tree[idx<<1|1].v[i];
	}
}
void build(int idx,int l,int r){
	if(l == r){
		f(26){
			tree[idx].v[i] = 0;
		}
		return ;
	}
	int mid = (l+r) >> 1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	pushup(idx);
}
void update(int idx,int l,int r,int x,int v){
	if(l==r){
		f(26){
			if(i==v){
				tree[idx].v[i]=1;
			}
			else{
				tree[idx].v[i]=0;
			}
		}
		return ;
	}
	int mid = (l+r) >> 1;
	if(x <= mid){
		update(idx<<1,l,mid,x,v);
	}
	else{
		update(idx<<1|1,mid+1,r,x,v);
	}
	pushup(idx);
}
void query(int idx,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r){
		f(26){
			sum[i] += tree[idx].v[i];
		}
		return;
	}
	int mid = (l+r) >> 1;
	if(ql <= mid){
		query(idx<<1,l,mid,ql,qr);
	}
	if(qr > mid){
		query(idx<<1|1,mid+1,r,ql,qr);
	}
}
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >>t;
	for(int c=1;c<=t;c++){
		printf("Case #%d:\n",c);
		cin >> s;
		int n = s.size();
		s = " "+s;
		build(1,1,n);
		f1(n){
			int num = s[i] - 'A';
			update(1,1,n,i,num);
		}
		int m;
		cin >> m;
		while(m--){
			char op;
			cin >> op;
			int l,r;
			cin >> l >> r;
			l++,r++;
			if(op =='g'){
				f(26){
					sum[i] = 0;
				}
				query(1,1,n,l,r);
				f(26){
					cout<<sum[i]<<' ';
				}
				cout<<'\n';
			}
			else{
				f(26){
					sum[i] = 0;
				}
				query(1,1,n,l,r);
				int idx = l;
				f(26){
					while(sum[i]--){
						update(1,1,n,idx,i);
						idx++;
					}
				}
			}
 
		}
		
	}
}
