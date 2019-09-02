#include <bits/stdc++.h>
using namespace std;
// LatexBegin
using VI = vector<int>;
bool noteq(int a, int b, int k, int n, int *RA) {
  return RA[a] != RA[b] || a + k >= n || b + k >= n 
      || RA[a + k] != RA[b + k];
}
void RS(int *bg, int *ed, int *RA, int N) {
  int n = ed - bg, box[N], tmp[n]; 
  fill_n(box, N, 0);
  for (int i = 0 ; i < n ; i++) box[RA[i]]++;
  partial_sum(box, box + N, box);
  for (int i = n - 1 ; ~i ; i--) 
    tmp[--box[RA[bg[i]]]] = bg[i];
  copy_n(tmp, n, bg);
}
void build_sa(string &s, VI &sa, VI &ra) {
  char *S = (char *)s.c_str();
  int n = s.size(), SA[n], RA[n], N = 256;
  copy_n(S, n, RA); for (int k = 1 ; k < n ; k <<= 1) {
    iota(SA, SA + n, 0), RS(SA, SA + n - k, RA + k, N);
    RS(SA, SA + n, RA, N); 
    int RA2[n]; RA2[SA[0]] = 0; N = 1;
    for (int i = 1 ; i < n ; i++) {
      if (noteq(SA[i - 1], SA[i], k, n, RA)) N++;
      RA2[SA[i]] = N - 1;
    }
    copy_n(RA2, n, RA); if (N == n) break;
  }
  sa.assign(SA, SA + n); ra.assign(RA, RA + n);
}
void build_hei(string &s, VI &sa, VI &ra, VI &hei) {
  hei.clear(); hei.resize(s.size());
  for (int i = 0, k = 0, n = s.size() ; i < n ; i++) {
    if (ra[i]) while(s[i + k] == s[sa[ra[i]-1]+k]) k++;
    hei[ra[i]] = k; k = max(0, k - 1);
  }
}
// LatexEnd
int magic(int v, vector<int> &pre) {
  return --upper_bound(pre.begin(), pre.end(), v) - pre.begin();
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, f = 0; while (cin >> n && n) {
    if (f) cout << '\n'; else f = 1;
    string s, str;
    vector<int> pre{0};
    int cnt = 1;
    for (int i = 0 ; i < n ; i++) {
      cin >> str, s += str, s += char(cnt++), pre.push_back(s.size());
      if (cnt == 'a') cnt += 26;
    }
    VI sa, ra, hei;
    build_sa(s, sa, ra);
    build_hei(s, sa, ra, hei);
    char *S = (char *)s.c_str();
    int L = 0, R = s.size(); while (R - L > 1) {
      int M = (R + L) >> 1; set<int> app;
      bool ok = false;
      for (int i = 0 ; i < s.size() ; i++) {
        if (s[sa[i]] == '$') continue;
        if (hei[i] < M) {
          if (app.size() * 2 > n)
            ok = true;
          app.clear();
        }
        app.insert(magic(sa[i], pre));
      }
      (ok ? L : R) = M;
    }
    if (L) {
      set<string> ans; set<int> app;
      for (int i = 0 ; i < s.size() ; i++) {
        if (s[sa[i]] == '$') continue;
        if (hei[i] < L) {
          if (app.size() * 2 > n) {
            string ans_str = s.substr(sa[i - 1], L);
            bool ok = true;
            for (auto &c : ans_str)
              if (!('a' <= c && c <= 'z'))
                ok = false;
            if (ok) ans.insert(ans_str);
          }
          app.clear();
        }
        app.insert(magic(sa[i], pre));
      }
      if (app.size() * 2 > n) {
        string ans_str = s.substr(sa.back(), L);
        bool ok = true;
        for (auto &c : ans_str)
          if (!('a' <= c && c <= 'z'))
            ok = false;
        if (ok) ans.insert(ans_str);
      }
      for (auto &str : ans)
        if (str.size() == L)
          cout << str << '\n';
    } else cout << "?\n";
  }
}
