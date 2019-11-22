#include <bits/stdc++.h>
using namespace std;
// LatexBegin
char t[1001];           // 原字串
char s[1001 * 2];       // 穿插特殊字元之後的t
int z[1001 * 2], L, R;  // 源自Gusfield's Algorithm

// 由a往左、由b往右，對稱地作字元比對。
int match(int a, int b)
{
    int i = 0;
    while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
    return i;
}

void longest_palindromic_substring()
{
    int N = strlen(t);

    // t穿插特殊字元，存放到s。
    // （實際上不會這麼做，都是細算索引值。）
    memset(s, '.', N*2+1);
    for (int i=0; i<N; ++i) s[i*2+1] = t[i];

    N = N*2+1;
//  s[N] = '\0';    // 可做可不做

    // Manacher's Algorithm
    z[0] = 1;
    L = R = 0;
    for (int i=1; i<N; ++i)
    {
        int ii = L - (i - L);   // i的映射位置
        int n = R + 1 - i;

        if (i > R)
        {
            z[i] = match(i, i);
            L = i;
            R = i + z[i] - 1;
        }
        else if (z[ii] == n)
        {
            z[i] = n + match(i-n, i+n);
            L = i;
            R = i + z[i] - 1;
        }
        else
        {
            z[i] = min(z[ii], n);
        }
    }

    // 尋找最長迴文子字串的長度。
    int n = 0, p = 0;
    for (int i=0; i<N; ++i)
        if (z[i] > n)
            n = z[p = i];

    // 記得去掉特殊字元。
    cout << "最長迴文子字串的長度是" << (n-1) / 2;

    // 印出最長迴文子字串，記得別印特殊字元。
    for (int i=p-z[p]+1; i<=p+z[p]-1; ++i)
        if (i & 1)
            cout << s[i];
}
// LatexEnd
int main() {

}
