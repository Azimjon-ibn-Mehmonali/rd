
// Problem: E. Tree Shuffling
// Contest: Codeforces - Codeforces Round #646 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1363/E
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

const int N = 222222;

int a[N], b[N], c[N], t0[N], t1[N];

signed main() {
	TEZ;

	int n;
	cin >> n;

	vector<vi> g(n + 1, vi());

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int u, v;
	// cin >> u >> v;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;

		g[u].pb(v);
		g[v].pb(u);
	}

	int jv = 0;
	function<void(int, int)> dfs = [&](int x, int y) {
		if (x != 1) a[x] = min(a[x], a[y]);

		if (b[x] == 1 && c[x] == 0) t0[x] = 1;
		if (b[x] == 0 && c[x] == 1) t1[x] = 1;

		for (int h : g[x]) {
			if (h == y) continue;
			dfs(h, x);

			t0[x] += t0[h];
			t1[x] += t1[h];
		}
		// if (x == 1) cout << t0[x] << ' ' << t1[x] << '\n';
		int z = min(t0[x], t1[x]);
		t0[x] -= z;
		t1[x] -= z;

		jv += 2 * z * a[x];
	};

	dfs(1, -1);
	// for (int i = 1; i <= n; i++)
	// cout << i << " " << t0[i] << " " << t1[i] << endl;
	if (t1[1] || t0[1])
		cout << -1 << endl;
	else
		cout << jv << endl;

	return 0;
}
