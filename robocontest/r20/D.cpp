// Muallif: Azimjon Mehmonali o'g'li

#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
	Ostream& os, const Cont& v) {
	os << "[";
	for (auto& x : v) {
		os << x << ", ";
	}
	return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}
//=========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

int n, m, a, b;
vector<vi> g;
vi bo;

int dfs(int u) {
	if (bo[u]) return 0;

	bo[u] = 1;
	int jv = 1;
	for (int v : g[u]) {
		// if (bo[v]) continue;
		jv += dfs(v);
	}
	return jv;
}

void f() {
	cin >> n >> m >> a >> b;

	g.clear();
	bo.clear();

	g.assign(n + 1, vi());
	bo.assign(n + 1, 0);

	int u, v;
	while (cin >> u >> v) {
		g[u].pb(v);
		g[v].pb(u);
	}

	int jv = 0;
	for (u = 1; u <= n; u++) {
		if (!bo[u]) {
			xtp(u);
			int r = dfs(u);
			xtp(r);
			jv += min(a + b * (r - 1), r * a);
		}
	}

	cout << jv << endl;
}

signed main() {
	TEZ;
	int t;
	cin >> t;
	while (t--) {
		f();
	}
	return 0;
}
