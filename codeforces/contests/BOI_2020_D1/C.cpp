
// Problem: C. Joker
// Contest: Codeforces - Baltic Olympiad in Informatics 2020, Day 1 (IOI,
// Unofficial Mirror Contest, Unrated) URL:
// https://codeforces.com/contest/1386/problem/C Memory Limit: 256 MB Time
// Limit: 1000 ms Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
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

//===========================================================

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
	return os << "]\n";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}

//===========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const ll mod = 1000000007LL;
const int INF = 1000000000;
const ll LINF = 1000000000000000000LL;

vector<vi> g;
vi r;
bool da, ts;

void dfs(int u, int o, int b) {
	if (ts) return;
	xtp(o);
	xtp(u);
	xtp(b);
	if (r[u]) {
		if (r[u] != b) {
			r[u] = b;
			ts = 1;
		} else {
			// ts = 1;
		}
		return;
	}
	r[u] = b;
	for (int v : g[u])
		if (v != o) dfs(v, u, (b == 1 ? 2 : 1));
}

int main() {
	TEZ;

	int n, m, q;
	cin >> n >> m >> q;

	int a, b;
	vii el{{-1, -1}};
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		el.pb({a, b});
	}
	xtp(el);
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		g.clear();
		g.assign(n + 1, vi());

		r.clear();
		r.assign(n + 1, 0);

		for (int k = 1; k <= m; k++) {
			if (k < a || b < k) {
				int x, y;
				tie(x, y) = el[k];
				g[x].pb(y);
				g[y].pb(x);
			}
		}
		xtp(g);
		ts = 0;
		for (int k = 1; k <= n; k++) {
			// xtp(k);
			if (!r[k]) {
				dfs(k, -1, 1);
			}
		}

		xtp(r);

		if (ts) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
