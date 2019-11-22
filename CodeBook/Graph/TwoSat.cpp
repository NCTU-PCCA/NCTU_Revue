// LatexBegin
vector<int>g[maxn]; 
vector<int>rev[maxn]; 
stack<int>st;  
int n,m,scc,idx;  
int low[maxn],dfn[maxn],instack[maxn],fa[maxn];  
int ans[maxn];
int in[maxn];
int opp[maxn],c[maxn];
void tarjan(int now){
	dfn[now] = low[now] = ++idx;
	instack[now] = 1;
	st.push(now);
	for(auto i:g[now]){
		if(!dfn[i]){
			tarjan(i);
			low[now] = min(low[now],low[i]);
		}
		else if(instack[i]){
			low[now] = min(low[now],dfn[i]);
		}
	}
	if(dfn[now] == low[now]){
		scc++;
		while(1){
			int cur = st.top();
			st.pop();
			instack[cur] = 0;
			fa[cur] = scc;
			if(cur == now)break;
		}
	}
}
bool check(){
	for(int i=0;i<2*n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=0;i<2*n;i+=2){
		if(!nd[i/4])continue;
		opp[fa[i]] = fa[i+1];
		opp[fa[i+1]] = fa[i];
	}
	return 1;
}
void build(){
	for(int i=1;i<=n;i++){
		int x = fa[i];
		for(auto j:g[i]){
			int y = fa[j];
			if(x!=y){
				rev[y].push_back(x);
				in[x]++;
			}
		}
	}
}
void topo(){
	memset(c,0,sizeof(c));
	queue<int>q;
	f1(scc){
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(!c[now]){
			c[now] = 1;
			c[opp[now]] = 2;
		}
		for(auto i:rev[now]){
			in[i]--;
			if(!in[i]){
				q.push(i);
			}
		}
	}	
}
// LatexEnd
