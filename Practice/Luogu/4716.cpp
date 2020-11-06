#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
template<typename T>
struct zhu_liu{
	static const int MAXN=300005,MAXM=300005;
	struct node{
		int u,v;
		T w,tag;
		node *l,*r;
		node(int u=0,int v=0,T w=0):u(u),v(v),w(w),tag(0),l(0),r(0){}
		void down(){
			w+=tag;
			if(l)l->tag+=tag;
			if(r)r->tag+=tag;
			tag=0;
		}
	}mem[MAXM];//йќњж…‹иЁж†¶й«” 
	node *pq[MAXN*2],*E[MAXN*2];
	int st[MAXN*2],id[MAXN*2],m;
	void init(int n){
		for(int i=1;i<=n;++i){
			pq[i]=E[i]=0;
			st[i]=id[i]=i;
		}m=0;
	}
	node *merge(node *a,node *b){//skew heap
		if(!a||!b)return a?a:b;
		a->down(),b->down();
		if(b->w<a->w)return merge(b,a);
		swap(a->l,a->r);
		a->l=merge(b,a->l);
		return a;
	}
	void add_edge(int u,int v,T w){
		if(u!=v)pq[v]=merge(pq[v],&(mem[m++]=node(u,v,w)));
	}
	int find(int x,int *st){
		return st[x]==x?x:st[x]=find(st[x],st);
	}
	T build(int root,int n){
		T ans=0;int N=n,all=n;
		for(int i=1;i<=N;++i){
			if(i==root||!pq[i])continue;
			while(pq[i]){
				pq[i]->down(),E[i]=pq[i];
				pq[i]=merge(pq[i]->l,pq[i]->r);
				if(find(E[i]->u,id)!=find(i,id))break;
			}
			if(find(E[i]->u,id)==find(i,id))continue;
			ans+=E[i]->w;
			if(find(E[i]->u,st)==find(i,st)){
				if(pq[i])pq[i]->tag-=E[i]->w;
				pq[++N]=pq[i],id[N]=N;
				for(int u=find(E[i]->u,id);u!=i;u=find(E[u]->u,id)){
					if(pq[u])pq[u]->tag-=E[u]->w;
					id[find(u,id)]=N;
					pq[N]=merge(pq[N],pq[u]);
				}
				st[N]=find(i,st);
				id[find(i,id)]=N;
			}else st[find(i,st)]=find(E[i]->u,st),--all;
		}
		return all==1?ans:-INF;//ењ–дёЌйЂЈйЂље°±з„Ўи§Ј 
	}
};
zhu_liu<LL> solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    solver.init(n);
    int m; cin >> m;
    int r; cin >> r;
    while (m--) {
        int u, v; LL w; cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }
    LL ans = solver.build(r, n);
    if (ans == -INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}
