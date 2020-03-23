#include <bits/stdc++.h>
using namespace std;
struct P {
    int v[3];
};
P s[2], t[2], p[2];
void MOVE(int id, int vid, int d) {
    p[id].v[vid] += d;
}
void print() {
    cout << "(";
    for (int i = 0 ; i < 3 ; i++)
        cout << p[0].v[i] << " )"[i + 1 == 3];
    cout << " (";
    for (int i = 0 ; i < 3 ; i++)
        cout << p[1].v[i] << " )"[i + 1 == 3];
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < 3 ; j++)
            cin >> s[i].v[j];
        for (int j = 0 ; j < 3 ; j++)
            cin >> t[i].v[j];
        p[i] = s[i];
    }
    print();
    if (p[0].v[0] == p[1].v[0]) {
        if (p[0].v[0] == 1000)
            MOVE(0, 0, -1);
        else
            MOVE(0, 0, 1);
        print();
    }
    while (p[0].v[2] != t[0].v[2] || p[1].v[2] != t[1].v[2]) {
        // 0
        if (p[0].v[1] == t[0].v[1]) {
            if (p[0].v[2] > t[0].v[2]) {
                MOVE(0, 2, -1);
            } else if (p[0].v[2] < t[0].v[2]) {
                MOVE(0, 2, 1);
            }
        } else {
            if (p[0].v[1] > t[0].v[1]) {
                MOVE(0, 1, -1);
            } else if (p[0].v[1] < t[0].v[1]) {
                MOVE(0, 1, 1);
            }
        }
        // 1
        if (p[1].v[1] == t[1].v[1]) {
            if (p[1].v[2] > t[1].v[2]) {
                MOVE(1, 2, -1);
            } else if (p[1].v[2] < t[1].v[2]) {
                MOVE(1, 2, 1);
            }
        } else {
            if (p[1].v[1] > t[1].v[1]) {
                MOVE(1, 1, -1);
            } else if (p[1].v[1] < t[1].v[1]) {
                MOVE(1, 1, 1);
            }
        }
        print();
    }
    int dx = 0;
    if (p[0].v[1] == 1000)
        MOVE(0, 1, -1), dx = 1;
    else
        MOVE(0, 1, 1), dx = -1;
    print();
    while (p[0].v[0] != t[0].v[0] || p[1].v[0] != t[1].v[0]) {
        // 0
        if (p[0].v[0] > t[0].v[0])
            MOVE(0, 0, -1);
        else if (p[0].v[0] < t[0].v[0])
            MOVE(0, 0, 1);
        // 1
        if (p[1].v[0] > t[1].v[0])
            MOVE(1, 0, -1);
        else if (p[1].v[0] < t[1].v[0])
            MOVE(1, 0, 1);
        print();
    }
    MOVE(0, 1, dx);
    print();
}
