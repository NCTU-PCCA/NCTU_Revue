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
//int u[15];
int b[5][5];
struct s
{
	vector<pair<pair<int,int>,int> >v;
}d[15];
set<pair<int,int> >dom;
int mx;
bool isstr(vector<int>v){
	for(int i = 0 ;i < 5 ;i++){
		int now = 0;
		int f = 0;
		for(int j=0;j<5;j++){
			if(j==i)continue;
			if(now == 0){
				now = v[j];
			}
			else{
				if(v[j]!=now+1){
					f = 1;
					break;
				}
				else{
					now++;
				}
			}
		}
		if(!f){
			return true;
		}
	}
	return false;
}
void cal(){
	int cnt = 0;
	int y = 0;
	//cout<<"gg"<<endl;
	f(5){
		vector<int>v;
		set<int>st;
		fr(j,0,5){
			v.pb(b[i][j]);
			st.insert(b[i][j]);
		}
		sort(v.begin(),v.end());
		if(v[0]==v[4]){
			if(y==0){
				cnt += 50;
				y = 1;
			}
			else{
				cnt += 100;
			}
		}
		else if(v[0]+1 == v[1] && v[1]+1 == v[2] && v[2]+1 == v[3] && v[3]+1 == v[4]){
			cnt += 40;
		}
		else if(isstr(v)){
			cnt += 30;
		}
		else if(v[0]==v[1] && v[3] == v[4] && st.size()==2){
			cnt += 25;
		}
		else if((v[0]==v[3]||v[1]==v[4])){
			cnt += v[2] * 4;
		}
		else if(v[0]==v[2]||v[1]==v[3]||v[2]==v[4]){
			cnt += v[2] * 3;
		}
	}
	f(5){
		vector<int>v;
		set<int>st;
		fr(j,0,5){
			v.pb(b[j][i]);
			st.insert(b[j][i]);
		}
		sort(v.begin(),v.end());
		if(v[0]==v[4]){
			if(y==0){
				cnt += 50;
				y = 1;
			}
			else{
				cnt += 100;
			}
		}
		else if(v[0]+1 == v[1] && v[1]+1 == v[2] && v[2]+1 == v[3] && v[3]+1 == v[4]){
			cnt += 40;
		}
		else if(isstr(v)){
			cnt += 30;
		}
		else if(v[0]==v[1] && v[3] == v[4] && st.size()==2){
			cnt += 25;
		}
		else if((v[0]==v[3]||v[1]==v[4])){
			cnt += v[2] * 4;
		}
		else if(v[0]==v[2]||v[1]==v[3]||v[2]==v[4]){
			cnt += v[2] * 3;
		}
	}
	f(1){
		vector<int>v;
		set<int>st;
		fr(j,0,5){
			v.pb(b[j][j]);
			st.insert(b[j][j]);
		}
		sort(v.begin(),v.end());
		if(v[0]==v[4]){
			if(y==0){
				cnt += 50;
				y = 1;
			}
			else{
				cnt += 100;
			}
		}
		else if(v[0]+1 == v[1] && v[1]+1 == v[2] && v[2]+1 == v[3] && v[3]+1 == v[4]){
			cnt += 40;
		}
		else if(isstr(v)){
			cnt += 30;
		}
		else if(v[0]==v[1] && v[3] == v[4] && st.size()==2){
			cnt += 25;
		}
		else if((v[0]==v[3]||v[1]==v[4])){
			cnt += v[2] * 4;
		}
		else if(v[0]==v[2]||v[1]==v[3]||v[2]==v[4]){
			cnt += v[2] * 3;
		}
	}
	f(1){
		vector<int>v;
		set<int>st;
		fr(j,0,5){
			v.pb(b[j][4-j]);
			st.insert(b[j][4-j]);
		}
		sort(v.begin(),v.end());
		if(v[0]==v[4]){
			if(y==0){
				cnt += 50;
				y = 1;
			}
			else{
				cnt += 100;
			}
		}
		else if(v[0]+1 == v[1] && v[1]+1 == v[2] && v[2]+1 == v[3] && v[3]+1 == v[4]){
			cnt += 40;
		}
		else if(isstr(v)){
			cnt += 30;
		}
		else if(v[0]==v[1] && v[3] == v[4] && st.size()==2){
			cnt += 25;
		}
		else if((v[0]==v[3]||v[1]==v[4])){
			cnt += v[2] * 4;
		}
		else if(v[0]==v[2]||v[1]==v[3]||v[2]==v[4]){
			cnt += v[2] * 3;
		}
	}
	mx = max(mx,cnt);
	//cout<<"gg"<<endl;
}
 
int main(){
	int t;
	cin >> t;
	for(int c = 1 ; c <= t ; c++){
		f(13){
			d[i].v.clear();
		}
		ms(b);
		f1(6){
			fr(j,1,7){
				dom.insert({i,j});
			}
		}
		int cur = 0;
		f(5){
			fr(j,0,5){
				if(b[i][j])continue;
				char c;
				cin >> c;
				if(c=='V'){
					int ff,ss;
					cin >> ff >> ss;
					d[cur].v.pb({{i,j},ff});
					d[cur++].v.pb({{i+1,j},ss});
					b[i][j] = ff;
					b[i+1][j] = ss;
					dom.erase({ff,ss});
					dom.erase({ss,ff});
				}
				else if(c=='H'){
					int ff,ss;
					cin >> ff >> ss;
					d[cur].v.pb({{i,j},ff});
					d[cur++].v.pb({{i,j+1},ss});
					b[i][j] = ff;
					b[i][j+1] = ss;
					dom.erase({ff,ss});
					dom.erase({ss,ff});
				}
				else{
					int ff;
					cin >> ff;
					b[i][j] = ff;
				}
			}
		}
		mx = 0;
		cal();
		f(12){
			for(auto j:dom){
				b[d[i].v[0].first.first][d[i].v[0].first.second] = j.first;
				b[d[i].v[1].first.first][d[i].v[1].first.second] = j.second;
				cal();
			}
			b[d[i].v[0].first.first][d[i].v[0].first.second] = d[i].v[0].second;
			b[d[i].v[1].first.first][d[i].v[1].first.second] = d[i].v[1].second;
 		}
		printf("Case %d: %d\n",c,mx);
	}
}
