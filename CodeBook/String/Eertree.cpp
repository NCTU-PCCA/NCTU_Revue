#include <bits/stdc++.h>
using namespace std;
// LatexBegin
const int SIGMA = 26;
struct Eertree {
  struct Node : vector<Node*> { Node *f; int len;
    Node(int len = 0) : f(NULL), len(len) {
      clear(); resize(SIGMA);
    }
  }*l, *rt; string s;
// LatexEnd
  string ans;
// LatexBegin
  Eertree(string &str) { s = "$";
// LatexEnd
    ans = "";
// LatexBegin
    rt = new Node(0); l = new Node(-1);
    rt->f = l; l->f = l;
    for (auto &c : str) insert(c);
  }
  int idx(char c) { return c - 'a'; }
  void insert(char c) {
    s += c; Node *u = trans(l); int i = idx(c);
    if (!(*u)[i]) { Node *v = new Node(u->len + 2);
      v->f = (*trans(u->f))[i]; if (!v->f) v->f = rt;
      (*u)[i] = v;
    }
    l = (*u)[i];
// LatexEnd
    if (l->len > ans.size()) ans = s.substr(s.size() - l->len, l->len);
// LatexBegin
  }
  Node* trans(Node *u) { int n = s.size() - 1;
    while (s[n - u->len - 1] != s[n]) u = u->f;
    return u;
  }
};
// LatexEnd
int main() {
  string s; while (cin >> s) {
    Eertree *sol = new Eertree(s);
    cout << sol->ans << '\n';
  }
}
