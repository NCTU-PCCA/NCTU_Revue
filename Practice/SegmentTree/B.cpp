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
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; while (cin >> n >> q) {
		vector<int> data(n);
		for (auto &v : data)
			cin >> v;
		Seg *sol = new Seg(n);
		for (int i = 0 ; i < n ; i++)
			sol->modify(i, i + 1, data[i]);
		while (q--) {
			string op; cin >> op;
			if (op[0] == 'Q') {
				int l, r; cin >> l >> r;
				l--;
				cout << sol->query(l, r)->maxV << '\n';
			} else {
				int x, v; cin >> x >> v; x--;
				sol->modify(x, x + 1, v);
			}
		}
		delete sol;
	}
}
