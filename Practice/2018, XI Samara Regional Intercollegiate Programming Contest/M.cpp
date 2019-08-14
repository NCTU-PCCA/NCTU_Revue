#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string data[3];
    for (int i = 0 ; i < 3 ; i++)
        cin >> data[i];
    int len = data[0].size();
    for (int i = 0 ; i < 3 ; i++) {
        int cnt = 0;
        for (int j = 0 ; j < len ; j++)
            cnt += (data[i % 3][j] != data[(i + 1) % 3][j]);
        if (cnt > 2) {
            cout << "Impossible\n";
            return 0;
        }
    }
    int cnt = 0; vector<int> pos;
    for (int i = 0 ; i < (int)data[0].size() ; i++) {
        if (data[0][i] != data[1][i]
        ||  data[1][i] != data[2][i]
        ||  data[2][i] != data[0][i])
            cnt++, pos.push_back(i);
    }
    if (cnt <= 1)
        cout << "Ambiguous\n";
    else if (cnt >= 4)
        cout << "Impossible\n";
    else {
        vector<set<char> > list(pos.size());
        for (int i = 0 ; i < (int)pos.size() ; i++) {
            list[i].insert(data[0][pos[i]]);
            list[i].insert(data[1][pos[i]]);
            list[i].insert(data[2][pos[i]]);
        }
        vector<string> ans;
        if (cnt == 2) {
            for (auto &c0 : list[0]) {
                for (auto &c1 : list[1]) {
                    vector<char> c_list{c0, c1};
                    bool flag = true;
                    for (int i = 0 ; i < 3 ; i++) {
                        int cnt__ = 0;
                        for (int j = 0 ; j < (int)pos.size() ; j++)
                            if (data[i][pos[j]] != c_list[j])
                                cnt__++;
                        if (cnt__ > 1)
                            flag = false;
                    }
                    if (flag) {
                        string tar = data[0];
                        tar[pos[0]] = c0;
                        tar[pos[1]] = c1;
                        ans.push_back(tar);
                    }
                }
            }
        } else {
            for (auto &c0 : list[0]) {
                for (auto &c1 : list[1]) {
                    for (auto &c2 : list[2]) {
                        vector<char> c_list{c0, c1, c2};
                        bool flag = true;
                        for (int i = 0 ; i < 3 ; i++) {
                            int cnt__ = 0;
                            for (int j = 0 ; j < (int)pos.size() ; j++)
                                if (data[i][pos[j]] != c_list[j])
                                    cnt__++;
                            if (cnt__ > 1)
                                flag = false;
                        }
                        if (flag) {
                            string tar = data[0];
                            tar[pos[0]] = c0;
                            tar[pos[1]] = c1;
                            tar[pos[2]] = c2;
                            ans.push_back(tar);
                        }
                    }
                }
            }
        }
        if (ans.size() == 1) {
            cout << ans[0] << '\n';
        } else if (ans.size() == 0) {
            cout << "Impossible\n";
        } else
            cout << "Ambiguous\n";
        
    }
}
