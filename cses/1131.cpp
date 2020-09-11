
// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
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

int diam(vector<vi> g) {
	int n = g.size() - 1;
	vi m(n + 1, 0);

	function<void(int, int)> dfs = [&](int u, int v) {
		m[u] = m[v] + 1;

		for (int h : g[u]) {
			if (h == v) continue;
			dfs(h, u);
		}
	};

	dfs(1, 0);

	// xtp(m);

	int ke = max_element(ALL(m)) - m.begin();
	m.assign(n + 1, 0);

	dfs(ke, 0);

	// xtp(m);

	return *max_element(ALL(m)) - 1;
}

signed main() {
	TEZ;

	int n;
	cin >> n;

	vector<vi> g(n + 1, vi());
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	int jv = diam(g);

	cout << jv << endl;

	return 0;
}
