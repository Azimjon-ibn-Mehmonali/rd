
// Problem : Алгоритм Флойда
// Contest : ACMP
// URL : https://acmp.ru/asp/do/index.asp?main=section&id_course=2&id_section=32
// Memory Limit : 16 MB
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
const ll INF = 1000000000ll;
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--, t--;

	ld g[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g[i][j] = 0;
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;
		g[a][b] = g[b][a] = max((ld)(100 - c) / 100., g[a][b]);
	}

	if (s == t) {
		cout << 0 << endl;
		return 0;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
	/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << g[i][j] << " ";
			cout << endl;
		}
	*/

	cout << setprecision(9) << 1 - g[s][t] << endl;

	return 0;
}
