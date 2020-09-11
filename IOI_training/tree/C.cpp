
// Problem: C. Andryusha and Colored Balloons
// Contest: Codeforces - Tree
// URL: https://codeforces.com/group/5mF1N2M956/contest/290453/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

vector<vi> g;
vi r;

void dfs(int u, int v) {
	int jo = 1;

	for (int h : g[u]) {
		if (h == v) continue;

		if (jo == r[u]) jo++;
		if (jo == r[v]) jo++;
		if (jo == r[u]) jo++;
		if (jo == r[v]) jo++;

		r[h] = jo++;
		dfs(h, u);
	}
}

signed main() {
	TEZ;

	int n;
	cin >> n;

	g.assign(n + 1, vi());
	r.assign(n + 1, 0);
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	r[1] = 1;
	dfs(1, 0);

	cout << *max_element(ALL(r)) << endl;
	for (int i = 1; i <= n; i++)
		cout << r[i] << " ";

	return 0;
}
