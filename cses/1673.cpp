
// Problem : High Score
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1673
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
const ll LINF = 1000000000000000000LL;

void dfs(int u, auto& g, vi& bor) {
	if (bor[u]) return;

	bor[u] = 1;

	for (int v : g[u])
		dfs(v, g, bor);
}

int main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vll mas(n + 1, -LINF);
	mas[1] = 0;

	vector<tuple<int, int, int>> el;

	int a, b, c;
	vector<vi> g(n + 1, vi());
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		el.pb({a, b, c});
		g[a].pb(b);
	}

	for (int i = 1; i < n; i++) {
		for (auto e : el) {
			tie(a, b, c) = e;
			mas[b] = max(mas[b], mas[a] + c);
		}
	}

	for (auto e : el) {
		tie(a, b, c) = e;
		if (mas[b] < mas[a] + c) {
			vi b1(n + 1, 0);
			vi b2(n + 1, 0);
			dfs(1, g, b1);
			dfs(a, g, b2);
			if (b1[a] && b2[n]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << mas[n] << endl;

	return 0;
}
