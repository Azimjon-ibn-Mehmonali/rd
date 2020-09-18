
// Problem: E. Lazy Student
// Contest: Codeforces - Practice #last
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/295403/problem/E
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

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vi w;

	int yi = 0;

	vector<pair<ii, int>> e(m + 1);
	e[0].F.F = -INF;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].F.F >> e[i].F.S;
		e[i].S = i;
		w.pb(e[i].F.F);

		if (e[i].F.S) {
			yi += w.back();
		}
	}

	SORT(e);
	SORT(w);
	int yy = 0;
	for (int i = 0; i < n - 1; i++) {
		yy += w[i];
	}

	if (yy < yi) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		cout << 1 << " " << i << endl;
	}

	return 0;
}
