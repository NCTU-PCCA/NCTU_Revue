#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 1 ; i <= 94 ; i++) {
        stringstream ss; ss << i;
        string output; ss >> output;
        system(("./C.out < tc/guess_" + output + ".in > res/output_" + output + ".out").c_str());
        system(("cat res/output_" + output + ".out | ./score.out tc/guess_" + output + ".in tc/guess_" + output + ".out").c_str());
    }
}
