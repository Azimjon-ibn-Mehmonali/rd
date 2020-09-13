
// Problem: C. Link Cut Centroids
// Contest: Codeforces - Codeforces Round #670 (Div. 2)
// URL: https://codeforces.com/contest/1406/problem/C
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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
const int N = 111111;

void f() {
	int n;
	cin >> n;

	vector<vi> g(n + 1, vi());
	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;

		g[x].pb(y);
		g[y].pb(x);
	}

	vi bs(n + 1, 1ll);
	vi p(n + 1, 0);
	bs[0] = 0;

	function<void(int, int)> dfs = [&](int u, int v) {
		// p[u] = v;
		for (int h : g[u]) {
			if (h == v) continue;
			p[h] = u;
			dfs(h, u);
			bs[u] += bs[h];
		}
	};

	dfs(1, 0);

	bs[0] = bs[1];

	int ek = INF;
	vi er;

	for (int i = 1; i <= n; i++) {
		int hs = n - bs[i];
		// cout << "---" << i << " " << hs << endl;
		for (int h : g[i]) {
			if (h == p[i]) continue;
			hs = max(hs, bs[h]);
			// cout << h << " " << bs[h] << endl;
		}
		// cout << "---" << i << " " << hs << endl;
		if (ek > hs) {
			ek = hs;
			er = {i};
		} else if (ek == hs) {
			er.pb(i);
		}
	}
	if (er.size() == 1ll) {
		cout << 1 << " " << g[1][0] << endl;
		cout << 1 << " " << g[1][0] << endl;
		return;
	};
	int q = er[0], w = er[1];
	int e;

	for (int h : g[q]) {
		if (h == w) continue;
		e = h;
		break;
	}

	cout << q << " " << e << endl;
	cout << e << ' ' << w << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
