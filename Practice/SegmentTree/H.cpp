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
		LL minV;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			minV = INF;
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
			u->minV = 1;
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
		if (qL <= u->L && u->R <= qR)
			return u;
		return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
	}
	Node* pull(Node *u, Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		u->minV = min(l->minV, r->minV);
		return u;
	}
	Node* pull(Node *u) {
		return pull(u, u->l, u->r);
	}
	void modify(int mL, int mR, LL v, Node *u = NULL) {
		if (!u) u = rt;
		if (mR <= u->L || u->R <= mL) return ;
		if (mL <= u->L && u->R <= mR) {
			u->minV = v;
			return ;
		}
		modify(mL, mR, v, u->l);
		modify(mL, mR, v, u->r);
		pull(u);
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<int> stk;
	int n, q; while (cin >> n >> q) {
		Seg *sol = new Seg(n);
		while (q--) {
			string op; cin >> op;
			if (op[0] == 'D') {
				int x; cin >> x; x--;
				stk.push_back(x);
				sol->modify(x, x + 1, 0);
			} else if (op[0] == 'Q') {
				int x; cin >> x; x--;
				int L = -1, R = x;
				while (R - L > 1) {
					int M = (L + R) >> 1;
					if (sol->query(M, x + 1)->minV == 0)
						L = M;
					else
						R = M;
				}
				int l = R;
				L = x, R = n + 1;
				while (R - L > 1) {
					int M = (L + R) >> 1;
					if (sol->query(x, M)->minV == 0)
						R = M;
					else
						L = M;
				}
				int r = L;
				cout << r - l << '\n';
			} else if (op[0] == 'R') {
				int x = stk.back(); stk.pop_back();
				sol->modify(x, x + 1, 1);
			}
		}
		delete sol;
	}
}
