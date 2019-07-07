#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct SegmentTree {
    struct Node {
        int L, R;
        Node *l, *r;
        int minV;
        Node (int L = 0, int R = 0) : L(L), R(R) {
            l = r = NULL;
            minV = INF;
        }
    }*rt, *buf, *ptr;
    SegmentTree (int n) {
        rt = build(0, n);
        buf = new Node[__lg(n) * 4 + 5];
    }
    ~SegmentTree() {
        clear(rt); delete []buf;
    }
    void clear(Node *u) {
        if (!u) return ;
        clear(u->l);
        clear(u->r);
        delete u;
    }
    Node* build(int L, int R) {
        Node *u = new Node(L, R);
        int M = (L + R) >> 1;
        if (R - L == 1) {
            u->minV = INF;
            return u;
        }
        return u->l = build(L, M), u->r = build(M, R), pull(u);
    }
    Node* pull(Node *u) {
        return pull(u, u->l, u->r);
    }
    Node* pull(Node *u, Node *l, Node *r) {
        if (!l || !r) return l ? l : r;
        u->minV = min(l->minV, r->minV);
        return u;
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, int v, Node *u = NULL) {
        if (!u) u = rt;
        if (mR <= u->L || u->R <= mL)
            return;
        if (mL <= u->L && u->R <= mR)
            return u->minV = v, void();
        modify(mL, mR, v, u->l);
        modify(mL, mR, v, u->r);
        return pull(u), void();
    }
};
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		s = " " + s;
		// int dp[n+5] = {0};
		int l[n+5] = {},r[n+5] = {};
		//for(int i = 1 ; i <= n ; i++){
		//	dp[i] = 1e6;
		//}
		for(int i = 1 ; i <=n ; i++){
			l[i] = i-k;
		}
		r[1] = -1;
		for(int i = 2 ; i <= n; i++){
			if(s[i] != s[i-1]){
				r[i] = r[i-1];
			}
			else{
				r[i] = i-2;
			}
		}
        SegmentTree *sol = new SegmentTree(n + 4);
        sol->modify(0, 1, 0);
		for(int i= 1 ; i <= n ; i++){
            int preV = sol->query(i - 1, i)->minV + 1;
            sol->modify(i, i + 1, preV);
			// dp[i] = dp[i-1] + 1;
            r[i]++;
            if (max(0, l[i]) >= r[i])
                continue;
            int minV = sol->query(max(0, l[i]), r[i])->minV;
            sol->modify(i, i + 1, min(preV, minV + 1));
			// for(int j = max(0,l[i]) ; j<= r[i] ; j++){
			// 	dp[i] = min(dp[i],dp[j]+1);
			//}
		}
        cout << sol->query(n, n + 1)->minV - 1 << '\n';
		// cout << dp[n]-1 << endl;
        delete sol;
	}
}
