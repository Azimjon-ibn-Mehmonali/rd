
// Problem: Longest Flight Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1680
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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

int lp[100005], p[100005];

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<vi> g(n + 1, vi());
	int u, v;

	for (int i = 1; i <= m; i++) {
		cin >> u >> v;

		g[u].pb(v);
	}

	memset(p, -1, sizeof(p));
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (lp[v] < lp[u] + 1) {
				lp[v] = lp[u] + 1;
				p[v] = u;
			}
			q.push(v);
		}
	}

	xtp(g[1]);

	if (p[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<signed> jv;
	int f = n;

	while (p[f] != -1)
		jv.pb(f), f = p[f];
	jv.pb(1);

	cout << jv.size() << endl;
	for (int i = jv.size() - 1; i >= 0; i--)
		cout << jv[i] << " ";

	return 0;
}
