#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int getid(int x,int y){
    return x*m+y;
}
vector<int>g[100005];
int dis[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    string s[n+5];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            if(s[i][0]=='M'){
                cout<<"-1"<<endl;
                exit(0);
            }
        }
        cout<<n<<endl;
        exit(0);
    }
    int dx[]={1,0,-1, 0};
    int dy[]={-1,-2,-1, -1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='M')continue;
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = (j+m+dy[k])%m;
                int ny2 = (ny+1+m)%m;
                if(nx>=n||nx<0||ny>=m||ny<0)continue;
                if(s[nx][ny]=='M'||s[nx][ny2]=='M')continue;
                int x = getid(i,j);
                int y = getid(nx,ny);
                g[x].push_back(y);
               // cout<<i<<' '<<j<<' '<<nx<<' '<<ny<<endl;
               // cout << x <<' '<<y<<endl;
            }
        }
    }
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        int now =q.front();
        q.pop();
        for(auto i:g[now]){
            if(~dis[i])continue;
            dis[i]=dis[now]+1;
            q.push(i);
        }
    }
    int ans = 1e7;
    for(int i=0;i<m;i++){
        if(~dis[getid(n-1,i)]){
            //cout<<getid(n-1,i)<<' '<<dis[getid(n-1,i)]<<endl;;
            ans = min(ans,dis[getid(n-1,i)]);
        }
    }
    if(ans == 1e7){
        cout<<-1<<endl;
    }
    else{
        cout<<ans+1<<endl;
    }
}
