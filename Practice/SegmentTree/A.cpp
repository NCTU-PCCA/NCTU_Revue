#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
const int lgN = __lg(MAXN) + 5;
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL v, add;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			v = add = 0;
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
		if (!u) ptr = buf, u->rt;
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
		u->v = l->v + r->v;
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
			u->add += v;
			return ;
		}
		modify(mL, mR, v, u->l);
		modify(mL, mR, v, u->r);
		pull(u);
	}
	void push(Node *u) {
		if (!u) return ;
		if (u->add) {
			u->v += u->add * (u->R - u->L);
			if (u->l) u->l->add += u->add;
			if (u->r) u->r->add += u->add;
			u->add = 0;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, kase = 0; cin >> t; while (t--) {
		cout << "Case " << ++kase << ":\n";
		int n; cin >> n;
		vector<int> data(n);
		for (auto &v : data)
			cin >> v;
		Seg *sol = new Seg(n);
		for (int i = 0 ; i < n ; i++)
			sol->modify(i, i + 1, data[i]);
		string s; while (cin >> s) {
			if (s[0] == 'E')
				break;
			if (s[0] == 'A') {
				int l, r; cin >> l >> r; l--;
				sol->modify(l, l + 1, r);
			}
			if (s[0] == 'S') {
				int l, r; cin >> l >> r; l--;
				sol->modify(l, l + 1, -r);
			}
			if (s[0] == 'Q') {
				int l, r; cin >> l >> r; l--;
				cout << sol->query(l, r)->v << '\n';
			}
		}
		delete sol;
	}
}
