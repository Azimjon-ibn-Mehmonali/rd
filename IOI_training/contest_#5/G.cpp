
// Problem: G. The Tag Game
// Contest: Codeforces - Contest #5
// URL: https://codeforces.com/group/5mF1N2M956/contest/289850/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

	int n, x;
	vector<vi> g;
	vi al, bo;

	cin >> n >> x;

	g.assign(n + 1, vi());
	al.assign(n + 1, 0);
	bo.assign(n + 1, 0);

	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	queue<int> q;

	q.push(1);
	al[1] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (!al[v]) {
				al[v] = al[u] + 1;
				q.push(v);
			}
		}
	}

	q.push(x);
	bo[x] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (!bo[v]) {
				bo[v] = bo[u] + 1;
				q.push(v);
			}
		}
	}

	int jv = 0;

	for (int i = 1; i <= n; i++) {
		if (bo[i] < al[i]) {
			jv = max(jv, al[i]);
		}
	}

	cout << 2 * (jv - 1) << endl;

	return 0;
}
