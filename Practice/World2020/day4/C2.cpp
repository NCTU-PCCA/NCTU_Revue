#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
template <typename T> struct Graph {
    vector<vector<T>> W; vector<pii> edges;
    void init(int n) { W.resize(n, vector<T>(n)); }
    
    
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<int> st{1, 5, 3, 2, 4};
    auto it = st.begin();
    cout << advance(it, rand() % st.size()) << '\n';
}
