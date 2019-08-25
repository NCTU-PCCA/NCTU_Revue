#include <bits/stdc++.h>
using namespace std;
// LatexBegin
const int SIGMA = 26;
const int MAXLEN = 1e5;
struct ACAutomaton{
  struct Node : vector<Node*> { Node *f; 
// LatexEnd
    int dp; bool vis;
/*
// LatexBegin
    Node() : f(NULL) { clear(); resize(SIGMA); }
// LatexEnd
*/
    Node() : f(NULL) {
      clear(); resize(SIGMA); dp = 0; vis = false;
    }
// LatexBegin
  }*r, *o;
  ACAutomaton() { o = new Node(), r = new Node(); }
  ~ACAutomaton() { remove(r); delete o; }
  void remove(Node *u) { if (!u) return ;
    for (auto &v : *u) remove(v); delete u;
  }
  int idx(char c) { return c - 'a'; }
  void buildTrie(string &s) { Node *u = r;
    for (auto &c : s) { int i = idx(c);
      if (!(*u)[i]) (*u)[i] = new Node(); u = (*u)[i];
    }
// LatexBegin
    u->dp++;
// LatexEnd
  }
  void buildAC() { static queue<Node*> q;
    for (auto &v : *o) v = r; r->f = o; q.push(r);
    while (q.size()) { Node *u = q.front(); q.pop();
      for (int i = 0 ; i < SIGMA ; i++) { 
        Node *v = (*u)[i]; if (!v) continue;
        v->f = trans(u->f, i); q.push(v);
      }
    }
  }
  Node* trans(Node *u, int c) {
    while (!(*u)[c]) u = u->f; return (*u)[c];
  }
  int search(string &s) { int ans = 0; Node *u = r;
// LatexEnd
/*
// LatexBegin
    for (int i = 0 ; i < s.size() ; i++)
      u = trans(u, idx(s[i]));
// LatexEnd
*/
    for (auto &c : s) {
      u = trans(u, idx(c));
      Node *t = u;
      while (t != r && !t->vis) {
        ans += t->dp;
        t->vis = true;
        t = t->f;
      }
// LatexBegin
    }
    return ans;
  }
};
// LatexEnd

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t; while (t--){
    int n; cin >> n;
    ACAutomaton *sol = new ACAutomaton();
    for (int i = 0 ; i < n ; i++) {
      string str; cin >> str;
      sol->buildTrie(str);
    }
    sol->buildAC();
    string target; cin >> target;
    cout << sol->search(target) << '\n';
    delete sol;
  }
}
