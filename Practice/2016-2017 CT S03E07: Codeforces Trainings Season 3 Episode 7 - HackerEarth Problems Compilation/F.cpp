#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i=i+1)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
 
const int BASE  = 1e9 + 0.5;
const int WIDTH = log10(BASE) + 0.5;
template <typename T>
inline string to_string(const T &x) {
    stringstream ss;
    return ss << x, ss.str();
}
typedef long long LL;
struct bigN : vector<LL> {
    bool neg;
    bigN(string s) {
        if (s.empty()) return ;
        if (s[0] == '-') neg = true, s = s.substr(1);
        else neg = false;
        for (int i = s.size() - 1 ; i >= 0 ; i -= WIDTH) {
            LL t = 0;
            for (int j = max(0, i - WIDTH + 1) ; j <= i ; j++)
                t = t * 10 + s[j] - '0';
            push_back(t);
        }
        trim();
    }
    template <typename T>
    bigN(const T &x) : bigN(to_string(x)) {}
    bigN() : neg(false) {}
    friend istream& operator >> (istream &in, bigN &b) {
        string s;
        return in >> s, b = s, in;
    }
    friend ostream& operator << (ostream &out, const bigN &b) {
        if (b.neg) out << '-';
        out << (b.empty() ? 0 : b.back());
        for (int i = b.size() - 2 ; i >= 0 ; i--)
            out << setw(WIDTH) << setfill('0') << b[i];
        return out;
    }
    inline void trim() {
        while (size() && !back()) pop_back();
        if (empty()) neg = false;
    }
    bigN operator - () const {
        bigN res = *this;
        return res.neg = !neg, res.trim(), res;
    }
    bigN operator + (const bigN &b) const {
        if (neg) return -(-(*this) + (-b));
        if (b.neg) return *this - (-b);
        bigN res = *this;
        if (b.size() > size()) res.resize(b.size());
        for (int i = 0 ; i < b.size() ; i++) res[i] += b[i];
        return res.carry(), res.trim(), res;
    }
    bigN operator - (const bigN &b) const {
        if (neg) return -(-(*this) - (-b));
        if (b.neg) return *this + (-b);
        if (abscmp(b) < 0) return -(b-(*this));
        bigN res = *this;
        if (b.size() > size()) res.resize(b.size());
        for (int i = 0 ; i < b.size() ; i++) res[i] -= b[i];
        return res.carry(), res.trim(), res;
    }
    inline void carry() {
        for (int i = 0 ; i < size() ; i++) {
            if (at(i) >= 0 && at(i) < BASE) continue;
            if (i + 1 == size()) push_back(0);
            int r = at(i) % BASE;
            if (r < 0) r += BASE;
            at(i + 1) += (at(i) - r) / BASE;
            at(i) = r;
        }
    }
    int abscmp(const bigN &b) const {
        if (size() > b.size()) return 1;
        if (size() < b.size()) return -1;
        for (int i = size() - 1 ; i >= 0 ; i--) {
            if (at(i) > b[i]) return 1;
            if (at(i) < b[i]) return -1;
        }
        return 0;
    }
    bigN operator * (const bigN &b) const {
        bigN res;
        res.neg = neg != b.neg;
        res.resize(size() + b.size());
        for (int i = 0 ; i < size() ; i++) 
            for (int j = 0 ; j < b.size() ; j++)
                if ((res[i + j] += at(i) * b[j]) >= BASE) {
                    res[i + j + 1] += res[i + j] / BASE;
                    res[i + j] %= BASE;
                }
        return res.trim(), res;
    }
    bigN operator / (const bigN &b) const {
        int norm = BASE / (b.back() + 1);
        bigN x = abs() * norm;
        bigN y = b.abs() * norm;
        bigN q, r;
        q.resize(x.size());
        for (int i = x.size() - 1 ; i >= 0 ; i--) {
            r = r * BASE + x[i];
            int s1 = r.size() <= y.size() ? 0 : r[y.size()];
            int s2 = r.size() <  y.size() ? 0 : r[y.size() - 1];
            int d = (LL(BASE) * s1 + s2) / y.back();
            r = r - y * d;
            while (r.neg) r = r + y, d--;
            q[i] = d;
        }
        q.neg = neg != b.neg;
        return q.trim(), q;
    }
    bigN abs() const {
        bigN res = *this;
        return res.neg = false, res;
    }
    bigN operator % (const bigN &b) const {
        return *this - (*this / b) * b;
    }
    int cmp(const bigN &b) const {
        if (neg != b.neg) return neg ? -1 : 1;
        return neg ? -abscmp(b) : abscmp(b);
    }
    bool operator < (const bigN &b) const { return cmp(b) < 0; }
    bool operator > (const bigN &b) const { return cmp(b) > 0; }
    bool operator <= (const bigN &b) const { return cmp(b) <= 0; }
    bool operator >= (const bigN &b) const { return cmp(b) >= 0; }
    bool operator == (const bigN &b) const { return cmp(b) == 0; }
    bool operator != (const bigN &b) const { return cmp(b) != 0; }
    template <typename T>
    operator T() {
        stringstream ss;
        ss << *this;
        T res;
        return ss >> res, res;
    }
};
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
	bigN n,m;
	while(cin >> n >> m){
		bigN sum = 0;
        int tmp = n;
		bigN cont[tmp+5] = {};
		f(tmp){
			cin >> cont[i];
			sum = sum + cont[i];
		}
		bigN mi = 0;
        bigN i = 1;
        for (int x = 0 ; x < 40 ; x++)
            i = i * 2;
		bigN tot = i;
		for(;i != 0;i = i / 2){
			bigN now = tot - mi - i;
			if(now<0)continue;
			bigN day = n * now;
			bigN cur = sum * now;
			bigN goal = m - (day + 1) * day / 2;
			int f = 0;
			fr(j,0,tmp){
				cur = cur + cont[j];
				goal = goal - (day + j + 1);
				if(cur >= goal){
					f = 1;
					break;
				}
			}
			if(f){
				mi = mi + i;
			}
		}
		mi = tot - mi;
		bigN day = n * mi;
		bigN cur = sum * mi;
		bigN goal = m - (day + 1) * day / 2;
		f(tmp){
			day = day + 1;
			cur = cur + cont[i];
			goal= goal - day;
			if(cur>=goal){
				cout<<day<<endl;
				exit(0);
			}
		}
	}
}
