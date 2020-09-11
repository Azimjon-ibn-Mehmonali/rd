
// Problem: G. Timofey and a tree
// Contest: Codeforces - Tree
// URL: https://codeforces.com/group/5mF1N2M956/contest/290453/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

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

vector<vi> g;
vii el;
vi c;

bool dfs(int u, int v, int r) {
	bool jv = 1;
	for (int h : g[u]) {
		if (h == v) continue;
		if (c[h] != r) {
			return false;
		}
		jv &= dfs(h, u, r);
	}

	return jv;
}

bool dff(int u) {
	bool jv = 1;
	for (int v : g[u]) {
		jv &= dfs(v, u, c[v]);
	}

	return jv;
}

signed main() {
	TEZ;

	int n;
	cin >> n;

	g.assign(n + 1, vi());
	c.assign(n + 1, 0);

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		el.pb({a, b});
		g[a].pb(b);
		g[b].pb(a);
	}

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	ii e = {-1, -1};
	for (auto w : el)
		if (c[w.F] != c[w.S]) {
			e = w;
			break;
		}

	if (e == ii{-1, -1}) {
		cout << "YES\n" << 1 << endl;
		return 0;
	}

	xtp(e);

	bool j1, j2;
	j1 = dff(e.F);
	j2 = dff(e.S);

	if (j1) {
		cout << "YES\n" << e.F << endl;
		return 0;
	}

	if (j2) {
		cout << "YES\n" << e.S << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}
