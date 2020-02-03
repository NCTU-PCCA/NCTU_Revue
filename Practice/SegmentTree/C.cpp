#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 4 * (1e5 + 5);
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL v, add;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			v = add = 0;
			l = r = NULL;
		}
	}_memN[MAXN * 4], *memPtr, buf[200], *ptr, *rt;
	Seg() { }
	void init(vector<int> &arr) {
		memPtr = _memN;
		rt = build(0, arr.size(), arr);
	}
	Node* build(int L, int R, vector<int> &arr) {
		Node *u = new (memPtr++) Node(L, R);
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
		push(u);
		if (qL <= u->L && u->R <= qR)
			return u;
		return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
	}
	inline Node* pull(Node *u, Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		push(l); push(r);
		u->v = l->v + r->v;
		return u;
	}
	inline Node* pull(Node *u) {
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
	inline void push(Node *u) {
		if (!u) return ;
		if (u->add) {
			u->v += u->add * (u->R - u->L);
			if (u->l) u->l->add += u->add;
			if (u->r) u->r->add += u->add;
			u->add = 0;
		}
	}
}seg;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q; while (cin >> n >> q) {
		vector<int> data(n);
		for (int i = 0 ; i < n ; i++)
			cin >> data[i];
		seg.init(data);
		while (q--) {
			string op; cin >> op;
			if (op[0] == 'Q') {
				int l, r; cin >> l >> r; l--;
				cout << seg.query(l, r)->v << '\n';
			} else {
				int l, r; LL c; cin >> l >> r >> c; l--;
				seg.modify(l, r, c);
			}
		}
	}
}
