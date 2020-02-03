#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
const int lgN = __lg(MAXN) + 5;
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL maxV, chg;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			maxV = chg = 0;
			l = r = NULL;
		}
	}buf[lgN << 2], *ptr, *rt;
	Seg(int n) {
		rt = build(0, n);
	}
	~Seg() {
		remove(rt);
	}
	void remove(Node *u) {
		if (!u) return ;
		remove(u->l);
		remove(u->r);
		delete u;
	}
	Node* build(int L, int R) {
		Node *u = new Node(L, R);
		if (R - L == 1) {
			return u;
		}
		int M = (L + R) >> 1;
		u->l = build(L, M);
		u->r = build(M, R);
		return u;
	}
	Node* query(int qL, int qR, Node *u = NULL) {
		if (!u) ptr = buf, u = rt;
		if (qR <= u->L || u->R <= qL)
			return NULL;
		push(u);
		if (qL <= u->L && u->R <= qR)
			return u;
		return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
	}
	Node* pull(Node *u, Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		push(l); push(r);
		u->maxV = max(l->maxV, r->maxV);
		return u;
	}
	Node* pull(Node *u) {
		return pull(u, u->l, u->r);
	}
	void modify(int mL, int mR, LL v, Node *u = NULL) {
		if (!u) u = rt;
		if (mR <= u->L || u->R <= mL) return ;
		push(u);
		if (mL <= u->L && u->R <= mR) {
			u->chg = v;
			return ;
		}
		modify(mL, mR, v, u->l);
		modify(mL, mR, v, u->r);
		pull(u);
	}
	void push(Node *u) {
		if (!u) return ;
		if (u->chg) {
			u->maxV = u->chg;
			if (u->l) u->l->chg = u->chg;
			if (u->r) u->r->chg = u->chg;
			u->chg = 0;
		}
	}
};
void dfs(int u, vector<vector<int> > &G, vector<int> &in, vector<int> &out, int &stamp) {
	in[u] = stamp++;
	for (auto &v : G[u])
		dfs(v, G, in, out, stamp);
	out[u] = stamp++;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, kase = 0; cin >> t; while (t--) {
		cout << "Case #" << ++kase << ":\n";
		int n; cin >> n;
		vector<vector<int> > G(n), revG(n);
		for (int i = 0 ; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			u--, v--;
			G[v].push_back(u);
			revG[u].push_back(v);
		}
		int rt = 0;
		while (revG[rt].size())
			rt = revG[rt][0];
		vector<int> in(n, -1);
		vector<int> out(n, -1);
		int stamp = 0;
		dfs(rt, G, in, out, stamp);
		Seg *sol = new Seg(n * 2);
		for (int i = 0 ; i < 2 * n ; i++)
			sol->modify(i, i + 1, -1);
		int q; cin >> q; while (q--) {
			string op; cin >> op;
			if (op[0] == 'C') {
				int x; cin >> x; x--;
				cout << sol->query(in[x], in[x] + 1)->maxV << '\n';
			} else {
				int x, v; cin >> x >> v; x--;
				sol->modify(in[x], out[x], v);
			}
		}
		delete sol;
	}
}
