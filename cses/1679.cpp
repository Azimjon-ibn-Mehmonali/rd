
// Problem: Course Schedule
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1679
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

// #pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")

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

//=========================================================
int recur_depth = 0;
#ifdef DEBUG
#define xtp(x)                                                           \
	{                                                                    \
		++recur_depth;                                                   \
		auto x_ = x;                                                     \
		--recur_depth;                                                   \
		cerr << string(recur_depth, '\t') << __func__ << ":" << __LINE__ \
			 << "\t" << #x << " = " << x_ << endl;                       \
	}
#else
#define xtp(x)
#endif
//=========================================================

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
	vii in(n + 1);
	int u, v;

	in[0] = {INF, 0};
	for (int i = 1; i <= n; i++) {
		in[i] = {0, i};
	}

	for (int i = 1; i <= m; i++) {
		cin >> u >> v;

		g[u].pb(v);
		in[v].F++;
	}

	vi r(n + 1, 0);
	vi ts;
	bool has_cycle = 0;

	function<void(int)> topsort = [&](int u) {
		r[u] = 1;

		for (int v : g[u]) {
			if (r[v] == 0) {
				topsort(v);
			} else if (r[v] == 1) {
				has_cycle = 1;
				return;
			}
		}

		r[u] = 2;
		ts.pb(u);
	};

	SORT(in);

	for (auto [q, w] : in) {
		if (w == 0) continue;
		if (r[w] == 0) topsort(w);
		if (has_cycle) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	REV(ts);
	xtp(ts);
	if (ts.size() != n) {
		cout << "IMPOSSIBLENN\n";
		return 0;
	}

	for (int i : ts)
		cout << i << " ";

	return 0;
}
