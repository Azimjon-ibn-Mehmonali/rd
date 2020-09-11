
// Problem : Shortest Routes II
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1672
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

int main() {
	TEZ;

	int n, m, q;
	cin >> n >> m >> q;

	n++;
	vector<vll> g(n, vll(n, LINF));

	for (int i = 0; i < n; i++)
		g[i][i] = 0;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		g[a][b] = min((ll)c, g[a][b]);
		g[b][a] = g[a][b];
	}

	for (int k = 1; k < n; k++)
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	while (q--) {
		cin >> a >> b;

		cout << (g[a][b] == LINF ? -1 : g[a][b]) << endl;
	}

	return 0;
}
