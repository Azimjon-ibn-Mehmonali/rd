
// Problem: I. NP-Hard Problem
// Contest: Codeforces - Contest #4
// URL: https://codeforces.com/group/5mF1N2M956/contest/289033/problem/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<vi> g(n + 1, vi());

	int u, w;
	while (cin >> u >> w) {
		g[u].pb(w);
		g[w].pb(u);
	}

	queue<int> q;
	vi r(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (g[i].empty()) continue;

		if (r[i]) continue;

		r[i] = 1;
		q.push(i);
		while (!q.empty()) {
			u = q.front();
			q.pop();

			for (int v : g[u]) {
				if (r[v]) {
					if (r[v] == r[u]) {
						cout << -1 << endl;
						return 0;
					}
					continue;
				}
				q.push(v);
				r[v] = r[u] == 1 ? 2 : 1;
			}
		}
	}

	cout << count(ALL(r), 1) << endl;
	for (int i = 1; i <= n; i++)
		if (r[i] == 1) cout << i << " ";

	cout << endl << count(ALL(r), 2) << endl;
	for (int i = 1; i <= n; i++)
		if (r[i] == 2) cout << i << " ";

	return 0;
}
