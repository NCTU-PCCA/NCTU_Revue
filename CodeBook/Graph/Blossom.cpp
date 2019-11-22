// LatexBegin
#include<cstdio>
#include<cstring>
#define swap(x,y) {int tt=x;x=y;y=tt;}
const int N=505*2;
const int M=124750*2;
int f[N];
struct qq
{
	int x,y;
	int last;
}s[M];
int num,last[N];
int n,m;
void init (int x,int y)
{
	num++;
	s[num].x=x;s[num].y=y;
	s[num].last=last[x];
	last[x]=num;
}
int match[N];
int id[N];//這個點是什麼點
//-1:沒訪問過  0:S點  1:T點
int q[N];//要擴充套件的佇列————也就是我們要嘗試幫誰換配偶
int pre[N];//在這次過程中,x的新配偶是誰
int Tim,vis[N];//對於lca的標記以及時間軸
int find (int x)
{
	if (f[x]==x) return f[x];
	f[x]=find(f[x]);
	return f[x];
}
int lca (int x,int y)//尋找lca
{
	Tim++;
	while (vis[x]!=Tim)
	{
		if (x!=0)
		{
			x=find(x);//先找到花根
			if (vis[x]==Tim) return x;
			vis[x]=Tim;
			if (match[x]!=0) x=find(pre[match[x]]);
			//因為在之前我們知道，每一個S點的配偶(也就是T點)的pre 都是指向他的父親的,於是就直接這麼跳就可以了
			//還有要注意的是，一定要先去到花根，因為他們現在已經是一個點了，只有花根的pre才指向他們真正的父親
			else x=0;
		}
		swap(x,y);
	}
	return x;
}
int st,ed;
void change (int x,int y,int k)//環  出現的是x---y的連邊  已知根是k
{
	while (find(x)!=k)
	{
		pre[x]=y;
		int z=match[x];
		id[z]=0;q[ed++]=z;if (ed>=N-1) ed=1;
		if (find(z)==z) f[z]=k;
		if (find(x)==x) f[x]=k;
		y=z;x=pre[y];
	}
}
void check (int X)//儘量幫助x尋找增廣路
{
	for (int u=1;u<=n;u++) {f[u]=u;id[u]=-1;}
	st=1;ed=2;
	q[st]=X;id[X]=0;
	while (st!=ed)
	{
		int x=q[st];
		for (int u=last[x];u!=-1;u=s[u].last)
		{
			int y=s[u].y;
			if (match[y]==0&&y!=X)
			//當然match[X]=0,但X(這次來尋找配偶的點)並不是一個可行的東西,所以不能算可行解
			{
				pre[y]=x;//先假設他與x相連
				int last,t,now=y;
				while (now!=0)//當然，這次來的X的match是為0，要是能更新到0就是結束
				{
					t=pre[now];//now新的配偶
					last=match[t];//理所當然啦
					match[t]=now;match[now]=t;
					now=last;
				}
				return ;
			}
			if (id[y]==-1)//找到一個沒有訪問過的點————進行擴充套件
			{
				id[y]=1;
				pre[y]=x;//先假設他與x相連
				id[match[y]]=0;q[ed++]=match[y];
				if (ed>=N-1) ed=1;
			}
			else if (id[y]==0&&find(x)!=find(y))//出現一個以前未處理過的奇環
			{
				int g=lca(x,y);
				change(x,y,g);change(y,x,g);
			}
		}
		st++;
		if (st>=N-1) st=1;
	}
}
int main()
{
	memset(vis,0,sizeof(vis));Tim=0;
	memset(match,0,sizeof(match));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	for (int u=1;u<=n;u++)
		if (match[u]==0)
			check(u);
	int ans=0;
	for (int u=1;u<=n;u++)
		if (match[u]!=0) ans++;
	printf("%d\n",ans/2);
	for (int u=1;u<=n;u++) printf("%d ",match[u]);
	return 0;
}
// LatexEnd
