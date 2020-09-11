
// Problem: D. Tree Tag
// Contest: Codeforces - Codeforces Round #668 (Div. 2)
// URL: https://codeforces.com/contest/1405/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

int n, a, b, da, db;

int diam(vector<vi> g) {
	// int n = g.size() - 1;
	vi m(n + 1, 0);

	function<void(int, int)> dfs = [&](int u, int v) {
		m[u] = m[v] + 1;

		for (int h : g[u]) {
			if (h == v) continue;
			dfs(h, u);
		}
	};

	dfs(a, 0);
	// xtp(m[b]);
	if (m[b] - 1 <= da) {
		return -1;
	}

	// xtp(m);

	int ke = max_element(ALL(m)) - m.begin();
	m.assign(n + 1, 0);

	dfs(ke, 0);

	// xtp(m);

	return *max_element(ALL(m)) - 1;
}

void f() {
	cin >> n >> a >> b >> da >> db;

	vector<vi> g(n + 1, vi());
	int x, y;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;

		g[x].pb(y);
		g[y].pb(x);
	}

	int d = diam(g);

	if (d == -1) {
		cout << "Alice" << endl;
		return;
	}

	if (2 * da >= min(d, db)) {
		cout << "Alice" << endl;
		return;
	}

	cout << "Bob" << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}