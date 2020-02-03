#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
const int lgN = __lg(MAXN) + 5;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL sum, chg, left, right, minV;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			sum = 0; minV = INF; chg = -1;
			l = r = NULL;
			left = -1, right = -1;
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
			u->left = u->right = L;
			u->minV = u->sum = 0;
			return u;
		}
		int M = (L + R) >> 1;
		u->l = build(L, M);
		u->r = build(M, R);
		return pull(u);
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
		u->sum = l->sum + r->sum;
		u->minV = min(l->minV, r->minV);
		if (l->minV > r->minV)
			u->left = r->left;
		else 
			u->left = l->left;
		if (l->minV < r->minV)
			u->right = l->right;
		else
			u->right = r->right;
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
		if (u->chg != -1) {
			u->sum = u->chg * (u->R - u->L);
			u->minV = u->chg;
			u->left = u->L;
			u->right = u->R - 1;
			if (u->l) u->l->chg = u->chg;
			if (u->r) u->r->chg = u->chg;
			u->chg = -1;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		Seg *sol = new Seg(n);
		while (q--) {
			int k; cin >> k;
			if (k == 1) {
				int l, v; cin >> l >> v;
				if (sol->query(l, n)->sum == n - l) {
					cout << "Can not put any one.\n";
					continue;
				}
				int L = l, R = n;
				while (R - L > 1) {
					int M = (R + L) >> 1;
					if ((M - l) - sol->query(l, M)->sum < v)
						L = M;
					else
						R = M;
				}
				auto u = sol->query(l, R);
				cout << u->left << ' ' << u->right << '\n';
				sol->modify(l, R, 1);
			} else {
				int l, r; cin >> l >> r; r++;
				cout << sol->query(l, r)->sum << '\n';
				sol->modify(l, r, 0);
			}
		}
		cout << '\n';
		delete sol;
	}
}
