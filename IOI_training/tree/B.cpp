
// Problem: B. Ehab and Path-etic MEXs
// Contest: Codeforces - Tree
// URL: https://codeforces.com/group/5mF1N2M956/contest/290453/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

signed main() {
	TEZ;

	int n;
	cin >> n;

	vector<vi> g(n + 1, vi());
	vii el;
	map<ii, int> ei;
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		if (a > b) swap(a, b);

		el.pb({a, b});
		g[a].pb(b);
		g[b].pb(a);
	}

	int ka, kn;
	ka = kn = -1;
	for (int i = 1; i <= n; i++) {
		if (ka < g[i].size()) {
			ka = g[i].size();
			kn = i;
		}
	}

	int jo = 0;
	for (int v : g[kn]) {
		a = v;
		b = kn;

		if (a > b) swap(a, b);

		ei[{a, b}] = jo++;
	}

	for (auto [f, s] : el) {
		if (ei.find(ii{f, s}) != ei.end()) {
			cout << ei[{f, s}] << endl;
		} else
			cout << jo++ << endl;
	}

	return 0;
}
