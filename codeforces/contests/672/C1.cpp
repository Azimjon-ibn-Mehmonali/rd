
// Problem: C1. Pokémon Army (easy version)
// Contest: Codeforces - Codeforces Round #672 (Div. 2)
// URL: https://codeforces.com/contest/1420/problem/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

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

void f() {
	int n, q;
	cin >> n >> q;

	vi a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	bool os = 1;
	int jv = 0;

	for (int i = 2; i <= n; i++) {
		if (os) {
			if (a[i - 1] < a[i]) continue;
			jv += a[i - 1];
			xtp("ka");
			xtp(a[i - 1]);
			os = !os;
		} else {
			if (a[i - 1] > a[i]) continue;
			jv -= a[i - 1];
			xtp("ki");
			xtp(a[i - 1]);
			os = !os;
		}
	}

	if (os) {
		jv += a.back();
	}

	cout << jv << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--) {
		f();
	}

	return 0;
}
