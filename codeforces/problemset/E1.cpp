
// Problem: E1. Weights Division (easy version)
// Contest: Codeforces - Codeforces Round #661 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1399/E1
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
	int n, s;
	cin >> n >> s;

	vector<vii> g(n + 1, vii());
	vector<pair<ii, int>> el;
	int u, v, w;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;

		g[u].pb({v, w});
		g[v].pb({u, w});
		el.pb({{u, v}, w});
	}

	vi r(n + 1, 0);

	function<void(int, int)> dfs = [&](int a, int b) {
		if (g[a].size() == 1 && b != -1) r[a] = 1;
		for (auto [h, o] : g[a]) {
			if (h == b) continue;
			dfs(h, a);
			r[a] += r[h];
		}
	};

	dfs(1, 0);
	xtp(r);

	priority_queue<ii> pq;

	int yi = 0;

	for (int i = 0; i < n - 1; i++) {
		int so = min(r[el[i].F.F], r[el[i].F.S]);
		yi += so * el[i].S;
		int di = (so * el[i].S) - (so * (el[i].S / 2));

		pq.push({di, i});
	}
	int jv = 0;
	xtp(yi);

	while (yi > s) {
		jv++;
		ii h = pq.top();
		xtp(h);
		pq.pop();

		yi -= h.F;
		xtp(yi);
		el[h.S].S /= 2;

		int so = min(r[el[h.S].F.F], r[el[h.S].F.S]);

		pq.push({so * el[h.S].S - so * (el[h.S].S / 2), h.S});
	}

	cout << jv << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
