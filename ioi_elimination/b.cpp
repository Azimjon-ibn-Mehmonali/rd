// Muallif: Azimjon Mehmonali o'g'li
// masala: B

//=========================================================

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//=========================================================
#ifdef DEBUG
#define xtp xtp1
#else
#define xtp(x)
#endif
//=========================================================

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define rSORT(a) sort(rALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

signed main() {
	TEZ;

	int g[200];
	int b[200] = {0};
	g[1] = 1;

	for (int i = 2; i <= 100; i++)
		g[i] = 1 + g[i - g[g[i - 1]]];
	
	int s = 0;
	for (int i = 1; i <= 100; i++) {
		s += g[i];
		b[g[i]]++;
//		cout << i << " " << g[i] << " " << s << endl;
	}

	for (int i = 1; i <= 100; i++) {
		cout << i << " --- " << b[i] << endl;
	}

	return 0;
}
