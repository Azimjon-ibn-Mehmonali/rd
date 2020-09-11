
// Problem: D - Friends
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_d
// Memory Limit: 1024 MB
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

	vector<vi> g(n + 1, vi());

	set<ii> el;
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		if (a > b) swap(a, b);

		if (el.count({a, b}) == 0) {
			g[a].pb(b);
			g[b].pb(a);

			el.insert({a, b});
		}
	}

	vi v(n + 1, 0);

	function<int(int)> dfs = [&](int u) {
		if (v[u]) {
			return 0ll;
		}

		v[u] = 1;
		int jv = 1;
		for (int h : g[u]) {
			jv += dfs(h);
		}

		return jv;
	};

	int jv = -INF;

	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			jv = max(jv, dfs(i));
		}
	}

	cout << jv << endl;

	return 0;
}
