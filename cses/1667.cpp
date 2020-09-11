
// Problem : Message Route
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1667
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

int main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<vi> g(n + 1, vi());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	vi o(n + 1, -1);
	queue<int> q;
	q.push(1);
	o[1] = -2;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (o[v] == -1) {
				o[v] = u;
				q.push(v);
			}
		}
	}
	xtp(g);
	xtp(o);
	if (o[n] != -1) {
		vi jv;
		while (o[n] != -2) {
			jv.pb(n);
			n = o[n];
		}
		jv.pb(1);

		REV(jv);
		cout << jv.size() << endl;
		for (int i : jv)
			cout << i << " ";
	}

	else
		cout << "IMPOSSIBLE" << endl;

	return 0;
}
