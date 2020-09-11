
// Problem : Round Trip
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1669
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
	return os << "]";
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

vector<vi> g;
set<ii> el;
vi p;
int n, m;

int dfs(int u) {
	for (int& i : g[u]) {
		// xtp(i);
		// xtp(p[i]);
		if ((p[i] > 0 || p[i] == -2) && (p[u] != i && p[i] != u)) {
			p[i] = u;
			xtp(u);
			xtp(i);
			return i;
		}
		p[i] = u;
		// xtp(p[i]);
		return dfs(i);
	}

	return -1;
}

int main() {
	TEZ;

	cin >> n >> m;

	g.assign(n + 1, vi());
	p.assign(n + 1, -1);

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		g[u].pb(v);
		g[v].pb(u);

		if (u > v) swap(u, v);
		el.emplace(u, v);
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] == -1) {
			p[i] = -2;
			int o = dfs(i);
			xtp(i);
			xtp(o);
			xtp(p);
			if (o != -1) {
				int t = o;
				vi jv;

				do {
					jv.pb(t);
					t = p[t];
				} while (t != o);
				jv.pb(p[t]);

				cout << jv.size() << endl;
				for (int& y : jv)
					cout << y << " ";
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

	return 0;
}
