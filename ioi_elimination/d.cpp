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

	vi a(n);
	for (int &i : a)
		cin >> i;

	vii b(m);
	vi al(n, 0);
	vector<vi> g(n, vi());

	for (ii &i: b) {
		cin >> i.F >> i.S;
		g[i.F - 1].pb(i.S - 1);
		g[i.S - 1].pb(i.F - 1);
	}

	vi v(n, 0);
	function<void(int, int)> dfs = [&](int u, int r) {
		v[u] = r;
		for (int h : g[u]) {
			if (v[h]) continue;
			dfs(h, r);
		}
	};

	int rr = 1;
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			dfs(i, rr++);
		}
	}

	vector<vi> p(rr, vi());
	for (int i = 0; i < n; i++) {
		p[v[i]].pb(a[i]);
	}

	for (int i = 0; i < rr; i++)
		rSORT(p[i]);
	
	for (int i = 0; i < n; i++) {
		a[i] = p[v[i]].back();
		p[v[i]].pop_back();
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
