// LatexBegin
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int MAXB = 33554432;
inline void Read(int& x) {
  x = 0; while(*inpch < '0') *inpch++;
  while(*inpch >= '0') x = x * 10 + *inpch++ - '0';
}
int main() { fread_unlocked(inp, 1, MAXB, stdin); }
// LatexEnd
