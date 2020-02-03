#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int lgN = (__lg(MAXN) + 5) * 4;
struct Seg {
	struct Node {
		int L, R;
		Node *l, *r;
		LL maxV, chg;
		Node(int L = 0, int R = 0) : L(L), R(R) {
			maxV = chg = 0;
			l = r = NULL;
		}
	}buf[10000], *ptr, *rt;
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
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		vector<int> V;
		vector<pair<int, int> > data;
		for (int i = 0 ; i < n ; i++) {
			int l, r; cin >> l >> r; r++;
			V.push_back(l);
			V.push_back(r);
			data.push_back({l, r});
		}
		sort(V.begin(), V.end());
		for (int i = 0 ; i < n ; i++) {
			pair<int, int> p = data[i];
			data[i].first = lower_bound(V.begin(), V.end(), p.first) - V.begin();
			data[i].second = lower_bound(V.begin(), V.end(), p.second) - V.begin();
		}
		Seg *sol = new Seg(V.size());
		for (int i = 0 ; i < n ; i++) {
			sol->modify(data[i].first , data[i].second, i + 1);
		}
		set<int> cnt;
		for (int i = 0 ; i < V.size() ; i++) {
			int v = sol->query(i, i + 1)->maxV;
			if (!v)
				continue;
			cnt.insert(v);
		}
		cout << cnt.size() << '\n';
	}
}
