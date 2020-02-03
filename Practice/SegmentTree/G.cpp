#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL v;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			v = 0;
			l = r = NULL;
		}
	}buf[100], *ptr, *rt;
	Seg(vector<LL> &arr) {
		rt = build(0, arr.size(), arr);
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
	Node* build(int L, int R, vector<LL> &arr) {
		Node *u = new Node(L, R);
		if (R - L == 1) {
			u->v = arr[L];
			return u;
		}
		int M = (L + R) >> 1;
		u->l = build(L, M, arr);
		u->r = build(M, R, arr);
		return pull(u);
	}
	Node* query(int qL, int qR, Node *u = NULL) {
		if (!u) ptr = buf, u = rt;
		if (qR <= u->L || u->R <= qL)
			return NULL;
		if (qL <= u->L && u->R <= qR)
			return u;
		return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
	}
	Node* pull(Node *u, Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		u->v = l->v + r->v;
		return u;
	}
	Node* pull(Node *u) {
		return pull(u, u->l, u->r);
	}
	void modify(int mL, int mR, Node *u = NULL) {
		if (!u) u = rt;
		if (mR <= u->L || u->R <= mL) return ;
		if (u->v == u->R - u->L) return ;
		if (u->R - u->L == 1) {
			u->v = sqrt(u->v);
			pull(u);
			return ;
		}
		modify(mL, mR, u->l);
		modify(mL, mR, u->r);
		pull(u);
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, kase = 0; while (cin >> n) {
		cout << "Case #" << ++kase << ":\n";
		vector<LL> data(n);
		for (auto &v : data)
			cin >> v;
		Seg *sol = new Seg(data);
		int q; cin >> q; while (q--) {
			int k; cin >> k;
			if (k == 0) {
				int l, r; cin >> l >> r; 
				if (l > r) swap(l, r);
				l--;
				sol->modify(l, r);
			} else {
				int l, r; cin >> l >> r; 
				if (l > r) swap(l, r);
				l--;
				cout << sol->query(l, r)->v << '\n';
			}
		}
		cout << '\n';
		delete sol;
	}
}
