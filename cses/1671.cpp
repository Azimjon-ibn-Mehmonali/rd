
// Problem : Shortest Routes I
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1671
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

	int n, m;
	cin >> n >> m;

	vector<vii> g(n + 1, vii());

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		g[a].pb({b, c});
	}

	vll mas(n + 1, LINF);
	vi bor(n + 1, 0);
	mas[1] = 0;

	priority_queue<pair<ll, int>> pq;
	pq.push({0, 1});

	while (!pq.empty()) {
		int u = pq.top().S;
		pq.pop();

		if (bor[u]) continue;

		bor[u] = 1;
		for (auto v : g[u]) {
			if (mas[u] + v.S < mas[v.F]) {
				mas[v.F] = mas[u] + v.S;
				pq.push({-mas[v.F], v.F});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << mas[i] << " ";

	return 0;
}
