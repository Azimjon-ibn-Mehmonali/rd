
// Problem: Cities
// Contest: CSES - BOI 2016, day 2
// URL: https://cses.fi/88/task/A
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

class UnionFind {
   public:
	vi size, p;

	UnionFind(int n) {
		size.assign(n, 1);
		p.assign(n, 0);

		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}

	void unite(int u, int v) {
		if (size[u] > size[v]) {
			swap(u, v);
		}

		size[v] += size[u];

		p[u] = v;
	}
};

signed main() {
	TEZ;

	int n, k, m;
	cin >> n >> k >> m;

	vector<vii> g(n, vii());
	vector<pair<int, ii>> el;
	int u, v, x;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> x;
		el.pb({x, {u - 1, v - 1}});
	}

	for (int i = 0; i)
		;

	return 0;
}
